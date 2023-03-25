/********************************-******************
  Leitura das informações de temperatura e humidade
  e escrita dessas informações no display oled.

  Links das bibliotecas externas:
    DTH -> https://github.com/adafruit/DHT-sensor-library
    u8glib -> https://github.com/olikraus/u8glib

  Desenvolvido por Letícia P Garcez - 03/2023
 ****************************************************/

#include <laboratorioFW_ARDUNO.h>
#include <DHT.h>
#include <U8glib.h>

U8GLIB_SSD1306_128X64 tela(U8G_I2C_OPT_NONE);
DHT dht(A_9, DHT11);

void setup() {
  dht.begin();
}

void loop() {
  tela.firstPage();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    String textoUm =   String(h) + " %t";
    String textoTemp =  String(t) + " *C";
    do {
      tela.setFont(u8g_font_unifont);
      tela.drawStr(0, 15, "Umidade: " );
      tela.drawStr(0, 30, textoUm.c_str());
      tela.drawStr(0, 45, "Temperatura: " );
      tela.drawStr(0, 60, textoTemp.c_str());
    } while ( tela.nextPage() );
  }
  delay(1000);
}
