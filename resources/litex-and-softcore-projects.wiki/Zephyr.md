# Zephyr O.S.

[Proceso de Instalación de Zephyr](https://docs.zephyrproject.org/latest/getting_started/index.html#getting-started-guide)

[Guía para dar soporte a nuevas boards](https://docs.zephyrproject.org/latest/guides/porting/board_porting.html)

## 1. Configuración de variables de entorno

Las variables de entorno se configuran en el shell(terminal) de nuestro GNU/Linux y pueden ser vistas con el comando `printenv`

|var|Uso|
|---|---|
|ZEPHYR_BASE|Se refiere al lugar donde se encuentra instalado el proyecto zephyr|
|ZEPHYR_SDK_INSTALL_DIR|Indica explícitamente la ruta del toolchain de zephyr (el cual tiene el toolchain para cross-compilar para diferentes plataformas)|
|ZEPHYR_TOOLCHAIN_VARIANT|Se usa para indicar queremos usar el SDK ofrecido por zephyr o usaremos nuestro propio cross-compilador|
|CROSS_COMPILE|Si en ZEPHYR_TOOLCHAIN_VARIANT se indica como variante **cross-compile** deberá indicar la ruta del cross-compilador a usar|

### 1.1 Ejemplos de configuración de variables de entorno

**Nota 1**: Usando una configuración similar a la de los siguientes ejemplos, tu proyecto (los archivos fuentes) puede estar ubicado por fuera del `.../zephyrproject/zephyr/` y aún así podrá ser compilado.

**Nota 2**: En realidad para iniciar zephyr puedes omitir estas configuraciones, pero al ir avanzando se hace necesario conocerlas para poder ajustar las herramientas a nuestras requermientos.

#### 1.1.1 Ejemplo de configuración usando el SDK de Zephyr

```bash
export ZEPHYR_BASE=~/zephyrproject/zephyr
export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.11.3
```

#### 1.1.2 Ejemplo de configuración donde se usa un cross-compilador externo para riscv32

**Nota**: El cross-compilador debe estar instalado en el equipo y debes conocer la ruta

```bash
export ZEPHYR_BASE=~/zephyrproject/zephyr
export ZEPHYR_TOOLCHAIN_VARIANT=cross-compile
export CROSS_COMPILE=~/miniconda3/envs/fpga/bin/riscv32-unknown-elf-
```
**Nota**: con la anterior configuración, tu proyecto puede estar ubicado por fuera del `.../zephyrproject/zephyr/` y aún así podrá ser compilado.

## 2. Configuración de aplicación Zephyr y compilación

Nos referimos en éste punto al proceso de configurar los archivos fuentes para una plataforma (board) y a la generación de zephyr.elf y zephyr.bin.

Cuando tenemos nuestros archivos fuentes del proyecto, debemos indicarle la configuración de cross-compilación según nuestra **BOARD**.
Para ello tendremos algunas posibilidades que hemos explorado y explicaremos a continuación:

Supongamos que nos encontramos en el proyecto de ejemplo hello_word y queremos compilar para litex_vexriscv:

```bash
cd hello_world/
tree .
.
├── CMakeLists.txt
├── prj.conf
├── README.rst
├── sample.yaml
└── src
    └── main.c

1 directory, 5 files
```
Podríamos pensar en usar alguna de las siguientes variantes para configurar y para compilar:

| # variante |Comando|Observación|
|:---:|---|---|
|1| west build -b litex_vexriscv ./|Configuración y compiación de zephyr.bin|
|2| cmake -B build -DBOARD=litex_vexriscv ./|Configuración de proyecto, la compilación se hará a través del comando **make**|
|3| cmake -B build -GNinja -DBOARD=litex_vexriscv ./|Configuración de proyecto seg, la compilación se puede hacer a través de **ninja**

* Si usas la *variante 1* zephyrproject hará todo el trabajo, y bastará con subir el zephyr.bin a la plataforma por el método que ya conozcas.
* Si usas la *variante 2* debes entrar al directorio build/ recién creado y usar el comando make; esta opción te permite observar más * detalles, como por ejemplo ver la configuración que estás usando a través del comando `make menuconfig`
* Si usas la *variante 3* deberás entrar el directorio construido build/ y desde allí podrás usar el comando `ninja`. Hay más opciones para el comando ninja como por ejemplo: `ninja clean`, `ninja run`.

Ejemplo

**Observaciones finales**

* Cuando configuramos nuestro proyecto para una board, si el proceso falla, elimina el directorio build creado, haz los ajustes e intena de nuevo; para remover el directorio y su contenido puedes usar el siguiente comando `rm -r build/`
* Zephyr usa ccache para mantener una copia inmediata de las compilaciones realizadas con el fin de que en cada proceso de compilación no deba hacer todo desde cero, podrás encontrar el caché en `~/.cache/zephyr/`.
