# Vexriscv y sdram

```bash
make g
make f
make flash-ft232
make litex_term
make litex_term SERIAL=/dev/ttyUSB1
```

Zephyr

```bash
~/gitPackages/litex/litex/litex/tools/litex_json2dts.py test/csr.json > riscv32-litex-vexriscv-johnny.dtsi
cp -i riscv32-litex-vexriscv-johnny.dtsi ~/zephyrproject/zephyr/dts/riscv/
```

## TODO

* Documentar
* Boton de reset no es funcional en éste ejemplo
* El Makefile del firmware requiere ser corregido el TARGET
* [Issue resuelto dado en sys_rst duplicado](https://github.com/enjoy-digital/colorlite/commit/b52aa387910a50932ddb29325eb16e1ab3c598b6)

## Referencias

[colorlite](https://github.com/enjoy-digital/colorlite)

