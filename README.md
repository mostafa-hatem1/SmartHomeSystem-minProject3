# Smart Home Automation Using ATmega32

## Objective
Design and implement a smart home system that automates lighting and fan speed control based on environmental conditions using ATmega32, LM35 temperature sensor, LDR, Flame sensor, and a PWM-controlled motor.

## Features
- **Automatic Lighting Control**: Uses LDR to control three LEDs.
  - <15%: All LEDs ON
  - 16–50%: Red and Green LEDs ON
  - 51–70%: Red LED ON
  - >70%: All LEDs OFF
- **Automatic Fan Speed Control**: Adjusts fan speed based on temperature.
  - ≥40°C: 100%
  - 35–40°C: 75%
  - 30–35°C: 50%
  - 25–30°C: 25%
  - <25°C: OFF
- **Fire Detection**: Flame sensor triggers alarm and displays alert on LCD.
- **LCD Display**: Shows temperature, light intensity, and fan status.

## Components
- **Microcontroller**: ATmega32
- **Sensors**: LDR (PA0), LM35 (PA1), Flame Sensor (PD2)
- **Display**: 16x2 LCD (PD0, PD1, PORTC)
- **Motor Control**: H-Bridge (PB0, PB1, PB3/OC0)
- **LEDs**: Red (PB5), Green (PB6), Blue (PB7)
- **Buzzer**: PD3

## Drivers
- **ADC**: Reads analog data from LM35 and LDR.
- **GPIO**: Handles pin configurations.
- **PWM**: Controls fan speed using Timer0.
- **LCD**: Displays data in 8-bit mode.
- **Temperature Sensor**: Measures room temperature.
- **LDR Sensor**: Reads light intensity.
- **LED**: Controls LEDs based on light intensity.
- **DC Motor**: Controls fan speed.
- **Flame Sensor**: Detects fire incidents.
- **Buzzer**: Alerts on fire detection.

## Code Characteristics
- **Modular**: Organized into separate modules for easy maintenance.
- **Portable**: Can be adapted to different hardware configurations.
- **Configurable**: Partially configurable for different requirements.



