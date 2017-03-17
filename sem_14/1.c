#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <limits.h>

int main() {

    time_t rawtime;
    struct tm * timeinfo;
    int64_t cur;
    int64_t time_in_sec;
    time( &rawtime );
    time_t loctime;
    //int64_t int_max = (llu1 << 7 - 1);
    while (scanf("%ld", &cur) != EOF) {
        time_in_sec = cur * 3600 * 24 + rawtime;
        if (time_in_sec > INT32_MAX || time_in_sec < INT32_MIN) {
            printf("OVERFLOW\n");
        } else {
            loctime = time_in_sec;
            timeinfo = localtime(&loctime);
            printf("%04d-%02d-%02d\n", (timeinfo -> tm_year) + 1900,
                    (timeinfo -> tm_mon) + 1, timeinfo -> tm_mday);
        }
    }
    return 0;
}
