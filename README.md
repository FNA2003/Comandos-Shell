# Comandos Shell
 Este programa para entornos __unix__, toma un comando de entrada junto a parámetros asociados a este y lo ejecuta en un proceso __pesado__ hijo, desde el padre, mostrando por salida estándar su resultado cada 255 caracteres.... Los comandos van desde los definidos en PATH hasta programas locales del directorio.

<sup>**Nota:** Este repositorio es parte de un conjunto de soluciones a problemas típicos presentes en la programación de 'bajo nivel' en C.</sup>

## Uso
Compilado:
```
    gcc ejecutarArgumentos.c -o ejecutarArgumentos 
```
Ejecución:
```
    ./ejecutarArgumentos <comando> [argumentos...]
```
Ejemplo de uso:
```
~/$ ./ejecutarArgumentos tree .
Padre lee de [10402]: .
├── ejecutarArgumentos
├── ejecutarArgumentos.c
├── shell
│   ├── common.c
│   ├── compilador.sh
│   ├── main.c
│   ├── pseudoLexer.c
│   ├── pseudoParser.c
│   └── shelib.h

Padre lee de [10402]: ├── sincronizacionABAC
│   ├── hilos.c
│   └── procesos.c
├── sincronizacion_padre_hijos.c
└── sumar_retorno_hijos.c

3 directories, 12 files
```
