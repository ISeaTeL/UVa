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
using namespace std;
long long arg[10], x, y, n, pw_a_b[100], pw_ab[100];
long long f(long long n) {
	for (int i = 0; i < 64; i++)
		if ((1LL << i) == n)
			return pw_a_b[i];

	long long temp_a_b = 2, temp_ab = 1, pw = 0;
	for (int i = 0; i < 64; i++)
		if ((n >> i) & 1) {
			temp_a_b = temp_a_b * pw_a_b[i] - temp_ab * f((1LL << i) - pw);
			temp_ab *= pw_ab[i];
			pw += 1L << i;
		}

	return temp_a_b;
}
int main(int argc, char *argv[]) {
	string str;
	while (getline(cin, str)) {
		stringstream ss;
		ss << str;
		int ct = 0;
		while (ss >> arg[ct++]);
		if (ct == 3 && arg[0] + arg[1] == 0)
			break;
		pw_a_b[0] = arg[0], pw_ab[0] = arg[1], n = arg[2];
		for (int i = 1; i < 64; i++) {
			pw_ab[i] = pw_ab[i - 1] * pw_ab[i - 1];
			pw_a_b[i] = pw_a_b[i - 1] * pw_a_b[i - 1] - 2 * pw_ab[i - 1];
		}
		printf("%lld\n", f(n));
	}
	return 0;
}