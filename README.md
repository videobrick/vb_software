software
========

How to setup the Allwinner A10 Pins
===================================



How to compile VideoBrick-Modules
=================================

1. Get Cross compiler and tools
-------------------------------

First update apt-get links by typing

$ sudo apt-get update

Install the toolchain by typing the following.

$ sudo apt-get install gcc-4.7-arm-linux-gnueabihf ncurses-dev uboot-mkimage build-essential git

2. Get linux-sunxi Kernel Tree
------------------------------

You can download the kernel sources using the following command:

$ git clone https://github.com/linux-sunxi/linux-sunxi

Copy default Config for Olimex LIME A10

$ cp a10_defconfig/a10lime_defconfig [LINUXSUNXI-DIR]/arch/arm/configs/
 
and make:

$ make ARCH=arm a10lime_defconfig

3. Compile VideoBrick Modules
-----------------------------

adjust the KDIR in the Makefile to point to the linux-sunxi Kernel tree

and make:

$ make

you will get adv7611.ko and sun4i_csi1.ko which need to be transfered to the Target


How to build Cedar H.264 gstreamer Plugins
========================================== 
