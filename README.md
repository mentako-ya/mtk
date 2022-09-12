# mtk

mtk is clone keybord with trackball.

- via firmware  [mtk_mtk64_via.hex](mtk/mtk_mtk64_via.hex)
- [via firmware build guide](qmk_firmware/keyboards/mtk/)

## キーマップ変更

キーマップの変更は、https://remap-keys.app/　で変更します。

下記に本キーボードを使用する際に最低限必要な手順を記載します。

remapの一般的な使用方法はサリチル酸さんの記事などをご参照ください。　https://salicylic-acid3.hatenablog.com/entry/remap-manual

1. [START REMAP FRO YOUR KEYBORD]　をクリック
<img width="500" src="mtk/remap_img/remap_1.png">

2. [+ KEYBORD]をクリック
<img width="500" src="mtk/remap_img/remap_2.png">

3. [mtk64] を選択して接続.
<img width="250" src="mtk/remap_img/remap_3.png">

4. Jsonファイルのアップロードを求められるので、下記からレイアウトに合わせたjsonファイルをダウンロードして使用する
<img width="500" src="mtk/remap_img/remap_4.png">

- 右ボール用 [mtk64_rb_via.json](mtk/mtk64_via.json)
- 左右ボール用 [mtk64_db_via.json](mtk/mtk64_db_via.json)

5. キーマップの変更 / キーマップの書き込み（右上Flashボタン） /　変更したキーマップの保存　/　キーマップのPDFダウンロード　などが可能

右ボールキーマップサンプル
- via keyleyout(right ball) [mtk64_rb_via.json](mtk/mtk64_via.json)
- sample keymap cheetsheet(right ball) [mtk64_rb_keymap_cheatsheet.pdf](mtk/mtk64_rb_keymap_cheatsheet.pdf)
<img width="1186" alt="remap_key_leyout" src="mtk/remap_img/mtk64_rb_keymap.png">

左右ボールキーマップサンプル
- via keyleyout(double ball) [mtk64_db_via.json](mtk/mtk64_db_via.json)
- sample keymap cheetsheet(double ball) [mtk64_db_keymap_cheatsheet.pdf](mtk/mtk64_db_keymap_cheatsheet.pdf)
<img alt="remap_key_leyout_double_ball" src="mtk/remap_img/mtk64_db_keymap.png">

## 基本的な使用方法

本キーボードは、レイヤー０〜４の４種類のキーマップを切り替えて使用します。

レイヤーの切り替えは左手親指キーのHOLD（シフトキーのように押したままにすること）に割り当てられており、左端からLayer(1),Layer(2),Layer(3)が設定されています。

- レイヤー０:通常のアルファベット入力
- レイヤー１:Shiftキー押下相当（大文字入力や記号入力）
- レイヤー２:右手のキーがマウスのボタンに切り替わる
- レイヤー３:トラックボールがスクロールモードに切り替わる、キースイッチはLEDの調整、トラックボールの速度、スクロールの速度調整

## レイヤー３トラックボール設定のコード値

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

## 左右トラックボール構成の動作
左右トラックボール構成で使用する場合、USBケーブルを挿した側（Master)がトラックボール、反対側（Slave)がマウスホイール（上下左右）になります。

## トラックボールのお手入れ
ボールとボールケースの白い支持球はこまめに掃除していただくと、滑りがよくなり快適に使用できます。

特に、微調整が必要な細かい作業を行う場合、ボールの滑りが悪いと狙ったところをカーソルが飛び越してしまい、非常にストレスが溜まります。

ボールケースの白い支持球周辺には埃が溜まります。時々ボールを外してメガネ拭きなどで掃除してください。

ボールに[シリコンスプレー](https://www.amazon.co.jp/dp/B000TGHTF4)を少量塗布して、ティッシュ、メガネ拭き、[キムワイプ](https://www.amazon.co.jp/dp/B001EHI9XI)などで軽く拭っていただくと、劇的に滑りが良くなり、操作性が向上します。
（シリコンスプレーは必須です）
