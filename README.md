The PyCorder
============

A credit-card-sized, SAMD51-based gadget for sensing, storing and showing data.

[PCB](https://oshpark.com/shared_projects/LN7RGg9E) | [BOM](https://octopart.com/bom-tool/ggGZZjZ3) | [UPDATES](https://twitter.com/josecastillo)

Features
--------

* A distinctly crisp and impressively low power 240x400 Sharp Memory Display
* A SAMD51G19 microcontroller, with plenty of room for [CircuitPython](https://circuitpython.org/)!
* 4 megabyte QSPI Flash; plenty of space for code, fonts and images
* Two buttons and a five-way joystick for user input
* Built-in battery charging, and room for a [350 mAh battery](https://www.adafruit.com/product/4237)
* One STEMMA port with current limiting and voltage protection
* One STEMMA-QT port for plugging in [STEMMA-QT compatible boards](https://www.adafruit.com/category/1018)
* One 9-pin connector, compatible with a veritable menagerie of [Sensor Cap](https://github.com/joeycastillo/Sensor-Cap/tree/main/PCB/Sensor%20Boards) sensor boards
* Enable switch for cutting power to the device
* One amber LED for charge state and one red LED for general purpose blinking

![image](/images/board.png)

Building your own PyCorder
--------------------------

You will need to [order the PCB's from someplace like OSH Park](https://oshpark.com/shared_projects/LN7RGg9E) (I recommend getting it in After Dark), and purchase all the parts on the [PyCorder Bill of Materials](https://octopart.com/bom-tool/ggGZZjZ3).

The board is hand-solderable, but a word of warning: **this is a relatively advanced build**. Almost all of the passive components are 0603 in size, which is at the limit of hand-solderability for many folks. A fine-tipped soldering iron is a must.

Pin definitions
---------------

Unlike a Metro or even a Feather, the PyCorder doesn't have a whole heap of GPIO pins. Having said that, I made sure to choose the pins with the most diverse set of features, opening the door to a whole lot of possibilities.

The **STEMMA port** is arguably one of the most powerful pins on the microcontroller. You can use it as a 10-bit true analog output, analog input, digital in/out or PWM. Access it in CircuitPython as `board.STEMMA`.

The **STEMMA-QT port** gives access to the board's I²C pins. Get at the I²C bus with `board.I2C()`, or the pins with `board.SDA` / `board.SCL`.

The **9-pin connector** can be used in a lot of different ways. From the top of the connector (which is pin 9):

* Pin 9, or `board.A0`, is the SAMD51's other DAC channel. Use this as an analog output, analog input or digital in/out.
* Pins 8 and 7 are the same I²C pins as the STEMMA-QT port; all I²C devices share the `board.I2C()` bus.
* Pin 6 has two names: `board.A1` and `board.SCK`. It can act as an analog input, PWM or digital in/out. In addition, it can act as the SCK pin for an SPI device on the other end of the 9-pin cable.
* Pin 5 (`board.A2` / `board.MOSI`) can act as an analog input, PWM, digital in/out, and the Main Out / Secondary In for an SPI device.
* Pin 4 (`board.D0` / `board.CS`) cannot support analog input, but you do get PWM and digital in/out. Can act as chip select for an SPI device.
* Pin 3 (`board.D1` / `board.MISO`) is PWM or digital in/out. Can act as the Main In / Secondary Out for an SPI device.
* Pin 2 is ground. 
* Pin 1 is a regulated 3.3 volt output from the on-board regulator.

The board has a **dual-output votage regulator** that can gate power to these three ports separately from the rest of the device. The enable pin for the main regulator output is, of course, tied to the on/off switch and pulled up by default. The second enable pin is tied to CircuitPython's `board.EN2`, and it is *pulled down by default*. This means that to power any device plugged in to these ports, you must do something like this first: 

```
en2 = DigitalInOut(board.EN2)
en2.switch_to_output()
en2.value = True
```

The LED is accessible at `board.LED`; you can output a digital signal to turn it on and off, or fade it with PWM.

Finally: the button inputs. These are easy: they're all active low and tied directly to pins on the SAMD51 (so you should enable internal pull-up resistors to use them). The rundown: 

* The button on the left side of the board is `board.PREVIOUS`
* The button on the right side is `board.NEXT`
* The four cardinal directions of the joystick map to `board.UP`, `board.DOWN`, `board.LEFT`, and `board.RIGHT`.
* You can press in on the joystick as a 'select' type action; detect this action on the `board.CENTER` pin.

Burning the bootloader
----------------------

You will burn the bootloader over the SWD interface. These pins are available as exposed test points on the right side of the back of the board. To connect to them, you can solder directly to the pads, or use pogo pins; they are 0.1 inch pitch, so you can make a compatible cable using [a 5x1 wire housing](https://www.adafruit.com/product/3145), [raw jumper wires](https://www.adafruit.com/product/3633) and [some pogo pins](https://www.adafruit.com/product/2429).

For convenience, a prebuilt bootloader is available in this repository. You can burn it bootloader using any SWD debugging tool like a J-Link or Atmel-ICE, but you can also use an Adafruit Trinket or PyRuler and the [Adafruit_DAP](https://github.com/adafruit/Adafruit_DAP) library.

You can also build the bootloader from scratch by copying the `bootloader/pycorder_m4` directory to the `boards` directory of [uf2-samdx1](https://github.com/adafruit/uf2-samdx1) and typing `make BOARD=pycorder_m4`.

CircuitPython on the PyCorder
-----------------------------

A CircuitPython UF2 is not included in this repository, because it's probably better to build your own with the latest greatest features. To get set up, follow the instructions in [Adafruit's guide to building CircuitPython](https://learn.adafruit.com/building-circuitpython?view=all); then copy the `circuitpython/pycorder_m4` directory to the CircuitPython repository's `ports/atmel-samd/boards` directory. 

Navigate to the `ports/atmel-samd` folder in your terminal and type `make BOARD=pycorder_m4`. This will generate a UF2 that you can drag to the PYCOBOOT drive.

Note that the CircuitPython build does not currently enable the display by default. You will have to paste some code like this at the beginning of your `code.py` to get the display working:

```
import busio
import framebufferio
import sharpdisplay
displayio.release_displays()
bus = busio.SPI(board.DISPLAY_CLOCK, MOSI=board.DISPLAY_DATA)
framebuffer = sharpdisplay.SharpMemoryFramebuffer(bus, board.DISPLAY_CS, 400, 240)
display = framebufferio.FramebufferDisplay(framebuffer, auto_refresh = True, rotation=270)
```

At this point you can add `display.show(None)` to display the CircuitPython console, or if you wish to show a displayio Group, `display.show(your_group)`.

Two final notes on the display: first, per the data sheet, the display requires a constant ~1Hz pulse on its EXTCOMIN pin. This reverses the polarity of the LCD, and is necessary for the display's long term stability. The CircuitPython board definition sets this pulse up as a PWM in its `board_init` function. If you wanted to do something like an Arduino core for it, you would be responsible for zatzing the display roughly once a second. EXTCOMIN is tied to the SAMD51's pin PA01, and the TC2 peripheral is ideal for generating this signal.

Second: the display only turns on when its DISP pin is pulled high, but the PyCorder connects it via a pull-down resistor so that the display defaults to an off state. This is intentional: the goal is to prevent the screen from turning on in the absence of the EXTCOMIN signal and degrading. DISP is tied to the SAMD51's pin PA00, and the `board_init` function pulls it high right after setting up the 1Hz pulse. This means that as long as the board is running, the screen will be on and the EXTCOMIN signal will be going to the screen.

Schematics and resources
------------------------

TODO