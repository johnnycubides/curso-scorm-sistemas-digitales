<!--

author: Carlos Camargo, Johnny Cubides

email: cicamargoba@unal.edu.co, jgcubidesc@unal.edu.co

comment: Material de apoyo para sistemas emebidos UNAL

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

## Fabricación de PCB

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

## ESP32 consideraciones

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

### Circuito de operación ESP32

Para el funcionamiento del esp32 en la PCB a construir se requiere un circuito adicional ya que el esp32 se puede configurar para que opere en dos modos principales: **flash** y **boot**.

* **Modo flash**: permite escribir la memoria flash que está en él 
* **modeo boot**: El esp32 ejecuta el programa que tiene almacenado en la memoria flash

Circuito requerido para poner en operación los módulos *wrover* o *wroom*:

![wroom operación](./img/esp32/wroom-circuito-operacion.png)
![wrover operación](./img/esp32/wrover-circuito-operacion.png)

### Documentación de referencia

* [Página de documentos técnicos del esp32](https://www.espressif.com/en/support/documents/technical-documents)
* [Manual técnico del esp32](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf)
* [Guia de diseño esp32](https://www.espressif.com/sites/default/files/documentation/esp32_hardware_design_guidelines_en.pdf)
* [Datasheet esp32 **wroom**](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)
* [Datasheet esp32 **wrover**](https://www.espressif.com/sites/default/files/documentation/esp32-wrover_datasheet_en.pdf)
* [Framework de desarrollo de esp](https://github.com/espressif/esp-idf)
* [Documentación de uso de esp32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html)

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

![Git](./img/git.png)

DOCUMENTACIÓN DE REFERENCIA DE GIT
==================================

* [Libro Pro Git en pdf](https://github.com/johnnycubides/curso-scorm-sistemas-digitales/raw/main/ref-docs/books/progit.pdf): Aprede a usar Git de manera profesional, el libro es de distribución libre en lenguaje español.

INSTALACIÓN DE GIT
==================

```sh
sudo apt install git
```

CONFIGURACIÓN DE GIT
====================

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

### KiCAD


![KiCAD](./img/kicad.png)

INSTALACIÓN DE KITCAD
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

