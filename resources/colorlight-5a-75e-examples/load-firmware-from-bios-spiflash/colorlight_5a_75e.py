#!/usr/bin/env python3

from litex.build.generic_platform import IOStandard, Subsignal, Pins
from migen.build.generic_platform import Misc
from migen.genlib.io import CRG
from migen.fhdl.structure import Cat
from litex.build.lattice import LatticePlatform
from litex.soc.integration.soc_core import SoCCore
from litex.soc.integration.soc import SoCRegion
from litex.soc.cores.uart import UARTWishboneBridge
from gateware.ios import Led
from litex.soc.integration.builder import Builder

from litex.soc.cores.clock import ECP5PLL
from migen.genlib.resetsync import AsyncResetSynchronizer
from litex.soc.cores.spi_flash import ECP5SPIFlash, SpiFlash, SpiFlashDualQuad

from litespi.phy.generic import LiteSPIPHY
from litespi.modules.generated_modules import W25Q32JV
from litespi.opcodes import SpiNorFlashOpCodes as Codes
from litespi import LiteSPI

from migen.fhdl.module import Module
from litex.soc.cores.clock import ClockDomain
# IOs ------------------------------------------------------------------------


_io_v7_1 = [  # Documented by @miek
    # clock
    ("clk25", 0, Pins("P6"), IOStandard("LVCMOS33")),
    # led
    ("user_led_n", 0, Pins("P11"), IOStandard("LVCMOS33")),
    # btn
    ("user_btn_n", 0, Pins("M13"), IOStandard("LVCMOS33")),
    # serial
    ("serial", 0,
        Subsignal("tx", Pins("F3")),  # J1.1
        Subsignal("rx", Pins("F1")),  # J1.2
        IOStandard("LVCMOS33")),
    ("serial", 1,
        Subsignal("tx", Pins("G2")),  # J1.5
        Subsignal("rx", Pins("H3")),  # J1.6
        IOStandard("LVCMOS33")),
    # spiflash (W25Q32JV)
    ("spiflash", 0,
        # clk
        Subsignal("cs_n", Pins("N8")),
        # Subsignal("clk",  Pins("")), driven through USRMCLK
        Subsignal("mosi", Pins("T8")),
        Subsignal("miso", Pins("T7")),
        IOStandard("LVCMOS33")),
    ("spiflash4x", 0,  # clock needs to be accessed through USRMCLK
        Subsignal("cs_n", Pins("N8"), IOStandard("LVCMOS33")),
        Subsignal("dq",   Pins("T8 T7   "), IOStandard("LVCMOS33")),),
    # sdram (M12616161A)
    ("sdram_clock", 0, Pins("C6"), IOStandard("LVCMOS33")),
    ("sdram", 0,
        Subsignal("a", Pins(
            "A9 E10 B12 D13 C12 D11 D10 E9",
            "D9 B7 C8")),
        Subsignal("dq", Pins(
            "B13 C11 C10 A11 C9 E8  B6  B9",
            "A6  B5  A5  B4  B3 C3  A2  B2",
            "E2  D3  A4  E4  D4 C4  E5  D5",
            "E6  D6  D8  A8  B8 B10 B11 E11")),
        Subsignal("we_n",  Pins("C7")),
        Subsignal("ras_n", Pins("D7")),
        Subsignal("cas_n", Pins("E7")),
        # Subsignal("cs_n", Pins("")), # gnd
        # Subsignal("cke",  Pins("")), # 3v3
        Subsignal("ba",    Pins("A7")),
        # Subsignal("dm",   Pins("")), # gnd
        IOStandard("LVCMOS33"),
        Misc("SLEWRATE=FAST")),
    # ethernet (B50612D)
    ("eth_clocks", 0,
        Subsignal("tx", Pins("M2")),
        Subsignal("rx", Pins("M1")),
        IOStandard("LVCMOS33")),
    ("eth", 0,
        Subsignal("rst_n",   Pins("P5")),
        Subsignal("mdio",    Pins("T2")),
        Subsignal("mdc",     Pins("P3")),
        Subsignal("rx_ctl",  Pins("N6")),
        Subsignal("rx_data", Pins("N1 M5 N5 M6")),
        Subsignal("tx_ctl",  Pins("M3")),
        Subsignal("tx_data", Pins("L1 L3 P2 L4")),
        IOStandard("LVCMOS33")),
    ("eth_clocks", 1,
        Subsignal("tx", Pins("M12")),
        Subsignal("rx", Pins("M16")),
        IOStandard("LVCMOS33")),
    ("eth", 1,
        Subsignal("rst_n",   Pins("P5")),
        Subsignal("mdio",    Pins("T2")),
        Subsignal("mdc",     Pins("P3")),
        Subsignal("rx_ctl",  Pins("L15")),
        Subsignal("rx_data", Pins("P13 N13 P14 M15")),
        Subsignal("tx_ctl",  Pins("R15")),
        Subsignal("tx_data", Pins("T14 R12 R13 R14")),
        IOStandard("LVCMOS33")),
    ("usb", 0,
        Subsignal("d_p", Pins("M8")),
        Subsignal("d_n", Pins("R2")),
        Subsignal("pullup", Pins("P4")),
        IOStandard("LVCMOS33")),
    # Mis definiciones
    ("user_led", 0, Pins("P11"), IOStandard("LVCMOS33")),  # LED en la placa
    ("user_led", 1, Pins("G3"), IOStandard("LVCMOS33")),  # LED externo
]


_connectors_v7_1 = [
    ("j1", "F3  F1  G3  - G2  H3  H5  F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j2", "J4  K3  G1  - K4  C2  E3  F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j3", "H4  K5  P1  - R1  L5  F2  F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j4", "P4  R2  M8  - -   T6  R6  F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j5", "M11 N11 P12 - K15 N12 L16 F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j6", "K16 J15 J16 - J12 H15 G16 F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j7", "H13 J13 H12 - G14 H14 G15 F15 L2 K1 J5 K2 B16 J14 F12 -"),
    ("j8", "A15 F16 A14 - E13 B14 A13 F15 L2 K1 J5 K2 B16 J14 F12 -"),
]


class _CRG(Module):
    def __init__(self, platform, sys_clk_freq):
        self.clock_domains.cd_sys = ClockDomain()
        # Clk / Rst
        clk25 = platform.request("clk25")
        rst_n = platform.request("user_btn_n", 0)
        platform.add_period_constraint(clk25, 1e9/25e6)
        # PLL
        self.submodules.pll = pll = ECP5PLL()

        pll.register_clkin(clk25, 25e6)
        pll.create_clkout(self.cd_sys,    sys_clk_freq)
        self.specials += AsyncResetSynchronizer(
            self.cd_sys, ~pll.locked | ~rst_n)


class Platform(LatticePlatform):
    default_clk_name = "clk25"
    default_clk_period = 1e9/25e6

    def __init__(self):
        LatticePlatform.__init__(
            self,
            device="LFE5U-25F-6BG256C",
            io=_io_v7_1,
            connectors=_connectors_v7_1,
            toolchain="trellis")


platform = Platform()


class BaseSoC(SoCCore):
    # update_mem_map = {
    #     "csr": 0x82000000,
    #     "rom": 0x00000000,
    #     "sram": 0x10000000,
    #     "main_ram": 0x40000000,
    #     "spiflash": 0x20000000,
    #     "vexriscv_debug": 0xf00f0000}
    # SoCCore.mem_map.update(update_mem_map)
    # del SoCCore.mem_map["rom"]
    SoCCore.mem_map = {
        "sram":             0x10000000,  # (default shadow @0xa0000000)
        "main_ram":         0x40000000,
        "spiflash":         0x20000000,  # (default shadow @0xa0000000)
        "csr":              0xe0000000,  # (default shadow @0x60000000)
        "vexriscv_debug":   0xf00f0000,
    }

    def __init__(self, platform, **kwargs):
        sys_clk_freq = int(25e6)
        # clk_freq=25e6,
        # SoCCore init ------------------------------------------------------
        SoCCore.__init__(
            self, platform,
            cpu_type="vexriscv",
            cpu_variant="lite+debug",
            # cpu_variant="lite",
            clk_freq=sys_clk_freq,
            csr_data_width=32,
            ident="LiTex Johnny RiscV",
            ident_version=True,
            integrated_rom_size=0x8000,
            # integrated_rom_size=0x0,
            # cpu_reset_address=self.mem_map["spiflash"] + 0x300000,
            uart_name="crossover",
            integrated_main_ram_size=0x4000)

        # CRG Clock Reset Generation ----------------------------------------
        self.submodules.crg = CRG(
            platform.request("clk25"),
            ~platform.request("user_btn_n"))
        # CRG
        # self.submodules.crg = _CRG(platform, sys_clk_freq)

        # SPIFlash ---------------------------------------------------------
        # self.submodules.spiflash_phy = LiteSPIPHY(
        #     platform.request("spiflash", 0),
        #     W25Q32JV(Codes.READ_1_1_1))
        # self.submodules.spiflash_mmap = LiteSPI(
        #     phy=self.spiflash_phy,
        #     clk_freq=sys_clk_freq,
        #     mmap_endianness=self.cpu.endianness)
        # self.add_csr("spiflash_mmap")
        # self.add_csr("spiflash_phy")
        # spiflash_size = 32*1024*1024  # 4Mbytes
        # spiflash_region = SoCRegion(
        #     origin=self.mem_map.get("spiflash", None),
        #     size=spiflash_size, cached=False)
        # self.bus.add_slave(
        #     name="spiflash",
        #     slave=self.spiflash_mmap.bus,
        #     region=spiflash_region)
        #
        # SPIFlash ---------------------------------------------------------
        # self.submodules.spiflash = ECP5SPIFlash(
        # spiflash_pads = ECP5SPIFlash(
        #     pads=platform.request("spiflash"),
        #     sys_clk_freq=sys_clk_freq,
        #     spi_clk_freq=5e6)
        # print(spiflash_pads.__dir__())
        # spiflash_size = 32*1024*1024
        # flash_offset = 0x300000
        #
        # SPIFlash ---------------------------------------------------------
        spiflash_size = 32*1024*1024
        flash_offset = 0x300000
        spiflash = SpiFlash(
            pads=platform.request("spiflash", 0),
            endianness=self.cpu.endianness)
        # print("endianness: ", self.cpu.endianness)
        spiflash.add_clk_primitive(self.platform.device)
        self.submodules.spiflash = spiflash
        self.register_mem(
            "spiflash", self.mem_map["spiflash"],
            self.spiflash.bus,
            size=spiflash_size)
        self.add_memory_region(
            "rom", self.mem_map["spiflash"] + flash_offset,
            spiflash_size - flash_offset, type="cached+linker")
        self.add_csr("spiflash")
        # self.add_constant("ROM_BOOT_ADDRESS", self.mem_map["spiflash"])
        self.add_constant(
            "ROM_BOOT_ADDRESS",
            self.mem_map["spiflash"] + flash_offset)
        # No CPU, use Serial to control Wishbone bus

        # Wishbone-UART bridge ----------------------------------------------
        self.submodules.serial_bridge = UARTWishboneBridge(
             platform.request("serial", 1),
             sys_clk_freq)
        self.add_wb_master(self.serial_bridge.wishbone)

        # CPU DBG ----------------------------------------------------------
        self.register_mem(
            "vexriscv_debug",
            0xf00f0000,
            self.cpu.debug_bus,
            0x10)

        # LEDs -------------------------------------------------------------
        user_leds = Cat(*[platform.request("user_led", i) for i in range(2)])
        self.submodules.leds = Led(user_leds)
        self.add_csr("leds")


soc = BaseSoC(platform)
# if hasattr(soc, "spiflash"):
#     # soc.add_constant("FLASH_BOOT_ADDRESS", soc.mem_map["spiflash"])
#     flash_offset = 0x300000
#     soc.add_constant(
#         "FLASH_BOOT_ADDRESS", soc.mem_map["spiflash"]+flash_offset)
builder = Builder(soc, output_dir="build", csr_csv="test/csr.csv")
builder.build()
