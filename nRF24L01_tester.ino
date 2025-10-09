// Código para probar dos módulos Nrf24l01
// ESP32 - 38 pines

#include <SPI.h>
#include "RF24.h"

// *************** VARIABLES ***************

// Pines de control para la RADIO 1 1 (VSPI, controlador 1)
#define CE1_PIN 4
#define CSN1_PIN 5

// Pines de BUS SPI 1 (VSPI, controlador 1)
#define SCK1_PIN 18
#define MISO1_PIN 19
#define MOSI1_PIN 23

// Pines de control para la RADIO 2 (HSPI, controlador 2)
#define CE2_PIN 2
#define CSN2_PIN 15

// Pines de BUS SPI 2 (HSPI, controlador 2)
#define SCK2_PIN 25
#define MISO2_PIN 26
#define MOSI2_PIN 27

const long SERIAL_BAUD = 115200;

// *************** END VARIABLES ***************

// Controladores SPI Duales
SPIClass spi1(VSPI); // Radio 1
SPIClass spi2(HSPI); // Radio 2

// Instancias RF24
RF24 radio1(CE1_PIN, CSN1_PIN);
RF24 radio2(CE2_PIN, CSN2_PIN);


// Prueba para iniciar el módulo 
bool test_radio_connection(RF24& radio, SPIClass& spi_bus, int radio_id) {
	Serial.print(F("\nINICIANDO PRUEBA PARA RADIO "));
	Serial.println(radio_id);

	// Iniciar la librería RF24
	if (!radio.begin(&spi_bus)) {
		Serial.print(F("Error: Error al iniciar la librería para Radio "));
		Serial.println(radio_id);
		return false;
	}

	// 2. Prueba si detecta algo conectado al ESP32
	if (radio.isChipConnected()) {
		Serial.println(F("Módulo conectado correctamente al bus SPI."));
		return true;
	} else {
		Serial.print(F("Error: Radio "));
		Serial.print(radio_id);
		Serial.println(F(" no responde"));
		Serial.println(F("Revisa cableado SPI y alimentacion (3.3V) de este modulo. Si esto no funciona, podría haber daño físico en el módulo o en los pines del ESP32"));
		return false;
	}
}

void setup() {
	Serial.begin(SERIAL_BAUD);
	delay(500);

	Serial.println(F("================================================="));
	Serial.println(F("Código para probar la pantalla OLED I2C (SSD1306)"));
	Serial.println(F("================================================="));

	bool success_radio1, success_radio2;

	//  Radio 1 
	// Configuración del SPI con el controlador VSPI
	spi1.begin(SCK1_PIN, MISO1_PIN, MOSI1_PIN, -1);
	Serial.print(F("\nINFO: Bus 1 (VSPI) en SCK/MISO/MOSI: "));
	Serial.print(SCK1_PIN); Serial.print("/"); Serial.print(MISO1_PIN); Serial.print("/"); Serial.println(MOSI1_PIN);

	success_radio1 = test_radio_connection(radio1, spi1, 1);

	//  Radio 2 
	// Configuración del SPI con el controlador HSPI
	spi2.begin(SCK2_PIN, MISO2_PIN, MOSI2_PIN, -1);
	Serial.print(F("\nINFO: Bus 2 (HSPI) en SCK/MISO/MOSI: "));
	Serial.print(SCK2_PIN); Serial.print("/"); Serial.print(MISO2_PIN); Serial.print("/"); Serial.println(MOSI2_PIN);

	success_radio2 = test_radio_connection(radio2, spi2, 2);

	Serial.println(F("\n=== RESULTADO FINAL"));

	if (success_radio1 && success_radio2) {
		Serial.println(F("OK: Ambas radios estan cableadas y responden correctamente."));
	} else {
		Serial.println(F("ERROR: Una o ambas radios fallaron. Verifica el cableado. Quizá los puertos de tu ESP32 están quemados, no sirven (Prueba con puertos alternativos). Quizá tu módulo no funciona."));
		while(1); 
	}
}

void loop() {

}