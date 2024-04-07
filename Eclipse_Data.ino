#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>
#include <DS1302.h>
#include <Adafruit_BMP085.h>
#include <ML8511.h>

#define IN A0
#define RST 2
#define DAT 4
#define CLK 5
#define CS 10

// Creando instancias de módulos
DS1302 rtc(RST, DAT, CLK);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Creando instancias de sensores
ML8511 ml8511(IN);
Adafruit_BMP085 bmp180;

// Declando variables para almacenar datos
float pres, temp, uv, duv;
String data;

void configurarModulos() {

  // Iniciando pantalla LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.backlight();
  lcd.home();

  // Iniciando módulo SD Card
  if (!SD.begin(10)) {
    
    lcd.setCursor(0,0);
    lcd.print("SD Card no");
    lcd.setCursor(0,1);
    lcd.print("encontrado.");
    
    while (1);
    
  }

  // Verificando conexión de sensor BMP180
  if (!bmp180.begin()) {
    
    lcd.setCursor(0,0);
    lcd.print("BMP180 no");
    lcd.setCursor(0,1);
    lcd.print("encontrado.");
    
    while(1);
    
  }
  
}

void leerSensores() {
  
  pres = bmp180.readPressure();
  temp = bmp180.readTemperature();
  uv = ml8511.getUV();
  duv = ml8511.estimateDUVindex(uv);
  
}

void escribirInfo() {
  
  File file;
  file = SD.open("info.csv", FILE_WRITE);
  file.println(data);
  file.close();
  
}

void imprimirDatos(Time t) {

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(String(int(t.hr / 10)) + String(t.hr % 10) + ":" + String(int(t.min / 10)) + String(t.min % 10) + ":" + 
            String(int(t.sec / 10)) + String(t.sec % 10) + " " + "DUV:" + String(int(duv)));
  lcd.setCursor(0,1);
  lcd.print("T:" + String(temp, 1) + " " + "P:" + String(pres / 100, 2)); // T[°C] | P[hPa]
  
}

void setup() {

  configurarModulos(); // Configurando los módulos y sensores
  ml8511.setDUVfactor(0.75); // Calibrando sensor ML8511
  
  lcd.clear();
  delay(1000);

}

void loop() {
  
  Time t = rtc.time(); // Obteniendo hora actual
  leerSensores(); // Obteniendo datos de sensores

  // Creando la trama de datos.
  data = String(int(t.hr / 10)) + String(t.hr % 10) + ":" + String(int(t.min / 10)) + String(t.min % 10) + ":" + String(int(t.sec / 10)) + 
         String(t.sec % 10) + "," + String(pres / 100, 2) + "," + String(temp, 1) + "," + String(uv, 1) + "," + String(int(duv));

  escribirInfo(); // Escribiendo info en tarjeta SD
  imprimirDatos(t); // Imprimiendo datos en la pantalla LCD

  delay(1000);

}
