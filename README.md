# mROS_stm
mROS library for STM32 family

## Target Boards

- [STM32F767 Nucleo-144](https://www.st.com/content/st_com/ja/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-f767zi.html)

## Development Platform of Host PC

- Windows 10 Pro
- Ubuntu 16.04.5

Please let us know if you could develop build anothoer host OS.

## Tools & SW components

- [Atollic TrueSTUDIO for STM32](https://atollic.com/truestudio/)
  - Currently we check only ver.9.0.1
- [TOPPERS/ASP kernel](http://toppers.jp/asp-d-download.html)
  - asp-1.9.3.tar.gz
  - asp_arch_arm_m7_gcc-1.9.3.tar.gz
- [TOPPERS configurator](http://toppers.jp/cfg-download.html)
  - (for Win) cfg-mingw-static-1_9_6.zip
    - Unzip the archive and locate to asp/cfg-mingw-static-1_9_6/cfg.exe
  - (for Linux) cfg-linux-static-1_9_6.gz
    - Unzip the archive and locate asp/cfg-linux-static-1_9_6
    - $ sudo apt install libstdc++6 lib32stdc++6
- [STM32CubeF7](https://www.st.com/content/st_com/ja/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32cube-mcu-packages/stm32cubef7.html)
