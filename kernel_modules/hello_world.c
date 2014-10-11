#include <linux/kernel.h> /* Needed for Macros*/
#include <linux/module.h> /* Needed for all kernel modules*/
#include <linux/init.h> 
#include <linux/version.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a my First Test Module...!");
MODULE_AUTHOR("GVK51");


static int __init my_start_init(void){

        printk(KERN_INFO "Hello World module loaded...!\n");
        return 0;
}

static void __exit my_remove_exit(void){

        printk(KERN_INFO "Hello World module Un-loaded...!\n");  

}

module_init(my_start_init);
module_exit(my_remove_exit);
