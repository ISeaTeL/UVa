#include <stdio.h>

int n;
char adj[101][101], all_vis[101], vis[101], dom[101][101];

void dfs(int x, int stop){
	if(x == stop)
		return;
	vis[x] = 1;
	int y;
	for(y = 0; y < n; y++)
		if(adj[x][y] && !vis[y])
			dfs(y, stop);
}

int main(){
	int t, i, j, tc = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &adj[i][j]);
		for(i = 0; i < n; i++)
			vis[i] = 0;
		dfs(0, -1);
		for(i = 0; i < n; i++)
			all_vis[i] = vis[i];
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
				vis[j] = 0;
			dfs(0, i);
			for(j = 0; j < n; j++)
				dom[i][j] = (all_vis[j] && !vis[j]) ? 1 : 0;
		}
		printf("Case %d:\n", ++tc);
		for(i = 0; i < n; i++){
			putchar('+');
			for(j = 0; j < 2 * n - 1; j++)
				putchar('-');
			puts("+");
			putchar('|');
			for(j = 0; j < n; j++){
				if(dom[i][j])
					putchar('Y');
				else
					putchar('N');
				putchar('|');
			}
			putchar(10);
		}
		putchar('+');
		for(i = 0; i < 2 * n - 1; i++)
			putchar('-');
		puts("+");
	}
	return 0;
}
