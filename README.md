# Sem-Traductores-2-D02-2022A
2/2/2022
Coronel Gonzalez Roberto Manuel 214771077
Mini analizador Sintactico.

Este proyecto fue desarollado usado el lenguaje de programacion c++ y el compilador Qt.

Este es el reporte de la segunda estapa de mi proyecto (compilador). Esta segunda etapa consta en la implementacion de dos ejemplos de tablas de gramaticas para la implementacion del analisis sintacticos en dos ejemplos. Los ejmplos a analizar son hola+mundo$ y a+b+c+d+e+f$ cada uno con su tabla de gramatica diferente. Fue necesaria la implementacion de una pila para llevar acabo el avance del analisis sintactico(la pila se inicializa con un 0).

Tabla 1 con gramatica E -> + d2,0,0,1, 0,0,r0,0, 0,d3,0,0, d4,0,0,0, 0,0,r1,0

Tabla 2 con gramatica r1 E -> + E | y r2 E ->e d2,0,0,1, 0,0,r0,0, 0,d3,r2,0, d2,0,0,4, 0,0,r1,0

En esta etapa agregue dos pushbuttons a mi interfaz uno para cada ejercicio.

Las tablas de gramaticas contienen desplazamientos,reglas y 0's. Cuando se encuentra un desplazamiento se agrega el elemento analizado y el desplazamiento a la pila. Cuando se encuentra una regla se libera el espacio correspondiente en la pila y se agrega una E, inmediatamente se vuelve a checar la tabla con los dos ultimos valores de la pila para agregar un nuevo elemento a la pila.Se obtiene un error de gramatica cuando se ob tiene un 0 en la tabla. El objetivo del analisis sintactico es analizar los simbolos obtenidos a base de la tabla de gramatica hasta encontrar un error o una regla r0 lo cual indica que la gramatica es correcta.

