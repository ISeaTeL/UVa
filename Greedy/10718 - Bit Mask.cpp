#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    //freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    long long n, l, u, ans;
    while(scanf("%lld%lld%lld", &n, &l, &u) > 0){
        ans = 0;
        for(int i = 31; i >= 0; i--){
            if((ans | (1L << i)) <= ((n & (1L << i)) ? l : u))
                ans |= 1L << i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}