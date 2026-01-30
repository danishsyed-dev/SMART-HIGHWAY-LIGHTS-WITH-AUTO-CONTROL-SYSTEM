# Hardware Bill of Materials (BOM)

| Item Name | Description/Specifications | Quantity | Estimated Use |
|-----------|----------------------------|----------|---------------|
| **Arduino UNO R3** | Microcontroller founded on ATmega328P, 5V operating voltage. | 1 | Main Control Unit |
| **LCD Display (16x2)** | 16 characters x 2 lines, HD44780 compatible controller, Blue/Green Backlight. | 1 | Status Display |
| **IR Sensor Module** | Infrared Obstacle Avoidance Sensor (FC-51 or similar). Active LOW output. | 2 | Vehicle Detection (Entry & Exit) |
| **LDR (Photoresistor)** | Light Dependent Resistor, 5mm. Resistance varies with light. | 1 | Day/Night Sensing |
| **Resistor 10kΩ** | 1/4W Through-hole resistor. | 1 | Pull-down for LDR circuit |
| **Resistor 220Ω** | 1/4W Through-hole resistor. | 4 | Current limiting for LEDs |
| **Potentiometer 10kΩ** | Preset/Trimpot for LCD Contrast adjustment. | 1 | LCD Contrast |
| **LEDs (White/Yellow)** | 5mm High Brightness LEDs. | 4 | Simulating Street Lights |
| **Breadboard** | 400 or 830 tie-points solderless breadboard. | 1 | Prototyping |
| **Jumper Wires** | Male-to-Male, Male-to-Female. | ~20 | Connections |
| **USB Cable** | Type A to Type B (Printer cable). | 1 | Uploading code & Power |

> **Note:** For a real highway implementation, LEDs would be replaced by Relay Modules controlling high-voltage AC street lamps.
