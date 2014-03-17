#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, s[50000], n, casect = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n--;
		for (int i = 0; i < n; ++i){
			scanf("%d", &s[i]);
		}
		long long Max = 0, from, to, tot, ansf = 0, anst = 0;
		for(int i = 0; i < n; i++){
			from = i;
			tot = 0;
			do{
				tot += s[i];
				to = i;
				if(tot > Max){
					Max = tot;
					ansf = from, anst = to;
				}
				else if(tot == Max && to - from > anst - ansf){
					ansf = from, anst = to;
				}
				
			}while(tot >= 0 && ++i < n);
		}
		if(Max)
			printf("The nicest part of route %d is between stops %lld and %lld\n", ++casect, ansf+1, anst+2);
		else
			printf("Route %d has no nice parts\n", ++casect);
	}
	return 0;
}