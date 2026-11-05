#include "keyball61.c"
#include "pointing_device.h"

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {
    // 従来の pmw3360_init() から pmw3610_init() へ差し替え
    pmw3610_init();
}
#endif
