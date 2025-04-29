# 🔐 RFID Attendance System using ESP32

<p align="center">
  <img src="https://i.imgur.com/mQoaWS8.jpeg" width="400" />
</p>


An IoT-based smart RFID attendance system using **ESP32**, **RC522 RFID module**, and **16x2 LCD Display**, with real-time data logging directly into **Google Sheets**. Designed for schools, colleges, or any organization that needs a simple and automated attendance solution.


🚀 Built with two powerful modes:  
➕ **User Registration Mode**  
📅 **Attendance Mode**

🕒 All attendance logs are recorded in **NST (Nepal Standard Time)**.

---



## ⚙️ Features

- 📲 ESP32 WiFi-enabled microcontroller
- 🪪 RC522 RFID module for tag scanning
- 📟 16x2 LCD Display for user feedback
- 📄 Google Sheets integration using Google Apps Script
- 🧠 Dual-mode system:
  - **Registration Mode** – Add new users with RFID UID and name
  - **Attendance Mode** – Log attendance with date and time
- 🌐 Real-time syncing over the internet
- 🕐 Timestamped records in NST

---

## 🧰 Hardware Required

| Component           | Quantity |
|---------------------|----------|
| ESP32 Dev Board     | 1        |
| RC522 RFID Module   | 1        |
| 16x2 LCD Display    | 1        |
| Jumper Wires        | Several  |
| Breadboard (Optional) | 1      |
| RFID Tags/Cards     | As needed|

---

## 📦 Folder Structure

📁 RFID-Attendance-ESP32/  
├── 📄 attendance.ino           # Main Arduino code  
├── 📄 credentials.h            # WiFi and Google Script credentials  
├── 📄 GoogleAppsScript.gs      # Script to connect to Google Sheets  
├── 📄 README.md                # This file  


---

## 🔌 Wiring Overview

| RC522 Pin | ESP32 Pin |
|-----------|-----------|
| SDA       | D21       |
| SCK       | D18       |
| MOSI      | D23       |
| MISO      | D19       |
| IRQ       | Not connected |
| GND       | GND       |
| RST       | D22       |
| 3.3V      | 3.3V      |

> 💡 Make sure to power the RC522 with **3.3V only** (not 5V)!

---

## ☁️ Google Sheets Integration

1. Create a new **Google Sheet**.
2. Go to `Extensions > Apps Script`.
3. Paste the code from `GoogleAppsScript.gs`.
4. Deploy it as a **Web App**:
   - **Execute as**: Me
   - **Who has access**: Anyone
5. Copy the Web App URL.
6. Paste it inside your `credentials.h` file as shown below.

---

## 🔐 `credentials.h` Example

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
const char* scriptURL = "YOUR_GOOGLE_SCRIPT_URL";
```

## ▶️ Modes Explained
### 🟢 Registration Mode
- Scan a new RFID tag.
- The system prompts for user details.
- UID and name are stored in Google Sheets.

### 🔵 Attendance Mode
- Tap the tag to mark attendance.
- Date and time are logged automatically.
- Duplicate entries for the same day are prevented.

## 🌍 Timezone Configuration
This system uses Nepal Standard Time (NST). You can adjust the timezone in the Apps Script:

``` cpp
   var timeZone = "Asia/Kathmandu"; // NST
```

## ✅ Future Enhancements
- 🖥️ Admin dashboard for data filtering and reporting
- 📧 Email notifications on entry
- 📲 NFC card and mobile tag support

## 🧠 Credits
Made with 💡 and ❤️ by **Sameer Sah** <br>
Inspired by the power of automation and microcontrollers.

--- 
> **⚠️ Note:**  
> This is only a **prototype**, not the whole system. It is meant for demonstration purposes and further development is required for full deployment.


---

Let me know if you want me to generate the Google Apps Script code or the actual `.ino` code too — I’ve got your back!





