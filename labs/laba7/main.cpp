#include "h.h"

using namespace std;
int main() {
	system("chcp 1251");
	int stat[256][256] = { 0 };
	int KeyLen = 1;
	int* ke = KeyFill(KeyLen);
	char* Exceptions = new char[1000];
	int* ExceptionsIndex = new int[500];
	Encoding(Exceptions, ExceptionsIndex, stat, KeyLen, ke);
	Decoding(Exceptions, ExceptionsIndex, ke, KeyLen);
	delete[] Exceptions;
	delete[] ExceptionsIndex;
	delete[] ke;
	Stats(stat);
	return 0;
}
