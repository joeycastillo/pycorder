#include "supervisor/board.h"
#include "mpconfigboard.h"
#include "shared-bindings/pwmio/PWMOut.h"
#include "hal/include/hal_gpio.h"

void board_init(void) {
    // set up square wave on PA01 (display EXTCOMIN)
    pwmio_pwmout_obj_t pwm;
    common_hal_pwmio_pwmout_construct(&pwm, &pin_PA01, 32768, 2, false);
    common_hal_pwmio_pwmout_never_reset(&pwm);

    // keep display on at all times (display DISP is PA00)
    gpio_set_pin_function(PIN_PA00, GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_direction(PIN_PA00, GPIO_DIRECTION_OUT);
    gpio_set_pin_level(PIN_PA00, true);
    never_reset_pin_number(PIN_PA00);
}

bool board_requests_safe_mode(void) {
    return false;
}

void reset_board(void) {
}
