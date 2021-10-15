# Brief:	Makefile para crear proyectos con litex, riscv32 en placas ecp5
# Author: Johnny Cubides
# e-mail: jgcubidesc@gmail.com
# date: Friday 15 May 2020

TARGET?=__main__
TOP=top
GATEWARE?=colorlight_5a_75e
GATE_DIR?=build/gateware
SOFT_DIR?=build/software
OPENFPGALOADER_BOARD?=colorlight-ft232rl
# TOOLS_DIR=../tools
TOOLS_DIR?=./
TERM=picocom# minicom

# ARGS=--revision=7.1 --uart-name=crossover --with-etherbone --csr-csv=test/csr.csv --build
ARGS=--revision=7.1 --csr-csv=test/csr.csv --build
# Poner la dirección del puerto serial que está usando
# o agregarlo en la línea de comandos ejemplo: make SERIAL=/dev/ttyUSB0x
SERIAL?=/dev/ttyUSB0

# Poner la dirección ip de la omega2 para poder conectarse a ella desde ssh
# o agregarlo en la línea de comandos ejemplo: make IP=x.x.x.x
IP_OMEGA?=192.168.3.1

# Poner el directorio destino de la omega2 para subir el bitstream, el lugar ideal es aquel donde tenga el script program.sh
# o agregarlo en la línea de comandos ejemplo: make IP=/root/
PATH_DEST?=/root/

NEXTPNR=nextpnr-ecp5
CC?=riscv32-unknown-elf-gcc

all: ${GATE_DIR}/${TARGET}-flash.svf firmware

${GATE_DIR}/${TARGET}.bit:
	@yosys -V || (echo "\nNo se puede encontrar yosys, si está usando conda active en ésta terminal el entorno donde se instaló las herramientas, ejemplo:\n\n\
	conda activate fpga \n\n\
	para más información visite la siguiente url:"; exit 123;)
	@${NEXTPNR} -V || (echo "\nNo se puede encontrar ${NEXTPNR}, si está usando conda active en ésta terminal el entorno donde se instaló las herramientas, ejemplo:\n\n\
	conda activate fpga \n\n\
	para más información visite la siguiente url:"; exit 123;)
	./${GATEWARE}.py ${ARGS}

gateware: ${GATE_DIR}/${TARGET}-flash.svf

${SOFT_DIR}/common.mak: gateware

firmware: ${SOFT_DIR}/common.mak
	@${CC} -v || (echo "\nNo se puede encontrar el compilador de ${CC}, si está usando conda active en ésta terminal el entorno donde se instaló las herramientas, ejemplo:\n\n\
	conda activate fpga \n\n\
	para más información visite la siguiente url:"; exit 123;)
	$(MAKE) -C firmware/ -f Makefile all


${GATE_DIR}/${TARGET}-flash.svf : ${GATE_DIR}/${TARGET}.bit
	${TOOLS_DIR}/bit_to_flash.py ${GATE_DIR}/$(TARGET).bit ${GATE_DIR}/${TARGET}-flash.svf

litex_term: firmware
	@ls ${SERIAL} || (echo "\n\nNo se encuentra ${SERIAL} conectado, verifique conexión o cambie el valor de SERIAL=${SERIAL} por un puerto serial existente\n\n"; exit 123;)
	litex_term ${SERIAL} --kernel firmware/firmware.bin

serial:
	@ls ${SERIAL} || (echo "\n\nNo se encuentra ${SERIAL} conectado, verifique conexión o cambie el valor de SERIAL=${SERIAL} por un puerto serial existente\n\n"; exit 123;)
ifeq ($(TERM), picocom)
	picocom ${SERIAL} -b 115200
else ifeq ($(TERM), minicom)
	minicom -o -b 115200 -D ${SERIAL}
endif

# prog FPGA FLASH from omega2
flash-o2: ${GATE_DIR}/${TARGET}-flash.svf
	@echo "Programar la FLASH de la FPGA desde la omega2"
	@echo "scp ${GATE_DIR}/${TARGET}-flash.svf root@${IP_OMEGA}:${PATH_DEST}"
	@scp ${GATE_DIR}/${TARGET}-flash.svf root@${IP_OMEGA}:${PATH_DEST} || (echo "No fue posible enviar ${TARGET}-flash.svf a la omega2"; exit 123;)
	@echo "Para programar la fpga puede abrir otra consola y en ella acceder por ssh a la omega2, ejemplo:\n\n\
	ssh root@${IP_OMEGA}\n\n\
	Cuando esté en la terminal de la omega2 puede ubicarse en el lugar donde se subió el archivo ${TARGET}-flash.svf el cual fue el directorio ${PATH_DEST} y desde allí programar \
	la fpga con el script de programación, ejemplo:\n\n\
	cd ${PATH_DEST}\n\
	sh program.sh ${TARGET}-flash.svf\n\n"

# prog FPGA ram from omega2
config-o2: ${GATE_DIR}/${TARGET}.svf
	@echo "Configurar la FPGA desde la omega2"
	@echo "scp ${GATE_DIR}/${TARGET}.svf root@${IP_OMEGA}:${PATH_DEST}"
	@scp ${GATE_DIR}/${TARGET}.svf root@${IP_OMEGA}:${PATH_DEST} || (echo "No fue posible enviar ${TARGET}.svf a la omega2"; exit 123;)
	@echo "Para programar la fpga puede abrir otra consola y en ella acceder por ssh a la omega2, ejemplo:\n\n\
	ssh root@${IP_OMEGA}\n\n\
	Cuando esté en la terminal de la omega2 puede ubicarse en el lugar donde se subió el archivo ${TARGET}.svf el cual fue el directorio ${PATH_DEST} y desde allí programar \
	la fpga con el script de programación, ejemplo:\n\n\
	cd ${PATH_DEST}\n\
	sh program.sh ${TARGET}.svf\n\n"

ERROR_FT232= "\nAsegurarse de tener conectado un adaptador ft232r y que los pines conrrespondientes a RX y TX estén desconectados\n"

# openFPGALoader
openFPGALoader-f: ${GATE_DIR}/${TARGET}.bit
	@openFPGALoader -b ${OPENFPGALOADER_BOARD} -f ${GATE_DIR}/${TARGET}.bit

openFPGALoader-m: ${GATE_DIR}/${TARGET}.bit
	@openFPGALoader -b ${OPENFPGALOADER_BOARD} -m ${GATE_DIR}/${TARGET}.bit

# Flashing from ft232
flash-ft232: ${GATE_DIR}/${TARGET}-flash.svf
	@${TOOLS_DIR}/program-ft232.sh ${GATE_DIR}/${TARGET}-flash.svf ${TOOLS_DIR} || (echo ${ERROR_FT232}; exit 123;)

# Config fpga from ft232
config-ft232: ${GATE_DIR}/${TARGET}.svf
	@${TOOLS_DIR}/program-ft232.sh ${GATE_DIR}/${TARGET}.svf ${TOOLS_DIR} || (echo ${ERROR_FT232}; exit 123;)

clean-gateware:
	rm -f ${GATE_DIR}/*.svf ${GATE_DIR}/*.bit ${GATE_DIR}/*.config ${GATE_DIR}/*.json ${GATE_DIR}/*.ys

clean-firmware:
	make -C firmware -f Makefile clean

clean: clean-gateware clean-firmware

g:gateware
cg:clean-gateware
f:firmware
cf:clean-firmware
c:clean

.PHONY: clean
