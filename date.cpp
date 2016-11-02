#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <chrono>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char * argv[]){
  
  struct tm * tim;
  time_t tt;
  time(&tt);
  tim = localtime(&tt);
  mktime(tim);
  const char * wkday[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  const char * abvwkday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  const char * month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  const char * fullmonth[] = {"January","February","March","April","May","June","July","August","Sepember","October","November","December"};
  const char * ds[] = {"EST","EDT"};

  if (argc == 1){
  cout << abvwkday[tim->tm_wday] << " " << month[tim->tm_mon] << " " << tim->tm_mday << " " 
       << tim->tm_hour << ":" << tim->tm_min << ":" << tim->tm_sec << " " 
       << ds[tim->tm_isdst] << " " << (1900 + tim->tm_year) << endl;
  }
  else if (*argv[1] == '+'){
    
    if(*(argv[1]+1) == '%'){
    
      if (*(argv[1]+2) == 'a'){
	cout << abvwkday[tim->tm_wday] << endl;
      }
      if (*(argv[1]+2) == 'A'){
	cout << wkday[tim->tm_wday] << endl;
      }
      if ((*(argv[1]+2) == 'b') || (*(argv[1]+2) == 'h')){
	cout << month[tim->tm_mon] << endl;
      }
      if (*(argv[1]+2) == 'B'){
	cout << fullmonth[tim->tm_mon] << endl;
      }
      if (*(argv[1]+2) == 'c'){
	string ampm = "AM";
	if((tim->tm_hour) > 12){
	  ampm = "PM";
	}
	cout << abvwkday[tim->tm_wday] << " " << tim->tm_mday << " " << month[tim->tm_mon] << " " << (1900 + tim->tm_year) << " " 
	     << ((tim->tm_hour) % 12) << ":" << tim->tm_min << ":" << tim->tm_sec << " " << ampm << " " 
	     << ds[tim->tm_isdst] << endl;
      }
      if (*(argv[1]+2) == 'C'){
	cout << (1900 + tim->tm_year) / 100 << endl;
      }
      if (*(argv[1]+2) == 'd'){
	cout << tim->tm_mday << endl;
      }
      if (*(argv[1]+2) == 'D'){
	cout << tim->tm_mon << "/" << tim->tm_mday << "/" << (1900 + tim->tm_year) << endl;
	  }
      if (*(argv[1]+2) == 'e'){
	cout << tim->tm_mday << " " << endl;
      }
      if (*(argv[1]+2) == 'F'){
	cout << tim->tm_mon << "-" << tim->tm_mday << "-" << (1900 + tim->tm_year) << endl;
      }
      if (*(argv[1]+2) == 'g'){
	cout << (1900 + tim->tm_year) % 100 << endl;
      }
      if (*(argv[1]+2) == 'G'){
	cout << (1900 + tim->tm_year) << endl;
      }
      if (*(argv[1]+2) == 'H'){
	cout << tim->tm_hour << endl;
      }
      if (*(argv[1]+2) == 'I'){
	cout << (tim->tm_hour) % 12 << endl;
      }
      if (*(argv[1]+2) == 'j'){
	cout << (1 + tim->tm_yday) << endl;
      }
      if (*(argv[1]+2) == 'k'){
	cout << tim->tm_hour << endl;
      }
      if (*(argv[1]+2) == 'l'){
	cout << (tim->tm_hour) % 12 << endl;
      }
      if (*(argv[1]+2) == 'm'){
	cout << (1 + tim->tm_mon) << endl;
      }
      if (*(argv[1]+2) == 'M'){
	cout << tim->tm_min << endl;
      }
      if (*(argv[1]+2) == 'n'){
	cout << "\n" << endl;
      }
      if (*(argv[1]+2) == 'N'){
	//cout << std::chrono::nanoseconds() << endl;
	//cout << std::chrono::high_resolution_clock::now() << endl;
	//auto finish = std::chrono::high_resolution_clock::now();
	//cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start) << endl;
      }
    }
  }
 
  return EXIT_SUCCESS;
}
