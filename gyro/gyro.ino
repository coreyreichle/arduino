#include <Wire.h>
#include <LiquidCrystal.h>

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23

int Addr = 105;                 // I2C address of gyro
int x, y, z;

int ledPin = 8;

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

void setup(){
  Wire.begin();
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  pinMode(ledPin, OUTPUT);
  writeI2C(CTRL_REG1, 0x1F);    // Turn on all axes, disable power down
  writeI2C(CTRL_REG3, 0x08);    // Enable control ready signal
  writeI2C(CTRL_REG4, 0x100);    // Set scale (500 deg/sec)
  delay(100);                   // Wait to synchronize
}

void loop(){
  digitalWrite(ledPin, LOW);
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(0,0); 
  getGyroValues();              // Get new values

  // In following Dividing by 114 reduces noise
  lcd.print(x );
  lcd.setCursor(7,0);
  lcd.print(y );
  lcd.setCursor(14,0);
  lcd.print(z );
  analogWrite(ledPin, x + y + z);
  delay(500);                   // Short delay between reads
}

void getGyroValues () {
  byte MSB, LSB;

  MSB = readI2C(0x29);
  LSB = readI2C(0x28);
  x = ((MSB << 8) | LSB);

  MSB = readI2C(0x2B);
  LSB = readI2C(0x2A);
  y = ((MSB << 8) | LSB);

  MSB = readI2C(0x2D);
  LSB = readI2C(0x2C);
  z = ((MSB << 8) | LSB);
}

int readI2C (byte regAddr) {
    Wire.beginTransmission(Addr);
    Wire.write(regAddr);                // Register address to read
    Wire.endTransmission();             // Terminate request
    Wire.requestFrom(Addr, 1);          // Read a byte
    while(!Wire.available()) { };       // Wait for receipt
    return(Wire.read());                // Get result
}

void writeI2C (byte regAddr, byte val) {
    Wire.beginTransmission(Addr);
    Wire.write(regAddr);
    Wire.write(val);
    Wire.endTransmission();
}
