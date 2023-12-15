#include "h.h"




int main() {
	system("chcp 1251>nul");
	char* mas = new char[2000];

	//char temp; 
	int i = 0;

	fill(mas, i);
	
	for (int y = 0; y < i; y++) {
		std::cout << mas[y] << "";
	}
	std::cout << "\n";//should be deleted


	int len;
	char* word = LastWord(i, mas,len);
	//PrintWord(word, len);
	std::cout << "\nproga:\n";
	Print(word, len, mas, i);


	

	
	
	
	
	return 0;
}
