#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFSIZE 4096

using std::cout;
using std::endl;
using std::string;

void nope_out(const string & prefix);


int main(const int argc, const char * argv []) {
    
  if (argc > 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(EXIT_FAILURE);
  } // if

  int ofd, cfd;
  off_t size = 0;
  int siz = 0;
  //if no args
  if(argc == 1){
    char buffer[1024];
    while ((size = read(STDIN_FILENO,buffer,BUFFSIZE)) >0){
      siz = siz + size;
      //nope_out("lseek");
    }
    cout << siz << endl;
  }
  //if file args
  if(argc == 2){
    const char * filename = argv[1];
    if ((ofd = open(filename, O_RDONLY)) == -1) {
      nope_out("open");
    } // if
    if ((size = lseek(ofd,0,SEEK_END)) == -1){
      nope_out("lseek");
    }
    //print out everything





    cout << size << " " << filename << endl;
  }



  if ((cfd = close(ofd)) == -1) {
    nope_out("close");
  } // if

  return EXIT_SUCCESS;
  
} // main

void nope_out(const string & prefix) {
  perror(prefix.c_str());
  exit(EXIT_FAILURE);
} // nope_out

