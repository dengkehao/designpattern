#include <iostream>
#include <vector>
#include <iomanip>


int add(int a, int b)
{
	return a + b;
}
int main() {
	int x = 1;
	const int y = 2;
	int c = add(x, y);
	std::cout << c;
	return 0;


}