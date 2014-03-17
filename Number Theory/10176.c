/* Warning !!!!!
 * Each binary number starts in a new line but may expand in several lines.
 * In the begining, I try with scanf but got WA.
 * Changing to getchar, and I got AC OTZ...
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char input;
    long long int tmp = 0, MOD = 131071;
    while ((input = getchar()) != EOF) {
        if (input == '#') {
            printf("%s\n", ((tmp % MOD)?("NO"):("YES")));
            tmp = 0;
        }
        else if (input == '1' || input == '0') {
            tmp = tmp * 2;
            tmp = tmp + (input - '0');
            tmp = tmp % MOD;
        }
    }
    return 0;
}
