/*
    ANSI escape sequences.
*/

#pragma once
#include <string>
#include <iostream>

namespace ANSI {
    // https://en.wikipedia.org/wiki/ANSI_escape_code#Fe_Escape_sequences
    const std::string ESC = "\x1b";
    const std::string CSI = ESC + "[";

    // various CSI sequences
    // https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_(Control_Sequence_Introducer)_sequences
#define CONTROL_FUNC(NAME,VALUE,DEFAULT)    \
void NAME(int n = DEFAULT) {                \
    std::cout << CSI << n << VALUE;         \
};                                                                                  


    // Moves the cursor n (default 1) cells in the given direction.
    // If the cursor is already at the edge of the screen, this has no effect.
    CONTROL_FUNC(CURSOR_UP, "A", 1);

    // Moves the cursor n (default 1) cells in the given direction.
    // If the cursor is already at the edge of the screen, this has no effect.
    CONTROL_FUNC(CURSOR_DOWN, "B", 1);

    // Moves the cursor n (default 1) cells in the given direction.
    // If the cursor is already at the edge of the screen, this has no effect.
    CONTROL_FUNC(CURSOR_FORWARD, "C", 1);

    // Moves the cursor n (default 1) cells in the given direction.
    // If the cursor is already at the edge of the screen, this has no effect.
    CONTROL_FUNC(CURSOR_BACK, "D", 1);

    // Moves cursor to beginning of the line n (default 1) lines down.
    CONTROL_FUNC(CURSOR_NEXT_LINE, "E", 1);

    // Moves cursor to beginning of the line n (default 1) lines up.
    CONTROL_FUNC(CURSOR_PREV_LINE, "F", 1);

    // Moves the cursor to column n (default 1).
    CONTROL_FUNC(CURSOR_HORIZONTAL_ABSOLUTE, "G", 1);

    // Clears part of the screen. 
    // - If n is 0 (or missing), clear from cursor to end of screen. 
    // - If n is 1, clear from cursor to beginning of the screen. 
    // - If n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS).
    // - If n is 3, clear entire screen and delete all lines saved in the scrollback buffer
    //   (this feature was added for xterm and is supported by other terminal applications).
    CONTROL_FUNC(ERASE_IN_DISPLAY, "J", 0);

    // Erases part of the line.
    // - If n is 0 (or missing), clear from cursor to the end of the line.
    // - If n is 1, clear from cursor to beginning of the line.
    // - If n is 2, clear entire line. Cursor position does not change.
    CONTROL_FUNC(ERASE_IN_LINE, "K", 0);

    // Scroll whole page up by n (default 1) lines. New lines are added at the bottom.
    CONTROL_FUNC(SCROLL_UP, "S", 1);

    // Scroll whole page down by n (default 1) lines. New lines are added at the top.
    CONTROL_FUNC(SCROLL_DOWN, "T", 1);

    // some control functions disobey the 1-param rule

    // Moves the cursor to row n, column m. The values are 1-based,
    // and default to 1 (top left corner) if omitted.
    void CURSOR_POSITION(int n = 1, int m = 1) {
        std::cout << CSI << n << ";" << m << "H";
    }

    // ???
    // "Same as CUP, but counts as a format effector function (like
    // CR or LF) rather than an editor function (like CUD or CNL).
    // This can lead to different handling in certain terminal modes."
    void HORIZONTAL_VERTICAL_POSITION(int n = 1, int m = 1) {
        std::cout << CSI << n << ";" << m << "f";
    }

#undef CONTROL_FUNC


    // specific CSI case, returns the formatted string
    // https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters
    std::string SGR(std::string code = "0") {
        return CSI + code + "m";
    }
    std::string SGR(int code = 0) {
        return CSI + std::to_string(code) + "m";
    }

    /*
    colors from the predefined set of 256 colors
    https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
        0-  7:  standard colors (as in ESC [ 30–37 m)
        8- 15:  high intensity colors (as in ESC [ 90–97 m)
        16-231:  6 × 6 × 6 cube (216 colors): 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
        232-255:  grayscale from dark to light in 24 steps
    */
    std::string SGR_256(std::string code, bool fg = true) {
        return CSI + (fg ? "38:5:" : "48:5:") + code + "m";
    }
    std::string SGR_256(int code, bool fg = true) {
        return SGR_256(std::to_string(code), fg);
    }

    // consoles such as KDE's Konsole & GNOME Terminal support full 24-bit RGB
    std::string SGR_RGB(std::string red, std::string green, std::string blue, bool fg = true) {
        return CSI + (fg ? "38;" : "48;") + "2;" + red + ";" + green + ";" + blue + "m";
    }
    std::string SGR_RGB(int red, int green, int blue, bool fg = true) {
        return SGR_RGB(
            std::to_string(red), std::to_string(green), std::to_string(blue), fg
        );
    }

#define CODE(NAME,VALUE) const std::string NAME = SGR( VALUE )

    // misc codes - see above wikipedia url
    CODE(NORMAL, 0);
    CODE(BOLD, 1);
    CODE(DIM, 2);
    CODE(ITALIC, 3);
    CODE(UNDERLINE, 4);
    CODE(STRIKETHROUGH, 9);
    const std::string RESET = NORMAL;

    // basic foreground colors
    CODE(FG_BLACK, 30);
    CODE(FG_RED, 31);
    CODE(FG_GREEN, 32);
    CODE(FG_YELLOW, 33);
    CODE(FG_BLUE, 34);
    CODE(FG_MAGENTA, 35);
    CODE(FG_CYAN, 36);
    CODE(FG_WHITE, 37);

    // basic background colors
    CODE(BG_BLACK, 40);
    CODE(BG_RED, 41);
    CODE(BG_GREEN, 42);
    CODE(BG_YELLOW, 43);
    CODE(BG_BLUE, 44);
    CODE(BG_MAGENTA, 45);
    CODE(BG_CYAN, 46);
    CODE(BG_WHITE, 47);

#undef CODE
}
