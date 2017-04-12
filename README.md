# rpi-poweroff

Microcontroller code to monitor a PIN on the Raspberry PI for a power off.
The pin is controlled through the `gpio-poweroff` overlay from the RaspberryPI Foundation.

I used a Adafruit feather board, but many more variations should do the same work.

## Software setup

Enable the overlay in config.txt with `dtoverlay=gpio-poweroff,gpiopin=26,active_low=y`.
An alternative is to load it at run time with `sudo dtoverlay gpio-poweroff gpiopin=26 active_low=y`.

## Wiring

There are just 3 simple connections:

 * Connect BCM26 from the RaspberryPI to Pin 5 on the Feather - see `monitor_pin` variable.
 * Connect GND from the RaspberryPI to GND on the Feather
 * Connect a 4.5 KOhm resistor between BCM26 to 3.3v - guarantees a HIGH when power is applied.

## Running

Connect the Feather to your computer through the USB and open the Serial Monitor from the Arduino IDE.
