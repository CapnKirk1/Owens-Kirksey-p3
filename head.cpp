#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stoi;
using std::stringstream;

char* text = NULL;
void nope_out(const string & prefix);
bool fileExists(const char * filename);
static int Read(char *filename);

int main(int argc, char * argv[]){
  char str[512] = "";
  
  if(argc == 1){
    char buffer[1024];
    int nbytes;

    while((nbytes = read(STDIN_FILENO, buffer, 128)) > 0){
      write(STDOUT_FILENO, buffer, nbytes);
    }//while

    if (nbytes == -1) nope_out("read");
  }

  if(argc == 2){
    int j = 0;
    bool exists = fileExists(argv[1]);
    if(exists){
      strcpy(str, argv[1]);
      Read(str);
      for(int i = 0; i < 10; i++){
	while(text[j] != '\n'){
	  cout << text[j];
	  j++;
	}//while
	cout << endl;
	j++;
      }//for
    }//if
    else{
      cout << "head: cannot open `" << argv[1] << "\' for reading: No such file or directory" << endl;
      exit(EXIT_FAILURE);
    }
  } 
  if(argc >= 4){
    
    for(int i = 1; i < argc; i++){
      if(*argv[i] == '-'){
	if(*(argv[i] + 1) == 'n'){

	}
	else{
	  cout << "head: invalid option -- \'" << argv[i] << "\'" << endl;
	  exit(EXIT_FAILURE);
	}
      }
    }    
    bool exists = fileExists(argv[3]);
    if(exists){
      int lines;
      string lineStr;
      stringstream ss;
      ss << argv[2];
      ss >> lineStr;
      lines = stoi(lineStr);
      int j = 0;
      strcpy(str, argv[3]);
      Read(str);
      for(int i = 0; i < lines; i++){
	while(text[j] != '\n'){
	  cout << text[j];
	  j++;
	}//while
	cout << endl;
	j++;
      }//for
    }//if  
  }
  else{
    cout << "head: cannot open `" << argv[3] << "\' for reading: No such file or directory" << endl;
    exit(EXIT_FAILURE);
  }
  
  return EXIT_SUCCESS;
}

static int Read(char *filename)
{
  FILE *file = NULL;

  file = fopen(filename, "rb");
  if (file == NULL)
    {
      return 1;
    }

  fseek(file, 0, SEEK_END);
  long  mag  = ftell(file);
  fseek(file, 0, SEEK_SET);

  text = (char*) malloc(mag + 1);

  mag = fread(text, 1, mag, file);
  if (mag == 0)
    {
      return 2;
    }

  return 0;

}



void nope_out(const string & prefix) {
  perror(prefix.c_str());
  exit(EXIT_FAILURE);
} // nope_out


bool fileExists(const char * filename)
{
  struct stat buf;
  if (stat(filename, &buf) != -1)
    {
      return true;
    }
  return false;
}
