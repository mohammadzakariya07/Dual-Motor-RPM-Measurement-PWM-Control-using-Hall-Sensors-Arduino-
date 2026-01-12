# Working of Dual Motor RPM Control System

- Hall sensors generate pulses on every motor rotation
- Arduino counts pulses using hardware interrupts
- Every 1 second, RPM is calculated using pulse count
- RPM values are mapped to PWM range (0–255)
- PWM signals control motor speed
- RPM values are displayed on Serial Monitor
