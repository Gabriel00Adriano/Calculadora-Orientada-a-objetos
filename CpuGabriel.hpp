#pragma once
#include "Calculator.hpp"
#define MAX_DIGITS 8
#define MAX_OPERATIONS 4
#define MEMORY_SIZE 8
#define OPERATOR_SIZE 1

class CpuGabriel : public Cpu{
  private:
    Display * display;
    Digit digits[MAX_DIGITS];
    Operation operation = NOOP;
    Control control;
    Digit memory1[MEMORY_SIZE];
    Digit memory2[MEMORY_SIZE];
    int count_Memory1 = 0;
    int count_Memory2 = 0;
  public:
    void receiveOperation(Operation);
    void receiveDigit(Digit);
    void receiveControl(Control);
    int convertIntoNumber(Digit);
    int convertIntoNumbers(Digit memory[], int count);
    Digit convertIntoDigit(int number);
    void convertIntoDigits(float result, Digit memory[], int count);
    void setDisplay(Display&);
    void Calculate(Operation);
    void showDigitsOnDisplay(Digit memory[], int count, int dot_Position);
    int digitQuantity(int result);
    int floatToInteger(float result);
    int dotPosition(float result);
};