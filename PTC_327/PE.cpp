#include<stdio.h>
int n;
void _p(int s[], int ans[]){
	for(int i = 0; i < n; i++){
		for(int j = i; j >= 0; j--)
			ans[i] += s[i] > s[j];
	}
}
void _i(int s[], int ans[]){
	int j;
	for(int i = 0; i < n; i++)
		ans[i] = 999;
	for(int i = 0; i < n; i++){
		for(j = n-1; j >= 0; j--){
			int x = 0;
			for(int k = 0; k <= j; k++)
				x += i > ans[k];
			if(x == s[j]){
				ans[j] = i;
				break;
			}
		}
		if(j == -1){
			int ind = 0;
			while(ans[ind] != 999)
				ind++;
			ans[ind] = i;
		}
	}
}

int main(){
	
	while(scanf("%d", &n), n){
		char str[10];
		int s[100], ans[100] = {0};
		scanf("%s", str);
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		if(str[0] == 'p')
			_p(s, ans);
		else
			_i(s, ans);
		printf("%d", ans[0]);
		for(int i = 1; i < n; i++)
			printf(" %d", ans[i]);
		putchar(10);
	}
	return 0;
}
