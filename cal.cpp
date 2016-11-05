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
int year = 0, daysPassed = 0, month = -1;
int getDay();

int main(int argc, char * argv[]){

  if(argc == 2){
    year = *argv[1];
  }//if
  if(argc == 3){
    month = *argv[1] - '0' ;
    for(int i = 0; i < 4; i++){ 
      year *= 10;
      year += *(argv[2] + i) - '0';
    
    }
    month--;
    cout << getDay() << endl;
  }
}//main

int getDay(){
  daysPassed = -14;
  for(int i = initialMonth; (i%12) != month; i++)
    {
      if(i > 11)
	year--;
  
      i = (i%12);

      switch(month)
	{
	case 0: daysPassed += 31; break;
	case 1: 
	  if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
	    daysPassed += 29;
	  }
	  else{
	    daysPassed += 28; 
	  }
	  break;
	case 2: daysPassed += 31; break;
	case 3: daysPassed += 30; break;
	case 4: daysPassed += 31; break;
	case 5: daysPassed += 30; break;
	case 6: daysPassed += 31; break;
	case 7: daysPassed += 31; break;
	case 8: daysPassed += 30; break;
	case 9: daysPassed += 31; break;
	case 10: daysPassed += 30; break;
	case 11: daysPassed += 31; break;
	}
    }
  for(int i = 1752; i < year; i++){
    
    if((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)){
      daysPassed += 366;
    } 
    else{
      daysPassed += 365;
    }
    daysPassed += 4;
    daysPassed = daysPassed % 7;

  }//for
  return daysPassed;
}//getDay
