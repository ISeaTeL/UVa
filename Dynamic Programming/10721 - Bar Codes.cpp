#include <cstdio>

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m) > 0){
		long long int dp[100][100] = {0};
		dp[0][0] = 1;
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < n; j++)
				for(int l = 1; l <= m; l++)
					dp[i][j+l] += dp[i-1][j];
		}
		printf("%lld\n", dp[k][n]);
	}
	return 0;
}