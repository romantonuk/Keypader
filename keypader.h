#ifndef keypader_h
#define keypader_h

#include <Arduino.h>
#include "independent_libs/digitalWriteFast.h"

namespace keypader {
  struct ISoftDriver_keypad {
      public:
        uint8_t* size;
        virtual void setupPins() = 0;
        virtual void setupPinsPullup() = 0;
        virtual void sendCoulumnsFull(uint32_t val) = 0;
        virtual void sendCoulumnsSingle(uint8_t reg, uint8_t val) = 0;
        virtual uint32_t receiveRowsFull() = 0;
        virtual uint8_t receiveRowsSingle(uint8_t reg) = 0;
        virtual ~ISoftDriver_keypad() {}
  };

  uint8_t isPressed(ISoftDriver_keypad& d, uint8_t column, uint8_t row){
    d.sendCoulumnsFull(0xFFFFFFFF);
    d.sendCoulumnsSingle(column, 0);
    return d.receiveRowsSingle(row); 
  } 
}

namespace DefaultSoftDrivers_keypad{
  struct DirectPinsSoft_keypad : keypader::ISoftDriver_keypad{
    public:
      uint8_t* coulumns;
      uint8_t* rows;

      // constructor
      DirectPinsSoft_keypad(uint8_t* coulumns, uint8_t* rows, uint8_t* size) {
        this->coulumns = coulumns;
        this->rows = rows;
        this->size = size;
      }

      // Setups pins
      void setupPins() override {
        setupPinsMaster(INPUT);
      }

      // Setups pins, but with pullup
      void setupPinsPullup() override {
        setupPinsMaster(INPUT_PULLUP);
      }

      // sends single bit to register
      void sendCoulumnsSingle(uint8_t reg, uint8_t val) override {
        digitalWriteFast(coulumns[reg], val);
      }
      // sends full packet
      void sendCoulumnsFull(uint32_t val) override {
        for (uint8_t i = size[0]; i > 0; i--)
          digitalWriteFast(coulumns[i - 1], (val & (1 << (i - 1))) >> (i-1));
      }

      // receives single bit from register
      uint8_t receiveRowsSingle(uint8_t reg){
        return digitalReadFast(rows[reg]);
      }

      // receives full packet
      uint32_t receiveRowsFull(){
        uint32_t res;
        for (uint8_t i = 0; i < size[1]; i++)
          res = res | (digitalReadFast(rows[i]) << i);
        return res; 
      }
    protected:
      void setupPinsMaster(uint8_t rowsInputType){
        for (uint8_t i = 0; i < size[0]; i++){
          pinModeFast(coulumns[i], OUTPUT);
          digitalWriteFast(coulumns[i], HIGH);
        }
        for (uint8_t i = 0; i < size[1]; i++)
          pinModeFast(rows[i], rowsInputType);
      }
  };
}

#endif