#include "Calculator.hpp"
#include "CpuGabriel.hpp"
#include <stdio.h>
#define MAX_DECIMAL_PLACE 1

int CpuGabriel::convertIntoNumber(Digit digit){
  switch(digit){
    case ZERO:
      return 0;
    case ONE:
      return 1;
    case TWO:
      return 2;
    case THREE:
      return 3;
    case FOUR:
      return 4;
    case FIVE:
      return 5;
    case SIX:
      return 6;
    case SEVEN:
      return 7;
    case EIGHT:
      return 8;
    case NINE:
      return 9;
  }
}

Digit CpuGabriel::convertIntoDigit(int number){
  switch(number){
    case 0:
      return ZERO;
    case 1:
      return ONE;
    case 2:
      return TWO;
    case 3:
      return THREE;
    case 4:
      return FOUR;
    case 5:
      return FIVE;
    case 6:
      return SIX;
    case 7:
      return SEVEN;
    case 8:
      return EIGHT;
    case 9:
      return NINE;
  }
}

void CpuGabriel::receiveDigit(Digit digit){
  if(this->operation == NOOP){
    memory1[count_Memory1] = digit;
    count_Memory1++;
  }else{
    memory2[count_Memory2] = digit;
    count_Memory2++;
  }
  this->display->addDigit(digit);
}
      
void CpuGabriel::receiveOperation(Operation operation){
  this->display->clear();
  if(this->operation != NOOP){
    this->Calculate(this->operation);
  }
  this->operation = operation;
}

void CpuGabriel::receiveControl(Control control){
  switch(control){
    case ON_CLEAR_ERROR: this->display->clear(); break;
    case OFF: break;
    case MEMORY_ADDITION: 
      if(count_Memory1 > 0)Calculate(ADDITION); break;
    case MEMORY_SUBTRACTION:
      if(count_Memory1 > 0)Calculate(SUBTRACTION); break;
    case MEMORY_READ_CLEAR:
    if(count_Memory1 > 0){ 
      showDigitsOnDisplay(this->memory1,this->count_Memory1, -1);
    }else{
      this->count_Memory1 = 0;
    }
    break;
  }
}

void CpuGabriel::setDisplay(Display & display){
  this->display = &display; 
}

int CpuGabriel::convertIntoNumbers(Digit memory[], int count){
    int temp = 0;
    for(int i = 0; i < count; i++){
        temp = (temp * 10) + convertIntoNumber(memory[i]); 
    }
    return temp;
}

int CpuGabriel::digitQuantity(int result){
    int count = 0;
    if(result == 0)return 1;
    if(result > 0 && result < 1)return 2;
    while(result != 0){
      result = result / 10;
      count++;
    }
    return count;
}
int CpuGabriel::floatToInteger(float result){
  int integer_Part = result;
  float decimal_Part = result - integer_Part;
  int count = digitQuantity(integer_Part);
    if(decimal_Part > 0){
      for(int i = 0; i < MAX_DECIMAL_PLACE; i++){
          decimal_Part = decimal_Part * 10;
      }
      for(int i = 0; i < count; i++){
        integer_Part*=10;
      }
    }
  return integer_Part + (int)decimal_Part;
}
void CpuGabriel::convertIntoDigits(float result, Digit memory[], int count){

  if(result < 0)result*=-1;
  
  int result_int = result;
  int result_Copy = result_int;
  int count_Copy = count;
  // Se o numero for menor que 1 necessitara de um tratamento diferente pois 0 a esquerda é desconsiderado.
  if(result < 1){
    int integer_Part = result;
    float decimal_Part = result - integer_Part;
    decimal_Part*=10;
    memory[0] = convertIntoDigit(integer_Part);
    memory[1] = convertIntoDigit((int)decimal_Part);
  }else{
  for(int i = 0; i < count; i++){
    result_int = result_int % 10;
    count_Copy--;
    memory[count_Copy] = convertIntoDigit(result_int);
    result_Copy = result_Copy / 10;
    result_int = result_Copy;
    }
  }
}

void CpuGabriel::showDigitsOnDisplay(Digit memory[], int count, int position){
  for(int i = 0; i < count; i++){
    if(i == position-1){
      this->display->addDigit(memory[i], true);
    }else{
      this->display->addDigit(memory[i]);
    }
  }
}

int CpuGabriel::dotPosition(float result){
  int integer_Part = result;
  float decimal_Part = result - integer_Part;
  if(decimal_Part > 0){
      return digitQuantity(integer_Part);
    }else{
    return -1;
  }
}

void CpuGabriel::Calculate(Operation operation){
  this->display->clear();
  
  float num1 = convertIntoNumbers(this->memory1, this->count_Memory1);
  float num2 = convertIntoNumbers(this->memory2, this->count_Memory2);
  float result = 0;
  
    switch(operation){
      case ADDITION: result = num1 + num2; break;
      case SUBTRACTION: result = num1 - num2; break;
      case MULTIPLICATION: result =  num1 * num2; break;
      case DIVISION: result = num1 / num2; break;
      case EQUAL: operation = NOOP; break;
  }
  int dot_Position = dotPosition(result);
  if(result > 1){result = floatToInteger(result);}
convertIntoDigits(result, this->memory1, digitQuantity(result));
  this->count_Memory2 = 0;
  showDigitsOnDisplay(this->memory1, digitQuantity(result), dot_Position);
  printf("%f %f %f", result, num1, num2);
  
  if(result < 0)this->display->setSignal(NEGATIVE);
}
