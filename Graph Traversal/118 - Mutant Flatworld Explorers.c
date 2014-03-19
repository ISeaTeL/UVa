#include <stdio.h>

int main(){
	int n, m, i, x, y, a, b, dir, vec[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	char c, cmd[101], lost[51][51] = {}, fg, d[4] = {'N', 'E', 'S', 'W'};
	scanf("%d %d", &n, &m);
	while(scanf("%d %d %c\n", &x, &y, &c) > 0){
		gets(cmd);
		for(i = 0; i < 4; i++)
			if(c == d[i])
				break;
		dir = i;
		fg = 0;
		for(i = 0; cmd[i]; i++){
			if(cmd[i] == 'L')
				dir = (dir + 3) % 4;
			else if(cmd[i] == 'R')
				dir = (dir + 1) % 4;
			else{
				a = x + vec[dir][0], b = y + vec[dir][1];
				if(a >= 0 && a <= n && b >= 0 && b <= m)
					x = a, y = b;
				else if(!lost[x][y]){
					lost[x][y] = 1;
					fg = 1;
					break;
				}
			}
		}
		printf("%d %d %c", x, y, d[dir]);
		if(fg) printf(" LOST");
		puts("");
	}
	return 0;
}
