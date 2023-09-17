# Flat Shading

https://github.com/adrianRFlores/SR2_flatShading/assets/84111818/a4381c5d-f6f3-43fb-8e96-1ea29a4e7dd1

# Controles
## Cámara
Space -> y+<br />
Left Control -> y-<br />
W -> z-<br />
S -> z+<br />
A -> x-<br />
D -> x+<br />
R -> FOV+<br />
F -> FOV-
## Luz
UP -> y+<br />
DOWN -> y-<br />
LEFT -> x-<br />
RIGHT -> x+<br />
. -> z-<br />
, -> z+

# Compilar en Windows
Utilizar MinGW con ``mingw32-make.exe`` dentro del directorio del Makefile. SDL y GLM vienen empacados dentro de la carpeta src.
``mingw32-pthreads-w32`` debe estar instalado dentro de MinGW para poder utilizar threading.
