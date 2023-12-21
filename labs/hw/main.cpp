#include "h.h"




int main() {
	system("chcp 1251>nul");
	char* mas = new char[2000];

	//char temp; 
	int textLen = 0;

	Fill(mas, textLen);
	
	for (int y = 0; y < textLen; y++) {
		std::cout << mas[y] << "";
	}
	std::cout << "\n";//should be deleted
	std::cout << textLen;

	int LastWordLen;
	char* word = LastWord(textLen, mas, LastWordLen);
	std::cout << "\nlast word:";
	PrintWord(word, LastWordLen);
	std::cout << "\nproga:\n";
	Print(word, LastWordLen, mas, textLen);


	

	
	
	
	
	return 0;
}
