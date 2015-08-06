#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 5;

	int i1 = 0xAAAAAAAA;
	int i2 = 0x55555555;

	int res = ((a & i1) >> 1) + ((a & i2) << 1);

	cout << res << endl;

	return 0;
}