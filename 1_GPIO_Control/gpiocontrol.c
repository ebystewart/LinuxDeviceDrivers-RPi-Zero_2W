#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>


static struct gpio_desc *led, *button;

#define IO_LED 535
#define IO_BUTTON 536

#define IO_OFFSET 0

int __init initModule(void){
	
	int status;

	printk("Initializing kernel module\n");
	led = gpio_to_desc(IO_LED + IO_OFFSET);
	if(!led){
		printk("gpioctrl - Error getting pin 23");
		return -ENODEV;
	}       
      	button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
	 if(!button){
		 printk("gpioctrl - Error getting pin 24");
		 return -ENODEV;
 	}

	status = gpiod_direction_output(led, 0); /* 0 is init value for led */
	if(status){
		printk("gpioctrl - Error getting gpio 23 to output");
		return status;
	}
	
	status = gpiod_direction_input(button);
	if(status){
		printk("gpioctrl - Error setting pin 24 to input");
		return status;
	}

	gpiod_set_value(led, 1);

	printk("gpioctrl - Button is %spressed\n", gpiod_get_value(button)? "" : "Not ");

	return 0;
}

void __exit exitModule(void){

	gpiod_set_value(led, 0);
	printk("De-initializing kernel module, Good Bye!!\n");
}





module_init(initModule);
module_exit(exitModule);

MODULE_AUTHOR("STEWART");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple Gpio driver demo");
