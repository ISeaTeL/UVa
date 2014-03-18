#include <stdio.h>
#include <string.h>

int n, adj[101][101], rec[101], ct;
/**/
void dfs(int x){
	int y;
	for(y = 1; y <= n; y++)
		if(adj[x][y] && !rec[y]){
			rec[y] = 1, ct++;
			dfs(y);
		}
}

int main(){
	int i, a, b, q;
	while(scanf("%d", &n), n){
		memset(adj, 0, sizeof(adj));
		while(scanf("%d", &a), a)
			while(scanf("%d", &b), b)
				adj[a][b] = 1;
		scanf("%d", &q);
		while(q--){
			memset(rec, 0, sizeof(rec));
			scanf("%d", &a);
			ct = 0;
			dfs(a);
			printf("%d", n - ct);
			for(i = 1; i <= n; i++)
				if(!rec[i])
					printf(" %d", i);
			putchar(10);
		}
	}
	return 0;
}
