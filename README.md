# Sem-Traductores-2-D02-2022A
Analisis semantico
22/05/22 Coronel Gonzalez Roberto Manuel 214771077
Esta es la continuacion de mi proyecto del compilador en esta parte se aborda el analisis semantico del codigo analizado. Algo que me gustaria destacar es que para poder realizar el analisis semantico fue necesario generar un arbol sintactico donde se almacenan las definiciones de funciones, variables y expresiones las cuales son necesarias para hacer el analisis semantico.

Para poder crear correctamente mi arbol sintactico hice varias rondas de analisis de codigo en excel en esta rama anexo un archivo excel para demostrarlo ademas aqui dejo unas capturas del analisis sintactico y la generacion de mi arbol sintactico.

Analisis semantico prueba 1.1
![image](https://user-images.githubusercontent.com/88813815/169708932-19f14b98-bd1a-403e-839a-bb1591ac79a5.png)


Analisis semantico prueba 1.2
![image](https://user-images.githubusercontent.com/88813815/169708963-d73fd2e4-c402-4a60-a1e2-d2342adaa53d.png)


Generando arbol sintactico 1.1
![image](https://user-images.githubusercontent.com/88813815/169709028-d102bcd0-f27a-4a60-8958-190a4684098a.png)


Generando arbol sintactico 1.2
![image](https://user-images.githubusercontent.com/88813815/169709074-3542fee0-190b-4b4a-a55c-41eaa785468f.png)


Generando arbol sintactico 1.3
![image](https://user-images.githubusercontent.com/88813815/169709155-4f6625bd-2533-43e8-b318-0dff31ede15b.png)


Generando arbol sintactico  vista completa
![image](https://user-images.githubusercontent.com/88813815/169709207-6c151019-f0f8-472c-b37a-8f05034b84f5.png)


Ventana analizador
![image](https://user-images.githubusercontent.com/88813815/169709249-718ea89f-14a7-49f8-bcd6-a191a70ced98.png)


Impresion de arbol sintactico en consola 1.1
![image](https://user-images.githubusercontent.com/88813815/169709321-9ce7bc20-5624-4149-b212-5227b96bfd8d.png)

Impresion de arbol sintactico en consola 1.2
![image](https://user-images.githubusercontent.com/88813815/169709351-b03a3bb8-f1b0-458b-97f3-0465999242b5.png)


Una vez creado mi arbol sintactico ya me es posible recorrer y analizar el arbol para ir llenando mi tabla de simbolos para hacer el analisis semantico. En analisis semantico se busca identificar si las sentencias de expresiones son correctas analizando si las variables involucradas se encuentran dentro de la misma funcion y si comparten el mismo tipo de dato.

Analisis de arbol 
 
Aqui se busca DefFunc para definicion de funcion, se busca DefVar para definicion de variables y sentencia para asignacion de valores a variables

![image](https://user-images.githubusercontent.com/88813815/169709532-bbc5130f-39a3-4a03-9708-fb9a26bc8e77.png)

![image](https://user-images.githubusercontent.com/88813815/169709550-5ef15237-7ca8-43a0-ac5d-33bde5b0995f.png)

![image](https://user-images.githubusercontent.com/88813815/169709712-4b845fac-3d4e-49ac-be24-d45d450029a6.png)


Creacion de tabla de simbolos y analisis 

![image](https://user-images.githubusercontent.com/88813815/169709764-c87af90f-45b0-4c23-84ca-526c9cdb1ecf.png)


Ejemplo analisis semantico correcto

![image](https://user-images.githubusercontent.com/88813815/169709813-65189744-4e04-4218-a155-72c174bf7814.png)

![image](https://user-images.githubusercontent.com/88813815/169709833-40a75da6-a006-43ad-848c-4aca72fcb046.png)

![image](https://user-images.githubusercontent.com/88813815/169709850-288c72ef-abf0-4b86-9fcc-e9c7efef8289.png)


Ejemplo de analisis semantico con error (si bien el analisis sintactico es correcto semnaticamente es incorecto que variables de tipo int interactuen con flotantes)

![image](https://user-images.githubusercontent.com/88813815/169709912-bc18e391-8bd6-4c1a-a71c-6d8bf208f397.png)

![image](https://user-images.githubusercontent.com/88813815/169709931-d9e2bc86-a176-4592-b73b-9223e14b3b32.png)

![image](https://user-images.githubusercontent.com/88813815/169709937-371af432-b08c-4665-957d-f37990701682.png)

















