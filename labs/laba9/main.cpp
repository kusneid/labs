#include "h.h"


; int main() {
	
	system("chcp 1251 >nul");

	//std::fstream file("output.txt");
	const int max_len = 200;
	//Dictionary mas[max_len];
	Dictionary* mas = new Dictionary[max_len];
	/*if (!file.is_open()) {
		std::cout << "File error!!\n";
		return 0;
	}*/
	int cur_len = 0;
	Fill(mas, cur_len);

	
	while (true)
	{
		switch (Menu())
		{
		case(1):AddWords(mas, cur_len, max_len); break;
		case(2):DeleteWord(mas, cur_len); break;
		case(3):Translate(mas, cur_len, 0); break;
		case(4):Translate(mas, cur_len, 1); break;
		case(5):PrintDictionary(mas, cur_len); break;
		case(6):DictionaryToFile("output.txt",mas, cur_len);
			break;
		case(7):return 0;
		
		}
	}
	
}