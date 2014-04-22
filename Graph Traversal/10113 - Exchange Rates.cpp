#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int adj[61][61], n;

int GCD(int a, int b){
	while(a && b){
		if(a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

void dfs(int x, int y){
	int z, a, b, c, d, gcd, r1, r2;
	for(z = 0; z < n; z++){
		if(x != z && adj[y][z] && !adj[x][z]){
			a = adj[x][y], b = adj[y][x];
			c = adj[y][z], d = adj[z][y];
			gcd = GCD(b, c);
			r1 = c / gcd;
			r2 = b / gcd;
			gcd = GCD(a * r1, d * r2);
			adj[x][z] = a * r1 / gcd;
			adj[z][x] = d * r2 / gcd;
			dfs(x, z);
		}
	}
}

int main(){
	int a, b, x, y, gcd;
	char cmd[2], tmp[2];
	string s1, s2;
	map<string, int> m;
	while(scanf("%s", cmd), cmd[0] != '.'){
		if(cmd[0] == '!'){
			cin >> a >> s1 >> tmp >> b >> s2;
			if(m.find(s1) == m.end())
				m[s1] = n++;
			if(m.find(s2) == m.end())
				m[s2] = n++;
			x = m[s1], y = m[s2];
			gcd = GCD(a, b);
			adj[x][y] = a / gcd;
			adj[y][x] = b / gcd;
		}
		else{
			cin >> s1 >> tmp >> s2;
			if(m.find(s1) == m.end())
				m[s1] = n++;
			if(m.find(s2) == m.end())
				m[s2] = n++;
			x = m[s1], y = m[s2];
			for(int i = 0; i < n; i++)
				if(adj[x][i])
					dfs(x, i);
			if(adj[x][y])
				cout << adj[x][y] << ' ' << s1 << " = " << adj[y][x] << ' ' << s2 << '\n';
			else
				cout << "? " << s1 << " = " << "? " << s2 << '\n';
		}
	}
	return 0;
}
