#include "InputHandler.h"
using namespace std;


/* TODO (k0sma3#9#): cross check input algorithm */
char* InputHandler::InputOperation()
{
	char *msg=0;
	cout<<"\n1.\tKeyboard Input";
	cout<<"\n2.\tFile Input\n";
	char choice;
	pt0:
	cin.clear();
	cout<< "$:>";
	cin>>choice;
	switch(choice)
		{
			case '1':msg=KeyboardInput();
				break;
			case '2':msg=FileInput();
				break;
			default:goto pt0;
				break;		
		}	
		return msg;
}

char* InputHandler::KeyboardInput()
{
    string in;
    cin.ignore();
    cout<< "\nmessage:>";
    getline(cin, in);
    char* _array_=new char[in.size()+1];
    size_t len=in.copy(_array_, in.size());
    _array_[len]='\0';
    return _array_;
}



char* InputHandler::FileInput()
{
    ifstream infile;
	OpenInputFile(infile);
	char* array=0;
	if(!infile.good())
	return array;
    string text;
    cin.ignore();
    getline(infile, text);
    array=new char[text.size()];
    int count=text.copy(array, text.size());
    array[count]='\0';
    infile.close();
    return array;
}


void InputHandler::OpenInputFile(ifstream& InFile)
{
	string filename;
	cout << "Enter name of message file" << endl;
	pt0:
	cin.ignore();
	cout<< "filename:>";
	getline(cin, filename);
	cout<< ">>"<<filename<<"?\tY/N\n";
	char ch;
	pt1:
	cin.clear();
	cout<< "$:>";
	cin>>ch;
	if(isupper(ch))
		ch=tolower(ch);
	
	if(ch=='y')
		{
			char _filename_[filename.size()+1];
			size_t len=filename.copy(_filename_, filename.size());
			_filename_[len]='\0';
			InFile.open(_filename_, ios::in);
		}
	else
	if(ch=='n')
		goto pt0;
	else
		goto pt1;
	if(!InFile.good()) 
	{
	 cout<<"couldn't open the user specified file."<<endl;
     cout<<"if the problem persists please move the text file to be opened"<<endl;
     cout<<"to the root folder of your drive and rename with a character"<<endl;
     cout<<"filename"<<endl;

     return;
	}
	return; 
}
