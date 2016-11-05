#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <sstream>
#include <string.h> 
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char * argv[]){

  int mode = 0755;
  if (argc == 1)
    {
      cout << "mkdir: missing operand" << endl;
      exit(EXIT_FAILURE);
    }

  for(int i = 1; i < argc; i++)
    {
      if( *(argv[i]) == '-')
	{
	  if( *(argv[i] + 1) == 'm')
	    {
	      i++;
	      mode = atoi(argv[i]);
	      char temp[16];
	      if(mode < 7) 
		{
		  strcpy(temp, "0");
		  strcat(temp, "0");
		  strcat(temp, "0");
		  strcat(temp, argv[i]);
		}
	      if(mode < 70) 
		{
		  strcpy(temp, "0");
		  strcat(temp, "0");
		  strcat(temp, argv[i]);
		}
	      if(mode < 700) 
		{
		  strcpy(temp, "0");
		  strcat(temp, argv[i]);
		}
	      mode = std::stoi(temp);
	      cout << "Mode of directory below: " << mode << endl;
	    }
	}
      else{
	cout << "Directory Made: " << argv[i] << endl;
	mkdir(argv[i],mode);
	mode = 0755;
      }
    }
  return EXIT_SUCCESS;
}
