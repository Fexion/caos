#include <stdio.h>
#include <inttypes.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>



int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    wint_t inp;
    char f = 1;
    while ((inp = getwchar()) != WEOF) {
        if (!iswspace(inp)) {
            if (iswlower(inp) && f) {
                inp = towupper(inp);
            }
            printf("%lc", inp);
            f = 0;
        } else {
            printf("%lc", inp);
        }
        if (inp == '.' || inp == '!' || inp == '?') {
            f = 1;
        }

    }
    //printf("\n");
    return 0;
}
