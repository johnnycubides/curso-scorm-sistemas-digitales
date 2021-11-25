#!/bin/bash -e
#						 ↑
# debug [-x -v]:[complete, abbreviated]
# Brief:	brief
# Author: Johnny Cubides
# e-mail: jgcubidesc@unal.edu.co
# date: Tuesday 14 September 2021
status=$?

declare -a lecciones
lecciones=(
introduccion
dominioMetodologia
zephyr
recursosHerramientas
soc
metodologiasDiseno
especificaciones
litexRiscVbaremetal
lm32
sistemasEmbebidos
)

if [ "$1" = "" ];
then
    echo "CREANDO TODAS LAS LECCIONES"
    for i in "${lecciones[@]}"
    do
        echo $i
        liaex -i $i/*.md --format scorm1.2 --output ./build-scorm1.2/$i
    done
else
    echo "CREANDO LA LECCIÓN $1"
    liaex -i $1/*.md --format scorm1.2 --output ./build-scorm1.2/$1
fi


