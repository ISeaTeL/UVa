#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define MAX 60000
using namespace std;
int n, s[MAX], t, rec[MAX];
int lower_bit(int x) {
	return x & -x;
}
void build(int n) {
	for (int i = 1; i <= n; i++)
		rec[i] = lower_bit(i);
}
int sum_(int n) {
	int tot = 0;
	while (n > 0) {
		tot += rec[n];
		n -= lower_bit(n);
	}
	return tot;
}
void minus_(int x) {
	while (x <= n) {
		rec[x] -= 1;
		x += lower_bit(x);
	}
}
int get(int x) {
	int upper = n, lower = 1, mid;
	while (upper >= lower) {
		mid = (upper + lower) / 2;
		if (sum_(mid) >= x)
			upper = mid - 1;
		else
			lower = mid + 1;
	}
	minus_(lower);
	return lower;
}
int main(int argc, char *argv[]) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &s[n - 1 - i]);
		for (int i = 0; i < n; i++) {
			s[i + 1] += s[i] / (i + 1);
			s[i] %= i + 1;
		}
		build(n);
		for (int i = n - 1; i >= 0; i--) {
			printf("%d", get(s[i] + 1));
			if (i)
				putchar(32);
		}
		putchar(10);
	}
	return 0;
}