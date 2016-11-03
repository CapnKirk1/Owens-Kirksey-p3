#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stoi;
using std::stringstream;

char* text = NULL;

static int Read(char *filename);

int main(int argc, char * argv[]){
  char str[512] = "";
  if(argc == 2){
    int j = 0;
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

  if(argc == 4){
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
