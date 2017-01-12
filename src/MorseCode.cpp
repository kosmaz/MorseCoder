#include "MorseCode.h"
using namespace std;

identify characters[]={"/",".-/","-.../","-.-./","-../","./","..-./","--./","..../","../","----/","-.-/",
    ".-../","--/","-./","---/",".--./","--.-/",".-./",".../","-/","..-/","...-/",".--/",
    "-..-/","-.--/","--../","-----/",".----/","..---/","...--/","....-/","...../",
    "-..../","--.../","---../","----./"};
    
char alphabets[]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t',
    'u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};

MorseCode::MorseCode()
{
  fLength=klength;
  fC_Length=k_c_length;
  fInput=new InputHandler();

}

MorseCode::~MorseCode()
{
	delete fInput;

}

void MorseCode::encrypter()
{ 	
  ofstream EOutFile("morse_encrypted.txt", ios::out);
  pt0:
  cout<<"INPUT THE MESSAGE TO BE ENCRYPTED TO MORSE CODE\n";
  char ch;
  char* msg=fInput->InputOperation();
  if(msg==0)
  	return;
  for(unsigned int k=0;k<strlen(msg);k++)
  {
  	ch=msg[k];
    for(int i=0;i<fLength;i++)
     if(ch==alphabets[i])
      {
      	cout<<characters[i]; 
        EOutFile<<characters[i];
      }
  }
        cout<<"\nDO YOU WANT TO ENCRYPT ANOTHER MESSAGE?\n";
        pt1:
        cout<<"\nY/N?\n";
        char ch1;
        cin.clear();
        cout<<endl<< "$:>";
        cin>>ch1;
        if(ch1=='y')
        	{
          	delete []msg;
          	goto pt0;          
					}	
        else
        if(ch1=='n')
        	{
            delete []msg;
            EOutFile.close();
          	return;
		  		}
         else
          goto pt1;   
    return;        
}

void MorseCode::decrypter()
{
	ofstream DOutFile("morse_decrypted.txt",ios::out);
	pt0:
	char* checked= new char[fC_Length];
	initialize(checked);

	cout<<"INPUT THE MESSAGE TO BE DECRYPTED TO MORSE CODE\n"; 
	fMsg=fInput->InputOperation();
	if(fMsg==0)
		return;
		
	fMsgLength=strlen(fMsg);

for(int i=0,j=0;i<fMsgLength;i++,j++)
  {
    checked[j]=fMsg[i];                  
    if(checked[j]=='/')
      {
      	de_switch_char(characters, checked, DOutFile);
        initialize(checked);
        j=-1;
      }
    if(i==fMsgLength-1)
      {
        cout<<"\nDO YOU WANT TO DECRYPT ANOTHER MESSAGE?\n";
        pt1:
        cout<<"\nY/N?\n";
        char ch;
        cin.clear();
        cout<<endl<< "$:>";
        cin>>ch;
        if(ch=='y')
        	{
          	delete []fMsg;          
 			delete []checked;
        	goto pt0;          
					}		
        else
        if(ch=='n')
        	{
            delete []fMsg;
            delete []checked;
            DOutFile.close();
          	return;
		  		}	
          else
          	goto pt1;
       }
  }
  return;
}

void MorseCode::de_switch_char(const identify characters[], const identify2 checked, ofstream& out1) const
{
  for(int i=0;i<fLength;i++)
    if(strcmp(checked,characters[i])==0)
      {
        cout<<alphabets[i];
        out1<<alphabets[i];
      }
      return;
}
/*c++ does not compare int with pointer variables defined using typedef
 *it means that conditional statements done using if,while,do while etc
 *before the comparism is done on the arguments they are first converted
 *to integers and then the gotten values from the arguments is then used
 * in the comparism to return a 0 or 1 value to the conditional statement
 */
