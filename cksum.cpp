#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>

using std::cout;
using std::endl;
//#define BUFFSIZE(4096);
int n = 0;
char * buf;
uint32_t checksum(std::ifstream&);
int main(int argc, char * argv[]){
  
  //  if(argc == 1){
  //while((n = read(STDIN_FILENO, buf, BUFFSIZE) > 0){
  //	write(STDOUT_FILENO, buf, n);
  //  }
  // }
  //else{
    for(int i = 1; 1 < argc; i++){
      //    cout << checksum(argv[1]) << endl;
    }
    // }
  return EXIT_SUCCESS;
}
  uint32_t checksum(std::ifstream& file) 
  {
    uint32_t sum = 0;

    uint32_t word = 0;
    while (file.read(reinterpret_cast<char*>(&word), sizeof(word))) {
      sum += word;
    }

    if (file.gcount()) {
      word &= (~0U >> ((sizeof(uint32_t) - file.gcount()) * 8));
      sum += word;
    }

    return sum;
  }
