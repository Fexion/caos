#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char const *argv[]) {
    argc--;
    int year, month_day, day ;
    sscanf (argv[1],"%d",&year);
    sscanf (argv[2],"%d",&month_day);
    sscanf (argv[3],"%d",&day);
    int count = 0;
    if (day == 7) {
        day = 0;
    }
    time_t rawtime;
    struct tm * timeinfo;
    for (int month = 0; month < 11; ++month) {
        time( &rawtime );
        timeinfo = localtime( &rawtime );
        timeinfo->tm_year = year - 1900;
        timeinfo->tm_mon = month;
        timeinfo->tm_mday = month_day;

        mktime( timeinfo );
        if ( timeinfo->tm_wday == (day)) {
            ++count;
        }
    }
    printf("%d\n", count);
    return 0;
}
