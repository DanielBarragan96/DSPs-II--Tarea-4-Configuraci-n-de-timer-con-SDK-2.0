# DSPs-II--Tarea-4-Configuraci-n-de-timer-con-SDK-2.0
#Daniel Barragán Alvarez IE702554

DSPs II
Usa el SDK en la K64 para hacer un programa que cumpla con los siguientes puntos:

Configurar un Timer (el que ustedes deseen: PIT, LPTMR, SysTick, RTC...) para que 
cada segundo cambie el estado del led RGB, de manera que se muestre la secuencia 
ROJO-VERDE-AZUL una y otra vez. El Timer debe estar configurado por interrupción.

Configurar el SW2 por interrupción para que la secuencia pare y el led se quede estático en el color en el que estaba al presionar el switch.

Configurar el SW3 por interrupción para que la secuencia cambie de sentido: si la secuencia era ROJO-VERDE-AZUL, después de presionar el switch ahora será AZUL-VERDE-ROJO. De la misma manera para cuando está en el estado AZUL-VERDE-ROJO, al presionar el switch la secuencia cambiará a ROJO-VERDE-AZUL.

Esta prohibido modificar registros directamente, todo debe ser a través del SDK.

Sube aquí un link a tu repositorio de github donde pueda ver tu solución. La calificación estará en base al último commit antes de la fecha de entrega. Si no hay ningún commit en el repositorio antes de la fecha de entrega la tarea no es válida.
