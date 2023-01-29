## How to build

1. mtkのリポジトリをチェックアウト。ブランチは"blemicro"。

    ```console
    $ git clone -b blemicro https://github.com/mentako-ya/mtk.git mtk
    ```

2. BLE Micro Pro用のqmk_firmwareリポジトリをチェックアウト。qmk_firmware_bmp フォルダにクローン

    ```console
    $ git clone --depth 1 -b dev/ble_micro_pro https://github.com/sekigon-gonnoc/qmk_firmware.git qmk_firmware_bmp
    ```

3.  `mtk/`のシンボリックリンクを qmk_firmware_bmp/keybords/配下に作成

    ```console
    $ ls
    mtk/ qmk_firmware_bmp/

    $ cd qmk_firmware_bmp/keyboards
    $ ln -s ../../mtk/qmk_firmware/keyboards/mtk mtk
    $ ls mtk/
    drivers/  mtk/  lib/  readme.md
    $ cd ..
    ```

4. ファームウェアをビルド

    uf2ファイルを生成して書き込む場合（Windows?)
    ```console
    $ qmk claen -a
    $ make mtk/mtk64e:default:uf2
    ```
    → BleMicroをUSB接続し、外部メディア[BLEMICROPRO]にファームウェアを書き込む
 

    nrfutilで書き込む場合（Mac?)
    ```console
    $ cd ~/git/qmk_firmware_bmp
    $ qmk claen -a
    $ make mtk/mtk64e:default:nrfutil
    ~
    Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)..........
    ```
    接続待ち状態になったらBOOTピンとGNDピンをショートさせる、
    もしくは、cuコマンドでDFUモードに切り替える
    ```console
    $ ls /dev | grep usbmodem
    $ cu.usbmodem00000000000xx
    $ sudo cu -l cu.usbmodem00000000000xx

    ```
    
    'dfu'でDFUモードに切り替え
    ```console
    > dfu
    cu: Got hangup signalu

    Disconnected.

    ```
    一旦切断されたのち、dfuモードで再起動され、ファームウェアの書き込みがはじまる
