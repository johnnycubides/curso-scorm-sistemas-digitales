#!/bin/sh
# sh program.sh file.svf
# openocd -f esp8266-remote_bitbang.cfg -c "init; scan_chain; svf -tap lfe5u25.tap -quiet -progress $1; shutdown; quit"
# openocd --debug -f ft232r.cfg -c "init; scan_chain; svf -tap lfe5u25.tap -quiet -progress $1; shutdown; quit"
# openocd -f ./ft232r.cfg -c "init; scan_chain; svf -tap lfe5u25.tap -quiet -progress $1; shutdown; quit"

# uso de script
# program-ft232r file.svf directorio_de_archivo_de_configuración_ft232

if [ "$2" = "" ];
then
  $2 = .
else
  openocd -f $2/ft232r.cfg  -c "init; scan_chain; svf -tap lfe5u25.tap -quiet -progress $1; shutdown; quit"
fi

