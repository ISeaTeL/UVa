#include<cstdio>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
map<vector<int>, int> M;
int n, m;
int di[] = {1, 0,-1, 0};
int dj[] = {0, 1, 0,-1};
struct STATE{
	int posi, posj;
	int log, step;
	char s[20][20];
}State;
int in(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}
int can(char c){
	return c == 'S' || c == 'B' || c == 'E';
}
int unique_(STATE& state){
	vector<int> v;
	v.push_back(state.posi);
	v.push_back(state.posj);
	v.push_back(state.log);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v.push_back(state.s[i][j]);
	if(M[v] == 0){
		M[v] = 1;
		return 1;
	}
	return 0;
}
void init(){
	State.posi = State.posj = State.log = State.step = 0;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			if(State.s[i][j] == 'B')
				State.posi = i, State.posj = j;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		M.clear();
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%s", State.s[i]);
		init();
		int ans = 0;
		queue<STATE> Q;
		Q.push(State);
		while(!Q.empty() && !ans){
			STATE now = Q.front();
			Q.pop();
			//find log
			int log[4] = {};
			for(int k = 0; k < 4; k++){
				int i = now.posi+di[k], j = now.posj+dj[k];
				while(in(i, j) && now.s[i][j] == (k%2?'-':'|'))
					log[k]++, i += di[k], j += dj[k];
			}

			//travel
			for(int k = 0; k < 4; k++){
				int i = now.posi+(log[k]+1)*di[k], j = now.posj+(log[k]+1)*dj[k];
				char c = now.s[i][j];
				if(log[k] && in(i, j) && can(c)){
					if(c == 'E')
						ans = now.step+1;
					STATE next = now;
					next.step++;
					next.posi = i;
					next.posj = j;
					if(unique_(next))
						Q.push(next);
				}
			}
			//get log
			if(now.log == 0)
				for(int k = 0; k < 4; k++)
					if(log[k]){
						STATE next = now;
						next.log = log[k];
						next.step = now.step+1;
						for(int x = 1; x <= log[k]; x++)
							next.s[x*di[k]+next.posi][x*dj[k]+next.posj] = '.';
						if(unique_(next))
							Q.push(next);
					}
			//put log
			if(now.log)
				for(int k = 0; k < 4; k++){
					int i = now.posi+di[k]*(now.log+1);
					int j = now.posj+dj[k]*(now.log+1);
					if(in(i, j) && can(now.s[i][j])){
						STATE next = now;
						int fg = 1;
						for(int l = 1; l <= now.log; l++){
							fg = fg && next.s[now.posi+l*di[k]][now.posj+l*dj[k]] == '.';
							next.s[now.posi+l*di[k]][now.posj+l*dj[k]] = (k%2?'-':'|');
						}
						next.step++;
						next.log = 0;
						if(fg && unique_(next))
							Q.push(next);
					}
				}
		}
		printf("%d\n", ans);
	}
	return 0;
}