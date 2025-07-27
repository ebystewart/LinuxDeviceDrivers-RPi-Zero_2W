# LinuxDeviceDrivers-RPi-Zero_2W
Linux Device drivers for Raspberry Pi 2W





Commands:
gpioinfo               : prints information about the lines of the GPIO chips
cat /sys/kernel/debug/gpio  : displays a list of derived GPIO numbers, which kernel/gpio framework identifies
ls /sys/class/gpio          : filesystem ABI (Application Binary Interface) for controlling GPIOs
echo 535 > export           : create a new folder named gpio535 (GPIO 23)
cd gpio535
echo out > direction        : sets the direction of gpio535 to out
echo 1 > value              : sets the value of gpio535 to 1
echo 535 > unexport         : removes the gpio535 folder
