#
#  ターゲットの指定（Makefile.targetで上書きされるのを防ぐため）
#
all:

#
#  アプリケーションファイル
#
APPLDIR = .
APPLNAME = stm32_sample
#USE_CXX = true
APPL_CFG = $(APPLNAME).cfg
USE_TRUESTUDIO = true

DEBUG = true
OMIT_OPTIMIZATION = true

#
#  toolchainのPATHを明示的に指定する場合
#  Windowsの場合はフルパスにする
#
#GCC_PATH_WIN = C:\Program Files (x86)\Atollic\TrueSTUDIO for STM32 9.0.1\ARMTools\bin

#
#  STM32Cubeライブラリのディレクトリの定義
#
STM32_LIB_DIR = ../../stm32cubef7

#
#  ASPソースファイルのディレクトリの定義
#
SRCDIR = ../../asp

#
#  STM32Cubeライブラリのビルド
#
INCLUDE_PATHS += -I./stm32_src
C_OBJ += stm32_src/system_stm32f7xx.o
include $(STM32_LIB_DIR)/Drivers/BSP/Makefile.bsp
include $(STM32_LIB_DIR)/Drivers/STM32F7xx_HAL_Driver/Makefile.hal
include $(STM32_LIB_DIR)/Drivers/CMSIS/Makefile.cms
include ../Makefile.stm

#
#  ASPカーネルライブラリ
#
KERNEL_LIB = .
include ../Makefile.asp

$(ALL_OBJ): kernel_cfg.h
