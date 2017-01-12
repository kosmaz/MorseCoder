//handles keyboard and file input operations
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H


#include <fstream>
#include <iostream>
#include <string>
#include <strings.h>
#include <stdlib.h>

class InputHandler
{
	friend class MorseCode;
	friend class CipherCode;
	
	private:
	char* InputOperation();
	char* FileInput();
	char* KeyboardInput();
	void OpenInputFile(std::ifstream& Infile);
		
};

#endif //INPUTHANDLER_H
