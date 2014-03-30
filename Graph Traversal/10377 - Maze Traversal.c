#include <stdio.h>

int main(){
	int t, n, m, i, j, x, y, dir, vec[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	char map[61][61], d[4] = {'N', 'E', 'S', 'W'};
	char cmd;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d\n", &n, &m);
		for(i = 1; i <= n; i++)
			gets(map[i] + 1);
		scanf("%d %d\n", &x, &y);
		dir = 0;
		while(cmd = getchar()){
			if(cmd == 'R')
				dir = (dir + 1) % 4;
			else if(cmd == 'L')
				dir = (dir + 3) % 4;
			else if(cmd == 'F'){
				i = x + vec[dir][0], j = y + vec[dir][1];
				if(map[i][j] == ' ')
					x = i, y = j;
			}
			else if(cmd == 'Q')
				break;
		}
		printf("%d %d %c\n", x, y, d[dir]);
		if(t) putchar(10);
	}
	return 0;
}
