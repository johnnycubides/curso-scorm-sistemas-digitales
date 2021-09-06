# Depurar con Qemu-Riscv32 y GDB

## Compilar para Riscv32

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

## Lanzar la emulación con Qemu-Riscv32 y debug server

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

## Depuración con GDB

El gdb a usar es el dado en el sdk de zephyr, sin embargo, para aprovechar las características de gdb haremos **uso de alguno de los siguientes programas** que nos servirán de interfaz gráfica.

* **[DDD](https://www.gnu.org/software/ddd/)**, instalación: `apt-get install -y ddd`
* **[gdbgui](https://www.gdbgui.com/installation/)**, instalación: `pip install gdbgui`

### DDD

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

### gdbgui

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




