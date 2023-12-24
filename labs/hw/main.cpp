#include "h.h"



//bool CheckForSpaces(char* wordCurrent,int wordCurrentLen);
int main() {
	system("chcp 1251>nul");
	char* mas = new char[2000]; 
	int textLen = 0;
	//std::cout << Compare("ghy", "ghh",3,3);
	Fill(mas, textLen);
	
	// for (int y = 0; y < textLen; y++) {
	// 	std::cout << mas[y] << "";
	// }
	// std::cout << "\n";
	// std::cout << textLen;//should be deleted
	//std::cout<<"HERE:::"<<CheckForSpaces("herguh ",7);
	int lastWordLen;
	char* word = LastWord(textLen, mas, lastWordLen);
	//std::cout << "\nlast word:";
	//PrintWord(word, lastWordLen);
	//std::cout << LastWordLen;
	//std::cout << "\nproga:\n";
	putch('\n');
	Print(word, lastWordLen, mas, textLen);

	return 0;
}
