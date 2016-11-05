#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::endl;
char* text = NULL;
long mag;
int lineCount;
int wordCount;
int byteCount;

static int Read(char *filename);

int main(int argc, char * argv[]){
  //char str[512] = "";
  //strcpy(str, argv[1]);
  Read(argv[1]);
    for(int i = 0; i < mag; i++){
    if(text[i] == '\n'){
      lineCount ++;
    }
    }
  for(int i = 0; i < mag; i++){
   
    if(text[i] == ' ' || (text[i] == '\n' && !(text[i+1] == '\n' || text[i+1] == ' '))) {
      wordCount ++;

      while(text[i+1] == ' ' || text[i+1] == '\n'){
	i++;
      }
    }
  }
  cout << lineCount << "  "  << wordCount << " " << mag << endl;
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
  mag  = ftell(file);
  fseek(file, 0, SEEK_SET);

  text = (char*) malloc(mag + 1);

  mag = fread(text, 1, mag, file);
  if (mag == 0)
    {
      return 2;
    }

  return 0;

}
