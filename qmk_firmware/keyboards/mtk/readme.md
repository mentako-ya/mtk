## How to build

1. [mtk](https://github.com/mentako-ya/mtk/)をチェックアウトします.

    ※ チェックアウト先 `~/git` は適宜変更

    ```console
    $ cd ~/git
    $ git clone https://github.com/mentako-ya/mtk.git mtk
    ```

2. [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/) より qmk_firmware ver.0.22.3 をチェックアウトします.

    ```console
    $ cd ~/git
    $ git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules -b 0.22.3 qmk_firmware
    ```

3. `qmk_firmware/keyboards/` フォルダに　`/mtk/qmk_firmware/keyboards/mtk` のシンボリックリンクを作成し、`qmk_firmware/keyboards/mtk` とします。

    ```console
    $ ls
    mtk/ qmk_firmware/

    $ cd qmk_firmware/keyboards
    $ ln -s ../../mtk/qmk_firmware/keyboards/mtk mtk
    $ ls mtk/
    drivers/  mtk/  lib/  readme.md
    ```

4. ファームウェアをビルドしてし、キーボードに書き込み(flash)します.

   - 右ボール左エンコーダーの場合
   
        [qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h](qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h) を確認します。
        ```c++
        // #### 自動マウスレイヤー切替有効化 ####
        #define AUTO_MOUSE_LAYER_ENABLE

        // #### エンコーダー設定 ####
        // 左エンコーダー有効 左ボール無効（デフォルト）
        #define ENCODER_LEFT_ENABLE
        // 右エンコーダー有効 右ボール無効
        //#define ENCODER_RIGHT_ENABEL

        // #### 両側ボール設定 ####
        //#undef ENCODER_ENABLE
        // slave側トラックボールをスクロール操作に使用する場合（デフォルト）
        //#define SLAVE_SCRL_DISABLE 0
        // slave側トラックボールをポインター操作に使用する場合
        //#define SLAVE_SCRL_DISABLE 1
        ```

     - make を使用する場合.
        ```console
        $ cd ~/git/qmk_firmware
        $ make -j8 SKIP_GIT=yes mtk/mtk64e:via:flash
        ```

     - qmk を使用する場合.　　　
        ```console
        $ cd ~/git/qmk_firmware
        $ qmk clean -a
        $ qmk flash -kb mtk/mtk64e -km via
        Ψ Compiling keymap with gmake --jobs=1 mtk/mtk64e:via:flash
        ~
        Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)..........
        ```
        ビルドが成功するとUSBシリアルポートの接続待ちになるので、接続したキーボードのリセットスッチを２回押下して書き込みを開始します。
        一方の書き込みが完了したら、再度flashを実行して反対のキーボードにも書き込みます。
    
    
   - 左ボール右エンコーダーの場合
   
        [qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h](qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h) を編集します。
        ```c++
        // #### 自動マウスレイヤー切替有効化 ####
        #define AUTO_MOUSE_LAYER_ENABLE

        // #### エンコーダー設定 ####
        // 左エンコーダー有効 左ボール無効（デフォルト）
        //#define ENCODER_LEFT_ENABLE
        // 右エンコーダー有効 右ボール無効
        #define ENCODER_RIGHT_ENABEL

        // #### 両側ボール設定 ####
        // #undef ENCODER_ENABLE
        // slave側トラックボールをスクロール操作に使用する場合（デフォルト）
        // #define SLAVE_SCRL_DISABLE 0
        // slave側トラックボールをポインター操作に使用する場合
        //#define SLAVE_SCRL_DISABLE 1
        ```
        右ボール左エンコーダーの場合と同じくビルドしてし、キーボードに書き込み(flash)します。
    
   - 両側ボールの場合
   
        [qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h](qmk_firmware/keyboards/mtk/mtk64e/keymaps/via/config.h) を編集します。
        ```c++
        // #### 自動マウスレイヤー切替有効化 ####
        #define AUTO_MOUSE_LAYER_ENABLE

        // #### エンコーダー設定 ####
        // 左エンコーダー有効 左ボール無効（デフォルト）
        #define ENCODER_LEFT_ENABLE
        // 右エンコーダー有効 右ボール無効
        //#define ENCODER_RIGHT_ENABEL

        // #### 両側ボール設定 ####
        #undef ENCODER_ENABLE
        // slave側トラックボールをスクロール操作に使用する場合（デフォルト）
        #define SLAVE_SCRL_DISABLE 0
        // slave側トラックボールをポインター操作に使用する場合
        //#define SLAVE_SCRL_DISABLE 1
        ```
        右ボール左エンコーダーの場合と同じくビルドしてし、キーボードに書き込み(flash)します。
    