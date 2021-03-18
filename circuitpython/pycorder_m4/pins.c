#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_global_dict_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_PA02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_PB03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_PB03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A2), MP_ROM_PTR(&pin_PB02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_PB02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_PB23) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_CS), MP_ROM_PTR(&pin_PB23) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D1), MP_ROM_PTR(&pin_PB22) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_PB22) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_STEMMA), MP_ROM_PTR(&pin_PA05) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_PA06) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_EN2), MP_ROM_PTR(&pin_PA04) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_SDA),MP_ROM_PTR(&pin_PA12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCL),MP_ROM_PTR(&pin_PA13) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_DISPLAY_DATA),MP_ROM_PTR(&pin_PB08) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_DISPLAY_CLOCK),MP_ROM_PTR(&pin_PB09) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_DISPLAY_CS),MP_ROM_PTR(&pin_PA07) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_UP),MP_ROM_PTR(&pin_PA17) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_RIGHT),MP_ROM_PTR(&pin_PA16) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_DOWN),MP_ROM_PTR(&pin_PA20) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_LEFT),MP_ROM_PTR(&pin_PA19) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_CENTER),MP_ROM_PTR(&pin_PA18) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_NEXT),MP_ROM_PTR(&pin_PA15) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_PREVIOUS),MP_ROM_PTR(&pin_PA21) },

    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&board_uart_obj) },
};

MP_DEFINE_CONST_DICT(board_module_globals, board_global_dict_table);
