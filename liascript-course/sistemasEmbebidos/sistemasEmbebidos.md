## Sistemas Embebidos


Proyecto
===============

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
===============

![ejemplo de sistema embebido](./img/ejemplo-sistema-embebido.png) ![omega modular](./img/omega-modular.jpg)

El dispositivo deberá responder a los requerimientos funcionales y no funcionales
y además tener las siguientes características:

* Desarrollar una PCB a la medida de la necesidad; podrá desarrollar el sistema embebido completo o desarrollar una tarjeta hija para una tarjeta de desarrollo
* Para las tareas de software se puede hacer uso de *Zephyr OS*, *ChibiOS* o *micropython*; si desea usar micropython deberá ser compilado a la medida de la necesidad
* El sistema debe permitir la comunicación con otros dispositivos para monitoreo o control por parte del usuario final (puede ser a través de un medio guiado o no, lo cual depende de la aplicación).

Sobre la caja
===============

![piccolo](./img/piccolo.jpg) ![estacion](./img/estacion.jpg)

En este caso se refiere a los aparatos encargados de realizar las tareas mecánicas, de protección,
estéticas, de experiencia de usuario, las cuales contienen sensores, actuadores y el sistema diseñado;
puede hacer uso de CAD para impresión 3D, corte láser, existen bibliotecas libres en Internet que
podrá descargar y ajustar a la necesidad.

Sobre la documentación
----------------------

Queremos documentar el proceso de desarrollo, para tal fin puede se requiere hacer uso de:

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
===============

Queremos que piensen que este producto va a ser ofrecido a un público que lo pueda necesitar por tanto
muestre el producto de tal manera que se pueda reconocer sus características y particularidades.

![Brochure IFLAB](./img/brochure-iflab.png)

## Ideación

En esta face del proyecto queremos plantear lo que queremos hacer, como también las restricciones de funcionamiento y de alcance;
Para tal fin deseamos responder a los siguientes items:

* Descripción
* Requerimientos del cliente y alcance
* Requerimientos funcionales

Requerimientos del cliente y alcance
===============

Son los relacionados a aquello que el cliente quiere que suceda con su producto, los cuales permiten jugar
sin que éste necesariamente sepa como debe suceder internamente, para este paso, puede crear diagrámas que den cuenta
de como interviene el **"artefacto"** en la necesidad del cliente, como el usuario interactua con el aparato considerando
aspectos estéticos y aquello que tiene un valor agregado (experiencia de usuario), como sugerencia **Liste todo aquello que
permita acotar el alcance del proyecto** para que identifique que partes de eso se pueden realizar en el tiempo disponible
en el curso y aquello que queda proyectado para una próxima iteración del desarrollo del proyecto en otro espacio-tiempo.

## Herramientas

* GIT
![Git](./img/git.png)
* KiCAD
![KiCAD](./img/kicad.png)
* Zephyr
![Zephyr](./img/zephyr.jpeg)
* Drawio
![Drawio](./img/drawio.png)

GNU/Linux
===============

|Comando  |Acción |Ejemplo  |
|:-------------:|:-------------:|:-----:|
|`pwd`  | Posición absoluta actual en el árbol de directorios ||
|`cat`  | Imprimir en pantalla el contenido de un archivo | cat README.md |
|`mkdir`  | Crear un directorio en el lugar especificado  | mkdir directorio  |
|`mkdir -p` | Crear un directorio vacio con su respectivo padre | mkdir -p ./directorioPadre/directorioHijo |
|`ls` | Listar el contenido de un directorio | ls, ls -ltrh |
|`cd` | Entrar a un directorio  | cd directorio |
|`cd ..`  | Subir un nivel en el árbol de directorio||
|`rm` | Remover un archivo  | rm archivo.txt  |


GIT
===============

INSTALACIÓN DE GIT
==================

```sh
sudo apt install git
```

CONFIGURACIÓN DE GIT
====================

```bash
git config --global user.name "Johnny Cubides"
git config --global user.email jgcubidesc@gmail.com
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
ejemplo

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

<div style="height:2000px;">
<!-- insert in the document body -->
<object data='docs/progit.pdf' 
        type='application/pdf' 
        width='100%' 
        height='100%'>
<p>This browser does not support inline PDFs. Please download the PDF to view it: <a href="docs/progit.pdf.pdf">Download PDF</a></p>
</object>
</div>

KiCAD
===============

INSTALACIÓN DE KITCAD
=====================

`sudo apt install kicad`

ACCESOS RÁPIDOS
===============

|Comando  |Explicación  |
|:-------------:|:-------------:|
| | |

