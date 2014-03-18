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
	//freopen("out", "w", stdout);
	int se = 0, n, q, s[1000];
	while(scanf("%d%d", &n, &q), n + q){
		printf("SET %d:\n", ++se);
		for (int i = 0; i < n; ++i){
			scanf("%d", &s[i]);
		}
		for (int qq = 0; qq < q; ++qq){
			int m, d, x;
			long long dp[100][100] = {};
			dp[0][0] = 1;
			scanf("%d%d", &d, &m);
			for (int i = 0; i < n; ++i){
				x = (s[i]%d + d)%d;//+d for negetive s[i]
				for(int j = m; j > 0; j--)
					for(int k = 0; k <= d; k++)
						dp[j][(k+x)%d] += dp[j-1][k];
			}
			printf("QUERY %d: %lld\n", qq+1, dp[m][0]+dp[m][d]);
		}
	}
	return 0;
}