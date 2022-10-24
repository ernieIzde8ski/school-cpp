/*
    ANSI escape sequences.
*/

#pragma once
#include <string>

namespace ANSI {
    const std::string ESC = "\x1b[";

    // basic escape sequences
    // https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters
    std::string SGR(std::string code) {
        return ESC + code + "m";
    }
    std::string SGR(int code) {
        return SGR(std::to_string(code));
    }

    /* 
    colors from the predefined set of 256 colors
    https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
        0-  7:  standard colors (as in ESC [ 30–37 m)
        8- 15:  high intensity colors (as in ESC [ 90–97 m)
        16-231:  6 × 6 × 6 cube (216 colors): 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
        232-255:  grayscale from dark to light in 24 steps
    */
    std::string color256(std::string code, bool fg = true) {
        return ESC + (fg ? "38:5:" : "48:5:") + code + "m";
    }
    std::string color256(int code, bool fg = true) {
        return color256(std::to_string(code), fg);
    }

    // consoles such as KDE's Konsole & GNOME Terminal support full 24-bit RGB
    std::string colorRGB(std::string red, std::string green, std::string blue, bool fg = true) {
        return ESC + (fg ? "38;" : "48;") + "2;" + red + ";" + green + ";" + blue + "m";
    }
    std::string colorRGB(int red, int green, int blue, bool fg = true) {
        return colorRGB(
            std::to_string(red), std::to_string(green), std::to_string(blue), fg
        );
    }

    // misc codes - see above wikipeda url
    const std::string NORMAL = SGR(0);
    const std::string RESET = NORMAL;
    const std::string BOLD = SGR(1);
    const std::string DIM = SGR(2);
    const std::string ITALIC = SGR(3);
    const std::string UNDERLINE = SGR(4);
    const std::string STRIKETHROUGH = SGR(9);

    // basic foreground colors
    const std::string FG_BLACK = SGR(30);
    const std::string FG_RED = SGR(31);
    const std::string FG_GREEN = SGR(32);
    const std::string FG_YELLOW = SGR(33);
    const std::string FG_BLUE = SGR(34);
    const std::string FG_MAGENTA = SGR(35);
    const std::string FG_CYAN = SGR(36);
    const std::string FG_WHITE = SGR(37);

    // basic background colors
    const std::string BG_BLACK = SGR(40);
    const std::string BG_RED = SGR(41);
    const std::string BG_GREEN = SGR(42);
    const std::string BG_YELLOW = SGR(43);
    const std::string BG_BLUE = SGR(44);
    const std::string BG_MAGENTA = SGR(45);
    const std::string BG_CYAN = SGR(46);
    const std::string BG_WHITE = SGR(47);
}