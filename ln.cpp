#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
using std::cout;
using std::endl;
bool fileExists(const char *);
int main(int argc, char* argv[] ){

  if(argc == 1){
    cout << "ln: missing file operand\nTry `ln --help\' for more information."  << endl;
  }
  if(argc == 2){
    bool exists = fileExists(argv[1]);
    if(!exists){
      cout << "ln: accessing `" << argv[1] <<"\': No such file or directory" << endl;
     return EXIT_FAILURE;
    }//if
    if(exists){
	cout << "ln: creating hard link `" << argv[1] << "\': File exists" <<endl;
      }
  }
  if(argc == 3){
    bool exists1 = fileExists(argv[1]);
    bool exists2 = fileExists(argv[2]);
  link(argv[1], argv[2]);
  if(!exists1){
    cout << "ln: accessing `"<< argv[1] << "\': No such file or directory" << endl;
  }
  if(exists2){
    cout << "ln: creating hard link `" << argv[2] << "\': File exists" <<endl;
  }
  }
  return EXIT_SUCCESS;
  
}
bool fileExists(const char * filename)
{
  struct stat buf;
  if (stat(filename, &buf) != -1)
    {
      return true;
    }
  return false;
}
