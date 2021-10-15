#!/bin/bash -e
#						 ↑
# debug [-x -v]:[complete, abbreviated]
# Brief:	agregar variables de entorno para proyecto con zephyr
# Author: Johnny Cubides
# e-mail: jgcubides@gmail.com
# date: Monday 21 September 2020
# source zephyr-env.sh
status=$?

export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR=~/zephyr-sdk-0.11.3
export ZEPHYR_BASE=~/zephyrproject/zephyr
