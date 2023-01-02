#pragma once

#include "Calculator.hpp"

class KeyGabriel: public Key{
  private:
    Keyboard* keyboard;
    char symbol;
    Digit digit;
    Operation operation;
    Control control;
    bool isDigit = false;
    bool isOperation = false;
    bool isControl = false;
  public:
    KeyGabriel(char, Digit);
    KeyGabriel(char, Operation);
    KeyGabriel(char, Control);
    void press();
    void setKeyboard(Keyboard&);
    char getSymbol();
};
