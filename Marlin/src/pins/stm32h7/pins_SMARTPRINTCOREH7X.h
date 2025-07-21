/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2022 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME      "SMARTPRINTCOREH7X"

// Motor-1 (X-axis)
#define X_STEP_PIN PG3
#define X_DIR_PIN PG4
#define X_ENABLE_PIN PG0
//#define X_MIN_PIN !PC0
//#define X_MAX_POS 200
//#define X_HOME_BUMP_MM 2
//#define X_CURRENT 800  // Adjust the current as needed

// Motor-2 (Y-axis)
#define Y_STEP_PIN PG8
#define Y_DIR_PIN PG9
#define Y_ENABLE_PIN PG5
//#define Y_MIN_PIN !PC1
//#define Y_MAX_POS 200
//#define Y_HOME_BUMP_MM 2
//#define Y_CURRENT 800  // Adjust the current as needed

// Motor-3 (Z-axis)
#define Z_STEP_PIN PG13
#define Z_DIR_PIN PG14
#define Z_ENABLE_PIN PG10
//#define Z_MAX_POS 200
//#define Z_HOME_BUMP_MM 2
//#define Z_CURRENT 1600  // Adjust the current as needed

// Motor-4 (Z-axis)
#define Z2_STEP_PIN PD7
#define Z2_DIR_PIN PD10
#define Z2_ENABLE_PIN PD4
//#define Z2_MAX_POS 200
//#define Z2_HOME_BUMP_MM 2
//#define Z2_CURRENT 1600  // Adjust the current as needed

// Motor-5 (Z-axis)
#define Z3_STEP_PIN PD11
#define Z3_DIR_PIN PD12
#define Z3_ENABLE_PIN PD8
//#define Z3_MAX_POS 200
//#define Z3_HOME_BUMP_MM 2
//#define Z3_CURRENT 1600  // Adjust the current as needed

// Motor-6 (Z-axis)
#define Z4_STEP_PIN PB10
#define Z4_DIR_PIN PB13
#define Z4_ENABLE_PIN PB14
//#define Z4_MAX_POS 200
//#define Z4_HOME_BUMP_MM 2
//#define Z4_CURRENT 1600  // Adjust the current as needed


// End Stops
#define X_STOP_PIN PC0
#define Y_STOP_PIN PC1
#define Z_STOP_PIN PC2

// Extruder (E0)
#define E0_STEP_PIN PF4
#define E0_DIR_PIN PF15
#define E0_ENABLE_PIN PG15
//#define E0_CURRENT 800  // Adjust the current as needed

// Extruder1 (E1)
//#define E1_STEP_PIN PD7
//#define E1_DIR_PIN PD10
//#define E1_ENABLE_PIN PD4
//#define E1_CURRENT 800  // Adjust the current as needed

// Extruder2 (E2)
//#define E2_STEP_PIN PD7
//#define E2_DIR_PIN PD10
//#define E2_ENABLE_PIN PD4
//#define E2_CURRENT 800  // Adjust the current as needed

// Bed
//#define HEATER_BED_PIN PB2
#define HEATER_BED_PIN PB0 // Use FAN4 to control SSR
#define TEMP_BED_PIN PF13

// Chamber
#define TEMP_CHAMBER_PIN PF11

// Heaters
#define HEATER_0_PIN PA10
//#define HEATER_1_PIN PE1
//#define HEATER_2_PIN PB11
#define TEMP_0_PIN PF12
//#define TEMP_1_PIN PF13
//#define TEMP_2_PIN PF14

// Fans
#define FAN0_PIN PB1
#define FAN1_PIN PB3
#define FAN2_PIN PB4
#define FAN3_PIN PE1

#define Z_MIN_PROBE_PIN PA4

#define BOARD_PREINIT() { \
  OUT_WRITE_OD(HEATER_0_PIN, 0); \
  OUT_WRITE_OD(HEATER_BED_PIN, 0); \
  OUT_WRITE_OD(FAN0_PIN, 0); \
}

#if HAS_TMC_UART
  //
  // Software serial
  // No Hardware serial for steppers
  //
  #define X_SERIAL_TX_PIN                   PG1
  #define X_SERIAL_RX_PIN        X_SERIAL_TX_PIN

  #define Y_SERIAL_TX_PIN                   PG6
  #define Y_SERIAL_RX_PIN        Y_SERIAL_TX_PIN

  #define Z_SERIAL_TX_PIN                   PG11
  #define Z_SERIAL_RX_PIN        Z_SERIAL_TX_PIN

  #define Z2_SERIAL_TX_PIN                   PD5
  #define Z2_SERIAL_RX_PIN        Z2_SERIAL_TX_PIN

  #define Z3_SERIAL_TX_PIN                   PD9
  #define Z3_SERIAL_RX_PIN        Z3_SERIAL_TX_PIN

  #define Z4_SERIAL_TX_PIN                   PB15
  #define Z4_SERIAL_RX_PIN        Z4_SERIAL_TX_PIN

  #define E0_SERIAL_TX_PIN                  PF2
  #define E0_SERIAL_RX_PIN      E0_SERIAL_TX_PIN

  //#define E1_SERIAL_TX_PIN                  PD5
  //#define E1_SERIAL_RX_PIN      E1_SERIAL_TX_PIN

  // Reduce baud rate to improve software serial reliability
  #ifndef TMC_BAUD_RATE
    #define TMC_BAUD_RATE                  19200
  #endif

#endif // HAS_TMC_UART

// NeoPixel Config
//#define NEOPIXEL_PIN PB9

// Led Effect
//#define NEOPIXEL_PANEL_IDLE true
//#define NEOPIXEL_FRAME_RATE 24

// Uncomment the following lines if you have additional servos
//#define NUM_SERVOS 4
//#define SERVO0_PIN PA15       //BLTouch
//#define SERVO1_PIN PB6
//#define SERVO2_PIN PB7
//#define SERVO3_PIN PB8

#if SD_CONNECTION_IS(ONBOARD)
  #define SD_DETECT_PIN                       PC13
  #define ONBOARD_SDIO
#elif SD_CONNECTION_IS(LCD)
  #define SD_SCK_PIN             LCD_P2_07_PIN
  #define SD_MISO_PIN            LCD_P2_09_PIN
  #define SD_MOSI_PIN            LCD_P2_08_PIN
  #define LCD_SDSS               LCD_P2_06_PIN
  #define SD_SS_PIN              LCD_P2_06_PIN
  #define SD_DETECT_PIN          LCD_P2_03_PIN
#endif

//
// EEPROM
//
#define FLASH_EEPROM_EMULATION

#if HAS_SPI_TFT

  #define TFT_SCK_PIN                LCD_P2_07_PIN
  #define TFT_MISO_PIN               LCD_P2_09_PIN
  #define TFT_MOSI_PIN               LCD_P2_08_PIN

  #define BTN_ENC                    LCD_P1_02_PIN
  #define BTN_EN1                    LCD_P2_05_PIN
  #define BTN_EN2                    LCD_P2_04_PIN

  #ifndef TFT_WIDTH
    #define TFT_WIDTH                      480
  #endif
  #ifndef TFT_HEIGHT
    #define TFT_HEIGHT                     320
  #endif

  #if ENABLED(BTT_TFT35_SPI_V1_0)

    /**
     *            ------                       ------
     *    BEEPER | 1  2 | LCD-BTN        MISO | 1  2 | CLK
     *    T_MOSI | 3  4 | T_CS       LCD-ENCA | 3  4 | TFTCS
     *     T_CLK | 5  6   T_MISO     LCD-ENCB | 5  6   MOSI
     *    PENIRQ | 7  8 | F_CS             RS | 7  8 | RESET
     *       GND | 9 10 | VCC             GND | 9 10 | NC
     *            ------                       ------
     *             EXP1                         EXP2
     *
     * 480x320, 3.5", SPI Display with Rotary Encoder.
     * Stock Display for the BIQU B1 SE Series.
     * Schematic: https://github.com/bigtreetech/TFT35-SPI/blob/master/v1/Hardware/BTT%20TFT35-SPI%20V1-SCH.pdf
     */

    #define TFT_CS_PIN               LCD_P1_08_PIN
    #define TFT_DC_PIN               LCD_P1_09_PIN
    #define TFT_A0_PIN               TFT_DC_PIN

    #define TOUCH_CS_PIN             LCD_P1_06_PIN
    #define TOUCH_SCK_PIN            LCD_P2_07_PIN
    #define TOUCH_MISO_PIN           LCD_P2_09_PIN
    #define TOUCH_MOSI_PIN           LCD_P2_08_PIN
    #define TOUCH_INT_PIN            LCD_P1_07_PIN

    #ifndef TOUCH_CALIBRATION_X
      #define TOUCH_CALIBRATION_X          17540
    #endif
    #ifndef TOUCH_CALIBRATION_Y
      #define TOUCH_CALIBRATION_Y         -11388
    #endif
    #ifndef TOUCH_OFFSET_X
      #define TOUCH_OFFSET_X                 -21
    #endif
    #ifndef TOUCH_OFFSET_Y
      #define TOUCH_OFFSET_Y                 337
    #endif
    #ifndef TOUCH_ORIENTATION
      #define TOUCH_ORIENTATION TOUCH_LANDSCAPE
    #endif

  #elif ENABLED(MKS_TS35_V2_0)

    /**                      ------                                   ------
     *               BEEPER | 1  2 | BTN_ENC               SPI1_MISO | 1  2 | SPI1_SCK
     *     TFT_BKL / LCD_EN | 3  4 | TFT_RESET / LCD_RS      BTN_EN1 | 3  4 | SPI1_CS
     *    TOUCH_CS / LCD_D4 | 5  6   TOUCH_INT / LCD_D5      BTN_EN2 | 5  6   SPI1_MOSI
     *     SPI1_CS / LCD_D6 | 7  8 | SPI1_RS / LCD_D7       SPI1_RS  | 7  8 | RESET
     *                  GND | 9 10 | VCC                         GND | 9 10 | VCC
     *                       ------                                   ------
     *                        EXP1                                     EXP2
     */

    #define TFT_CS_PIN               LCD_P1_08_PIN  // SPI1_CS
    #define TFT_DC_PIN               LCD_P1_09_PIN  // LCD_D7
    #define TFT_A0_PIN               TFT_DC_PIN

    #define TFT_RESET_PIN            LCD_P1_05_PIN

    #define LCD_BACKLIGHT_PIN        LCD_P1_04_PIN
    #define TFT_BACKLIGHT_PIN        LCD_BACKLIGHT_PIN

    #define TOUCH_BUTTONS_HW_SPI
    #define TOUCH_BUTTONS_HW_SPI_DEVICE 4

    #define TOUCH_CS_PIN             LCD_P1_06_PIN  // LCD_D4
    #define TOUCH_SCK_PIN            LCD_P2_07_PIN  // SPI1_SCK
    #define TOUCH_MISO_PIN           LCD_P2_09_PIN  // SPI1_MISO
    #define TOUCH_MOSI_PIN           LCD_P2_08_PIN  // SPI1_MOSI
    #define TOUCH_INT_PIN            LCD_P1_07_PIN  // LCD_D5

    #define LCD_READ_ID                     0xD3
    #define LCD_USE_DMA_SPI

    #define TFT_BUFFER_WORDS               14400

    #ifndef TOUCH_CALIBRATION_X
      #define TOUCH_CALIBRATION_X         -17253
    #endif
    #ifndef TOUCH_CALIBRATION_Y
      #define TOUCH_CALIBRATION_Y          11579
    #endif
    #ifndef TOUCH_OFFSET_X
      #define TOUCH_OFFSET_X                 514
    #endif
    #ifndef TOUCH_OFFSET_Y
      #define TOUCH_OFFSET_Y                 -24
    #endif
    #ifndef TOUCH_ORIENTATION
      #define TOUCH_ORIENTATION TOUCH_LANDSCAPE
    #endif
  #endif
#endif

#if HAS_WIRED_LCD

  #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)

    /**
     *          ------                           ------
     *  BEEPER | 1  2 | BTN_ENC            MISO | 1  2 | SCK
     *  LCD_EN | 3  4 | LCD_RS          BTN_EN2 | 3  4 | SD_CSEL
     *  LCD_D4 | 5  6 | LCD_D5          BTN_EN1 | 5  6 | MOSI
     *  LCD_D6 | 7  8 | LCD_D7           SD_DET | 7  8 | RESET
     *     GND | 9 10 | 5V                  GND | 9 10 | KILL
     *          ------                           ------
     *           EXP1                             EXP2
     */

    #define BTN_ENC                LCD_P1_02_PIN
    #define BEEPER_PIN             LCD_P1_03_PIN
    #define LCD_PINS_EN            LCD_P1_04_PIN
    #define LCD_PINS_RS            LCD_P1_05_PIN
    #define LCD_PINS_D4            LCD_P1_06_PIN

    #define BTN_EN1                LCD_P2_05_PIN
    #define BTN_EN2                LCD_P2_04_PIN

  #elif ENABLED(CR10_STOCKDISPLAY)

    /**
     *           ------
     *   BEEPER | 1  2 | BTN_ENC
     *  BTN_EN1 | 3  4 | ---
     *  BTN_EN2 | 5  6 | LCD_D4
     *   LCD_RS | 7  8 | LCD_EN
     *      GND | 9 10 | 5V
     *           ------
     *            EXP3
     */

    #define BTN_ENC                LCD_P1_02_PIN
    #define BEEPER_PIN             LCD_P1_03_PIN
    #define LCD_PINS_EN            LCD_P1_04_PIN
    #define LCD_PINS_RS            LCD_P1_05_PIN
    #define LCD_PINS_D4            LCD_P1_06_PIN

    #define BTN_EN1                LCD_P2_05_PIN
    #define BTN_EN2                LCD_P2_04_PIN

  #elif ENABLED(FYSETC_MINI_12864_2_1)

    /**
     *          ------                           ------
     *  BEEPER | 1  2 | BTN_ENC            MISO | 1  2 | SCK
     *  LCD_EN | 3  4 | LCD_RS          BTN_EN2 | 3  4 | SD_CSEL
     *  LCD_D4 | 5  6 | LCD_D5          BTN_EN1 | 5  6 | MOSI
     *  LCD_D6 | 7  8 | LCD_D7           SD_DET | 7  8 | RESET
     *     GND | 9 10 | 5V                  GND | 9 10 | KILL
     *          ------                           ------
     *           EXP1                             EXP2
     */

    #define BTN_ENC                LCD_P1_02_PIN
    #define BEEPER_PIN             LCD_P1_03_PIN
    #define LCD_PINS_EN            LCD_P1_04_PIN
    #define LCD_PINS_RS            LCD_P1_05_PIN

    #define BTN_EN1                LCD_P2_05_PIN
    #define BTN_EN2                LCD_P2_04_PIN

    #define LCD_PINS_DC            LCD_P1_05_PIN
    #define DOGLCD_CS              LCD_P1_04_PIN
    #define DOGLCD_A0              LCD_PINS_DC
    #define LCD_BACKLIGHT_PIN      -1
    #define LCD_RESET_PIN          LCD_P1_06_PIN
    #define NEOPIXEL_PIN           LCD_P1_07_PIN
    #define DOGLCD_MOSI            LCD_P2_08_PIN
    #define DOGLCD_SCK             LCD_P2_07_PIN
    #define FORCE_SOFT_SPI
    //#define SOFTWARE_SPI

  #endif

#endif

/**
 *       ----                                      ---- 
 *      |  1 | 5V_SPARE                           |  1 | 5V_SPARE
 *      |  2 | SC_BTN_ENC (PC14)                  |  2 | RST_IN
 *      |  3 | SC_BEEPER  (PC15)                  |  3 | EM_STOP    (PD13)
 *      |  4 | LCD_EN     (PE15)                  |  4 | SC_BTN_EN2 (PD15)
 *      |  5 | LCD_RS     (PE14)                  |  5 | SC_BTN_EN1 (PD14)
 *      |  6 | LCD_D4     (PE13)                  |  6 | SPI4_CS1   (PE3)
 *      |  7 | LCD_D5     (PE12)                  |  7 | SPI4_SCK   (PE2)
 *      |  8 | LCD_D6     (PE11)                  |  8 | SPI4_MOSI  (PE6)
 *      |  9 | LCD_D7     (PE10)                  |  9 | SPI4_MISO  (PE5)
 *      | 10 | GND                                | 10 | GND
 *       ----                                      ---- 
 *       J18 (LCD-P1)                               J24 (LCD-P2)
 */

#define LCD_P1_02_PIN                         PC14
#define LCD_P1_03_PIN                         PC15
#define LCD_P1_04_PIN                         PE15
#define LCD_P1_05_PIN                         PE14
#define LCD_P1_06_PIN                         PE13
#define LCD_P1_07_PIN                         PE12
#define LCD_P1_08_PIN                         PE11
#define LCD_P1_09_PIN                         PE10

#define LCD_P2_02_PIN                         -1
#define LCD_P2_03_PIN                         PD13
#define LCD_P2_04_PIN                         PD15
#define LCD_P2_05_PIN                         PD14
#define LCD_P2_06_PIN                         PE3
#define LCD_P2_07_PIN                         PE2
#define LCD_P2_08_PIN                         PE6
#define LCD_P2_09_PIN                         PE5