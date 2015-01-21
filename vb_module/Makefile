ARCHA := arm
KDIR := /root/linux-sunxi
PWD := $(shell pwd)
EXTRA_CFLAGS := -I$(KDIR)/drivers/media/video/sun4i_csi/include
CC := gcc



obj-m := adv7611.o sun4i_csi1.o
sun4i_csi1-objs := sun4i_csi_reg.o sun4i_drv_csi.o



default: tools 
	make ARCH=$(ARCHA) CROSS_COMPILE=$(CROSS) -C $(KDIR) M=$(PWD) modules


v4l2-capture: v4l2-capture.c 
	$(CROSS)$(CC) $(CFLAGS) -o v4l2-capture v4l2-capture.c

nv16toyuv_packed: nv16toyuv_packed.c	
	$(CROSS)$(CC) $(CFLAGS) -o nv16toyuv_packed nv16toyuv_packed.c

nv16toyuv_planar: nv16toyuv_planar.c	
	$(CROSS)$(CC) $(CFLAGS) -o nv16toyuv_planar nv16toyuv_planar.c

tools: v4l2-capture nv16toyuv_packed nv16toyuv_planar


clean:
	make -C $(KDIR) M=$(PWD) clean
	rm v4l2-capture nv16toyuv_packed nv16toyuv_planar
