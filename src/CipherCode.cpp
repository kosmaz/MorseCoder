#include "CipherCode.h"
#include "Utilities.h"
using namespace std;
using namespace kosmaz;



CipherCode::CipherCode()
{
  fInput=new InputHandler();
  fStart=0;
  fIncreament=2;
  fCycle=99;
  const int tshuffle=1000;
  cout<<"\nENTER THE KEY OF THE MESSAGE\n";
  cout<<endl<< "$:>";
  Utilities* utilities=new Utilities;
  char* char_seed_value=utilities->hide_user_input();
  int seed_value=atoi(char_seed_value);
  delete char_seed_value;
  delete utilities;	
  srand(seed_value%gMaxTable);

  for(int i=0;i<tmax;i++){
      fTable[i]=i+' ';
    }

  for(int k=0;k<tshuffle;k++)
    {
      int index1=rand()%tmax;
      int index2=rand()%tmax;

      int temp=fTable[index1];
      fTable[index1]=fTable[index2];
      fTable[index2]=temp;
    }
}

CipherCode::~CipherCode()
{
	delete fInput;
}

void CipherCode::Encrypt(char*& m)
{
	int k = fStart;
	for(int i=0; m[i] != '\0'; i++)
	 {
		char ch = m[i];
		m[i] = fTable[(ch-32 +k ) % tmax];
		k += fIncreament;
	}
}

void CipherCode::encrypter()
{
  ofstream EOutFile;
  pt0:
  EOutFile.open("cipher_encrypted.txt", ios::out);
  cout<<"\nINPUT THE MESSAGE TO BE ENCRYPTED\n";
  char* msg=fInput->InputOperation();
  if(msg==0)
		return;
	for(int i=0;i<fCycle;i++)	
		Encrypt(msg);
	cout<<msg;
	EOutFile<<msg;
	EOutFile.close();
		
	cout<<"\nDO YOU WANT TO ENCRYPT ANOTHER MESSAGE USING THE SAME KEY?\n";
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

void CipherCode::MakeRTable()
{
	for(int i = 0;i < tmax; i++) 
	{
	 int tem = fTable[i];
	 tem -= ' ';
	 fRTable[tem] = i;
	}
}

void CipherCode::Decrypt(char*& m)
{
	int ch;
	int k = fStart;
	
 for(unsigned int i=0;i<strlen(m);i++)
    {
   	 ch=m[i];
     int t = fRTable[ch - 32];
   	 t -= k;
      while(t<0) t+= tmax;
       m[i]=char(t + ' ');
      k += fIncreament;
   	}

	 return;
}

void CipherCode::decrypter()
{
  MakeRTable();
  ofstream DOutFile;
  pt0:
  DOutFile.open("cipher_decrypted.txt", ios::out);	
  cout<<"\nINPUT THE MESSAGE TO BE DECRYPTED\n";
  char* msg=fInput->InputOperation();
  if(msg==0)
		return;
	for(int i=0;i<fCycle;i++)	
		Decrypt(msg);
	cout<<msg;
	DOutFile<<msg;
	DOutFile.close();
	
	cout<<"\nDO YOU WANT TO DECRYPT ANOTHER MESSAGE USING THE SAME KEY?\n";
        pt1:
        cout<<"\nY/N?\n";
        char ch1;
        cin.clear();
        cout<<endl<< "$:>";
        cin>>ch1;
        if(ch1=='y')
        	{
        		delete msg;
          	goto pt0;          
          }	
        else
        if(ch1=='n')
        	{
      	    delete msg;
      	    DOutFile.close();
    	      return;
				  }
          else
          	goto pt1;
	return;	
}
