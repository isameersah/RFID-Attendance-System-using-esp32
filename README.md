# 📡 RFID-Based IoT Attendance System Using ESP32 & Google Sheets  
> ⚡️ Real-time Cloud Logging | 🧠 Smart Automation | 🔐 Secure & Scalable

![rfid-banner](https://your-image-link/banner.png)

---

## 🚀 Executive Summary

The RFID Attendance System leverages **IoT (ESP32)** and **RFID (RC522)** modules to automate classroom attendance by logging entries directly into **Google Sheets** via **HTTP Webhooks**. It eliminates manual paperwork, reduces human error, and provides instant cloud-based data tracking and reporting — enabling modern, data-driven educational environments.

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

## 📂 Project Structure

```bash
📁 rfid-attendance/
├── 📄 README.md
├── 🧠 code/
│   ├── main.ino            # ESP32 Arduino code
│   └── google_script.gs    # Google Apps Script
├── 📷 images/               # Demo GIFs/Screenshots
├── 📄 LICENSE
└── 📄 .env (WiFi credentials - excluded)
