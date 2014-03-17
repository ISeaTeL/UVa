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
	int w, t, n, m, fg = 0;
	while(scanf("%d%d", &m, &w) > 0){
		int dp[1002][2] = {}, depth, value, s[50][2];
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d%d", &depth, &value);
			s[i][0] = depth, s[i][1] = value;
			depth *= w*3;
			for(int j = m; j-depth >= 0; j--)
				if(dp[j][0] < dp[j-depth][0]+value){
					dp[j][0] = dp[j-depth][0]+value;
					dp[j][1] = dp[j-depth][1] | (1 << i);
				}
		}
		int Max = 0, state = 0, bct = 0;
		for(int i = 0; i <= m; i++)
			if(Max < dp[i][0])
				Max = dp[i][0], state = dp[i][1];
		if(fg++)
			putchar(10);
		printf("%d\n", Max);
		for(int i = 0; i < n; i++)
			if(1&(state >> i))
				bct++;
		printf("%d\n", bct);
		for(int i = 0; i < n; i++)
			if(1&(state >> i))
				printf("%d %d\n", s[i][0], s[i][1]);
	}
	return 0;
}