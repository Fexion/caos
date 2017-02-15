#include <inttypes.h>
#include <math.h>
#include <stdio.h>

int main()
{
int c = getchar_unlocked();
double pows[23];
pows[0] = 1;
for (int i = 1; i < 23; ++i)
{
pows[i] = pows[i - 1] * 7;
}
while (c != EOF)
{
int exp = 0;
double ans = 0;
while ((!('0' <= c && c <= '9') && c != '.') && c != EOF)
{ // read spaces
c = getchar_unlocked();
}
if (c == EOF)
{
break;
}
if (c != '.' && c != EOF)
{ // read integer
while ('0' <= c && c <= '9')
{
ans = ans * 7 + (c - '0');
c = getchar_unlocked();
}
}
if (c == '.' && c != EOF)
{ // read float
c = getchar_unlocked();
while ('0' <= c && c <= '9')
{
ans += (c - '0') / pows[exp+1];
c = getchar_unlocked();
++exp;
}
}
printf("%.10g\n", ans);
}
return 0;
}
