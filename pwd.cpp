#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <err.h>
using std::cout;
using std::endl;

/*
 Prints out the path from path max to your current directory
*/
  int main( void ){
    char* p;
    char buff[PATH_MAX + 1];
    cout.setf(std::ios::unitbuf);
    p = getcwd( buff, PATH_MAX + 1 );
    if( p != NULL ) {
      cout << p << endl;
    }
    
    return EXIT_SUCCESS;
  }
 
