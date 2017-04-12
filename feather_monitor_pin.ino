/*
 * for the adafruit feather 32u4
 *
 * Monitor when a pin goes high, output state changes to the serial console
 * 
 */

int monitor_pin=5;
int current_status;

int get_monitor_pin()
{
   return digitalRead(monitor_pin);
}

void setup() {

  delay(5000);

  pinMode(monitor_pin, INPUT);  
  current_status=get_monitor_pin();

  Serial.begin(9600);
  Serial.print("PIN is now: ");
  Serial.println(current_status);
  Serial.println("monitoring...");
}

void loop() {

  if (current_status != get_monitor_pin()) {

    current_status = !current_status;
    Serial.print("uptime: ");
    Serial.print(millis());
  
    Serial.print(" monitor pin is: ");
    Serial.println(current_status);
  }
}

