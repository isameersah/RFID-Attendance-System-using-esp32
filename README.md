# 📡 RFID-Based IoT Attendance System Using ESP32 & Google Sheets  
> ⚡️ Real-time Cloud Logging | 🧠 Smart Automation | 🔐 Secure & Scalable

![rfid-banner](https://your-image-link/banner.png)

---

## 🚀 Executive Summary

The RFID Attendance System leverages **IoT (ESP32)** and **RFID (RC522)** modules to automate classroom attendance by logging entries directly into **Google Sheets** via **HTTP Webhooks**. It eliminates manual paperwork, reduces human error, and provides instant cloud-based data tracking and reporting — enabling modern, data-driven educational environments.
---

## 🧠 Overview

This project is a complete **IoT Attendance System** using:

- 📶 **ESP32 microcontroller**
- 📇 **RFID RC522 reader**
- 📄 **Google Sheets** for cloud-based logging
- 🖥️ **LCD Display** (16x4 I2C)
- 🔌 **Wi-Fi** integration for real-time updates

> Built with no external libraries — only raw SPI, WiFi, and HTTPClient.

---

## 🏷️ Tech Stack

![Platform](https://img.shields.io/badge/platform-ESP32-blue.svg)
![RFID](https://img.shields.io/badge/module-RC522-orange.svg)
![Google Sheets](https://img.shields.io/badge/database-Google%20Sheets-green.svg)
![LCD](https://img.shields.io/badge/display-16x4%20I2C-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-yellow.svg)

---

## 📸 Demo Preview

| RFID Scan | Google Sheet Log | Serial Monitor |
|-----------|------------------|----------------|
| ![scan](https://your-image-link/scan.gif) | ![sheet](https://your-image-link/sheet.gif) | ![serial](https://your-image-link/serial.gif) |

> *(Replace links with your own images or gifs.)*

---

## ⚙️ Features Checklist

- [x] 🔍 RFID-based attendance scanning
- [x] 🌐 ESP32 Wi-Fi connection
- [x] 📄 Google Sheets as cloud storage
- [x] 📟 LCD UID display
- [x] 🛡️ Duplicate prevention and validations
- [x] 🔔 Live updates via Serial Monitor
- [ ] 📲 Mobile App (Planned)
- [ ] 🔐 Biometric integration (Planned)
- [ ] 📊 Admin dashboard with charts (Future)

---



# 📡 RFID-Based IoT Attendance System Using ESP32 & Google Sheets

Welcome to our powerful, real-time attendance management system that uses **RFID**, **ESP32**, and **Google Sheets** for smart logging. Built to eliminate manual processes and reduce human error, this project automates attendance tracking using affordable components and a Wi-Fi connection.

---

## 🛠️ Hardware Components

| Component            | Description                                 |
|---------------------|---------------------------------------------|
| ESP32 Dev Module     | Microcontroller with Wi-Fi capability       |
| RC522 RFID Reader   | For reading RFID cards/tags                 |
| RFID Cards/Tags     | Unique UIDs used for attendance             |
| LCD 16x4 (I2C)       | Displays UID and Name                       |
| Breadboard + Wires  | For connections                             |
| USB Type-C Cable     | Data-capable, to connect ESP32 to PC        |
| Internet Connection  | Required for syncing with Google Sheets     |

> Most of the components were sourced from our college IoT lab with approval from **Mr. Shishir Subedi**. Additional components were purchased by team members.

---

## ⚙️ System Workflow

1. ✅ **Scan RFID Card**
2. 📟 UID displayed on LCD
3. ⏱️ UID + Timestamp sent to Google Sheets
4. 📊 Attendance stored securely in the cloud

---

## 🔌 Wiring Summary

### 📶 RC522 to ESP32

| RC522 Pin | ESP32 Pin | Purpose         |
|-----------|-----------|-----------------|
| 3.3V      | 3.3V      | Power Supply     |
| GND       | GND       | Ground           |
| RST       | D4        | Reset            |
| SDA       | D5        | SPI Slave Select |
| SCK       | D18       | SPI Clock        |
| MOSI      | D23       | SPI Data Out     |
| MISO      | D19       | SPI Data In      |

### 🖥️ LCD to ESP32

| LCD I2C Pin | ESP32 Pin |
|-------------|------------|
| VCC         | VIN        |
| GND         | GND        |
| SDA         | D21        |
| SCL         | D22        |

---

## 💻 Software Setup

### Prerequisites

- 🧰 [Arduino IDE](https://www.arduino.cc/en/software)
- 📄 Google Account with access to Google Sheets & Apps Script
- 📦 ESP32 board package in Arduino IDE

### Steps

1. 🔌 Connect ESP32 using USB Type-C.
2. 🧠 Upload code via Arduino IDE.
3. 📄 Create a Google Sheet with headers: `UID`, `Timestamp`.
4. 🧰 Deploy Apps Script Web App (set access to `Anyone`).
5. ✅ Scan card → Logs attendance → Confirms via Serial Monitor.

---

## 🔍 Testing & Output

- On card scan, UID appears on LCD.
- Sheet logs timestamp + UID in real-time.
- Monitor shows: `Data sent to Google Sheet ✅`

> Troubleshooting: Check wiring, power (3.3V), Wi-Fi credentials, Apps Script permissions.

---

## 🚀 Future Work

💡 Suggested improvements:

- 🔊 Buzzer/LED feedback on scan  
- 🧠 AI for smart attendance tracking  
- 📱 Mobile app for real-time alerts  
- 🔐 Biometric fusion (Face/Fingerprint + RFID)  
- 🧾 Automatic attendance reports to email  
- 🏫 Smart Campus integration (library, labs, etc.)

---

## 📈 Results & Findings

- ⏱️ Reduced attendance time
- ❌ Eliminated proxy marking
- 💾 Reliable cloud-based data storage
- 💰 Budget-friendly and scalable
- 🔁 Reusable for schools, colleges, offices

---

## 🧾 Conclusion

The RFID Attendance System revolutionizes traditional attendance marking. It’s fast, efficient, scalable, and secure. From hardware wiring to Google Sheets integration — this system delivers a modern attendance solution ready for 2025 and beyond.

---

## 🧑‍💻 Contributors

| 🙋‍♂️ Name                  | 💼 Role                         |
|----------------------------|--------------------------------|
| **Sameer Sah**             | 🚀 Project Lead & Developer     |
| **Anshumala Bhandari**     | 🔧 Developer & Researcher       |
| **Bibhuti Sigdel**         | 📝 Developer & Documentation    |
| **Sanshree Shrestha**      | 🔍 Research & Data Handling     |
| **Shraddha Budhathoki**    | 🎨 UI/UX Designer & Report Writer |
| **Sagun Budhatho**         | 🧪 Assistant Developer & Tester  |
|--------------------------------------------------------------|
- 🧠 Supervised by: **Shishir Subedi**

---

## 📎 License

This project is open-source under the [MIT License](LICENSE).

---

## 🔗 Connect with Me

- 💼 [LinkedIn](https://www.linkedin.com/in/YOUR-PROFILE/)
- 🐙 [GitHub](https://github.com/YOUR-USERNAME)
