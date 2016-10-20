#include <cstdlib>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

enum Month { January, February, March, April, May, June, July, 
	     August, September, October, November, December};
enum Day { Su, Mo, Tu, We, Th, Fr, Sa};
enum Calendar{Julian, Gregorian};
int initialDate = 14;
Month initialMonth = September;
Day initialDay = Th;
int initialYear = 1752;
void printMonth(int, Month, int);

int main(int argc, char *argv[1]){

  Month currentMonth = October;
  if (argc == 0){

  }
  if (argc == 1){

  }
  if (argc == 2){

  }
  if (argc == 3){

  }
  printMonth(19, currentMonth, 2016);

  return EXIT_SUCCESS;
}
void printMonth(int date, Month m, int year)
{
  long daysPassed = 0;
  daysPassed = daysPassed + date - initialDate;
  for(int i = initialMonth; (i%12) != m; i++)
{
  if(i > 11)
    year--;
  
  i = (Month)(i%12);

  switch(m)
    {
    case January: daysPassed += 31; break;
    case February: 
      if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
	daysPassed += 29;
      }
	else{
	  daysPassed += 28; 
	}
      break;
    case March: daysPassed += 31; break;
    case April: daysPassed += 30; break;
    case May: daysPassed += 31; break;
    case June: daysPassed += 30; break;
    case July: daysPassed += 31; break;
    case August: daysPassed += 31; break;
    case September: daysPassed += 30; break;
    case October: daysPassed += 31; break;
    case November: daysPassed += 30; break;
    case December: daysPassed += 31; break;
      }
 }
  for(int i = initialYear; i < year; i++)
    {
      if(i % 4 == 0 && (i % 100 != 0 || year % 400 == 0) && m <= 1){
	daysPassed += 366;
      }
      else{
	daysPassed += 365;
      }
      
    }
  int day = 0;
  day = initialDay;
  day += (daysPassed % 7);
  day = (day % 7);
  cout << "October " << year << endl << "Su Mo Tu We Th Fr Sa" << endl 
       << day << endl;
 
  
}
