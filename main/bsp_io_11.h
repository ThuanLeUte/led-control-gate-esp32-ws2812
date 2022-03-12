/**
 * @file       bsp_io_11.h
 * @copyright  Copyright (C) 2020 ThuanLe. All rights reserved.
 * @license    This project is released under the ThuanLe License.
 * @version    1.0.0
 * @date       2021-01-23
 * @author     Thuan Le
 * @brief      Pin description for hardware version 1.1
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_IO_11_H
#define __BSP_IO_11_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>

/* Public defines ----------------------------------------------------- */
                                    // Schematic
// PIN NAME PORT 0 ``````````````````````````````
#define IO_LED_BUFFER_0             (23)
#define IO_LED_BUFFER_1             (22)
#define IO_LED_BUFFER_2             (21)
#define IO_LED_BUFFER_3             (19)
#define IO_LED_BUFFER_4             (18)
#define IO_LED_BUFFER_5             (17)
#define IO_LED_BUFFER_6             (16)
#define IO_LED_BUFFER_7             (33)

#define IO_LED_BLUE                 (25)
#define IO_LED_GREEN                (26)
#define IO_LED_RED                  (27)

#define IO_BUTTON_1                 (34)
#define IO_BUTTON_2                 (35)

/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
/* -------------------------------------------------------------------- */
#ifdef __cplusplus
} // extern "C"
#endif
#endif // __BSP_IO_11_H

/* End of file -------------------------------------------------------- */
