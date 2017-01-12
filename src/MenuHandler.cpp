#include "MenuHandler.h"
#include "MorseCode.h"
#include "CipherCode.h"
#include "Utilities.h"
using namespace std;



void MenuHandler::RunProgram()
{
	/*Trying to give access to only specific users*/
        cout<<"                        \tCRYPTOGRAPH"<<endl;
        cout<<"          To have access to the cryptograph please input the key code."<<endl;
        cout<< "key:>";
        kosmaz::Utilities* utilities=new kosmaz::Utilities;
  		char* in=utilities->hide_user_input();
 		int in1=atoi(in);
		delete in;	
  		delete utilities;
          if(in1!=1010)
          return;
        else
            cout<<endl<<endl<<endl<<endl<<endl;
            cout<<"PLEASE SELECT YOUR OPTION IN THE MENU GIVEN BELOW"<<endl;
            cout<<endl<<endl;
            pt0:
            cout<<"1. MORSE CODE"<<endl;
            cout<<"2. CIPHER CODE"<<endl;
            cout<<"3. EXIT"<<endl;
            cout<<endl<<endl<<endl;
            char ch;
            Pt1:
            cout<< "$:>";
            cin>>ch;            
            switch(ch)
              {
              case '1':
              {
              	MorseCode Run;
              	cout<<"1.	ENCRYPTER"<<endl;
				       
			   		      cout<<"2.	DECRYPTER"<<endl;
				 	      cout<<"3.	RETURN TO MAIN MENU"<<endl;
								char which;
								pt2:
								cin.clear();
								cout<<endl<< "$:>";
								cin>>which;
								cout<<endl;
								if(which=='1')
									Run.encrypter();
								else
								if(which=='2')
									Run.decrypter();
								else
								if(which=='3')
									goto pt0;
								else
									goto pt2;
							 }		
							goto pt0;
 	               	break;
        
                                 
              case '2':
              {
              	CipherCode Run;
              	cout<<"\n1.	ENCRYPTER"<<endl;
								cout<<"2.	DECRYPTER"<<endl;
								cout<<"3.	RETURN TO MAIN MENU"<<endl;
								char which;
								pt3:
								cin.clear();
								cout<<endl<< "$:>";
								cin>>which;
								cout<<endl;
								if(which=='1')
									Run.encrypter();
								else
								if(which=='2')
									Run.decrypter();
								else
								if(which=='3')
									goto pt0;
								else
  								goto pt3;
              }
              goto pt0;
                break;
                
              case '3':
              {
              	cout<<"\nExit? Y/N\n\n";
                char ch;
								cin.clear();
								pt4:
								cout<< "$:>";
								cin>>ch;
								ch=tolower(ch);
								if(ch=='y')
									{	
										cout<<"\nContact us:\n";
										cout<<"08139278033\n";
										cout<<"kosmaz2009@yahoo.com\n\n";
										system("pause");
										return;
									 }
								else
								if(ch=='n')
									goto pt0; 
								else
				 					goto pt4;
				 			 }		
                break;
                
                default:goto Pt1;	 
                break;			  
     		}
        return;
}
