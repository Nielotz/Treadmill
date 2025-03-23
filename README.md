# Treadmill

**⚠️ Warning:** BLDC driver that supports 6 poles is preferred.

## Summary

I have got broken treadmill with purpose to repair.
Original board (RTW-082381-003) had shorted IGBT on high side and short in the main uC on the low side. Found thread with many people having exact the same issue with no solution other than new BLDC.

This repository is an attempt to integrate BLDC (BLDH400R) with existing treadmill parts to create custom controls / UI.

## Components

### Motor

| Specification | Value |
|---------------|-------|
| Model | RT-0551W-00002 |
| Rated Power | 550W |
| Speed | 2500r/min |
| Poles | 6? (6 magnets, 9 coils) :? |

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

### BLDC driver

| Specification | Value |
|---------------|-------|
| Model | BLDH400R |
| Rated motor power | 400W |
| Minimal motor speed | 60 RPM* |
| SPEED feedback | * |
| Poles config - jumpers [3rd,4th] | 4[1,0] (default if open loop[0,0]), **8[0,1]**, 10 [1,1]|
| Communication | Direct pin, 2-wire EIA/TIA-485 |

*Requires poles to match :c </br>
Maybe we get speed from hals?

### uC: ESP8266 by NodeMcu V3
