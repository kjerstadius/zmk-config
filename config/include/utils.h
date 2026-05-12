#pragma once

#include <behaviors.dtsi>

#define COMBO_KEYS(side, row, pos1, pos2) CORE_KEY_POS(side##, row, pos1) CORE_KEY_POS(side##, row, pos2)

#define MACRO_TAP_MS 5
#define MACRO_WAIT_MS 5

#define MACRO(name, binds) \
    name: name { \
        compatible = "zmk,behavior-macro"; \
        wait-ms = <MACRO_WAIT_MS>; \
        tap-ms = <MACRO_TAP_MS>; \
        #binding-cells = <0>; \
        bindings = <binds>; \
    }

#define LINGER_KEY(name, hold_bind, tap_bind) \
    name##_hold: name##_hold { \
        compatible = "zmk,behavior-macro"; \
        wait-ms = <0>; \
        tap-ms = <0>; \
        #binding-cells = <0>; \
        bindings = <hold_bind>; \
    }; \
    name##_tap: name##_tap { \
        compatible = "zmk,behavior-macro"; \
        wait-ms = <0>; \
        tap-ms = <0>; \
        #binding-cells = <0>; \
        bindings = <tap_bind>; \
    }; \
    name: name { \
        compatible = "zmk,behavior-hold-tap"; \
        #binding-cells = <2>; \
        tapping-term-ms = <250>; \
        flavor = "tap-preferred"; \
        bindings = <&name##_hold>, <&name##_tap>; \
    }
