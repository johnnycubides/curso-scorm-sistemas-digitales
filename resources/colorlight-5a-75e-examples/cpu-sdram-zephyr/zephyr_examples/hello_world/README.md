# Actions

## Comandos

* `export-vars-zephyr` exporta las variables de entorno del sdk y
  del proyecto zephyr
* `make config` configura el proyecto.
* `make compile` genera el ejecutable zephyr
* `make litex_term` carga el ejecutable en la placa colorlight
* `make cache-rm-zephyr` limpia la cache de zephyr.

```bash
cmake -B build -DBOARD=litex_vexriscv ./
make -C build/
```

## Cargar Firmware a RAM por puerto serial

```bash
litex_term /dev/ttyUSB0 --kernel build/zephyr/zephyr.bin --kernel-adr 0x40000000 --speed 115200
```

Donde:
* `--speed` se refiere al baudrate con el que fue configurado el módulo uart
* `--kernel` se refiere a la imagen del firmware a cargar en el lugar especificado
* `--kernel-adr` se refiere a la dirección de memoria donde deberá escribir el firmware que
  debe coincidir con la dirección indicada en el bios para que después de escrito el firmware
  el procesador salte a esa dirección para cargar el nuevo firmware.

## Referencias

[LiteX SoC builder (litex)](https://docs.zephyrproject.org/latest/reference/devicetree/bindings.html#litex-soc-builder-litex)


