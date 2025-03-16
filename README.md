# Astro Power Box 

## Overview

PBV1 Power Distribution Box is designed for **astrophotography setups**, allowing users to efficiently power and control their astronomical equipment. It provides multiple **USB and 12V outputs**, making it an essential component for **observatory automation** and **field setups**.

## Key Features

✅ 4 switchable **USB 2.0 ports** (3A max per port)\
✅ 4 switchable **12V output ports** (3A max per port)\
✅ Configurable **persistent boot states** for outputs\
✅ **ASCOM and INDI driver** support for remote control\
✅ **Bluetooth connectivity** for serial communication\
✅ Supports up to **150W of total power distribution**

## Technical Specifications

### **Electrical**

| Specification       | Max | Typical | Min |
| ------------------- | --- | ------- | --- |
| Input Voltage (Vin) | 15V | 12V     | 5V  |
| Power Consumption   | 15A | -       | -   |
| USB2 Ports          | 4   | -       | -   |
| 12V Outputs         | 4   | -       | -   |

### **Physical**

| Specification | Value                       |
| ------------- | --------------------------- |
| Dimensions    | 110 mm x 100 mm x 31 mm     |
| Weight        | 250 grams                   |
| Enclosure     | Plastic (PLA thermoplastic) |
| Mounting      | Pre-drilled holes           |

### **Environmental Conditions**

| Condition             | Range                    |
| --------------------- | ------------------------ |
| Operating Temperature | -10°C to 50°C            |
| Storage Temperature   | -20°C to 60°C            |
| Humidity Range        | 10%-90% (non-condensing) |

## Directory Structure

```
astro_power_box/
├── cad/         # 3D enclosure design (STEP)
├── code/        # MCU firmware (Arduino)
├── doc/         # Documentation (LaTeX, images)
├── pcb/         # KiCad PCB design files
└── README.md    # Project overview
```

## Device Operation

The PBV1 allows individual control of **USB and 12V outputs** via **serial Bluetooth communication**. The outputs are managed through **dedicated ASCOM and INDI drivers**, enabling integration with astrophotography software like **KStars and N.I.N.A.**

### **Control Features**

- **Remote switch control** for USB and 12V outputs
- **Default power states** configurable via software
- **Real-time power monitoring** (if applicable)

## Setup Instructions

### **Windows Setup**

1. Connect the **12V XT30 connector** to PBV1.
2. Connect a **USB-A to USB-B cable** between the host computer and PBV1.
3. Ensure the computer is discoverable for **Bluetooth devices**.
4. In Windows **Bluetooth settings**, add a new device.
5. Select **HC-05** and enter **PIN: 1234**.
6. A new **Serial Port** will appear under **COM and LPT** in **Device Manager**.
7. Note the **Serial Port name (e.g., COM6)** for ASCOM driver setup in NINA.

### **ASCOM Driver Installation (Windows)**

1. Download the latest ASCOM driver: [Download Here](https://drive.google.com/drive/folders/1Y-2tLgOCcrt2SNI-Vw1phUzMPFCBjFHW?usp=drive_link)
2. Run the installer and follow on-screen instructions.
3. Open your **astrophotography software** and configure the driver.
4. Set the **Serial Bluetooth port** as shown in **Device Manager**.
5. Assign labels for outputs (default: Switch 1 to 8).

### **INDI Driver Installation (Linux/Mac)**

🚧 **Not Released Yet**

## **Setting Up Custom Boot Configuration for Outputs**

1. Download the **BT Serial Android app**: [Google Play Store](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal)
2. Pair your phone with **PBV1 Bluetooth module (HC-05)**.
3. Connect to **BT Serial Terminal** (Baud rate: **9600**).
4. Send `eX` where `X = 0-7` to set default boot states.
5. The device confirms changes and requires a reboot.
6. If modifying multiple outputs, send multiple commands before rebooting.

## Wiring & Pinout Diagrams

📌 See `doc/figures/ConnectionDiagram.png` for the full wiring diagram.

## Troubleshooting & FAQs

- **Device not detected?** → Check drivers and connections.
- **Power issues?** → Verify fuse settings and power source.
- **USB ports not working?** → Try a different USB cable.

## License

📜 This project is licensed under the **MIT License**.

## Contributing

Contributions are welcome! Open an **issue** or submit a **pull request**.

---

🚀 **PBV1 - Power Distribution Box for Astrophotography**


