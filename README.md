# digital_dice

## Prerequisites
If you are into board games and microcontrollers, this project helps you create a digital dice.
You need the following hardware parts:

- A Texas Instruments G-series [LaunchPad](http://www.ti.com/tool/MSP-EXP430G2)
- An [MSP430-G2553 microcontroller](http://www.ti.com/product/msp430g2553) with 20 pins suiting the LaunchPad
- A Kingbright SC39-11GWA 7-segment LED-display
- Eight protective resistors (about 10 kiloohms or whatever you have lying around)
- Jumper cables and a breadboard

You also need to install the following software:

- msp430-gcc
- msp430-binutils
- mspdebug
- make
- git
- doxygen (If you want nice documentation, but who doesn't?)

If you use a Debian-based linux like [Debian](https://debian.org) itself, [Ubuntu](https://ubuntu.com) or [Linux Mint](https://linuxmint.com) you are a very smart and handsome
person and you can easily install all of that with one bash-command:

```sh
sudo apt install gcc-msp430 binutils-msp430 mspdebug make git doxygen
```

If you don't use a Debian-based linux, I can't guarantee that you find all that software in your
repositories. I think provides that stuff in its Build Service. But that's all I can
tell you. But as a Linux user you are still smart and handsome.
If you use Windows or MacOS, please install Linux first and then follow the above steps. 
This will dramatically increase your smart- and handsomeness and will make the following steps way easier.

## Wiring up
Now that you got the prerequisites done, you can start wiring the 7-segment display with the LaunchPad.
Download the data sheet for the display [here] (http://www.kingbrightusa.com/images/catalog/SPEC/SC39-11GWA.pdf).
Now you can use the following table to connect the pins correctly. I used the pins of port 2 as much as possible
since in most projects they hang around uselessly anyway. If you need a different pinout, you need to adapt the
firmware. But I am getting off topic...here's the table:

|LaunchPad|Display|
|---------|-------|
|P 2.0    |1      |
|P 2.1    |2      |
|GND      |3      |
|P 2.2    |4      |
|P 2.3    |5      |
|P 2.4    |10     |
|P 2.5    |9      |
|P 1.6    |7      |

**DON'T FORGET PROTECTIVE RESISTORS!** That happened to me once and I don't want it to happen to you. I used the
10-kiloohms resistors I had lying around. Of course you don't need one for the GND but you better put one in for
every segment pin.

## Building and installing the software
I am a huge fan of command line tools and especially _make_. For that reason, every task you need to perform for
the installation has a _make_-target. You build the firmware with

```sh
make          # How incredibly surprising...
```

Before you install it, connect the LaunchPad via USB to your computer. Now execute

```sh
make install  # Installs the firmware on the MCU
```

to install the firmware on your MSP. You should see a zero on the display now. If you push the button, the
dice is "rolled". If you release it, you get the number you rolled.

## Creating the documentation
Building the documentation with _doxygen_ is also just calling a specific _make_-target:

```sh
make documentation  # Creates the documentation
```

It puts the output of _doxygen_ in the _doc_-folder.

## Schematics and PCB
Breadboards are not really suitable for board game nights. I intend to create schematics and a PCB-layout
and provide it as open hardware. Stay tuned if you are interested in that.
