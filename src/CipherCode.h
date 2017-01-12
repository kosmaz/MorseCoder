//for encrypting string of characters using cipher mechanism
#ifndef CIPHERCODE_H
#define CIPHERCODE_H

#include "InputHandler.h"

const int tmax=95;
const int gMaxTable=1000;

class CipherCode
{
	public:
		CipherCode();
		~CipherCode();
		void encrypter();
		void decrypter();
						
	private:
		void Decrypt(char*& m);
		void MakeRTable();
        void Encrypt(char*& m);
		 
         char fTable[tmax]; 
         char fRTable[tmax];
         int fStart;
         int fCycle;
         int fIncreament;
         InputHandler* fInput;
};

#endif //CIPHERCODE_H
