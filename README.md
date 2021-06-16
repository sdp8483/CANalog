# CANalog

CAN to analog converter.

## TODO
### PCB
- [x] Add resistor to stm32 reset line so that stm32 programmer can reset uC when esp8266 is pulling pin high
- [x] Increase clearance between terminals and mounting holes by about 1mm
- [x] Increase spacing between aout terminal and CAN terminal, possibly center CAN terminal.
- [ ] add 16bit DAC
### WiFi Interface Firmware
- [ ] fix webpage layout for mobile devices
- [ ] aout control for analog calibration
- [ ] setup over the air update for esp8266 firmware
### CAN Interface Firmware
- [ ] LED persistance for CAN activity
- [ ] setup bootloader over spi for wifi update of firmware
- [ ] setup CAN filtering
- [ ] test std ID CAN messages
- [ ] test timing
- [ ] write code to detect versioning pins
