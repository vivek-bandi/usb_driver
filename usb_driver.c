#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>

static struct usb_device *device;

static struct usb_device_id skel_table[] = 
{
    {USB_DEVICE(0X0951,0X1665)},
    {}
};

static int skel_probe(struct usb_interface *interface, const struct usb_device_id *id){
    struct usb_host_interface *iface_desc;
    struct usb_endpoint_descriptor *endpoint;
    int i;
    iface_desc = interface->cur_altsetting;
    printk(KERN_INFO "pendrive interface %d now probed : {%04X:%04X}\n",
           iface_desc->desc.bInterfaceNumber,
           id->idVendor,
           id->idProduct);

    printk(KERN_INFO "ID->bNumEndpoints: %02X", iface_desc->desc.bNumEndpoints);
    printk(KERN_INFO "ID->bInterfaceClass: %02X", iface_desc->desc.bInterfaceClass);

}

static int __init usb_skel_init(void){
    int result;
    printk(KERN_INFO "Module is Initialised\n");
    return 0;
}
module_init(usb_skel_init);

static void __exit usb_skel_exit(void){
    printk(KERN_INFO "Module is exited\n");
}
module_exit(usb_skel_exit);

MODULE_LICENSE("GPL"); // General Public License
MODULE_AUTHOR("Vivek");
MODULE_DESCRIPTION("usb driver project");