#include "Character.h"
#include <Arduino.h>
//made by Rick Overhorst

Character::Character(char character, uint8_t buff[], int size)
{
  Serial.println("blyat");
  Serial.println(sizeof(buff));
  this->character = character;
  this->buff = (uint8_t*) malloc(sizeof(buff)*sizeof(uint8_t));
  memcpy(this->buff, buff,size+1);

  Serial.println(size);
  for (size_t i = 0; i < size; i++)
  {
    Serial.println(this->buff[i],HEX);
  }

  this->size = size;
}

char Character::getCharacter()
{
  return character;
}

uint8_t* Character::getBuff()
{
  return this->buff;
}
