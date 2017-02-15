#include <stdio.h>
#include <inttypes.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>



int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    uint32_t digit = 0, upper = 0, lower = 0;
    wint_t inp;
    while ((inp = getwchar()) != WEOF) {
        if (iswdigit(inp)) {
            digit++;
        } else if (iswupper(inp)) {
            upper++;
        } else if (iswlower(inp)) {
            lower++;
        }
    }
    printf("%u\n%u\n%u\n", digit, upper, lower);
    return 0;
}
