#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int time(int argc,char *argv[]){
    char currDate[30];
time_t t= time(NULL);
struct tm tm = *localtime(&t);
sprintf(currDate,"%d:%d:%d",tm.tm_hour,tm.tm_min,tm.tm_sec);
cout << currDate;
}
