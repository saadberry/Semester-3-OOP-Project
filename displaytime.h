#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int displayTime(){
    char currDate[30];
time_t t= time(NULL);
struct tm tm = *localtime(&t);
sprintf(currDate,"%d-%d-%d %d:%d:%d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_day,tm.tm_hour,tm.tm_min,tm.tm_sec);
cout << currDate;
}
