    //GIL TASK no = 2;
    // here in this task i m controlling the leds using ldr sensor. and showing the ldr and led status on LCD screen.
    #include <Wire.h>
 // #include <LiquidCrystal.h>  // for simple liquid crystal LCD (20x4)/(16x2) we this library.
    #include <LiquidCrystal_I2C.h>
    
    LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 of I2c module.
    // pins  initializing
    int ldr_pin=A3;//Set A3(Analog Input) for LDR.
    int green_led = 8;
    int red_led = 7;
    
    void setup() {
    lcd.init();// it works as lcd.begin()
    Serial.begin(9600);
    pinMode(green_led,OUTPUT);
    pinMode(red_led,OUTPUT);
    pinMode(A3,INPUT);
    }
    
    void loop() {
    lcd.backlight();
    int value = analogRead(ldr_pin);//Reads the Value of LDR(light).
    Serial.println("LDR value is =  ");//Printing the value of LDR.
    Serial.println(value);
    // print ldr value on lcd display.
    lcd.setCursor(0,0);// 1st column and 1st row.
    lcd.print("LDR VAUE =  ");
    lcd.setCursor(13,0);
    lcd.print(value);
    // applying condition
    if(value > 600)
      {
        lcd.setCursor(3,1); // 3rd column and 2nd row
        lcd.print("red led glow :");

        digitalWrite(green_led, LOW);//the LED will glow in dark.
        digitalWrite(red_led, HIGH);// the LED glow in light.
      }
      else
      {
        lcd.setCursor(4,2);// 4th column and 3rd row.
        lcd.print("green led glow :");

        digitalWrite(green_led,HIGH);//Turns the LED ON in Light.
        digitalWrite(red_led,LOW);//Turns the red_LED OFF in dark.
      }
      lcd.clear();
    }
