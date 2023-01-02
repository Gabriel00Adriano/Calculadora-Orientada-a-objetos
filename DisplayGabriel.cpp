#include <stdio.h>
#include "DisplayGabriel.hpp"

void DisplayGabriel::refresh(){
      console.set_color(Color::BG_Black);
      console.set_color(Color::FG_White);
      console.clear_screen();
      int i = 0;

      for(; i < this->digitsCount; i++){
          
        switch(this->digits[i]){
        case ZERO:
          this->showDigitForm(" _ _ ","|   |","|   |","|   |"," _ _ ",i);
          break;
        case ONE:
          this->showDigitForm("     ","  /| "," / | ","   | ","   | ",i);
          break;
        case TWO:
          this->showDigitForm(" _ _ ","    |"," _ _ ","|    "," _ _ ",i);
          break;
        case THREE:
          this->showDigitForm(" _ _ ","    |"," _ _ ","    |"," _ _ ",i);
          break;
        case FOUR:
          this->showDigitForm("     ","|   |"," - - ","    |","    |",i);
          break;
        case FIVE:
          this->showDigitForm(" _ _ ","|    "," _ _ ","    |"," _ _ ",i);
          break;
        case SIX:
          this->showDigitForm(" _ _ ","|    "," _ _ ","|   |"," _ _ ",i);
          break;
        case SEVEN:
          this->showDigitForm(" _ _ ","    |","    |","    |","    |",i);
          break;
        case EIGHT:
          this->showDigitForm(" _ _ ","|   |","|_ _|","|   |"," _ _ ",i);
          break;
        case NINE:
          this->showDigitForm(" _ _ ","|   |"," _ _|","    |"," _ _|",i);
          break;
        }
        if(dots[i] == true){
            printf("■");
        }else{
            printf(" ");
            
        }
      }
      if(signal==NEGATIVE){
          this->console.set_cursor(1, 1+i * 7);printf("     ");
          this->console.set_cursor(2, 1+i * 7);printf("     ");
          this->console.set_cursor(3, 1+i * 7);printf("  ▄▄ ");
          this->console.set_cursor(4, 1+i * 7);printf("     ");
          this->console.set_cursor(5, 1+i * 7);printf("     ");        
      }
      
  }

void DisplayGabriel::showDigitForm(const char * line1, const char * line2, const char * line3, const char * line4, const char * line5, unsigned char column){
    
  this->console.set_cursor(1, 1+column * 7);printf(line1);
  this->console.set_cursor(2, 1+column * 7);printf(line2);
  this->console.set_cursor(3, 1+column * 7);printf(line3);
  this->console.set_cursor(4, 1+column * 7);printf(line4);
  this->console.set_cursor(5, 1+column * 7);printf(line5);
}

DisplayGabriel::DisplayGabriel(){
    this->console.init(0, 0);
    this->clear();
}

void DisplayGabriel::addDigit(Digit digit, bool withDot){
    if(this->digitsCount < MAX_DIGITS){ 
        dots[this->digitsCount] = withDot;
        digits[this->digitsCount++] = digit;
        this->refresh();
  }
}

void DisplayGabriel::setSignal(Signal signal){
    this->signal = signal;
    this->refresh();
}

void DisplayGabriel::clear(){
    this->digitsCount = 0;
    this->signal = POSITIVE;
    this->refresh();
}