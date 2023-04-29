## How to build

1. Check out this repository.

    ```console
    $ git clone https://github.com/mentako-ya/mtk.git mtk
    ```

2. Check out [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/) repository in another place.

    ```console
    $ git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules -b 0.16.3 qmk
    ```

    Currently mtk firmwares are verified to compile with QMK 0.16.3

3. Create a symbolic link to this `mtk/` directory from [qmk/qmk_firmware]'s `keyboards/` directory.

    ```console
    $ ls
    mtk/ qmk/

    $ cd qmk/keyboards
    $ ln -s ../../mtk/qmk_firmware/keyboards/mtk mtk
    $ ls mtk/
    drivers/  mtk/  lib/  readme.md
    $ cd ..
    ```

4. `make` your mtk via firmwares.

    ```console
    $ make -j8 SKIP_GIT=yes mtk/mtk64e:via:flash
    ```
    
    Or build and flash firmware.
    ```console
    $ cd ~/git/qmk_firmware
    $ qmk clean -a
    $ qmk flash -kb mtk/mtk64e -km via
    Ψ Compiling keymap with gmake --jobs=1 mtk/mtk64e:via:flash
    ~
    Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)..........
    ```
    Press the reset switch twice. then start flash firmware.
   

