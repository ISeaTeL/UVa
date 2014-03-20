#include <stdio.h>

int main(){
	int n, m, i, j, x, y, a, b;
	char ins[12][12];
	while(scanf("%d %d %d", &n, &m, &y), n + m + y){
		getchar();
		int ct[12][12] = {};
		for(i = 0; i < n; i++)
			gets(ins[i]);
		x = 0, y--;
		a = x, b = y;
		ct[x][y] = 1;
		while(1){
			if(ins[x][y] == 'N')
				a = x - 1;
			else if(ins[x][y] == 'S')
				a = x + 1;
			else if(ins[x][y] == 'W')
				b = y - 1;
			else
				b = y + 1;
			if(!(a >= 0 && a < n && b >= 0 && b < m)){
				printf("%d step(s) to exit\n", ct[x][y]);
				break;
			}
			else if(ct[a][b]){
				printf("%d step(s) before a loop of %d step(s)\n", ct[a][b] - 1, ct[x][y] - ct[a][b] + 1);
				break;
			}
			else{
				ct[a][b] = ct[x][y] + 1;
				x = a, y = b;
			}
		}
	}
	return 0;
}
