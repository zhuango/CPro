ifneq ($(KERNELRELEASE),)

obj-m :=hello.o

else
KDIR:= /lib/modules/2.6.32-279.9.1.el6.x86_64/build

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers

endif
