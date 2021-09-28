<!--

author: Carlos Camargo, Johnny Cubides

comment: Sesión

-->

# Introducción de Sistemas Digitales

Vídeo sobre industria digital CC-by-sa

## Etapas de fabricación

## Herramientas de Diseño

### Herramientas de desarrollo de software

#### Compiladores

![GCC](img/gcc.jpg)

El GNU Compiler Collection normalmente llamado GCC, es un grupo de compiladores de lenguajes de programación producido por el proyecto GNU. Es el compilador estándar para el software libre, de los sistemas operativos basados en Unix y algunos propietarios como Mac OS de Apple. Soporta los lenguajes ADA, C, C++, Fortran, Java, Objective-C, Objective-C++ para las arquitecturas Alpha, ARM, Atmel AVR, Blackfin, H8/300, System/370, System/390, IA-32 (x86), x86-64, IA-64 i.e. the ”Itanium”, Motorola 68000, Motorola 88000, MIPS, PA-RISC, PDP-11, PowerPC, SuperH, SPARC, VAX, Renesas R8C/M16C/M32C y MorphoSys. Gracias a esto puede considerarse como una herramienta universal para el desarrollo de sistemas embebidos, el código escrito en una plataforma (en un lenguaje de alto nivel) puede ser implementado en otra sin mayores cambios, esto elimina la dependencia entre el código fuente y el procesador (re-utilización de código), lo que no es posible cuando se utiliza el lenguaje ensamblador.

#### Depuradores

![GDB](img/gdb.jpg)

El depurador oficial de GNU (GDB) al igual que GCC, soporta múltiples lenguajes y plataformas; permite monitorear y modificar las variables internas del programa y hacer llamado a funciones de forma independiente a la ejecución normal del mismo. Además, permite establecer sesiones remotas utilizando el puerto serie o TCP/IP. Aunque GDB es una aplicación que se ejecuta en consola de comandos, se han desarrollado varios front-ends como DDD o GDB/Insight.

#### Manipulación de código Objeto

#### Librerías

Es necesario contar con las librerías standard de C: stdio, stdlib, math, etc; las más utilizadas en sistemas embebidos son:

**glibc** Es la librería C oficial del proyecto GNU; el principal inconveniente al trabajar con esta librería en sistemas embebidos es que genera ejecutables de mayor tamaño que los generados a partir de otras librerías, lo cual no la hace muy atractiva para este tipo de aplicaciones.

**uClibc** Es una librería diseñada especialmente para sistemas embebidos, es mucho más pequeña que **glibc**. 

**newlib** Al igual que **uClibc**, está diseñada para sistemas embebidos. El típico “Hello, world!” ocupa menos de 30k en un entorno basado en newlib, mientras que en uno basado en glibc, puede ocupar 380k.

**diet libc** Es una versión de libc optimizada en tama˜ no, puede ser utilizada para crear ejecutables estáticamente enlazados para Linux en plataformas alpha, arm, hppa, ia64, i386, mips, s390, sparc, sparc64, ppc y x86 64.

### Herramientas de CAD

Para la elaboración de las cajas que contendrán las tarjetas electrónicas y servirán de soporte fı́sico a los dispositivos electrónicos, se utilizará la herramienta QCAD disponible para los sistemas operativos más utilizados; con esta aplicación se puede generar la forma de la placa de circuito impreso con los orificios necesarios para ajustarse a la caja y a la aplicación; este archivo puede ser exportado a la herramienta KICAD lo que facilita la colocación de componentes.

#### Kicad

Este tipo de herramientas han sido las más difı́ciles de conseguir ya que al comienzo de este estudio no existı́a una herramienta que permitiera realizar de forma fácil la elaboración del esquemático, asignación de footprints, distribución y localización de componentes en el layout, ruteo de las señales, y verificación de reglas de diseño tanto en el esquemático como en el layout. En la actualidad, el proyecto KICAD ha alcanzado un nivel adecuado para ser utilizado en el desarrollo de aplicaciones comercializables y fue utilizado en todos los proyectos académicos durante la aplicación del presente plan de estudios; está formado por 5 aplicaciones: el editor de esquemáticos Eeschema; el editor de circuitos impresos Pcbnew; el visor de archivos gerber Gerbview; la utilidad para asignar footprints Cvpcb y el manejador de proyectos Kicad.

![KiCad](img/kicad.png)

#### QCAD

QCAD es una aplicación informática de diseño asistido por computadora para diseño 2D. Funciona en los sistemas operativos Windows, Mac OS X y Linux. QCAD tiene una licencia de software GNU General Public License, concretamente, el código fuente de las versiones 3.1 y posteriores tienen licencia GPLv3.

#### OpenSCAD

OpenSCAD es una aplicación libre para crear objetos sólidos de CAD. No es un editor interactivo sino un compilador 3D basado en un lenguaje de descripción textual. Un documento de OpenSCAD especifica primitivas geométricas y define como son modificadas y manipuladas para reproducir un modelo 3D. Wikipedia

![OpenSCAD](img/openscad.png)

### Análisis y simulación de circuitos

#### QUCS

### Simulación y verificación digital

#### Icarus

#### GTKWAVE

### Herramientas de Síntesis

#### LiteX

### Documentación y manejo de proyectos

#### GIT

#### Wiki
