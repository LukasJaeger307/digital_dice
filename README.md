# digital_dice

## Prerequisites
If you are into board games and microcontrollers, this project helps you create a digital dice.
You need the following hardware parts:

- A Texas Instruments G-series LaunchPad
- An MSP430-G2553 microcontroller with 20 pins suiting the LaunchPad
- A Kingbright SC39-11GWA 7-segment LED-display
- Eight protective resistors (about 10 kiloohms or whatever you have lying around)
- Jumper cables and a breadboard

You also need to install the following software:

- msp430-gcc
- msp430-binutils
- mspdebug
- make
- git
- Doxygen (If you want nice documentation, but who doesn't?)

If you use a Debian-based linux like Debian itself, Ubuntu or Linux Mint you are a very smart and handsome
person and you can easily install all of that with one bash-command:

```sh
sudo apt install gcc-msp430 binutils-msp430 mspdebug make git doxygen
```

If you don't use a Debian-based linux, I can't guarantee that you find all that software in your
repositories. I think Opensuse provides that stuff in its Build Service. But that's all I can
tell you. But as a Linux user you are still smart and handsome.
If you use Windows or MacOS, I have absolutely no idea what you need to install. Sorry...
