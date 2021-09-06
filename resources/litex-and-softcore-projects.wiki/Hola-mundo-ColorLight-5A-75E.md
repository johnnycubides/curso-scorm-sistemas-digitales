# Pasos para construir y ejecutar el Blink en ColorLight 5A-75E

En éste ejemplo se usará la omega2 para programar por jtag la fpga (ecp5) de la colorlight 5A-75E V7.1.

## 1. Conexiones entre FPGA y Omega2

![omega2+ pinout](https://github.com/unal-digital-electronic/litex-and-softcore-projects/blob/master/cl-5a-75e-project-example/blink/img/Omega2.png)

![omega2+jtag](https://github.com/unal-digital-electronic/litex-and-softcore-projects/raw/master/openocd-tool/host/omega2/colorlight-5A-75E-openocd-config/img/omega2_jtag.jpg)

![5a-75e-jtag](https://github.com/unal-digital-electronic/litex-and-softcore-projects/raw/master/openocd-tool/host/omega2/colorlight-5A-75E-openocd-config/img/5A-75E.jpg)

## 2. Instalación de las herramientas de síntesis para Lattice ECP5 

// TODO documentar ya sea para conda o por compilación de archivos fuentes de las herramientas

## 3. [Instalación de openocd en Omega2](https://github.com/unal-digital-electronic/litex-and-softcore-projects/tree/master/openocd-tool/host/omega2/precompiled-openocd)

## 4. Configuración de openocd para Omega 2
Basta con seguir las [instrucciones del paso 1 de éste link](https://github.com/unal-digital-electronic/litex-and-softcore-projects/tree/master/openocd-tool/host/omega2/colorlight-5A-75E-openocd-config#1-subir-archivos-desde-el-pc-a-la-omega2)

## 5. Construcción del Blink
En [éste directorio](https://github.com/unal-digital-electronic/litex-and-softcore-projects/tree/master/cl-5a-75e-project-example/blink) encontrará los archivos fuentes del blink, desde allí ejecute el comando `make all`; como resultado se generarán éstos dos archivos: **blink-flash.svf** y **blink.svf**

* **blink.svf**: Archivo para programar en la RAM directamente 
* **blink-flash.svf**: Archivo para programar en la flash de la FPGA

## 6. Subir archivos .svf

Los archivos **.svf** son los que la fpga tomará para comportarse como deseamos 

Debe conocer la dirección ip de la omega2 y ésta ser accesible desde su PC
```bash
scp blink.svf blink-flash.svf root@ip_de_omega2:/root/
```

## 7. Programar FPGA

Hacer loggin por ssh a la omega2

```bash
ssh root@ip_de_omega2
```

**Observación**: En cualquiera de los dos casos siguientes, después de ejecutar el comando deberá ver el led parpadeando

### 7.1 Programar en la RAM

```bash
sh program.sh blink.svf
```
La programación desaparecerá despues de cada reinicio

### 7.2 Programar en la FLASH

```bash
sh program.sh blink-flash.svf
```
La programación será permanente en la FPGA

### Ejemplo de programación

```bash
root@Omega-49E1:~# sh program.sh blink.svf 
set gpiomux pwm0 -> gpio
set gpiomux pwm1 -> gpio
Open On-Chip Debugger 0.10.0-05040-gf98f83eada-dirty (2017-10-12-15:09)
Licensed under GNU GPL v2
For bug reports, read
        http://openocd.org/doc/doxygen/bugs.html
SysfsGPIO nums: tck = 17, tms = 2, tdi = 16, tdo = 15
SysfsGPIO num: trst = 1
SysfsGPIO num: srst = 19
Info : SysfsGPIO JTAG/SWD bitbang driver
Info : JTAG only mode enabled (specify swclk and swdio gpio to add SWD mode)
Warn : gpio 19 is already exported
Info : This adapter doesn't support configurable speed'
Info : JTAG tap: lfe5u25.tap tap/device found: 0x41111043 (mfg: 0x021 (Lattice Semi.), part: 0x1111, ver: 0x4)
Warn : gdb services need one or more targets defined
   TapName             Enabled  IdCode     Expected   IrLen IrCap IrMask
-- ------------------- -------- ---------- ---------- ----- ----- ------
 0 lfe5u25.tap            Y     0x41111043 0x41111043     8 0x05  0xff
svf processing file: "blink.svf"
95%    
Time used: 0m33s638ms 
'svf file programmed successfully for 618 commands with 0 errors'
shutdown command invoked
sh: write error: Invalid argument
root@Omega-49E1:~#
```

## Referencias

[Configuración openocd para ecp5-x](https://github.com/f32c/f32c/tree/master/rtl/proj/lattice/programmer/openocd/ulx3s)

[Fuentes verilog para el blink.svf usado](https://github.com/Martoni/MartoniColorlight/tree/master/simpleBlink)

[Configuración de interfaz jtag openocd para omega2](https://github.com/johnnycubides/onion-medialab/tree/master/sw/omega-packs/stm32f100)

[Script de configuración para crear el .svf que se alamcena en la flash](https://github.com/NiklasFauth/colorlight-led-cube/blob/master/fpga/syn/bit_to_flash.py)
