# mtk

mtk is clone keybord with trackball.

- via、remap対応 ファームウェア  
   [mtk_mtk64_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64_via.hex)   rev1基板用　右ボール/左ボール/左右ボール用
   
   [mtk_mtk64e_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64e_via.hex) rev2基板用　左ロータリーエンコーダー、右ボール用
   
   [mtk_mtk64e_AutoMouseLayer_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64e_AutoMouseLayer_via.hex) rev2基板用　左ロータリーエンコーダー、右ボール用、自動マウスレイヤー切替
   
   [mtk_mtk64e_left_ball_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64e_left_ball_via.hex) rev2基板用　右ロータリーエンコーダー、左ボール用

- via、remap用 via.json

    [mtk64_rb_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_rb_via.json)     rev1 mtk64　右ボール用 
    
    [mtk64_db_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_db_via.json)  rev1 mtk64　左右ボール用 
    
    [mtk64e_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64e_via.json)      rev2 mtk64e　ロータリーエンコーダー＆ボール用 

- ご自身でファームウェアをカスタマイズ、ビルドする場合 

   [via firmware ビルドガイド](qmk_firmware/keyboards/mtk/)

## 更新情報

[takashicompanyさんの実装](https://zenn.dev/takashicompany/articles/69b87160cda4b9)を参考に、
トラックボール操作時に自動でマウスレイヤー2に切り替わる対応を追加しました。

[mtk_mtk64e_AutoMouseLayer_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64e_AutoMouseLayer_via.hex)

※容量の都合でこちらのファームウェアはLEDエフェクトを省略しています。（LEDのOn/Off、色と明るさ調整は可能、点滅やグラデーションは不可）
LEDエフェクトが必要な場合、従来のファームウェアをご利用ください。

通電直後のエンコーダー誤作動対応を追加しました。

バックプレートが透明アクリル製になりました。

バックプレート固定用の低頭6角穴付きボルトの付け外しには[T5サイズのレンチ](https://amzn.asia/d/b8Xeegc)を使用します。

メインの基板が黒色になりました。

親指のロープロファイルキーの向きを内向きに変更しました。
[MCC-profile POM Choc keycap](https://shop.yushakobo.jp/products/3694)のような、シリンドリカル（円柱状に凹んでいる形状）のキーを使用できます。

[MBK Choc Low-Profile Keycaps](https://shop.yushakobo.jp/products/mbk-choc-low-profile-keycaps)のような、スフィリカル（お椀状に凹んでいる形状）のキーでは手前側の角が親指に当たって痛くなってしまう方におすすめです。

## キーボードの接続

まず、動作確認のために、右左の各キーボードを単体でPCに接続し、キー入力が可能であること、OLEDにキーボードの情報が表示されることを確認してください。

（OLEDは一定時間操作しないと消灯します）

接続時にキー入力できない場合、OLEDに何も表示されない場合、ロゴが表示されていてキー情報（数値やコード）が表示されない場合は、OLEDの斜め下にあるリセットボタン（ボルトの頭）をプッシュするか、キーボードを接続し直してください。

動作しない場合は、プロマイクロのコンスルーが抜けかけている、回路がショートしていて起動できない（LEDの取り付け方向間違いでこの状態になることが多いです）などのハードウェアの問題か、ファームウェアが消えているなどのソフトウェアの問題が考えられます。

USB接続時にプロマイクロ裏側の赤いランプが点灯しているか、USB端子の隙間から確認してください。

赤いLEDが点灯していない場合、点灯してもすぐ消えてしまう場合ば、ハードウェアの問題です。

左右単体で動作確認できたら、TRSケーブルで左右を接続し、どちらか一方のUSB端子をPCに接続してください。

左右を繋ぐと動作しない場合、TRSケーブルが奥まできちんと刺さっていないか、TRSケーブルの断線、接触不良が考えられます。

TRSケーブルは、ケーブル付け根が本体のケースの中まで入り込む設計です。ねじ込むようにしてしっかり奥まで差し込んでください。


## キーマップ変更

キーマップの変更はChromeブラウザを使用して、https://remap-keys.app/　で変更します。

下記に本キーボードを使用する際に最低限必要な手順を記載します。

remapの一般的な使用方法はサリチル酸さんの記事などをご参照ください。

　https://salicylic-acid3.hatenablog.com/entry/remap-manual

1. [START REMAP FOR YOUR KEYBORD]　をクリック
<img width="500" src="mtk/remap_img/remap_1.png">

2. [+ KEYBORD]をクリック
<img width="500" src="mtk/remap_img/remap_2.png">

3. [mtk64] か。[mtk64e]を選択して接続.
<img width="250" src="mtk/remap_img/remap_3.png">

4. Jsonファイルのアップロードを求められるので、下記からレイアウトに合わせたjsonファイルをダウンロードして使用する
<img width="500" src="mtk/remap_img/remap_4.png">

- mtk64　右ボール用      [mtk64_rb_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_rb_via.json)
- mtk64　左右ボール用    [mtk64_db_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_db_via.json)
- mtk64e　ロータリーエンコーダー＆ボール用 [mtk64e_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64e_via.json)

5. キーマップの変更 / キーマップの書き込み（右上Flashボタン） /　変更したキーマップの保存　/　キーマップのPDFダウンロード　などが可能

右ボール　キーマップサンプル
- via keyleyout(right ball) [mtk64_rb_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_rb_via.json)
- sample keymap cheetsheet(right ball) [mtk64_rb_keymap_cheatsheet.pdf](mtk/mtk64_rb_keymap_cheatsheet.pdf)
<img width="1186" alt="remap_key_leyout" src="mtk/remap_img/mtk64_rb_keymap.png">

左右ボール　キーマップサンプル
- via keyleyout(double ball) [mtk64_db_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64_db_via.json)
- sample keymap cheetsheet(double ball) [mtk64_db_keymap_cheatsheet.pdf](mtk/mtk64_db_keymap_cheatsheet.pdf)
<img width="1186" alt="remap_key_leyout_double_ball" src="mtk/remap_img/mtk64_db_keymap.png">

ロータリーエンコーダー＆ボール　キーマップサンプル
- via keyleyout(rotary encoder) [mtk64e_via.json](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk64e_via.json)
- sample keymap cheetsheet(rotary encoder) [mtk64e_keymap_cheatsheet.pdf](mtk/mtk64e_keymap_cheatsheet.pdf)
- sample keymap cheetsheet(rotary encoder) [mtk64e_AutoMouseLayer_keymap_cheatsheet.pdf](mtk/mtk64e_AutoMouseLayer_keymap_cheatsheet.pdf)
<img width="1186" alt="remap_key_leyout_rotary_encoder" src="mtk/remap_img/mtk64e_keymap.png">

※ 製品出荷時点でキーボードに設定済みのマッピングは、ファームウェアのデフォルトキーマッピングとは一部異なります。

キーマップのリセットや、キーボードの初期化を行うと、キーマップはファームウェアのデフォルトキーマップにリセットされます。

キーマップ変更やリセットを行う前に、初期のマッピングの状態でマップの保存をお勧めします。

## ファームウェア更新
[Pro Micro Web Updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html) を使用してファームウェアを更新できます。

出荷時に書き込まれているファームウェアは[mtk_mtk64e_AutoMouseLayer_via.hex](https://raw.githubusercontent.com/mentako-ya/mtk/main/mtk/mtk_mtk64e_AutoMouseLayer_via.hex)になります。　

[Pro Micro Web Updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html) にアクセスし、事前にダウンロードしたファームウェアをアップロードします。

キーボードの左右どちらか一方をUSB接続し、画面上の[flash]ボタンを押下します。

シリアルポートへの接続要求のウインドウが表示されるので、OLED斜め下のリセットスイッチ（ボルトの頭）を２回連続でクリックします。

シリアルポートの一覧に「Pro Micro 5v」が表示されるので、選択して接続ボタンを押下します。

## 基本的な使用方法

本キーボードは、レイヤー０〜3の４種類のキーマップを切り替えて使用します。

レイヤーの切り替えは左手親指キーのHOLD（シフトキーのように押したままにすること）に割り当てられており、左端からLayer(1),Layer(2),Layer(3)が設定されています。

- レイヤー０:通常のアルファベット入力
- レイヤー１:Shiftキー押下相当（大文字入力や記号入力）
- レイヤー２:右手のキーがマウスのボタンに切り替わる
- レイヤー３:トラックボールがスクロールモードに切り替わる、キースイッチはLEDの調整、トラックボールの速度、スクロールの速度調整

自動マウスレイヤー切替に対応したファームウェアでは、トラックボールを一定距離動かすと自動的にレイヤー2に切り替わり、マウスボタンクリックが可能になります。
デフォルトでは１秒間何も操作しないとレイヤー0に戻ります。
自動マウスレイヤー切替機能がOnの場合、OLED３行目が反転表示されます。
（レイヤー３左側のキーボード最下段左から２番目のキーで自動切替機能On／Off）

## レイヤー３トラックボール設定のコード値
レイヤー３にマッピングされているキーのうち、トラックボールの設定を行うキーは、１６進数のカスタムコードで設定します。

コード値については下記の表を参照してください。


### レイヤー３トラックボール設定のコード値　mtk64　（mtk_mtk64_via.hex）
- 0x5DA5:トラックボール設定リセット
- 0x5DA6:トラックボール設定保存（次回接続時にトラックボール設定が保存された値になっている）
- 0x5DA7:トラックボールのカーソル速度 -1000
- 0x5DA8:トラックボールのカーソル速度 -100
- 0x5DA9:トラックボールのカーソル速度 +100
- 0x5DAA:トラックボールのカーソル速度 +1000
- 0x5DAB:トラックボールのスクロールモードOn/Off
- 0x5DAC:トラックボールのスクロールモードOn
- 0x5DAD:トラックボールのスクロール速度を下げる
- 0x5DAE:トラックボールのスクロール速度を上げる

### レイヤー３トラックボール設定のコード値　mtk64e　（mtk_mtk64e_via.hex/mtk_mtk64e_AutoMouseLayer_via.hex）
- 0x5DA5:トラックボール設定リセット
- 0x5DA6:トラックボール設定保存（次回接続時にトラックボール設定が保存された値になっている）
- 0x5DAA:トラックボールのカーソル速度 -1000
- 0x5DA8:トラックボールのカーソル速度 -100
- 0x5DA7:トラックボールのカーソル速度 +100
- 0x5DA9:トラックボールのカーソル速度 +1000
- 0x5DAB:トラックボールのスクロールモードOn/Off
- 0x5DAC:トラックボールのスクロールモードOn
- 0x5DAD:トラックボールのスクロール速度を下げる
- 0x5DAE:トラックボールのスクロール速度を上げる

### レイヤー３自動マウスレイヤー切替設定のコード値　mtk64e　（mtk_mtk64e_AutoMouseLayer_via.hex）
- 0x5DAF:自動マウスレイヤー切替On/Off (有効時にOLEDを反転表示）
- 0x5DB0:自動マウスレイヤー切替距離 +
- 0x5DB1:自動マウスレイヤー切替距離 -
- 0x5DB2:自動マウスレイヤーから元のレイヤーに戻る時間 + 0.1秒
- 0x5DB3:自動マウスレイヤーから元のレイヤーに戻る時間 - 0.1秒
 
## 左右トラックボール構成の動作
左右トラックボール構成で使用する場合、USBケーブルを挿した側（Master)がトラックボール、反対側（Slave)がマウスホイール（上下左右）になります。

## トラックボールのお手入れ
ボールとボールケースの白い支持球はこまめに掃除していただくと、滑りがよくなり快適に使用できます。

白い支持球周辺に埃が溜まりますので、時々ボールを外してメガネ拭きなどで掃除してください。
ボールの滑りが悪いと、狙ったところをカーソルが飛び越してしまい、非常に使いづらくなります。

ボールに[シリコンスプレー](https://www.amazon.co.jp/dp/B000TGHTF4)を少量塗布して、ティッシュ、メガネ拭き、[キムワイプ](https://www.amazon.co.jp/dp/B001EHI9XI)などで軽く拭っていただくと、劇的に滑りが良くなり、操作性が向上します。

定期的にシリコンを塗布する必要がありますが、シリコンスプレーは1本あれば数年使用できます。
