#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int adj[1000][1000], visit[1000], n, ti;
set<pair<int, int> > bridge;
int dfs(int s, int t){
	int vas = visit[s] = ++ti;
	for(int i = 0; i < n; i++)
		if(adj[s][i] && i != t){
			if(visit[i]){
				vas = min(vas, visit[i]);
			}
			else{
				int va = dfs(i, s);
				vas = min(va, vas);
				if(visit[s] < va)
						bridge.insert(make_pair(s > i ? i : s, s > i ? s : i));
			}
		}
	return vas;
}
int main(){
	while(cin>>n){
		memset(adj, 0, sizeof(adj));
		memset(visit, 0, sizeof(visit));
		bridge.clear();
		for(int i = 0; i < n; i++){
			int a, b, m;
			scanf("%d (%d)", &a, &m);
			for(int j = 0; j < m; j++)
				cin >> b, adj[a][b] = adj[b][a] = 1;
		}
		for(int i = 0; i < n; i++)
			if(!visit[i])
				dfs(i, -1);
		printf("%d critical links\n", (int)bridge.size());
		for(set<pair<int, int> >::iterator it = bridge.begin(); it != bridge.end(); it++)
			printf("%d - %d\n", it -> first, it -> second);
		putchar(10);
	}
	return 0;
}