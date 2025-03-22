# Treadmill

I have got broken treadmill with purpose to repair.
Original board (RTW-082381-003) had shorted IGBT on high side and short in the main uC on the low side. Found thread with many people having exact the same issue with no solution other than new BLDC.

This repository is an attempt to integrate BLDC (BLDH400R) with existing treadmill parts to create custom controls / UI.

## Components

### Motor: RT-0551W-00002

#### Connectors

##### 3PIN (power)

| Color    | Pin |
|----------|-----|
| 🔴 RED   | W   |
| 🟢 GREEN | V   |
| 🔵 BLUE  | U   |

##### 5PIN (HAL sensors)

| Color     | Pin |
|-----------|-----|
| 🟢 GREEN  |  U  |
| ⚪ WHITE  |  V  |
| 🟡 YELLOW |  W  |
| 🔴 RED    | +5  |
| ⚫ BLACK  | GND |

### BLDC: BLDH400R

### uC: ESP8266 by NodeMcu V3
