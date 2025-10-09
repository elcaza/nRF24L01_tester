# nRF24L01 tester for ESP32
Un código para probar el funcionamiento correcto del ESP32 y dos módulos de radiofrecuencia (Nrf24l01|E01-ML01DP5|E01 2G4M27D).

Este proyecto considera:
+ ¿El módulo está conectada?
	+ Quizá no la has conectado
	+ Quizá te equivocaste de pines
	+ Quizá los puertos de tu ESP32 están quemados, no sirven (Prueba con puertos alternativos)
	+ Quizá tu módulo no funciona

# Componentes
+ Algún módulo: Nrf24l01|E01-ML01DP5|E01 2G4M27D
	+ Puede servir con uno o dos
+ ESP32 

# Instrucciones de uso
1. Conecta tu dispositivo
2. Compila y carga el código en el ESP32
3. A través del "Serial Monitor (115200)" podrás ver si existen errores 
    + Prueba al menos dos veces reiniciando el dispositivo

# Conexiones
<img src="https://raw.githubusercontent.com/elcaza/nRF24L01_tester/refs/heads/main/images/connections.png">
