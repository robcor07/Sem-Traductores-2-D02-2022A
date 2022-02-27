# Sem-Traductores-2-D02-2022A
2/27/2022 Coronel Gonzalez Roberto Manuel 214771077

Etapa del proyecto Gramatica del compilador.

Este proyecto fue desarollado usado el lenguaje de programacion c++ y el compilador Qt.

Este es el reporte de la estapa de la gramatica del compilador. Para esta etapa fue necesario cargar la tabla de gramatica en el mi programa. Para esto fue necesario agregar un archivo llamado gramatica.lr este contiene la gramatica necesaria para mi compilador. Fue necesario llevar acabo una lectura del archivo para llenar un arreglo bidimencional table[95][46] el cual cumplira el funcionamiento de mi tabla de analisis. Adicionalmente cree dos tablas adicionales la primera es un vector table2[46] esta almacena todos los lexemas que conforman todas las filas de mi tabla esto me es util para identificar la posicion de busqueda de cada lexema. La segunda es un arreglo bidimensional rules[52][2] este me sirve para guardar todas las reglas que seran necesarias en el primer espacio guardo los pops que se necesitan hacer y en el segundo espacio se guarda la entrada a ala pila que genera esa regla. Una vez aregado esto solo fue necesario modificar un poco mi algoritmo sintactico para hacer el analisis con la nueva gramatica. No hubo cambios nuevos a la interfaz de mi programa.




![Example](https://user-images.githubusercontent.com/88813815/145701460-3e80f530-f20c-44c4-a404-66f6e2869af0.png)
![Example2](https://user-images.githubusercontent.com/88813815/145701594-5d560378-d2ed-4253-9b6a-911fc7d0660e.png)
![example3](https://user-images.githubusercontent.com/88813815/145701597-56927e68-0f46-4cdc-9729-da5adb4bb6e1.png)
