#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
enum Month { January, February, March, April, May, June, July, 
	     August, September, October, November, December};
enum Day { Su, Mo, Tu, We, Th, Fr, Sa};
enum Calendar { Julian, Gregorian};

int initialDate = 14;
Month initialMonth = September;
Day initialDay = Th;
int initialYear = 1752;

long daysPassed(int, Month, int);
int day(long);
void print();

int main(int argc, char *argv[1]){

  if (argc == 0){

  }
  if (argc == 1){
    
  }
  if (argc == 2){

  }
  if (argc == 3){

  }
  print();
  return EXIT_SUCCESS;
}

long daysPassed(int date, Month m, int year)
{
  long daysPassed = 0;
  daysPassed = daysPassed + date - initialDate;

  for(int i = initialMonth; (i%12) != m; i++)
{
  if(i > 11)
    year--;
  
  i = (Month)(i%12);
  
  int q = m;
  q--; q = q % 12;
  m = (Month)q;
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
  return daysPassed;
}//daysPassed

int day(long daysPassed){
  int day = 0;
  day = 4;
  day = day + (daysPassed % 7);
  day = (day % 7);
  return day;
}//day

void print(){
  string month = "       March ";
  Month m = October;
  int n = (m + 1);
  int year = 1752;
  //cout << month << year << endl 
  ///   << "Su Mo Tu We Th Fr Sa" << endl;
  cout << n << " " << year << " " << daysPassed(1, m, year) << endl;
  /*
  for(int i = 0; i < day(daysPassed(1, March, year)); i++){
    cout << "   ";
  }
  cout << " 1" << endl;
  */
}
