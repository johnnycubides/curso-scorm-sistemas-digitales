#!/usr/bin/env python3

import time
from litex import RemoteClient

wb = RemoteClient()
wb.open()

print("Testing Led...")
for i in range(32):
    wb.regs.leds_out.write(i)
    time.sleep(1)
