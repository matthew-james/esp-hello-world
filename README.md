# esp-hello-world
hello world for the esp8266, using esp-vagrant + esp-open-sdk

# Usage

* Get setup with [esp-vagrant](https://github.com/matthew-james/esp-vagrant), or your build environment of choice.

* Checkout this repo

````bash
cd /home/vagrant/user_data
git clone git@github.com:matthew-james/esp-hello-world.git 
````

* Build and burn the firmware

````bash
make && make flash
````

* connect to the serial port

````bash
esp-console 9600
````

## Credits

The Makefile is based on [https://github.com/esp8266/source-code-examples](https://github.com/esp8266/source-code-examples).  user_main.c is based on [Matt Callow's code here](https://github.com/mattcallow/esp8266-sdk/blob/master/apps/03hellowworld/user/user_main.c).
