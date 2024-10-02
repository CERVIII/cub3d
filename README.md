# cub3D - Mi primer RayCaster con miniLibX

Este es un proyecto de la escuela 42 en el que se implementa un RayCaster utilizando la biblioteca miniLibX. El objetivo es crear un juego en 3D que simule un laberinto y permita al jugador moverse y explorar el entorno.

## Limitaciones

- El proyecto debe utilizar la biblioteca miniLibX, ya sea la versión disponible en el sistema operativo o la versión obtenida de las fuentes.
- La gestión de la ventana debe ser fluida, permitiendo cambiar a otras ventanas y minimizarla.
- Se deben mostrar diferentes texturas de pared dependiendo de la orientación de la pared (Norte, Sur, Este, Oeste).
- El programa debe permitir establecer colores diferentes para el piso y el techo.
- El programa debe mostrar la imagen en una ventana y cumplir con las siguientes reglas:
	- Las flechas izquierda y derecha del teclado deben permitir al jugador mirar hacia la izquierda y hacia la derecha en el laberinto.
	- Las teclas W, A, S y D deben permitir al jugador moverse a través del laberinto.
	- Presionar ESC debe cerrar la ventana y salir del programa de manera limpia.
	- Presionar la cruz roja en el marco de la ventana debe cerrar la ventana y salir del programa de manera limpia.
	- Se recomienda el uso de imágenes de la biblioteca miniLibX.

## Descripción del archivo de escena

El programa debe tomar como primer argumento un archivo de descripción de escena con la extensión .cub. El archivo de escena debe seguir las siguientes reglas:

- El mapa debe estar compuesto por solo 6 caracteres posibles: 0 para un espacio vacío, 1 para un muro, y N, S, E o W para la posición inicial del jugador y la orientación.
- El mapa debe estar cerrado/rodeado por paredes, de lo contrario el programa debe devolver un error.
- Cada tipo de elemento puede estar separado por una o más líneas vacías.
- Cada tipo de elemento puede establecerse en cualquier orden en el archivo, excepto para el mapa que siempre debe ser el último.
- Cada tipo de información de un elemento puede separarse por uno o más espacios.
- El mapa debe analizarse tal y como aparece en el archivo, los espacios son una parte válida del mapa y depende del programador manejarlos. El programa debe ser capaz de analizar cualquier tipo de mapa, siempre que respete las reglas establecidas.

A continuación se muestra un ejemplo de un archivo de escena válido:

```
NO ./ruta_a_la_textura_del_norte
SO ./ruta_hacia_la_textura_sur
WE ./ruta_al_oeste_textura
EA ./ruta_al_este_textura
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
```

## Compilación y ejecución

Para compilar el programa, ejecuta el siguiente comando:

```
make
```

Esto generará el ejecutable `cub3D`. Para ejecutar el programa con un archivo de escena, utiliza el siguiente comando:

```
./cub3D archivo.cub
```

¡Diviértete explorando el laberinto en 3D!

