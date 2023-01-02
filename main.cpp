#include "Calculator.hpp"
#include <iostream>

void testDisplay(Display &display) {
  std::cout << "Testing DISPLAY...\n";
  display.setSignal(NEGATIVE);
  display.addDigit(ZERO, true);
  display.addDigit(ZERO, true);
  display.clear();
  display.addDigit(ZERO);
  display.addDigit(ZERO);
  display.addDigit(ONE);
  display.addDigit(TWO);
  display.addDigit(THREE, true);
  display.addDigit(FOUR);
  display.addDigit(FIVE);
  display.addDigit(ZERO);
  display.addDigit(ONE);
}

void testCpu(Cpu &cpu) {
  std::cout << "Testing CPU...\n";
  cpu.receiveControl(ON_CLEAR_ERROR);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(TWO);
  cpu.receiveDigit(THREE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(FOUR);
  cpu.receiveDigit(FIVE);
  cpu.receiveDigit(SIX);
  cpu.receiveOperation(ADDITION);

  cpu.receiveDigit(FIVE);
  cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(FIVE);
  // cpu.receiveOperation(SUBTRACTION);
  // cpu.receiveOperation(EQUAL);
  /* -5 */
}

void testKeyboard(Keyboard &keyboard) {
  try {
    keyboard.findKey('1').press();
    keyboard.findKey('2').press();
    keyboard.findKey('3').press();
    keyboard.findKey('+').press();
    keyboard.findKey('1').press();
    keyboard.findKey('=').press();
  } catch (const char *exception) {
    std::cerr << exception;
  }
}
/* Coloque aqui a referência para suas implementações */
#include "CpuGabriel.hpp"
#include "DisplayYasmin.hpp"
#include "KeyboardGabriel.hpp"
#include "KeyGabriel.hpp"

int main() {
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayYasmin d1;
  CpuGabriel c1;
  KeyboardGabriel kb1;

  KeyGabriel keyZero('0', ZERO);
  KeyGabriel keyOne('1', ONE);
  KeyGabriel keyTwo('2', TWO);
  KeyGabriel keyThree('3', THREE);
  KeyGabriel keyFour('4', FOUR);
  KeyGabriel keyFive('5', FIVE);
  KeyGabriel keySix('6', SIX);
  KeyGabriel keySeven('7', SEVEN);
  KeyGabriel keyEight('8', EIGHT);
  KeyGabriel keyNine('9', NINE);

  KeyGabriel keyAddition('+', ADDITION);
  KeyGabriel keySubtraction('-', SUBTRACTION);
  KeyGabriel keyDivision('/', DIVISION);
  KeyGabriel keyMultiplication('*', MULTIPLICATION);
  KeyGabriel keyEqual('=', EQUAL);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

  kb1.addKey(keyOne);
  kb1.addKey(keyTwo);
  kb1.addKey(keyThree);

  kb1.addKey(keyAddition);
  kb1.addKey(keyEqual);

  /* Fase de testes */
  //testDisplay(d1);
  testCpu(c1);
  //testKeyboard(kb1);
}