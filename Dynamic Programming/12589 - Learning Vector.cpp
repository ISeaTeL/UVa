#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int cmp(const void *v, const void *o){
	int *a = (int*)v, *b = (int*)o;
	if(a[1]*b[0] < b[1]*a[0])
		return 1;
	else if(a[1]*b[0] > b[1]*a[0])
		return -1;
	return 1;
}
int dp[100][3000];
int main(){
	//freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int t, n, K;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++){
		int s[100][2] = {};
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &n, &K);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &s[i][0], &s[i][1]);
		qsort(s, n, sizeof(s[0]), cmp);
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 2700; j >= 0; j--)
				for(int k = K; k > 0; k--)
					if(dp[k-1][j] >= 0 && dp[k][j+s[i][1]] < dp[k-1][j] + j*s[i][0]*2 + s[i][0]*s[i][1])
						dp[k][j+s[i][1]] = dp[k-1][j] + j*s[i][0]*2 + s[i][0]*s[i][1];
		int ans = 0;
		for(int i = 0; i < 3000; i++)
			ans = max(ans, dp[K][i]);
		printf("Case %d: %d\n", tt, ans);
	}
	return 0;
}