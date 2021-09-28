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


dominio-descriptivo.png

![Dominio descriptivo](img/dominio-descriptivo.png)

Como se puede observar, cada uno de los niveles de abstracción se ocupa de unos determinados valores, que posteriormente las herramientas de síntesis y optimización se encargarán de ajustar y optimizar, usando algoritmos de iteración sobre cada uno de los elementos. 

![Niveles abstracción](img/niveles-abstraccion.png)

Los niveles de abstracción, se describen por medio de la siguiente tabla:

![Tabla niveles abstracción](img/tabla-niveles.png)

## Metodologías de diseño

El diseño de software es un proceso para conceptualizar los requisitos de software en la implementación de software. El diseño de software toma los requisitos del usuario como desafíos y trata de encontrar una solución óptima. Mientras se conceptualiza el software, se elabora un plan para encontrar el mejor diseño posible para implementar la solución deseada.

**1. Metodología ágil**

El desarrollo ágil de software envuelve un enfoque para la toma de decisiones en los proyectos de software, que se refiere a métodos de ingeniería del software basados en el desarrollo iterativo e incremental, donde los requisitos y soluciones evolucionan con el tiempo según la necesidad del proyecto.

* Wikipedia: https://es.wikipedia.org/wiki/Desarrollo_%C3%A1gil_de_software

![Metodología ágil](img/agile.png)

* Fuente: https://excelencemanagement.wordpress.com/2021/03/01/metodologias-agiles-cuestion-de-principios-y-de-valores/

**2. Modularidad**

La modularidad es la capacidad que tiene un sistema de ser estudiado, visto o entendido como la unión de varias partes que interactúan entre sí y que trabajan para alcanzar un objetivo común, realizando cada una de ellas una tarea necesaria para la consecución de dicho objetivo. Cada una de esas partes en que se encuentre dividido el sistema recibe el nombre de módulo. Idealmente un módulo debe poder cumplir las condiciones de caja negra, es decir, ser independiente del resto de los módulos y comunicarse con ellos (con todos o sólo con una parte) a través de unas entradas y salidas bien definidas.

* Fuente: https://www.fing.edu.uy/tecnoinf/maldonado/cursos/eda/material/teo/EDA-teorico2.pdf

![Modularidad](img/modularidad.jpg)

### Metodología Top-Down


