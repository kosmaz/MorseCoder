//used for encrypting string of characters using morse cod mechanism
#ifndef MORSECODE_H
#define MORSECODE_H

#include "InputHandler.h"

typedef const char identify[7],identify2[1];
const int klength=37 ;
const int k_c_length=7;

class MorseCode
{
public:
  MorseCode();
  ~MorseCode();
  
  void encrypter();
  void decrypter();
private:

  inline void initialize(char initial[]);
  void de_switch_char(const identify characters[], const identify2 checked,
  											std::ofstream& out1)  const;

   char* fMsg;
   int fMsgLength;
   int fLength;
   int fC_Length;
   InputHandler* fInput;

};

inline void MorseCode::initialize(char initial[])
{
  for(int i=0;i<fC_Length;i++)
    initial[i]='\0';
}

#endif // MORSECODE_H
