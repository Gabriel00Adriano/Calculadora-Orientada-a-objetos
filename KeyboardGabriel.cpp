#include "KeyboardGabriel.hpp"

void KeyboardGabriel::receiveDigit(Digit digit) {
  this->cpu->receiveDigit(digit);
}
void KeyboardGabriel::receiveOperation(Operation operation) {
  this->cpu->receiveOperation(operation);  
}
void KeyboardGabriel::receiveControl(Control control) {
  this->cpu->receiveControl(control); 
}

void KeyboardGabriel::addKey(Key& key) {
  this->keys[this->keysCount++] = &key;
  key.setKeyboard(*this);
}

Key& KeyboardGabriel::findKey(char symbol) {
  for(int i = 0; i < this->keysCount; i++)
    if(this->keys[i]->getSymbol() == symbol)
      return *this->keys[i];

  throw "KEY_NOT_FOUND";
}

void KeyboardGabriel::setCpu(Cpu& cpu) {
  this->cpu = &cpu;
}