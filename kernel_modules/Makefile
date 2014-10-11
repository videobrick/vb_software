ARCHA := arm
CROSS := arm-linux-gnueabihf-
obj-m := hello_world.o
KDIR := /home/f15h/SourceCode/linux-sunxi
PWD := $(shell pwd)
default:
	make ARCH=$(ARCHA) CROSS_COMPILE=$(CROSS) -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
