#include <iostream>
using namespace std;
void sol(int n, int from, int by, int to) {
	if (n <= 1) {
		printf("%d %d\n", from, to);
		return;
	}
	sol(n - 1, from, to, by);
	printf("%d %d\n", from, to);
	sol(n - 1, by, from, to);
}
int pow(int x, int y) {
	if (y == 0) return 1;
	if (y % 2 == 0) {
		int tmp = pow(x, y / 2);
		return tmp * tmp;
	}
	else return x * pow(x, y - 1);
}
int main() {
	int N;
	scanf("%d", &N);
	cout << pow(2, N) - 1 << endl;
	sol(N, 1, 2, 3);
	return 0;
}