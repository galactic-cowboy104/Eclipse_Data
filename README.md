# Repositorio: Medición de Datos de Sensores para el Eclipse del 8 de abril

Este repositorio contiene un proyecto de Arduino diseñado para medir datos ambientales utilizando varios sensores. El objetivo principal es recopilar información relevante durante el eclipse solar del 8 de abril para propósitos de investigación y observación.

## Requisitos

- Placa Arduino compatible.
- Sensores ML8511 y BMP180.
- Módulo DS1302 para el reloj en tiempo real.
- Pantalla LCD compatible con I2C.
- Tarjeta SD para almacenamiento de datos.
- IDE de Arduino instalado en su computadora.

## Contenido

- **Código de Arduino**: El archivo .ino contiene el código fuente del programa de Arduino. Este programa se encarga de leer los datos de los sensores ML8511 y BMP180, obtener la hora del módulo DS1302, y mostrar los datos en una pantalla LCD mientras los guarda en una tarjeta SD en formato CSV.

- **Diagrama de Conexiones**: Se incluye una imagen que muestra el diagrama de conexiones físicas necesario para conectar los sensores y módulos al Arduino de manera correcta.

## Instrucciones de Uso

### Conexiones Físicas:

1. Siga el diagrama de conexiones físicas proporcionado para conectar los sensores ML8511 y BMP180, así como el módulo DS1302 y la pantalla LCD al Arduino.

### Configuración y Ejecución del Programa:

1. Conecte su Arduino a la computadora y abra el archivo .ino en el IDE de Arduino.
2. Verifique que las librerías necesarias estén instaladas y cargue el programa en la placa Arduino.
3. Alimente el circuito y observe la pantalla LCD para visualizar los datos ambientales en tiempo real.

### Almacenamiento y Análisis de Datos:

1. Los datos medidos se guardarán automáticamente en un archivo CSV en la tarjeta SD.
2. Utilice un lector de tarjetas SD para acceder al archivo CSV y analizar los datos utilizando herramientas de hojas de cálculo como Microsoft Excel.

¡Disfrute de la experiencia de observar el eclipse solar y recolectar datos ambientales con este proyecto de Arduino!