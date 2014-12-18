ARCHA := arm
CROSS := arm-linux-gnueabihf-
KDIR := /home/f15h/SourceCode/linux-sunxi
PWD := $(shell pwd)
EXTRA_CFLAGS := -I$(KDIR)/drivers/media/video/sun4i_csi/include


obj-m := adv7611.o sun4i_csi1.o
sun4i_csi1-objs := sun4i_csi_reg.o sun4i_drv_csi.o

default:
	make ARCH=$(ARCHA) CROSS_COMPILE=$(CROSS) -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
