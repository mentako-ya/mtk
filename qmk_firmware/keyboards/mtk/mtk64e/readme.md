# mtk64

Make example for this keyboard (after setting up your build environment):

    make mtk/mtk64:via

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Special keycodes

Value    | Keycode    |Description
---------|------------|------------------------------------------------------------------
`0x5DB1` | `KBC_RST`  |Reset Keyball configuration
`0x5DB2` | `KBC_SAVE` |Persist Keyball configuration to EEPROM
`0x5DB3` | `CPI_I100` |Increase 100 CPI (max 12000)
`0x5DB4` | `CPI_D100` |Decrease 100 CPI (min 100)
`0x5DB5` | `CPI_I1K`  |Increase 1000 CPI (max 12000)
`0x5DB6` | `CPI_D1K`  |Decrease 1000 CPI (min 100)
`0x5DB7` | `SCRL_TO`  |Toggle scroll mode
`0x5DB8` | `SCRL_MO`  |Enable scroll mode when pressing
`0x5DB9` | `SCRL_DVI` |Increase scroll divider (max 7 = 1/128)
`0x5DBA` | `SCRL_DVD` |Decrease scroll divider (min 0 = 1/1)

*NOTE*: The values are for VIA/Remap
