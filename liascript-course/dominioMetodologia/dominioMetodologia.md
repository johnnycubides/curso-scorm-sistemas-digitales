# Dominio descriptivo y metodología de diseño

## Dominio descriptivo

VHDL soporta varios estilos para la descripción de diseños. Estos, denominados dominios descriptivos, son distintos en cuanto al nivel de abstracción que manejan, y son: 

1. Dominio de Comportamiento.

El dominio de Comportamiento o algorítmico es el nivel de abstracción más elevado que soporta VHDL. Cuando se describe usando este nivel de abstracción, el circuito se modela en términos de su funcionalidad, sin preocuparse de los componentes internos del mismo o de qué forma física se llevará a cabo esta funcionalidad.

2. Dominio de Flujo de Datos (RTL).

El dominio de Flujo de Datos describe el circuito en términos de cómo los datos se mueven a través del sistema y la forma en que la información fluye a través de los registros del circuito. El diseñador toma en cuenta las distintas señales que interactúan en un circuito, así como su comportamiento por medio de ecuaciones lógicas y sentencias de asignación. Este modelo es comúnmente llamado Transferencia Lógica de Registros (RTL, Register Transfer Logic). Es un nivel intermedio que permite simplificar la lógica combinacional, mientras que las partes más importantes del circuito, los registros, son especificados de acuerdo a la función a modelar.

3. Dominio Físico.

El dominio Físico, o nivel lógico, se usa para describir circuitos en términos de sus componentes. Puede ser usado para crear una descripción de bajo nivel, como la descripción a nivel de transistor, o una descripción a nivel de diagrama de bloques. El diseñador emplea los recursos que el lenguaje proporciona para describir las interconexiones entre los distintos componentes de un circuito. 

* bibing: http://bibing.us.es/proyectos/abreproy/12112/fichero/Documento_por_capitulos%252F2_Cap%C3%ADtulo_2.pdf

Como podemos observar, cada uno de los niveles de abstracción se ocupa de unos determinados valores, que posteriormente las herramientas de síntesis y optimización se encargarán de ajustar y optimizar, usando algoritmos de iteración sobre cada uno de los elementos. Como se observa en la siguiente figura:

dominio-descriptivo.png

![Dominio descriptivo](img/dominio-descriptivo.png)


## Metodologías de diseño

Introducción...

Algunas metodologías de diseño de software como metodología agil o Modularidad

### Metodología Top-Down


