#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int dp[20000];
int main(){
	int n, m, M;
	while(cin >> m >> n){
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		M = m+200;
		for(int i = 0; i < n; i++){
			int p, f;
			cin >> p >> f;
			for(int i = M; i-p >= 0; i--)
				if(dp[i-p] >= 0 && dp[i] < dp[i-p] + f)
					dp[i] = dp[i-p] + f;
		}
		int Max = -1, Mind = -1;
		for(int i = 0; i <= M; i++){
			if(Max < dp[i] && (i <= m || i > 2000))
				Max = dp[i], Mind = i;
		}
		cout << Max << endl;
	}
	return 0;
}