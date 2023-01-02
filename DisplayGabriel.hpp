#pragma once
#include "Calculator.hpp"
#include "Console.hpp"

#define MAX_DIGITS 8


class DisplayGabriel : public Display{
  private:
    Console console;
    Digit digits[MAX_DIGITS];
    unsigned char digitsCount = 0;
    Signal signal = POSITIVE;
    bool dots[MAX_DIGITS];
    void refresh();
    void showDigitForm(const char * line1, const char * line2, const char * line3, const char * line4, const char * line5, unsigned char column);

  public:

    DisplayGabriel();
    void addDigit(Digit digit, bool withDot = false);
    void setSignal(Signal signal);
    void clear();
};