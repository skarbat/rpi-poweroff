# rpi-poweroff

A microcontroller code that detects the Raspberry PI going to a power off, then cuts the power to the board.
Used to control the Raspberry power consumption from an external source, like a battery.

The pin is controlled through the `gpio-poweroff` overlay from the RaspberryPI firmware.

I used a Adafruit feather board, but many more variations should do the same work.

## Software setup

Enable the overlay in config.txt with `dtoverlay=gpio-poweroff,gpiopin=16,active_low=y`.
An alternative is to load it at run time with `sudo dtoverlay gpio-poweroff gpiopin=16 active_low=y`.

## Wiring

There are 3 connections needed. A powerup transistor, a detection pin, and the poweroff pin.

 * Connect BCM16 from the RaspberryPI to Pin 11 on the Feather - will go LOW when the PI powers off
 * Connect GND from the RaspberryPI to GND on the Feather
 * Connect a 4.5 KOhm resistor between BCM16 to 3.3v - guarantees a HIGH when power is applied.
 * Connect Pin 5 on the feather to a transistor base, then RPi 5V and GND to collector / emitter - use a resistor on the base
 * Connect Pin 13 from the feather to BCM17 on the Raspberry - this is a probe pin set to HIGH when controller available

## Running

Connect the Feather to your computer through the USB and open the Serial Monitor from the Arduino IDE.
It will turn on the RaspberryPI after 3 seconds.

From the RPi, insert the overlay as explained above, then do a `sudo poweroff`. The feather will detect
the power off and will cut power to the board through the transistor.
