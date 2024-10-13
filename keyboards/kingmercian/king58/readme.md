# King 58
Custom split keyboard based on the lotus/lily58 using RP2040 controller.

### Building
Make example for this keyboard (after setting up your build environment):

    make kingmercian/king58/rp2040:kingmercian

### Bootloader
To enter the bootloader
* **Keycode in layout**: Press and hold the key mapped to `QK_BOOT`(see below) while applying power.
    * left side: Hold `ESC`
    * right side: Hold `~`


### Flashing
To flash, transfer the compiled .uf2 firmware onto the root of the RP2040 after entering bootloader mode.


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
