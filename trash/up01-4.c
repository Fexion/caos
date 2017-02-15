#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <inttypes.h>
int main() {
    int char_code;
    int64_t result = 0;
    double double_length = 0;
    int val = 0;
    int printed = 1;
    int max_int = (~(unsigned int)0) >> 1;
    int min_int = ~max_int;
    while ((char_code = getchar()) != EOF)  {
        if (isspace(char_code) == 0) {
            if (ispunct(char_code) != 0){
                double_length = 1;
            } else {
                if (char_code == 'a') val = -1;
                else val = char_code - '0';
                if (double_length == 0) {
                    printed = 0;
                    result = result*3 + val;
                }
            }
        } else {
            if (printed == 0) {
                printed = 1;
                if ((result >= (min_int + 1)) && (result <= max_int)) {
                    printf("%.10g", result);
                } else printf("%lld\n", min_int);
                result = 0;
                double_length = 0;
            }
        }
    }

}
