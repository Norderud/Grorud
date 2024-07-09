#ifndef CHARACTERMAP_H
#define CHARACTERMAP_H

struct Chars {
    static constexpr char downLeftUpRight = '/';
    static constexpr char downRightLeftUp = '\\';
    static constexpr char horizontalLow = '_';
    static constexpr char horizontalMid = '-';
    static constexpr char vertical = '|';
    static constexpr char T = 'T';
    static constexpr char X = 'X';
    static constexpr char leftBracket = '(';
    static constexpr char rightBracket = ')';
    static constexpr char rocket = '^'; // Corrected placeholder
    static constexpr char plus = '\x8a';
    static constexpr char rightArrow = '\x8d';
    static constexpr char leftArrow = '\x8b';
    static constexpr char blackBox = '\x9d';
    static constexpr char stop = '\xb0';
    static constexpr char arrow_4x4_right_arrow = '\xa0';
    static constexpr char arrow_4x4_left_arrow = '\x90';
};

#endif // CHARACTERMAP_H