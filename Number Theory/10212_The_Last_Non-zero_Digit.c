#include <stdio.h>
#define LLI long long

void solve(LLI ed, LLI st) {
    LLI i, tmp = 1;
    for (i = st; i <= ed; i++) {
        while (tmp % 10 == 0) {
            tmp /= 10;
        }
        tmp *= i;
    }
    while (tmp % 10 == 0) {
        tmp /= 10;
    }
    printf("%lld\n", tmp % 10);
}

int main(int argc, char *argv[])
{
    LLI n, m;
    while (~scanf("%lld%lld", &n, &m)) {
        solve(n, n - m + 1);
    }
    return 0;
}
