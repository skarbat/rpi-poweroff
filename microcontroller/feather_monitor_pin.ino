/*
 * for the adafruit feather 32u4
 *
 * Monitor when a pin goes high, output state changes to the serial console
 * 
 */

// The RPi sets it LOW to request a power off
int poweroff_pin=11;

// Is set HIGH to let the RPi detect the battery
int detection_pin=13;

// Connected to a transistor, turns the RPi ON and OFF
int rpi_power_pin=5;

// Used to monitor poweroff_pin changes
int poweroff_status=0;


int get_poweroff_status()
{
   return digitalRead(poweroff_pin);
}


void setup() {

  // initial delay to allow serial console to get ready
  Serial.begin(9600);
  delay(3000);

  // Setup pin directions and statuses
  pinMode(poweroff_pin, INPUT);
  poweroff_status=get_poweroff_status();

  delay(20);

  pinMode(detection_pin, OUTPUT);
  digitalWrite(detection_pin, HIGH);

  delay(20);

  // when the Feather wakes up, we power on the raspberry pi
  pinMode(rpi_power_pin, OUTPUT);
  digitalWrite(rpi_power_pin, HIGH);

  delay(20);

  Serial.print("poweroff_pin is ");
  Serial.println(poweroff_status);
  Serial.println("monitoring...");
}


void loop() {

  if (poweroff_status != get_poweroff_status()) {

    poweroff_status = !poweroff_status;
    Serial.print("uptime: ");
    Serial.print(millis());
  
    Serial.print(" monitor pin has changed to: ");
    Serial.println(poweroff_status);

    // if the raspberry pi signals a LOW, power it off - gpio-poweroff overlay
    if (poweroff_status == 0) {
      Serial.println("powering off the raspberry pi");
      delay(1500);
      digitalWrite(rpi_power_pin, LOW);
    }
  }
}

