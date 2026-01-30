# SMART HIGHWAY LIGHTS WITH AUTO CONTROL SYSTEM

**Diploma Major Project (2019)**

![Project Hero Image - Placeholder](docs/images/project-banner.png)
*(Replace with actual project photo)*

## 📄 Abstract
Traditional street lighting systems remain ON throughout the night, consuming vast amounts of energy regardless of traffic flow. This project, **Smart Highway Lights with Auto Control System**, introduces an intelligent solution that uses sensors to detect vehicle movement and ambient light, activating street lights only when necessary. This significantly reduces energy consumption and maintenance costs.

---

## ⚡ Features
- **Automatic Day/Night Detection**: Intelligent switching based on ambient light conditions.
- **Vehicle Movement Detection**: Lights turn ON only when a vehicle approaches.
- **Energy Conservation**: Reduces electricity wastage by keeping lights OFF when no vehicles are present.
- **Real-time Status Display**: 16x2 LCD shows the current mode (Day/Night) and light status.
- **Scalable Design**: Can be extended to cover long stretches of highways.

---

## 🛠 Hardware Components

| Component | Specification | Quantity |
|-----------|---------------|----------|
| Arduino UNO | Microcontroller | 1 |
| LCD Display | 16x2 Alphanumeric | 1 |
| IR Sensor Module | Obstacle/Proximity Sensor | 2 |
| LDR | Light Dependent Resistor | 1 |
| LEDs | White (representing street lights) | 4 |
| Resistors | 10kΩ, 220Ω | Various |
| Connecting Wires | Jumper wires (M-M, M-F) | - |
| Breadboard | - | 1 |

---

## 🔌 Circuit Connections

### LCD Display
| LCD Pin | Arduino Pin |
|---------|-------------|
| RS | Pin 8 |
| EN | Pin 9 |
| D4 | Pin 10 |
| D5 | Pin 11 |
| D6 | Pin 12 |
| D7 | Pin 13 |

### Sensors & Actuators
| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| **LDR** | A0 | Analog Input for Light detection |
| **IR Sensor 1** | Pin 2 | Detects vehicle entry |
| **IR Sensor 2** | Pin 3 | Detects vehicle exit/next zone |
| **LED 1 & 2** | Pin 4, 5 | Street Light Zone 1 |
| **LED 3 & 4** | Pin 6, 7 | Street Light Zone 2 |

> **Note:** LEDs are configured as Active LOW in the code (Common Anode logic or Sink configuration). Adjust `digitalWrite` logic if using Active HIGH.

---

## 📸 Circuit Diagram & Gallery

### Circuit Diagram
![Circuit Diagram - Placeholder](docs/images/circuit-diagram.png)
*(Place your circuit diagram here)*

### Project Prototype
![Prototype Image 1 - Placeholder](docs/images/prototype-1.png)

![Prototype Image 2 - Placeholder](docs/images/prototype-2.png)

---

## 🚀 How It Works
1. **Day Mode**: The LDR detects sunlight (> Threshold). System stays in "DAY" mode, keeping all lights OFF.
2. **Night Mode**: When LDR detects darkness (< Threshold), system enters "NIGHT" mode.
3. **Standby**: At night, if no vehicles are detected, lights remain OFF (or dimmed in advanced versions) to save power.
4. **Active Mode**: 
   - When **IR Sensor 1** detects a vehicle, the first set of lights turns ON.
   - As the vehicle moves to **IR Sensor 2**, the next set of lights turns ON.
   - Lights automatically turn OFF after a delay once the vehicle passes.

---

## 📁 Repository Structure
```
├── src/                # Source code
│   └── SmartHighwayLights/ 
│       └── SmartHighwayLights.ino  # Main Arduino Sketch
├── docs/               # Documentation
│   └── (FINAL)SMART...pdf          # Original Project Report
├── LICENSE             # MIT License
└── README.md           # Project Documentation
```

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

**Copyright (c) 2019 SYED DANISH ALI**
