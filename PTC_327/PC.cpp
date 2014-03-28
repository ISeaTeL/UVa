#include<stdio.h>

int main(){
	int n;
	while(scanf("%d", &n), n){
		int adj[100][100] = {0}, fg = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &adj[i][j]);
		for(int a = 0; a < n; a++)
			for(int b = 0; b < n; b++)
				for(int c = 0; c < n; c++)
					for(int d = 0; d < n; d++){
						int ct[100] = {0}, x = 0;
						ct[a]++, ct[b]++, ct[c]++, ct[d]++;
						for(int i = 0; i < n; i++)
							if(ct[i] == 1)
								x++;
							if(x == 4 && adj[a][b] && adj[b][c] && adj[c][d] && adj[d][a])
								fg = 1;
					}
		if(fg)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
