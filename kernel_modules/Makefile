ARCHA := arm
obj-m := hello_world.o read_csi1_cfg_reg.o adv7611.o
KDIR := /root/linux-sunxi
PWD := $(shell pwd)
EXTRA_CFLAGS := -I$(KDIR)/drivers/media/video/sun4i_csi/include

default:
	make ARCH=$(ARCHA) CROSS_COMPILE=$(CROSS) -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
