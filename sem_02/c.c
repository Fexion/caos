#include <stdio.h>
#include <ctype.h>

int
main()
{
    int c;
    char dot = 0;
    double ans = 0;
    int der = 7;
    char done = 0;

    while ((c = getchar_unlocked()) != EOF) {
        if (isspace(c)) {
            if (done) {
                printf("%.10g\n", ans);
                done = 0;
            }
            dot = 0;
            der = 7;
            ans = 0;
        } else if (c == '.') {
            dot = 1;
        } else if (isdigit(c)) {
            c -='0';
            if (!dot) {
                ans = ans * 7 + (double)c;
                done = 1;
            } else {
                ans += (double)c / der;
                der *= 7;
            }
        }


    }
    if (done) {
        printf("%.10g\n", ans);
    }

    return 0;
}
