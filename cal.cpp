#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
const char * fullmonth[] = {"January","February","March","April","May","June","July","August","Sepember","October","November","December"};
int initialYear = 1752, initialMonth = 1;
int year = 0, day = 1, month = -1;

struct tm * tim;
void displayYear(int mon, int yr);
void displayWeek();
void displayDays();
int daysin(int mon);
int weekDay();
int main(int argc, char * argv[]){
  
  time_t tt;
  time(&tt);
  tim = localtime(&tt);
  mktime(tim);    
  year = (1900 + tim->tm_year);
  month = tim->tm_mon;
  day = tim->tm_mday;
  stringstream mon;
  stringstream yer;
  if(argc == 2){
    year = *argv[1];
  }
  if(argc == 3){
    mon << argv[1];
    mon >> month;
    month--;
    month = month % 12;
    yer << argv[2];
    yer >> year;

    // month = *argv[1] - '0' ;
    //month--;
    //for(int i = 0; i < 4; i++){ 
    // year *= 10;
    // year += *(argv[2] + i) - '0';
    //}
    day = 1;    
  } 
  displayYear(month,year);
  displayWeek();
  displayDays();
  
}//main

int weekDay(){
  tm timeStruct = {};
  timeStruct.tm_year = year - 1900;
  timeStruct.tm_mon = month - 1;
  timeStruct.tm_mday = 1;
  timeStruct.tm_hour = 12; //  To avoid any doubts about summer time, etc.
  mktime(&timeStruct);
  return timeStruct.tm_wday;
}
void displayYear(int mon, int yr){
  const char * fullmonth[] = {"January","February","March","April","May","June","July","August","Sepember","October","November","December"};
  cout << "    " << fullmonth[mon] << " " << yr << endl;
}
void displayWeek(){
  cout << "Su Mo Tu We Th Fr Sa" << endl;
}
void displayDays(){
  int weekday = (tim->tm_wday-((day-1) % 7) % 7);
  for(int i=1;i<=daysin(month);i++){
    if(i ==1){
      for(int j = 0; j < weekday; j++){
	cout << "   ";
      }
    }
    if(i < 10)
      cout << " "<< i <<" ";
    if(i >= 10)
      cout << i<< " ";
    if((weekday % 7) == 6){
      cout << "\n";
    }
    weekday++;
  }
  cout << "\n" << endl;
}


int daysin(int mon){
  switch(mon){
  case 0: return 31; break;
  case 1: 
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      return 29;
    }
    else{
      return 28; 
    }
    break;
  case 2: return 31; break;
  case 3: return 30; break;
  case 4: return 31; break;
  case 5: return 30; break;
  case 6: return 31; break;
  case 7: return 31; break;
  case 8: return 30; break;
  case 9: return 31; break;
  case 10: return 30; break;
  case 11: return 31; break;
  default: return 0;
  }
}
