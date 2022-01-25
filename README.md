# Sem-Traductores-2-D02-2022A
1/24/2022
Coronel Gonzalez Roberto Manuel 214771077

Etapa del proyecto analizador léxico completo.

Este proyecto fue desarollado usado el lenguaje de programacion c++ y el compilador Qt.

Este es el reporte de la primera estapa de mi proyecto (compilador). Esta primera etapa corresponde a un analizador lexico el cual recibe simbolos los cuales debe analizar e identificar correctamente a base de criterios previamente establecidos. En total son 24 diferentes tipos de simbolos los que mi analizador lexico debe identificar y a la vez es necesario asignarle su numero de tipo correspondiente (del 0 al 23). Este programa inicia con la obtencion de varios simbolos a analizar y se analiza character a character usuando un automata el cual identifica el tipo de simbolo y una vez que todos los simbolos son analizados se muestran los resultados obtenidos del analisis.

Símbolo Tipo identificador 0 entero 1 real 2 cadena 3 tipo 4 int,float,void opSuma 5 +,- opMul 6 *,/ opRelac 7 <,<=,>,>= opOr 8 || opAnd 9 && opNot 10 ! opIgualdad 11 ==, != ; 12 , 13 ( 14 ) 15 { 16 } 17 = 18 if 19 while 20 return 21 else 22 $ 23

Para obtener una mejor interaccion con mi proyecto decidi agregar una interfaz grafica sencilla que en el transcurso de la elaboracion de mi proyecto tendra diferentes mejoras. Por el momento mi interfaz cuenta con una ventana que tiene un Textedit para recibir entradas de simbolos, tiene un PushButton para activar el analisis de los simbolos, y por ultimo tiene un Tablewidget donde se muestran los simbolos de entrada ya analizados.

Interfaz grafica

![image](https://user-images.githubusercontent.com/88813815/150914658-35620004-bdee-4e64-ab4e-908e437137ae.png)

Validando simbolos

![image](https://user-images.githubusercontent.com/88813815/150914831-4152cfd0-fe17-4c90-ae56-15a390b3f52f.png)
![image](https://user-images.githubusercontent.com/88813815/150914884-20b4f11e-c898-44e8-9df1-6b68c5ac3125.png)
![image](https://user-images.githubusercontent.com/88813815/150914930-b0338bac-ae4f-449e-ae29-b58225144ea3.png)

Otro ejemplo

![image](https://user-images.githubusercontent.com/88813815/150915423-bce057ae-dd4e-4456-abbe-d47649797622.png)
![image](https://user-images.githubusercontent.com/88813815/150915443-f2f55fef-2405-455e-bbe1-2ada70b9972e.png)
![image](https://user-images.githubusercontent.com/88813815/150915477-3f3d2c89-6aa5-4aca-a446-677401ba7e65.png)
![image](https://user-images.githubusercontent.com/88813815/150915520-d107753f-25f2-40cb-820a-3364a7e68fcb.png)
![image](https://user-images.githubusercontent.com/88813815/150915570-49e605a5-452c-4af3-b5ea-049c76d27d76.png)
![image](https://user-images.githubusercontent.com/88813815/150915606-5ed0df89-7459-47f2-9869-d00f813ed144.png)







