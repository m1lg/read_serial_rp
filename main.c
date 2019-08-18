
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main( void ) {

time_t current;
time_t previous;

printf("egg\n");

struct timespec ts;
struct timespec ts_new;
timespec_get(&ts, TIME_UTC);
char buff[100];
strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
for (;;) {
    timespec_get(&ts_new, TIME_UTC);
    

    strftime(buff, sizeof buff, "%D %T", gmtime(&ts_new.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts_new.tv_nsec);


    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));
    printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);

    printf("Pin 1 is %d\n", digitalRead(1));
    printf("Pin 2 is %d\n", digitalRead(2));
    delay(500);

}



}
