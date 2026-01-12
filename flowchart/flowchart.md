START
  ↓
Initialize Arduino Pins
  ↓
Attach Interrupts to Hall Sensors
  ↓
Read Pulse Count
  ↓
Every 1 Second?
  ├─ No → Continue
  └─ Yes
       ↓
Calculate RPM
       ↓
Map RPM to PWM
       ↓
Update Motor Speed
       ↓
Display RPM on Serial Monitor
       ↓
Repeat
