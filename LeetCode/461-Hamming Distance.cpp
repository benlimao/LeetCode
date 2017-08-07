#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 32; i++)
	{
		if (x % 2 != y % 2)
			cnt++;
		x = x >> 1;
		y = y >> 1;
	}
	return cnt;
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int cnt = hammingDistance(x, y);
		cout << cnt;
	}
	return 0;
}