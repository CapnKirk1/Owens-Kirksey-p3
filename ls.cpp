#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
bool isA = false;
bool isL = false;
int j = 1;
void nope_out(const string & prefix);
int compare (const void * a, const void * b)
{
  return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char * argv []) {
  //if(argc != 1)
    {
      //char dot = '.';
      //char * noarg[1] = {&dot};
    
      for(int k = 1; k < argc; k++){
	if(*argv[k] == '-'){
	  if(*(argv[k] + 1) == 'a'){
	    isA = true;
	  }
	  if(*argv[k] == 'l'){
	    isL = true;
	  }
	}
      }
      for(j = 1; j < argc; j++){
	//doit(argc,argv);
	cout.setf(std::ios::unitbuf);
	char * dirname;
	//cout << argc << endl;  
	if (argc == 1)
	  {
	    char dot = '.';
	    dirname == &dot;
	  }
	else{
	dirname = argv[j];
	}
	DIR * dirp = nullptr;
	struct dirent * direntp;
	//open
	if ((dirp = opendir(dirname)) == nullptr ){
	  nope_out("opendir");
	} 
	char * name[128];
	int i = 0;
	while((direntp = readdir(dirp)) != nullptr){
	  if(*(direntp->d_name) != '.' || isA ){
	    name[i] = direntp->d_name;
	    i++;
	  }
	  //    if( i % 5 == 0){cout << "\n"}
	}
	qsort(name,i,sizeof(char*),compare);
	for( int j = 0; j < i; j++)
	  { 
	    if(i % 5 == 0){cout << "\n";}
	    cout << name[j] << "\t";  
	  }
	//close
	if (closedir(dirp) == -1){
	  nope_out("closedir");
	}
	cout << endl;
      }
    }
  return EXIT_SUCCESS;

} // main

void nope_out(const string & prefix) {
  perror(prefix.c_str());
  exit(EXIT_FAILURE);
} // nope_out
