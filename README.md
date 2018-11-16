# mROS_stm
mROS library for STM32 family

## Target Boards

- [STM32F767 Nucleo-144](https://www.st.com/content/st_com/ja/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-f767zi.html)

## Development Platform and Tools for Host PC

- IDE: [Atollic TrueSTUDIO for STM32](https://atollic.com/truestudio/)
  - Windows 10 Pro
  - Ubuntu 16.04.5
    - Currently we check only ver.9.0.1
- CUI
  - macOS High Sierra 10.13.6 / arm-none-eabi version 5.4.1 20160609
  - Ubuntu 16.04.5 / gcc-arm-none-eabi version 4.9.3 20150529

Please let us know if you could develop build anothoer host OS.

## Tools & SW components

- [TOPPERS/ASP kernel](http://toppers.jp/asp-d-download.html)
  - asp-1.9.3.tar.gz
  - asp_arch_arm_m7_gcc-1.9.3.tar.gz
- [STM32CubeF7](https://www.st.com/content/st_com/ja/products/embedded-software/mcus-embedded-software/stm32-embedded-software/stm32cube-mcu-packages/stm32cubef7.html)
- [TOPPERS configurator](http://toppers.jp/cfg-download.html)
  - (for Win) cfg-mingw-static-1_9_6.zip
    - Unzip the archive and locate to asp/cfg-mingw-static-1_9_6/cfg.exe
  - (for Linux) cfg-linux-static-1_9_6.gz
    - Unzip the archive and locate asp/cfg-linux-static-1_9_6/cfg
    - $ sudo apt install libstdc++6 lib32stdc++6
  - (for macOS) cfg-osx-static-1_9_5.gz
    - Unzip the archive and locate asp/cfg-macosx-static-1_9_5/cfg

## Build

- For TrueSTUDIO
  - Specify and open `workspace` as workspace
  - Import `workspace/*` such as `asp_sample1/`
  - Describe `#USE_TRUESTUDIO = true` on Makefile
  - You can bulid and debug these projects
- For CUI
  - cd to project dir such as `workspace/asp_sample1/`
  - Comment-out `#USE_TRUESTUDIO = true` or describe `#USE_TRUESTUDIO = false` on Makefile
  - `$ make` or `$ make depend && make`

