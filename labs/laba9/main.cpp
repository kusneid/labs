#include "h.h"

int main() {
	const int max_len = 3;
	Dictionary mas[max_len];
	int user_input, cur_len = 0;//true size of mas
	bool isFull = false;
	while (true)
	{
		user_input = Menu();
		switch (user_input)
		{
		case(1):AddWords(mas, cur_len, max_len,isFull); break;
		case(2):DeleteWord(mas, cur_len); break;
		case(3):Translate(mas, cur_len, 0); break;
		case(4):Translate(mas, cur_len, 1); break;
		case(5):PrintDictionary(mas, cur_len); break;
		case(6):DictionaryToFile("output.txt", mas, cur_len);
		case(7):return 0;
		
		}
	}
	
}