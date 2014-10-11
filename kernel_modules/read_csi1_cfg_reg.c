#include <linux/kernel.h> /* Needed for Macros*/
#include <linux/module.h> /* Needed for all kernel modules*/
#include <linux/init.h> 
#include <linux/version.h>
#include <linux/vmalloc.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <linux/clk.h>
#include <mach/clock.h>

#define CCM_BASE_ADDR  0x01C20000
#define CSI1_BASE_ADDR 0x01C1D000
#define TWI_STAT_REG 0x01C2B000

#define CSI1_CFG_REG 0x004
#define TWI_STAT_OFF 0x010
#define CCM_CSI1_CLK 0x138

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a my First Test Module...!");
MODULE_AUTHOR("GVK51");


static int csi1_enable_sys_clk(void)
{
	int     result;
	struct clk *clk;

	clk = clk_get(NULL, "ahb_csi1");
	result = clk_enable(clk);
	if(result) {
		return result;
	}

	clk = clk_get(NULL, "csi1");
	result = clk_enable(clk);


	return result;
}

static int __init my_start_init(void){
		int reg;
		void __iomem *io;

		csi1_enable_sys_clk();
/*        io = ioremap(CCM_BASE_ADDR, 256);
		iowrite32((1 << 31), io + CCM_CSI1_CLK);
		reg = ioread32(io + CCM_CSI1_CLK);
		printk(KERN_INFO "ccm_csi1_clk: 0x%08x!\n",reg);
        iounmap(io);
*/
		mdelay(500);

		io = ioremap(CSI1_BASE_ADDR, 256);

		if(io == NULL)
			printk(KERN_INFO "ioremap error!\n");
		else
			printk(KERN_INFO "ioremap ok!\n");

		iowrite32(0x1, io);

		mdelay(500);

        reg = ioread32(io);

        printk(KERN_INFO "Register = 0x%08x\n", reg);

		iounmap(io);

        return 0;
}

static void __exit my_remove_exit(void){
        printk(KERN_INFO "Module Un-loaded...!\n");  

}

module_init(my_start_init);
module_exit(my_remove_exit);
