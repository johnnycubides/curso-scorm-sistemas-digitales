BAUD?=115200
SERIAL?=/dev/ttyUSB0
ADDRESS?=0x40000000

commands:
	@echo make config [cc]
	@echo make compile [c]
	@echo make litex_term [l]
	@echo make cache-rm-zephyr [r]

cc:config
c:compile
l:litex_term
r:cache-rm-zephyr

config:
	rm -rf build
	cmake -B build -DBOARD=litex_vexriscv \
	-DDTC_OVERLAY_FILE=./boards/litex_vexriscv_dts.overlay ./

compile:
	make -C build/ -f Makefile all

litex_term: build/zephyr/zephyr.bin
	@echo "Para salir oprime ctrl+cbc (sin soltar el ctrl)"
	litex_term $(SERIAL) --kernel build/zephyr/zephyr.bin \
		--kernel-adr $(ADDRESS) \
		--speed $(BAUD)

export-vars-zephyr:
	@echo "Exportando variables de entorno"
	. ./zephyr-env.sh

cache-rm-zephyr:
	rm -rf ~/.cache/zephyr/
