#include<stdio.h>

int main(){
	int s[1000][2];
	int n;
	while(scanf("%d", &n), n){
		int ct[1000] = {0}, lose[1000] = {0}, a = 0, b = 0, max = 0;
		for(int i = 0; i < n; i++)
			scanf("%d%d", &s[i][0], &s[i][1]);
		for(int i = 0; i < n; i++)
			for(int  j= 0; j < n; j++)
				if(s[i][0] > s[j][0] && s[i][1] > s[j][1]){
					ct[i]++;
					lose[j] = 1;
				}
		for(int i = 0; i < n; i++){
			if(ct[i] > max){
				max = ct[i];
				a = s[i][0], b = s[i][1];
			}
			else if(ct[i] && ct[i] == max && a < s[i][0]){
				a = s[i][0];
				b = s[i][1];
			}
			else if(ct[i] && ct[i] == max && a == s[i][0] && b < s[i][1]){
				b = s[i][1];
			}
				
		}
		int strong = 0;
		for(int i = 0; i < n; i++)
			if(lose[i] == 0)
				strong++;
		printf("%d %d %d\n", strong, a, b);
	}
	return 0;
}
