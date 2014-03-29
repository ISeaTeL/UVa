#include <stdio.h>
#include <string.h>

int adj[30][30], rec[30];

int main(){
	int n, i, j, sum0, sum1, fg, ans;
	while(scanf("%d", &n), n){
		memset(adj, 0, sizeof(adj));
		memset(rec, 0, sizeof(rec));
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &adj[i][j]);
		fg = 1;
		while(fg){
			fg = 0;
			for(i = 0; i < n; i++){
				if(rec[i])
					continue;
				sum0 = sum1 = 0;
				for(j = 0; j < n; j++){
					if(rec[j] || i == j)
						continue;
					if(adj[i][j])
						sum1++;
					else
						sum0++;
				}
				if(sum0 < 2 || sum1 < 2)
					rec[i] = 1, fg = 1;
			}
		}
		ans = 0;
		for(i = 0; i < n; i++)
			if(!rec[i])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
