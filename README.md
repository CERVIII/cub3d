Las limitaciones son las siguientes:
- Debe utilizar el miniLibX. O bien la versión que está disponible en el sistema operativo
o a partir de sus fuentes. Si elige trabajar con las fuentes, tendrá que
las mismas reglas para su libft que las escritas más arriba en la parte Instrucciones comunes.
Instrucciones.
- La gestión de su ventana debe seguir siendo fluida: cambiar a otra ventana, minimizar, etc.
- Mostrar diferentes texturas de pared (la elección es suya) que varían en función de que
según la orientación de la pared (Norte, Sur, Este, Oeste).
6
cub3D Mi primer RayCaster con miniLibX
- Tu programa debe ser capaz de establecer los colores del piso y del techo a dos diferentes.
- El programa muestra la imagen en una ventana y respeta las siguientes reglas:
◦ Las flechas izquierda y derecha del teclado deben permitir mirar a izquierda y
derecha en el laberinto.
◦ Las teclas W, A, S y D deben permitir mover el punto de vista a través de
el laberinto.
◦ Pulsar ESC debe cerrar la ventana y salir del programa limpiamente.
◦ Pulsar sobre la cruz roja del marco de la ventana debe cerrar la ventana y
salir del programa limpiamente.
◦ Se recomienda encarecidamente el uso de imágenes del minilibX.
- Su programa debe tomar como primer argumento un archivo de descripción de escena con la extensión .cub
.
◦ El mapa debe estar compuesto por sólo 6 caracteres posibles: 0 para un espacio vacío,
1 para un muro, y N,S,E o W para la posición inicial del jugador y la
orientación.
Este es un mapa válido simple:

111111
100101
101001
1100N1
111111

El mapa debe estar cerrado/rodeado por paredes, si no el programa debe devolver
un error.
◦ Excepto para el contenido del mapa, cada tipo de elemento puede estar separado por una o
más línea(s) vacía(s).
◦ Excepto el contenido del mapa, que siempre tiene que ser el último, cada tipo de
elemento puede establecerse en cualquier orden en el archivo.
◦ Excepto para el mapa, cada tipo de información de un elemento puede separarse
por uno o más espacio(s).
◦ El mapa debe analizarse tal y como aparece en el archivo. Los espacios son una parte válida del
son una parte válida del mapa y depende de usted manejarlos. Usted debe ser capaz de analizar cualquier tipo de mapa,
siempre que respete las reglas del mapa.
7
cub3D Mi primer RayCaster con miniLibX
◦ Cada elemento (excepto el mapa) la primera información es el identificador de tipo (compuesto por uno o dos carácter(es)), seguido de toda la información específica para cada
objeto en un orden estricto como :
∗ Textura del norte:
NO ./ruta_a_la_textura_del_norte
- identificador: NO
- ruta de acceso a la textura norte
∗ Textura sur:
SO ./ruta_hacia_la_textura_sur
- identificador: SO
- ruta de acceso a la textura sur
∗ Textura oeste:
WE ./ruta_al_oeste_textura
- identificador: WE
- camino hacia la textura oeste
∗ Textura este:
EA ./ruta_al_este_textura
- identificador: EA
- camino hacia la textura este
∗ Color del suelo:
F 220,100,0
- identificador: F
- Colores R,G,B en el rango [0,255] 0, 255, 255

◦ Ejemplo de la parte obligatoria con una escena .cub minimalista:
NO ./ruta_al_norte_textura
SO ./ruta_hacia_la_textura_sur
WE ./camino_al_texto_oeste
EA ./camino_al_texto_este
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
◦ Si se encuentra alguna configuración errónea de cualquier tipo en el archivo, el programa
debe salir correctamente y devolver «Error\n» seguido de un mensaje de error explícito
de su elección.