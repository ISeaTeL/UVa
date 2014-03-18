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
	int n, t, s[10000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i){
			scanf("%d", &s[i]);
		}
		reverse(s, s+n);
		int dp[10000][2] = {};
		for(int i = 0; i < n; i++){
			dp[i][0] = dp[i][1] = 1;
			for(int j = 0; j < i; j++){
				if(s[j] > s[i] && dp[j][1] + 1 > dp[i][1])
					dp[i][1] = dp[j][1] + 1;
				if(s[j] < s[i] && dp[j][0] + 1 > dp[i][0])
					dp[i][0] = dp[j][0] + 1;
			}
		}
		int Max = 0;
		for(int i = 0; i < n; i++){
			if(Max < dp[i][0] + dp[i][1] - 1)
				Max = dp[i][0] + dp[i][1] - 1;
		}
		printf("%d\n", Max);
	}
	return 0;
}
