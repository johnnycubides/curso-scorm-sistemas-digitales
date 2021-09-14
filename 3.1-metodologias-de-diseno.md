# Metodologías de diseño

El diseño de software es un proceso para conceptualizar los requisitos de software en la implementación de software. El diseño de software toma los requisitos del usuario como 
desafíos y trata de encontrar una solución óptima. Mientras se conceptualiza el software, se elabora un plan para encontrar el mejor diseño posible para implementar la solución 
deseada.

## Top-down

El diseño de arriba hacia abajo toma todo el sistema de software como una entidad y luego lo descompone para lograr más de un subsistema o componente basado en algunas 
características. Cada subsistema o componente se trata como un sistema y se descompone más adelante. Este proceso se mantiene en ejecución hasta que se alcanza el nivel más bajo 
del sistema en la jerarquía descendente.

## Modularidad

La modularidad es la capacidad que tiene un sistema de ser estudiado, visto o entendido como la unión de varias partes que interactúan entre sí y que trabajan para alcanzar un 
objetivo común, realizando cada una de ellas una tarea necesaria para la consecución de dicho objetivo. Cada una de esas partes en que se encuentre dividido el sistema recibe el 
nombre de módulo. Idealmente un módulo debe poder cumplir las condiciones de caja negra, es decir, ser independiente del resto de los módulos y comunicarse con ellos (con todos o 
sólo con una parte) a través de unas entradas y salidas bien definidas.

Ingeniería de software es la producción de software con calidad. Calidad implica dos tipos de factores: internos y externos. Los factores externos son cualidades que son 
"detectadas" por los usuarios, por ejemplo: velocidad y facilidad de uso. Los factores internos son cualidades perceptibles por profesionales del área de la computación, por 
ejemplo: modularidad y legibilidad.

Factores externos:

1. Correctitud: Capacidad para realizar con exactitud las tareas definidas en las especificaciones.
2. Robustez: Capacidad de reaccionar apropiadamente ante condiciones excepcionales.
3. Extensibilidad: Facilidad de adaptar los productos de software a los cambios en la especificación.
4. Reutilización: Capacidad de los elementos de software de servir para la construcción de muchas aplicaciones diferentes.
5. Compatibilidad: Facilidad de combinar unos elementos de software con otros.
6. Eficiencia: Capacidad para exigir la menor cantidad posible de recursos (tiempo de procesador, espacio de memoria, ancho de banda, etc.).
7. Portabilidad: Facilidad de transferir los productos de software a diferentes entornos de hardware y software.
8. Facilidad de uso: Cubre la facilidad de instalación, de operación y de supervisión.
9. Funcionalidad: Conjunto de posibilidades que proporciona un sistema.

## Arquitectura jerarquica

La arquitectura jerarquica considera todo el sistema como una estructura jerarquica, en la que el sistema de software se divide en modulos o sub -sistemas logicos en diferentes 
niveles de la jerarquia. Este enfoque se utiliza normalmente en el diseno de software de sistema, como protocolos de red y sistemas operativos.

En el diseno de la jerarquia de software del sistema, un subsistema de bajo nivel proporciona servicios a sus subsistemas adyacentes de nivel superior, que invocan los metodos 
de nivel inferior. La capa inferior proporciona una funcionalidad mas especifica, como servicios de E / S, transacciones, programacion, servicios de seguridad, etc. La capa 
intermedia proporciona funciones mas dependientes del dominio, como la logica empresarial y los servicios basicos de procesamiento. Y la capa superior proporciona 
funcionalidades mas abstracto en forma de interfaces de usuario como GUI, funciones de programacion de shell, etc.

Los estilos arquitectonicos jerarquicos son:
- Subrutina principal
- Maestro-esclavo
- Máquina virtual

### Subrutina principal

El proposito de este estilo es reutilizar los modulos y desarrollar libremente modulos o subrutinas individuales . En este estilo, un sistema de software se divide en subrutinas
utilizando un refinamiento de arriba hacia abajo de acuerdo con la funcionalidad deseada del sistema.

**Ventajas**
- Facil descomposicion del sistema de acuerdo con el refinamiento de la jerarquia.
- uede utilizarse en un subsistema de diseno orientado a objetos.

**Desventajas**
- Vulnerable porque contiene data compartidos globalmente.
- El acoplamiento estrecho puede provocar que cambien mas efectos domino.

### Maestro-Esclavo

Este enfoque aplica el principio de "divide y venceras" y apoya el calculo de fallas y el calculo de precision. Es una modificacion de la arquitectura de la rutina principal 
que asegura la confiabilidad del sistema y la tolerancia a fallas.

**Ventajas**
- Calculo escalabilidad mas rapida y sencilla.
- Proporciona robustez porque los esclavos se pueden duplicar.
- El esclavo se puede implementar de manera diferente para minimizar los errores semanticos.

**Desventajas**
- Costos de comunicacion.
- No todos los problemas se pueden.
- Problema de implementacion y portabilidad dificil.

### Arquitectura de la maquina virtual

La arquitectura de la maquina virtual reclama ciertas funcionalidades, que no son nativas del hardware y / o del software en el que se implementa. Una maquina virtual se basa 
en un sistema existente y proporciona una abstraccion virtual, un conjunto de atributos y operaciones.

**Ventajas**
- Portabilidad e independencia de plataforma de la maquina.
- Simplicidad en el desarrollo de software.
- Ofrece flexibilidad a traves de la capacidad de interrumpir y consultar el programa.
- Simulacion de un modelo operativo ante desastres.
- Introduzca cambios en tiempo de ejecucion.

**Desventajas**
- Ejecucion lenta del interprete debido a la naturaleza del interprete.
- Existe un costo de rendimiento debido al calculo adicional involucrado.
