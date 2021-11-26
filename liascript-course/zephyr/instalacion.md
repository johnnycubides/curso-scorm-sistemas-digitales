## Zephyr O.S.

**Configuración y compilación**

[Proceso de Instalación de Zephyr](https://docs.zephyrproject.org/latest/getting_started/index.html#getting-started-guide)

[Guía para dar soporte a nuevas boards](https://docs.zephyrproject.org/latest/guides/porting/board_porting.html)

**Configuración de variables de entorno**

Las variables de entorno se configuran en el shell(terminal) de nuestro GNU/Linux y pueden ser vistas con el comando `printenv`

|var|Uso|
|---|---|
|ZEPHYR_BASE|Se refiere al lugar donde se encuentra instalado el proyecto zephyr|
|ZEPHYR_SDK_INSTALL_DIR|Indica explícitamente la ruta del toolchain de zephyr (el cual tiene el toolchain para cross-compilar para diferentes plataformas)|
|ZEPHYR_TOOLCHAIN_VARIANT|Se usa para indicar queremos usar el SDK ofrecido por zephyr o usaremos nuestro propio cross-compilador|
|CROSS_COMPILE|Si en ZEPHYR_TOOLCHAIN_VARIANT se indica como variante **cross-compile** deberá indicar la ruta del cross-compilador a usar|

**Ejemplos de configuración de variables de entorno**

**Nota 1**: Usando una configuración similar a la de los siguientes ejemplos, tu proyecto (los archivos fuentes) puede estar ubicado por fuera del `.../zephyrproject/zephyr/` y aún así podrá ser compilado.

**Nota 2**: En realidad para iniciar zephyr puedes omitir estas configuraciones, pero al ir avanzando se hace necesario conocerlas para poder ajustar las herramientas a nuestras requermientos.

**Ejemplo de configuración usando el SDK de Zephyr**

```bash
export ZEPHYR_BASE=~/zephyrproject/zephyr
export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.11.3
```

**Ejemplo de configuración donde se usa un cross-compilador externo para riscv32**

**Nota**: El cross-compilador debe estar instalado en el equipo y debes conocer la ruta

```bash
export ZEPHYR_BASE=~/zephyrproject/zephyr
export ZEPHYR_TOOLCHAIN_VARIANT=cross-compile
export CROSS_COMPILE=~/miniconda3/envs/fpga/bin/riscv32-unknown-elf-
```
**Nota**: con la anterior configuración, tu proyecto puede estar ubicado por fuera del `.../zephyrproject/zephyr/` y aún así podrá ser compilado.

**2. Configuración de aplicación Zephyr y compilación**

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


## Depurar con Qemu-Riscv32 y GDB

**Compilar para Riscv32**

En el projecto de zephyr existen varios ejemplos; para nuestro interés compilaremos el referente a sincronizaciones el cual se encontrará en el directorio samples. Ejemplo: 

```bash
cd ~/zephyrproject/zephyr
```
Allí encontrará los siguientes directorios:
```bash
.
├── arch
├── boards
├── cmake
├── CMakeFiles
├── doc
├── drivers
├── dts
├── include
├── kernel
├── lib
├── misc
├── modules
├── samples
├── scripts
├── share
├── soc
├── subsys
└── tests
```
Ahore observemos la siguiente imagen; en ella se puede apreciar el proceso para crear el ejectuable .elf.

![proceso de compilacion](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/zephyr-riscv-compile-elf.png)

Para crear el ejecutable, lanza el siguiente comando en la terminal el cual desarrollará los procesos numerados desde el 1 hasta el 3.
```bash
west build -p auto -b qemu_riscv32 samples/synchronization/
```
El anterior comando también puede ser sustituido por el siguiente comando:

```bash
cmake -B build -DBOARD=qemu_riscv32 samples/synchronization/
cd build/
make
```

O también por:
```bash
cmake -B build -GNinja -DBOARD=qemu_riscv32 samples/synchronization/
cd build/
ninja
```
Sin importar cuál proceso de comandos uses tu resultado deberá ser similar al presentado en la siguiente imagen:

![salida compilada](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/salida-compilar-zephyr-quemu-riscv32.png)

**Lanzar la emulación con Qemu-Riscv32 y debug server**

![lanzar emulación con qemu y debug server](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/qemu-dbgserver.png)

En este proceso se inicia la emulación para la arquitectura de riscv32 y además, se abre un servidor de depuración en puerto TCP localhos:1234; ésto permitira hacer uso de gdb para monitorear el flujo de nuestro programa. Para tal fin abra otra terminal y ubícate en el siguiente directorio del proyecto:

```bash
cd ~/zephyrproject/zephyr/build
```
Allí encontrará los siguientes directorios:
```bash
.
├── app
├── CMakeFiles
├── Kconfig
├── modules
└── zephyr
```
Finalmente ejecute el siguiente comando para lazar la emulación y el servicio para depuración:
```bash
ninja debugserver
```
[salida con el comando ninja debugserver]()

Recuerda también que podrás hacer uso de éste comando para la misma operación:
```bash
make debugserver
```

![salida con el comando make debugserver](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/make-debug-server-quemu-riscv32.png)

**Depuración con GDB**

El gdb a usar es el dado en el sdk de zephyr, sin embargo, para aprovechar las características de gdb haremos **uso de alguno de los siguientes programas** que nos servirán de interfaz gráfica.

* **[DDD](https://www.gnu.org/software/ddd/)**, instalación: `apt-get install -y ddd`
* **[gdbgui](https://www.gdbgui.com/installation/)**, instalación: `pip install gdbgui`

**DDD**

![ddd debugger](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/ddd-riscv32.png)

Abre una terminal y ubícate en el siguiente directorio:

```bash
cd ~/zephyrproject/zephyr/build/zephyr
```
Y allí ejecuta el siguiente comando para hacer uso de **ddd**:
```bash
ddd --debugger "~/zephyr-sdk-0.11.3/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-gdb -ex 'target remote localhost:1234' ./zephyr.elf"
```

Si tienes problemas con dependencias de python, puedes probar el siguiente comando:
```bash
ddd --debugger "~/zephyr-sdk-0.11.3/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-gdb-no-py -ex 'target remote localhost:1234' ./zephyr.elf"
```

**gdbgui**

![gdbgui debugger](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/dev-tools/synthesis-compilation-and-programming-tools/zephyr/docs/zephyr-compile/gdbgui-riscv32.png)

```bash
cd ~/zephyrproject/zephyr/build/zephyr
```
Y allí ejecuta el siguiente comando para hacer uso de **gdbgui**:
```bash
gdbgui --gdb ~/zephyr-sdk-0.11.3/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-gdb --gdb-args='-ex "target remote localhost:1234" ./zephyr.elf'
```
Si tienes problemas con dependencias de python, puedes probar el siguiente comando:
```bash
gdbgui --gdb ~/zephyr-sdk-0.11.3/riscv64-zephyr-elf/bin/riscv64-zephyr-elf-gdb-no-py --gdb-args='-ex "target remote localhost:1234" ./zephyr.elf'
```

