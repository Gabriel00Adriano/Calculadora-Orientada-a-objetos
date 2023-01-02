#include "KeyGabriel.hpp"

KeyGabriel::KeyGabriel(char symbol, Digit digit){
  this->isDigit = true;
  this->symbol = symbol;
  this->digit = digit;
}
KeyGabriel::KeyGabriel(char symbol, Operation operation){
  this->isOperation = true;
  this->symbol = symbol;
  this->operation = operation;
  
}
KeyGabriel::KeyGabriel(char symbol, Control control){
  this->isControl = true;
  this->symbol = symbol;
  this->control = control;
}

void KeyGabriel::press() {
  if(this->isDigit) this->keyboard->receiveDigit(this->digit);
  if(this->isOperation) this->keyboard->receiveOperation(this->operation);
  if(this->isControl) this->keyboard->receiveControl(this->control);  
}

void KeyGabriel::setKeyboard(Keyboard &keyboard) { this->keyboard = &keyboard; }

char KeyGabriel::getSymbol() { return this->symbol; }