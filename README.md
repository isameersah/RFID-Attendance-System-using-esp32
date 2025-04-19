🔐 RFID Attendance System using ESP32
An IoT-based smart RFID attendance system using ESP32, RC522 RFID module, and LCD Display, with real-time data logging directly into Google Sheets. Designed for schools, colleges, or any organization that needs a simple and automated attendance solution.

🚀 Built with two powerful modes:
➕ User Registration Mode
📅 Attendance Mode

🕒 All attendance logs are recorded in NST (Nepal Standard Time).

⚙️ Features
📲 ESP32 WiFi-enabled microcontroller

🪪 RC522 RFID module for tag scanning

📟 16x2 LCD Display for user feedback

📄 Google Sheets integration using Google Apps Script

🧠 Dual-mode system:

Registration Mode – Add new users with RFID UID and name

Attendance Mode – Log attendance with date and time

🌐 Real-time syncing over the internet

🕐 Timestamped records in NST

🧰 Hardware Required

Component	Quantity
ESP32 Dev Board	1
RC522 RFID Module	1
16x2 LCD Display	1
Jumper Wires	Several
Breadboard (Optional)	1
RFID Tags/Cards	As needed
📦 Folder Structure
bash
Copy
Edit
📁 RFID-Attendance-ESP32/
├── 📄 attendance.ino           # Main Arduino code
├── 📄 credentials.h            # WiFi and Google Script credentials
├── 📄 GoogleAppsScript.gs      # Script to connect to Google Sheets
├── 📄 README.md                # This file
🔌 Wiring Overview

RC522 Pin	ESP32 Pin
SDA	D21
SCK	D18
MOSI	D23
MISO	D19
IRQ	Not connected
GND	GND
RST	D22
3.3V	3.3V
💡 Make sure to power the RC522 with 3.3V only (not 5V)!

☁️ Google Sheets Integration
Create a Google Sheet.

Go to Extensions > Apps Script, paste the code from GoogleAppsScript.gs.

Deploy it as a Web App (with permissions: Anyone with the link).

Copy the Web App URL and paste it in your credentials.h.

🔐 credentials.h Example
cpp
Copy
Edit
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
const char* scriptURL = "YOUR_GOOGLE_SCRIPT_URL";
▶️ Modes Explained
🟢 Registration Mode
Use the RFID tag to register new users. Their UID and name will be saved in the Google Sheet.

🔵 Attendance Mode
Tap the tag to log the date and time of attendance. Duplicate entries for the same day are avoided.

🌍 Timezone Configuration
This system uses Nepal Standard Time (NST). Adjust Google Apps Script for other timezones if needed:

javascript
Copy
Edit
var timeZone = "Asia/Kathmandu"; // NST
📸 Demo
(Insert GIF or image of system in action – optional but cool!)

✅ Future Enhancements
Admin dashboard for data filtering

Email notifications on entry

NFC card support

🧠 Credits
Made with 💡 and ❤️ by Sameer Sah.
Inspired by the power of automation and microcontrollers.

📜 License
This project is licensed under the MIT License – feel free to use and modify!

Let me know if you want this turned into a README.md file or want to add a badge or demo video link!
