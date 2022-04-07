<!--

author: Carlos Camargo, Johnny Cubides

email: cicamargoba@unal.edu.co, jgcubidesc@unal.edu.co

comment: Material de apoyo para sistemas emebidos UNAL

version: 0.2.0

blue: true 

script: ./pdfobject.min.js
        ./pdfobject.js

-->

## Sistemas Embebidos UNAL

[Plan de estudios (CDIO) Sistemas Embebidos en pdf](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/camargo-docs/CDIO.pdf)

Proyecto
========

A continuación verá un esquema que representa las diferentes fases/tareas del desarrollo del un proyecto en el curso de sistemas embebidos:

![proyecto](./img/projectSE/cronograma.drawio.png)

¿Qué queremos hacer?
====================

En nuestro curso lo que deseamos hacer es un producto terminado,
que esté orientado a la solución de una situación real.

¿Qué se debe entregar?
======================

* **Sistema embebido electrónico**
* **Caja**
* **Documentación**
* **Brochure comercial**

Sobre el sistema embebido
=========================

![ejemplo de sistema embebido](./img/ejemplo-sistema-embebido.png) ![omega modular](./img/omega-modular.jpg)

El dispositivo deberá responder a los requerimientos funcionales y no funcionales
y además tener las siguientes características:

* Desarrollar una PCB a la medida de la necesidad; podrá desarrollar el sistema embebido completo o desarrollar una tarjeta hija para una tarjeta de desarrollo
* Para las tareas de software se puede hacer uso de *Zephyr OS* o *Micropython*; si desea usar Micropython deberá ser compilado a la medida de la necesidad
* El sistema debe permitir la comunicación con otros dispositivos para monitoreo o control por parte del usuario final (puede ser a través de un medio guiado o no, lo cual depende de la aplicación).

Sobre la caja
=============

![piccolo](./img/piccolo.jpg) ![estacion](./img/estacion.jpg)

En este caso se refiere a los aparatos encargados de realizar las tareas mecánicas, de protección,
estéticas, de experiencia de usuario, las cuales contienen sensores, actuadores y el sistema diseñado;
puede hacer uso de CAD para impresión 3D, corte láser, existen bibliotecas libres en Internet que
podrá descargar y ajustar a la necesidad.

Sobre la documentación
----------------------

Queremos documentar el proceso de desarrollo, para tal fin puede hacer uso de:

* git
* Wiki

En primer lugar GIT es un sistema de gestión de versiones para proyectos de cualquier tipo que
permite seguirle la pista a nuestro proyectos de manera colaborativa; puede hacer uso de gestores
de repositorios de proyectos como *gitlab*, *github*, *bitbucket* o cualquier otro que conozca.

Con respecto a la Wiki, en realidad puede ser en cualquier lugar siempre y cuando muestre el proceso
realizado del proyecto como también el producto terminado con algún demo; los gestores de repositorios
de proyectos anteriormente mencionados tienen la posibilidad de crear wikis asociadas al proyecto, pero
también puede hacer uso de un blog o crear páginas web staticas (gitlab y github tienen esa propiedad y por ahora es libre)

Sobre el brochure
=================

Queremos que piensen que este producto va a ser ofrecido a un público que lo pueda necesitar por tanto
muestre el producto de tal manera que se pueda reconocer sus características y particularidades.

Ejemplo de brochure:

![Brochure IFLAB](./img/brochure-iflab.png)

## Ideación

En esta face del proyecto queremos plantear lo que queremos hacer, como también las restricciones de funcionamiento y de alcance;
Para tal fin deseamos responder a los siguientes items:

* Descripción
* Requerimientos del cliente y alcance
* Requerimientos funcionales
* Experiencia de usuario

Requerimientos del cliente y alcance
====================================

Son los relacionados a aquello que el cliente quiere que suceda con su producto, los cuales permiten juzgar
sin que éste necesariamente sepa como debe suceder internamente, para este paso, puede crear diagrámas que den cuenta
de como interviene el **"artefacto"** en la necesidad del cliente, como el usuario interactua con el aparato considerando
aspectos estéticos y aquello que tiene un valor agregado (experiencia de usuario), como sugerencia **Liste todo aquello que
permita acotar el alcance del proyecto** para que identifique que partes de eso se pueden realizar en el tiempo disponible
en el curso y aquello que queda proyectado para una próxima iteración del desarrollo del proyecto en otro espacio-tiempo.

Cronograma
==========

El cronograma que desee diseñar para realizar su proyecto puede ser referenciado con el el diagrama de fases/tareas propuesto
en esta documentación en [este enlace](#Sistemas-Embebidos-UNAL)

## ¿Qué es un sistema embebido?

Antes de definir el sistema embebido, se invita o hacer una revisión de la siguiente presentación del que da una idea sobre los
[paradigmas de diseño de los SoC](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/otros/nuevos_paradigmas_de_disenio.pdf).

Realizada la ubicación de los paradigmas de diseño se puede aproximar a la definición de los sistemas digitales haciendo lectura del documento
[Implementación de la Metodologı́a de Transferencia Tecnológica Propuesta en el diseño de Sistemas Embebidos, paginas 1-5, 14-16](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/camargo-docs/Implementacion-metodologia-transferencia-tecnologica-SE.pdf).

También puede acompañar la anterior lectura con el siguiente
[resumen técnico sobre la metodologia de diseño de sistemas embebidos en las páginas 7-10 del PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/camargo-docs/metodologia-de-diseno-SE-camargo.pdf).

Metodología de diseño para el área de Sistemas Digitales
========================================================

Con las lecturas anteriormente recomendadas podrá analizar el siguiente gráfico que se observa en el documento de [CDIO](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/camargo-docs/CDIO.pdf) pagina xx
que explica como se relaciona los cursos de electrónica digital ofrecidos en la Universidad Nacional de Colombia; podrá ubicar en
él qué se implementa en el curso de Sistemas embebidos.

![Metodología de diseño para el área de Sistemas Digitales](./img/sistemas-embebidos/metodoliga-de-diseno-SE.png)

Los siguientes gráficos dan cuenta de los elementos claves en sistemas embebidos que son señalados en las lecturas anterioemente
recomendadas.

Flujo de diseño de un sistema embebebido
========================================

![Flujo de diseño de un sistema embebido](./img/sistemas-embebidos/flujo-de-diseno-de-un-SE.png)

Arquitectura de un Sistema Embebido
===================================

![Arquitectura de un sistema embebido](./img/sistemas-embebidos/arquitectura-de-un-SE.png)

Arquitectura de un sistema embebido comercial con memoria interna
=================================================================

![arquitectura de SE comercial con memoria interna](./img/sistemas-embebidos/arquitectura-SE-comerciar-memoria-interna.png)


Arquitectura de un sistema embebido comercial con memoria externa
=================================================================

![arquitectura de SE comercial con memoria externa](./img/sistemas-embebidos/arquitectura-SE-comercial-memoria-external.png)

Flujo de diseño para aplicaciones un sistema embebido
=====================================================

![Flujo de diseño de software para un SE](./img/sistemas-embebidos/flujo-de-diseno-sw-para-crear-aplicaciones.png)

Ejemplo de flujo de diseno para crear un aplicación en un procedador softcore
=============================================================================

![flujo de diseño de aplicación en LM32](./img/sistemas-embebidos/flujo-de-diseno-hw-sw-procesador-softcore.png)

### ESP32 consideraciones

El Esp32 es un SoC muy popular de bajo costo con periféricos como I2C, SPI, UART, ADC, DAC y de comunicación inalámbrica WiFi/Bluetooth.

![esp32 soc](./img/esp32/esp32-soc.jpg) ![esp32 diagrama de bloques](./img/esp32/esp32-diagrama-bloques.png)

Además del encapsulado del esp32 también se puede encontrar en módulos que contienen memorias, parche de antena (o conector para antena externa) y oscilador llamados *wroom* y *wrover* como se ven en la siguiente imagen

![Empaquetados esp32](./img/esp32/esp32-empaquetados.png)

En este punto es importante observar los esquemas circuitales como los empaquetados de los módulos mencionados, por ejemplo observemos esta información para el **wroom**:

![wroom empaquetado](./img/esp32/esp32-wroom-empaquetado-imagen.png)
![wroom esquematico](./img/esp32/esp32-wroom-schematic.png)

De las anteriores imágen ponga especial identifique donde se encuentra la antena, la memoria flash, el esp32 y el cristal oscilador.

Siguiendo la misma idea, ahora observe el empaquetado y el esquema circuital del módulo **wrover**, observe que este módulo además de tener los mismo componentes del anterior, se le ha agregado
un chip de SPRAM:

![wrover empaquetado](./img/esp32/esp32-wrover-empaquetado-imagen.jpg)
![wrover esquematico](./img/esp32/esp32-wrover-schematic.png)

#### Circuito de operación ESP32

Para el funcionamiento del esp32 en la PCB a construir se requiere un circuito adicional ya que el esp32 se puede configurar para que opere en dos modos principales: **flash** y **boot**.

* **Modo flash**: permite escribir la memoria flash que está en él 
* **modeo boot**: El esp32 ejecuta el programa que tiene almacenado en la memoria flash

Circuito requerido para poner en operación los módulos *wrover* o *wroom*:

![wroom operación](./img/esp32/wroom-circuito-operacion.png)
![wrover operación](./img/esp32/wrover-circuito-operacion.png)

#### Documentación de referencia

* [Página de documentos técnicos del esp32](https://www.espressif.com/en/support/documents/technical-documents)
* [Manual técnico del esp32](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf)
* [Guia de diseño esp32](https://www.espressif.com/sites/default/files/documentation/esp32_hardware_design_guidelines_en.pdf)
* [Datasheet esp32 **wroom**](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)
* [Datasheet esp32 **wrover**](https://www.espressif.com/sites/default/files/documentation/esp32-wrover_datasheet_en.pdf)
* [Framework de desarrollo de esp](https://github.com/espressif/esp-idf)
* [Documentación de uso de esp32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html)



## Diseño y fabricación de PCB

![Flujo de diseño para frabricación de PCB](./img/pcbDesing/flujo-de-diseno-PCB.png)

### Diseño de esquemático

Con respecto al diseño del esquemático del circuito para un sistema embebido, se plantea el desarrollo en la herramienta KiCAD
con hojas jerárquicas.

A continuación se comparte un esquemático con un diseño jerárquico el cual permite el estudio de distintas herramientas
usadas en KiCAD.

[Ejemplo de esquemático para un sistema embebido usando el módulo esp8266 en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/example-schematics/luna-esp8266.pdf)

<div style="height:2000px;">
<!-- https://pdfobject.com/generator/ -->
<object data='https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/example-schematics/luna-esp8266.pdf#scrollbar=1&toolbar=1' 
        type='application/pdf' 
        width='100%' 
        height='100%'>
<p>This browser does not support inline PDFs. Please download the PDF to view it: <a href="https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/example-schematics/luna-esp8266.pdf">Download PDF</a></p>
</object>
</div>

Tenga en cuenta lo siguiente para su diseño
===========================================

* Diseñe los agujeros de sujeción del sistema embebido a la caja.
* Haga uso de las recomendaciones de conexión de los datasheets.
* Cuando agregue elementos de Bypass como es el caso de los condensadores Ubiquelos junto a los elementos indicados pues deben quedar lo más cerca entre ellos en el ruteo (como se indique en datasheet).
* No olvide agregar otros sistemas de protección para el sistema en contra de corrientes parásitas, estáticas y demás, hay dispositivos en el mercado construidos para ello, como arreglos de diodos, inductancias
capacitores, etc.
* Los ciruitos Analógicos son distintos a los circuitos digitales y deben desacoplarse para no generar interferencia entre ellos, reconozca métodos para realizar tal procedimiento si lo requiere su diseño.
* Agregue un LED de energización del sistema embebido
* Agregue un LED de usuario para hacer el "hello world"
* Use conectores apropiados para sus perifericos, recuerde que puede ser pin headers, Molez, JST, RJx, Jacks, Grove entre otros.
* Tenga presente que algunos componentes pueden potencia y disipar calor, haga las anotaciones para que se refleje esta información en el ruteo.
* Haga uso de reguladores LDO que son diseñados con propósito de sacar el mejor provecho a sus fuentes de alimentación, consulte la siguiente información de [digikey sobre LDO](https://www.digikey.com/es/articles/use-advanced-ldos-iot-wireless-sensor-power-supply-design)

### Fabricación de PCB

Capacidad de desarrollo de PCB por parte de las empresas
========================================================

![pcb capacidad](./img/pcbDesing/capacidad-creacion.png)

Es necesario conocer la técnología que usan las empresas en su proceso de fabricación para ahorrar costos,
conocer sus posibilidades y qué estándares existen.

La invitación en este caso es reconocer algunas variables importantes cuando emprendamos el ruteo:

* Tamaño mínimo recomendado de la pista (sin costo adicional)
* Tamaño de vías (perforaciones)
* Mínimo espacio entre pistas
* Costos en la creación de PCBs de uno y dos caras
* Panelización

Estas son las capacidades ofrecidas por algunas empresas:

* [Capacidades ofrecidas por JLCPCB](https://jlcpcb.com/capabilities/Capabilities)

### Normas de diseño IPC

Documentación de referencia sobre las normas IPC
------------------------------------------------

* [Normas IPC comprimido pdf de 41MB](https://drive.google.com/file/d/1sRoVv3UpkkW9lRWvpXItrszYJ7POOIxs/view?usp=sharing)
* [Normas IPC pdf de 177 MB](https://drive.google.com/file/d/1zWp61wTCGvVhFP5wHKmmkJQWqAea1irN/view?usp=sharing)

Vídeos sobre normas IPC
-----------------------

[Norma IPC 2221 para Circuitos Impresos Reglas eléctricas que debes seguir](https://www.youtube.com/watch?v=RiP0Z-NhS6M)

!?[Norma IPC](https://www.youtube.com/watch?v=RiP0Z-NhS6M)

Resistencias SMD
================

* [Resistencias de proposito general SMD pdf](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/datasheets/general/chip-resistor-smd-2167052.pdf)

Dimensiones resistencias
------------------------

![resistencia dimensiones](./img/pcbDesing/res/resistencia-dimensones.png)

![resistencia dimensiones tabla](./img/pcbDesing/res/resistencia-tabla-de-dimension.png)

Resistencia SMD en Kicad
------------------------

En el caso de que los componentes sean soldados con un cautin se recomienda no usar empaquetados pequeños, la recomendación
es seleccionar mínimo el empaquetado *0603* con la etiqueta de **handsolder**, observar la siguiente imagen de ejemplo:

![kicad hansolder](./img/pcbDesing/res/asig-resistor-smd-handsolder.png)

### Componentes y fabricantes de PCBs

Fabricantes Internacionales
===========================

* [OSH Park (US)](https://oshpark.com/)

* [Eurocircuits (EU)](https://www.eurocircuits.com/)

* [Seeed Studio Fusion Service (China)](https://www.seeedstudio.com/fusion_pcb.html)

* [PCBWay (China)](https://www.pcbway.com/)

* [jlcpcb.com (China)](https://jlcpcb.com/)

* [allpcb.com (China)](https://www.allpcb.com/)

Fabricantes Nacionales
======================

* [Colcircuitos](https://colcircuitos.com/circuitos-impresos-servicios-integrales/)
* [Microensamble](https://microensamble.com)
* [PCBmicrocircuitos](https://pcbmicrocircuitos.com)

Tiendas componentes electrónicos
================================

* [Digikey](https://www.digikey.com/)
* [mouser](https://co.mouser.com)

## Herramientas

* GIT
* KiCAD
* Zephyr
* Drawio

### GNU/Linux

El sistema operativo GNU/Linux es un clone de UNIX, UNIX es el sistema operativo padre de otros sistemas operativos
actualmente usados por ejemplo MacOS, Solaris, FreeBSD entre otros, conocer de manera general a UNIX es encontrar
coincidencias en la forma y uso de los sistemas operativos mencionados. A continuación se comparte un
pdf de 24 páginas que muestra de manera general sus principales características.

[Apuntes UNIX en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/linux/unix.pdf)

Llegar por primera vez a un sistema operativo como lo es "Linux" es un reto que requiere esmero y dedicación, se invita a tener la siguiente
referencia en PDF la cual podrá consultar de vez en cuando, y que a través de las prácticas propuestas, podrá mejorar el desempeño en el uso
de este gran sistema operativo como lo es GNU/Linux.

[Sistema operativo Linux (teoría y práctica) en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/linux/linux.pdf)

Se recomienta también tener el siguiente libro de referencia escrito en inglés sobre las funciones de Linux.

[How Linux Works What Every Superuser Should Know en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/linux/HowLinuxWorks.pdf)

Comando útiles
==============

Para tener mayor claridad sobre el mundo de los comandos en Linux tenga de referencia el siguiente libro que le permitirá conocer las combinaciones de los comandos y argumentos según su necesidad.

[The Linux Comman Line en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/linux/TLCL-19.01.pdf)

[Sitio oficial del libro](https://linuxcommand.org/index.php)

Los comandos presentados en la siguiente tabla se ejecutan en una terminal de Linux.

|Comando  |Acción |Ejemplo  |
|:-------------:|:-------------:|:-----:|
|`pwd`  | Posición absoluta actual en el árbol de directorios | `pwd` |
|`cat`  | Imprimir en pantalla el contenido de un archivo | `cat README.md` |
|`mkdir`  | Crear un directorio en el lugar especificado  | `mkdir directorio`  |
|`mkdir -p` | Crear un directorio vacío con su respectivo padre | `mkdir -p ./directorioPadre/directorioHijo` |
|`ls` | Listar el contenido de un directorio | `ls -ltrh` |
|`ln -s`| Crea enlaces simbólicos (en Windows accesos directos) para ficheros | `ln -s /path/archivoFuente /path/archivoDestino` |
|`cd` | Entrar a un directorio  | `cd directorio` |
|`cd ..`  | Subir un nivel en el árbol de directorio| `cd ../` |
|`rm` | Remover un archivo  | `rm archivo.txt` |
|`rm -r`| Remover ficheros de manera recursiva | `rm -r directorio/` |
|`cp`| Hacer copias de ficheros | `cp path/directorio path/copia` |
|`mv`| Mover fichero a nuevoPath/ | `mv archivo pathDestino/` |
|`mv`| Cambiar el nombre de un fichero | `mv archivo nuevoNombreArchivo` |
|`grep`| Buscar una coincidencia dentro de los ficheros | `grep -lr "palabraCoincidencia" path/` |
|`find`| Encontrar un archivo en alguna ruta | `find -iname ./ "parteDelNombreDelArchivoAEncontrar*"`|


GESTORES DE PAQUETES
====================

En "Linux" existen maneras distintas para instalar un programa, entre ellas:

* **Compilar desde archivos fuentes**: se requiere tener los archivos fuentes, reglas de compilación pueden estar basadas en [Make](https://es.wikipedia.org/wiki/Make), compiladores y librerías como parte de las dependencias de compilación.
* **Aplicaciones empaquetadas**: En este caso se obtiene un archivo que se desempaquetará y se instalará en el sistema linux sin requerir el compilador, en el caso de las Distribuciones basadas en "Debian" los paquetes son de extensión **.deb**.
* **Gestores de paquetes**: Las distribuciones Linux tienen servidores en la nube con las aplicaciones empaquetadas para distintas arquitecturas, a través de un cliente instalado en la computadora instalará el paquete con sus dependencias.

Para el caso de Debian se hace uso de algunos gestores de paquetes que facilitan el proceso de instalación de los programas; tal es el caso de **apt**, **apt-get** o **aptitude**.

A continuación se explica el proceso de uso **apt**:

|Comando| Observación |
|:-------------:|:-------------:|
| `apt update` | Actualiza los apuntadores de los sources list para que pueda encontrar los servidores donde están los paquetes de los programas |
| `apt install paquete` | Permite instalar una aplicación con la opción de aceptar algunas condiciones como por ejemplo instalación de dependencias |
| `apt install -f` | Tratará de reparar el funcionamiento de una aplicación a través de por ejemplo la instalación de dependencias rotas, sino lo logra, es posible que desinstale la aplicación y se requiera un procedimiento manual |
| `apt remove paquete` | Desinstala un paquete |


SHELL
=====

En construcción...

MAKE
====

```bash
sudo apt install make
```

[Tutorial Makefile](https://makefiletutorial.com)

[Make en español en PDF](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/make.pdf)

### GIT

![Git](./img/git/git.png)

A continuación se diagrama la funcionalidad del sistema distribuido de control de versiones **git**.

![Funcionalidad del sistema GIT](./img/git/funcionalidad-git.png)

Para conocer la filosofía de GIT se invita revisar el libro llamado Pro Git del cual compartimos el enlace en PDF. Se sugiere revisar el capítulo de *Fundamentos de Git*

* [Libro Pro Git en pdf](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/progit.pdf): Aprede a usar Git de manera profesional, el libro es de distribución libre en lenguaje español.

A continuación se expresan algunas instrucciones vitales que puede usar como especie de receta para iniciarse en el mundo de *Git*

INSTALACIÓN DE GIT
==================

Use el siguiente comando en la terminal de Linux para instalar el cliente de Git de línea de comandos.

```sh
sudo apt install git
```

CONFIGURACIÓN DE GIT
====================

Nuevamente en la terminal ejecuta los siguientes comandos para ajustar el cliente de Git.

```bash
git config --global user.name "Johnny Cubides"
git config --global user.email nombre@dominio.com
git config --global core.editor nvim
git config --list
```

CONFIGURAR LLAVE SSH (OPCIONAL)
===============================

Creando llave
-------------

```bash
ssh-keygen -t rsa -b 4096 -C "ETIQUETA"
```
> La ETIQUETA puede ser tu correo electrónico

A continuación la terminal te pedirá un nombre para guardar el archivo con la llave,
ejemplo:

```bash
Enter file in which to save the key (/home/johnny/.ssh/id_rsa): /path/nombre-archivo
```

> Usa un **nombre-archivo** representativo

Agregar la llave al agente
--------------------------

```bash
ssh-add ~/.ssh/nombre-archivo
```

> Si el agente no está activo lo puedes lanzar con el siguiente comando:
> `eval "$(ssh-agent -s)"`

CLONAR UN REPOSITTORIO
======================

```sh
git clone nombre-de-repositorio
```

HACER UN PULL
=============

La acción de **pull** realiza primero una búsqueda y trae al repositorio local los cambios que hayan sido realizados en el repositorio remoto.

```bash
git pull
```

> Recomiendo que antes de empezar a trabajar se realice un pull en el repositorio local para tener siempre los últimos cambios
> reportados por los demás compañeros.


HACER UN PUSH
=============

La acción de PUSH lleva los cambios del repositorio local al repositorio remoto alojado en un servidor de GIT,
Para que esta operación sea válida se requiere realizar los siguientes pasos:

1. Agregar los archivos con cambios que serán enviados con **git add**
2. Para cometer el push se requiere realizar un comentario sobre los cambios a subir al repositorio remoto de GIT
3. Se realiza el **push** para llevar los cambios
> Se recomienda que se trabaje en directorios específicos para no crear conflictos con cambios que hayan realizado otros
> compañeros y que no se hayan tenido en cuenta.

```bash
git add .
git commit -m "comentario del commit"
git push
```

MARKDOWN
========

[Tutorial de markdown](https://www.markdowntutorial.com/es/)

### KiCAD


![KiCAD](./img/kicad.png)

Documentación de KiCAD
----------------------

[Enlace de documentación oficial de kicad](https://docs.kicad.org/)

INSTALACIÓN DE KiCAD
---------------------

`sudo apt install kicad`

ACCESOS RÁPIDOS
---------------

|Comando  |Explicación  |
|:-------------:|:-------------:|
| | |

Mi primer PCB con kicad
-----------------------

* [Make Your First Printed Circuit Board](https://www.build-electronic-circuits.com/kicad-tutorial/?fbclid=IwAR3OwgRqwc85H-j0YJTUkhBbJpkR1eex80cYIkS15KJx4cIzqhzl-UpF0DQ): Este tutroial en idioma inglés acerca al estudio de la herramienta de diseño *kicad* mientras crea su primera PCB.
![tutorial primera pcv](./img/pcbDesing/primera-pcb-tutorial.png)

Ejercicios de routeo
--------------------


* [flow free](https://www.bigduckgames.com/flowfree): Para desarrollar la habilidad de routeo, puede realizar hacer uso de la herramienta **flow free** la cualnos reta a pensar la manera correcta de conectar nodos de colores a través de puentes, la herramienta está compilada en distintas tiendas.

![flow free](./img/pcbDesing/flow-free.png)

### Comunicación Serial

Para flashear el sistema embebido, realizar depuraciones, capturar datos del programa o interactuar con algún interprete con RELP o prompt, se requiere acceder a través de un hardware que sirva de intermediario entre
el HOST (PC) y el sistema embebido.

TODO: Imagen de Adaptador USB-a-SERIAL

Estos adaptadores generalmente permiten la modificación de los niveles lógicos de 1 y 0 evaluados en rangos entre [0-3.3] V o [0-5] V; cuando lo vaya a usar con su sistema embebido verifique que corresponde con los
niveles de tensión requeridos por el sistema. Entre los adaptadores más famosos se encuentran los siguientes:

* cp2102
* ch340
* ft232rl

La flexibilidad del ft232rl
===========================

Con respecto al ft232rl se destaca la posibilidad de usar sus pines para emular el comportamiento de un JTAG, SPI entre otros, lo que lo hace una gran opción flexible para poder
comunicarse con diferentes placas, además de tener un excelente relación entre costo y beneficio que supera con creces a los otros adaptadores listados con anterioridad.

Para entender mejor el tema de fléxibilidad se remite ver la documentación de este par de proyectos que pueden hacer uso de este adaptador:

* [openFPGALoader](https://github.com/trabucayre/openFPGALoader)
* [OpenOCD ft232](https://github.com/openocd-org/openocd/blob/master/src/jtag/drivers/ft232r.c) y [Tutorial de OpenOCD ft232](https://jacobncalvert.com/2020/02/04/jtag-on-the-cheap-with-the-ftdi-ft232r/)

Permisos en la configuración serial
===================================

En los sistemas Linux es importante recordar que todo los elementos son reconocidos como archivos y que el hardware es reconocido también como un archivo con una etiqueta que lo hace denominar "especial",
para los dispositivos seriales estos generalmente son reconocidos en el directorio de dispositivos `/dev/` como sigue:

* /dev/ttyUSBx
* /dev/ttyACMx

Donde **x** representa el número del adaptador el cual puede empezar por **0** y se numeran en orden ascendente si se identifican varios adaptadores USB-SERIALES.

Estos archivos como se indican son especiales y para tener permisos de escritura y de lectura de debe modificar ese argumento que generalmente se hace con `chmod`, pero acá
mencionaremos una estrategia que hace que el procedimiento sea automatizado cada vez que se conecta un dispositivo serial.

Configuración de permisos del adaptador USB-SERIAL
==================================================

Todos estos dispositivos tendrán permisos en el grupo denominado **dialout** lo que debemos hacer es agregar nuestro usuario a este grupo para tal fin ejecute el siguiente comando:

```bash
sudo usermod -a -G dialout nombre de usuario
```

**Observaciones**:

* Si no sabe cual es su nombre de usuario ejecute en consola el comando `whoami`
* Si quiere ver los grupos a los que pertenece su usuario ejecute el comando `groups`
* Si necesita más ayudas puede consultar la [wiki de archlinux] que contiende información adicional e interesante

Programas para terminales seriales
==================================

Para que estos adaptadores funcionen y se pueda transmitir y recibir información a través de pantalla y comando por teclado existen los **monitores seriales**. A continuación
se mencionará dos de estos y se explicará brevemente información útil para su funcionamiento.

Monitor Minicom
---------------

El monitor minicom tiene una alta flexibilidad en su configuración y en sus capacidades, permite transferir archivos a los dispositivo embebidos directamente, configurar atributos en la
comunicación como lo es la paridad, el baudrate y por ejemplo, el control por hardware, este último es importante reconocerlo en las opciones y desactivarlo ya que da la impresión
de que la aplicación no funciona siendo un parámetro a controlar nuevamente desde su configuración.

**Instalación**:

Ejecute el siguiente comando:

```bash
sudo apt install minicom
```

**Uso**:

```bash
minicom -o -b baudrate -D /dev/ttyUSBx
```

**Explicación**:

* `-o` mantiene la aplicación funcionando reportando por pantalla si el adaptador USB es desconectado
* `-b` se refiere al baudrate con el que se desea iniciar la comunicación, típicamente se usan valores como 9600 o 115200 baudios
* `-D` Indica el adaptador USB con el cual se quiere iniciar la comunicación

**Secuencia de comando usando minicom**

En minicom se debe combinar teclas y hacer secuencias con las mismas para llegar a algunos lugares, acá se explicará las combinaciones con el símbolo + y la tecla control con el símbolo **^**

**Lista de comandos**

* `^+a z q` finaliza la aplicación
* `^+a z c` limpia la pantalla
* `^+a z o` entra al menú de configuraciones de minicom

**Sobre el control de flujo**:

Mencionado anteriormente se puede ubicar este en el menú en el item **Serial port setup** y desde allí con la tecla F deshabilitar (Poner en **No**) el control de hardware **Hardware Flow Control** quedando como sigue::

```sh
    +-----[configuration]------+
    | Filenames and paths      |
    | File transfer protocols  |
    | **Serial port setup**    |
    | Modem and dialing        |
    | Screen and keyboard      |
    | Save setup as dfl        |
    | Save setup as..          |
    | Exit                     |
    +--------------------------+
###################################
    +-----------------------------------------------------------------------+
    | A -    Serial Device      : /dev/ttyUSB0                              |
    | B - Lockfile Location     : /var/lock                                 |
    | C -   Callin Program      :                                           |
    | D -  Callout Program      :                                           |
    | E -    Bps/Par/Bits       : 115200 8N1                                |
    | F - Hardware Flow Control : No                                        |
    | G - Software Flow Control : No                                        |
    | H -     RS485 Enable      : No                                        |
    | I -   RS485 Rts On Send   : No                                        |
    | J -  RS485 Rts After Send : No                                        |
    | K -  RS485 Rx During Tx   : No                                        |
    | L -  RS485 Terminate Bus  : No                                        |
    | M - RS485 Delay Rts Before: 0                                         |
    | N - RS485 Delay Rts After : 0                                         |
    |                                                                       |
    |    Change which setting?                                              |
    +-----------------------------------------------------------------------+
```

Prueba de loopback
==================

Esta prueba se puede realizar y es importante si lo que se requiere es verificar que el adaptador USB-SERIAL funciona correctamente, esto se
puede realizar conectando un jumper o conector rápido entre los pines RX y TX del dispositivo, abriendo un Monitor Serial y escribiendo con
el teclado caracteres, deberá ver en pantalla los caracteres en el orden que los está escribiendo.

### Zephyr OS

![Zephyr](./img/zephyr.jpeg)

### Drawio

![Drawio](./img/drawio.png)

## Proyectos

Plataformas de Crowdfunding
===========================

Las plataformas de crowdfunding permiten visibilizar e impulsar proyectos
de emprendimiento artísticos, de desarrollo, de innovación entre otros.
Allí se han apoyado ideas de desarrollo interesante como han sido:

[Omega2](https://www.kickstarter.com/projects/onion/omega2-5-iot-computer-with-wi-fi-powered-by-linux?lang=es): Sistema embebido que costaba 5 dólares con capacidad de correr Linux y conexión WiFi.

[Mycropython](https://www.kickstarter.com/projects/214379695/micro-python-python-for-microcontrollers): Proyecto que permite programar microcontroladores en el lenguaje Python.

[Cubetto](https://www.kickstarter.com/projects/primotoys/cubetto-hands-on-coding-for-girls-and-boys-aged-3?ref=discovery_category_most_backed): Plataforma de programación de hardware tangible.

[Espruino](https://www.kickstarter.com/projects/gfw/espruino-javascript-for-things?ref=discovery_category_most_backed): Programa microcontroladores con el lenguaje de programación JavaScript.

[Papilio Duo](https://www.kickstarter.com/projects/13588168/papilio-duo-drag-and-drop-fpga-circuit-lab-for-mak?ref=discovery_category_most_backed): Crear circuitos y probar en FPGA de manera gráfica o por bloques.

[Endless](https://www.kickstarter.com/projects/1381437927/endless-computers?ref=discovery_category_most_backed): Computadoras para todo el mundo.

Si es necesario un poco de inspiración para emprender un proyecto, puede revisar
los siguientes sitios de crowdfunding, podrá encontrar proyectos que inclusive
podrá adoptar para emprender su propio proyecto.

Enlaces a plataformas de crowdfunding
-------------------------------------

[Kickstarter](https://www.kickstarter.com)

[Indiegogo](https://www.indiegogo.com/)

[Ulule](https://es.ulule.com/)

Proyectos Sistemas Embebidos UNAL 2022-I
========================================

**En proceso...**

Proyectos Sistemas Embebidos UNAL 2021-II
=========================================

Enlaces de los repositorios del proyectos
-----------------------------------------

* [Github del proyecto: Telemetría apícola](https://github.com/Norely/Telemetria-apicola)
* [Github del proyecto: Termómetro cervercero](https://github.com/Dportela2001/RemoteTempMonitor)
* [Github del proyecto: Control de biosistemas](https://github.com/DaryhenViancha/Control-de-biosistemas)
* [Github del proyecto: Control de aforo](https://github.com/screinac/controlador-de-aforo)
* [Github del proyecto: Cuidador de mascotas](https://github.com/Davidariza99/Proyecto-embebidos)
* [Github del proyecto: Dispensador para mascotas](https://github.com/AndresRodriguezUN/Dispensador-de-Comida-para-mascotas)
* [Github del proyecto: Cerradura electrónica](https://github.com/CamSP/cerradura-electronica)
* [Github del proyecto: Monitor bodega](https://github.com/Grupo-Monitor-Bodega)

Vídeos de las presentaciones de los proyectos
---------------------------------------------

!?[Telemetría Apícola](https://youtu.be/vyEqwwPkpSk)

!?[Termómetro cervercero](https://youtu.be/wNGFhHlYesc)

!?[Control de biosistemas](https://youtu.be/OPwyoVEpBv4)

!?[Control de aforo](https://youtu.be/n9p1b5t7SQs)

!?[Cuidador de mascotas](https://youtu.be/NZSnmj3M8_A)

!?[Dispensador para mascotas](https://youtu.be/8CSYblkC2kM)

!?[Cerradura electrónica](https://youtu.be/EMLXIH5TPao)

!?[Monitor bodega](https://youtu.be/-TkDQ2qM4i0)

!?[Conclusiones](https://youtu.be/FYKkyEN5acA)

