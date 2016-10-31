#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

using std::cout;
using std::endl;

int main(int argc, char * argv[]){
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir (argv[0])) != NULL) {
    
    while ((ent = readdir (dir)) != NULL) {
      if(*(ent->d_name) == '.'){
	cout << ent->d_name << endl;
	//unlink(temp);                                                            
      }
    }
    closedir (dir);
  }
  return EXIT_SUCCESS;
}
