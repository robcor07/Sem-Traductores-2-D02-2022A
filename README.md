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

Interfaz actualizada con dos botones adicionales para los 2 ejercicios

![image](https://user-images.githubusercontent.com/88813815/153123830-66126a9f-c60e-421f-84b1-ef7a616c5234.png)

Ejercicio 1 Hola + Mundo

![image](https://user-images.githubusercontent.com/88813815/153123981-45a7ae37-6ed4-4fbf-bef8-529a107c8059.png)

![image](https://user-images.githubusercontent.com/88813815/153124022-530e4aa0-c034-428b-99b4-85b22613b84b.png)


Ejercicio 2 a+b+c+d+e+f

![image](https://user-images.githubusercontent.com/88813815/153124082-ff5539ed-c802-4b3c-98c9-684b5a3410c5.png)
![image](https://user-images.githubusercontent.com/88813815/153124270-abc7b3b0-0829-43b1-a390-389eda41a1f6.png)
![image](https://user-images.githubusercontent.com/88813815/153124347-6b0c8352-73d9-4832-a7f1-e483cd519b5d.png)
![image](https://user-images.githubusercontent.com/88813815/153124414-19c1f2a8-8807-4d8b-a731-5eb1a4cac649.png)
![image](https://user-images.githubusercontent.com/88813815/153124449-bc4a8bab-7e17-464b-9fa6-b653379645a5.png)





