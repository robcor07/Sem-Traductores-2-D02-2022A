# Sem-Traductores-2-D02-2022A
Proyecto Final
22/05/22 Coronel Gonzalez Roberto Manuel 214771077
Esta es la ultima etapa de mi compilador consiste en un analizador lexico, gramatica de compilador integrada, analizador sintactico, arbol sintactico, analizador semantico y generacion de codigo de ensamblador.
Para esta ultima etapa genero un archivo .asm para posteriormente ejecutarlo en en programa de ensamblador esto con el proposito de ejecutar el codigo que se analizo.

Este proyecto fue creado con c++ y qt.

Actualmente mi programa es capaz de generar sumas y restas de enteros.

Ejemplo de suma 


![image](https://user-images.githubusercontent.com/88813815/169720144-b2aa1fd3-9431-47d8-826c-7eb5d9b0df79.png)

![image](https://user-images.githubusercontent.com/88813815/169720154-08429881-2ffa-42ed-b9d6-2ec217da21ac.png)


Se crea un archivo llamado Suma.asm con el codigo necesario para generar la suma en esamblador

![image](https://user-images.githubusercontent.com/88813815/169720249-16b5cce1-62ee-423b-9e8b-c86c4c6aded7.png)


Se carga 11 en ax

![image](https://user-images.githubusercontent.com/88813815/169720275-4daaf04f-89c6-44ae-9975-d00092ec3bfc.png)


Se carga 4 en bx

![image](https://user-images.githubusercontent.com/88813815/169720294-2244ab59-0e59-4e92-9a7e-d2a4eccf9a52.png)


Se suma bx con ax y se guarda en cx

![image](https://user-images.githubusercontent.com/88813815/169720339-a8a60cb2-8a4b-459a-b916-e6657fea6805.png)


Ejemplo de resta

![image](https://user-images.githubusercontent.com/88813815/169720366-30a15333-717a-46c9-bb94-616f5d88d95c.png)

![image](https://user-images.githubusercontent.com/88813815/169720371-4c7b37c2-dc5d-4bf4-98b8-e66a9707f169.png)


Genera un archivo llamado Resta.asm con las instrucciones necesarias para hacer una resta en esamblador

![image](https://user-images.githubusercontent.com/88813815/169720400-883e573f-2355-408e-81af-98fca5a643b2.png)

![image](https://user-images.githubusercontent.com/88813815/169720422-299ccea4-ba4c-452f-8909-5b7e82690274.png)


Se carga un 17 en ax

![image](https://user-images.githubusercontent.com/88813815/169720445-9540771b-239d-42cb-8bc6-73c447c7ad7d.png)


Se carga un 12 en bx

![image](https://user-images.githubusercontent.com/88813815/169720459-afc49b52-c138-4abe-b2b5-a1b2330ce492.png)


Se hace la resta bx a ax y se guarda en cx

![image](https://user-images.githubusercontent.com/88813815/169720474-acb5f49a-0d15-438a-ad0f-87b551c0c9cb.png)































