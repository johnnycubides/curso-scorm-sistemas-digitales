# Acciones

Pasos para probar este proyecto

1. `. zephyr-env.sh`
2. `make config`
3. `make compile`
4. `make litex_term`
5. Escriba el comando `reboot` en el prompt de litex y espere a que sea cargado el programa

## Comando y explicación de su funcionamiento

Los siguientes comandos los encontrará en el **Makefile** de este directorio.

* `make config` configura el proyecto.
* `make compile` genera el ejecutable zephyr
* `make litex_term` carga el ejecutable en la placa colorlight
* `make cache-rm-zephyr` limpia la cache de zephyr.
* `make export-vars-zephyr` exporta las variables de entorno del sdk y
  del proyecto zephyr (Aún no funciona)

Sino quiere hacer uso de los comandos propuestos en el **Makefile** encontrará a continuación
los que puede ejecutar desde la consola


### Configuración y compilación y compilación

```bash
cmake -B build -DBOARD=litex_vexriscv \
  -DDTC_OVERLAY_FILE=./board/litex_vexriscv.overlay ./
make -C build/ -f Makefile all
```

### Cargar Firmware a RAM por puerto serial

```bash
litex_term /dev/ttyUSB0 --kernel build/zephyr/zephyr.bin --kernel-adr 0x40000000 --speed 115200
```

Donde:
* `--speed` se refiere al baudrate con el que fue configurado el módulo uart
* `--kernel` se refiere a la imagen del firmware a cargar en el lugar especificado
* `--kernel-adr` se refiere a la dirección de memoria donde deberá escribir el firmware que
  debe coincidir con la dirección indicada en el bios para que después de escrito el firmware
  el procesador salte a esa dirección para cargar el nuevo firmware.

## Observaciones

* El archivo que encontrará en `./board/litex_vexriscv.overlay` son las configuraciones
que se desean sobreescribir el las encontradas por default en los archivos **DTS** y **DTSI**,
esto permite que haga sus propias configuraciones en cada uno de sus proyectos. Para
que sea más fácil su comprensión estudie el siguiente link: [DTS en zephyr os](https://docs.zephyrproject.org/2.3.0/guides/dts/index.html).

* El archivo `./prj.conf` le indica a las herramientas de compilación que módulos y/o
  drivers deberá compilar o serán dependencias para éste proyecto, con esto podrá
  controlar la compilación de dependencias exclusivamente para éste proyecto.

## Referencias

[LiteX SoC builder (litex)](https://docs.zephyrproject.org/latest/reference/devicetree/bindings.html#litex-soc-builder-litex)

[documentación de gpio en zephyr os](https://docs.zephyrproject.org/apidoc/latest/drivers_2gpio_8h.html)

[Guia sobre bindings para zephyr os](https://docs.zephyrproject.org/2.3.0/guides/dts/bindings.html)

