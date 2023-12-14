#include <iostream>
#include <conio.h>


void PrintWord(char* word, int len) {
	for (int i = 0; i < len; i++)
	{
		putch(word[i]);
	}
}

int main() {
	system("chcp 1251>nul");
	char* mas = new char[2000];

	char temp; 
	int i = 0;
	do
	{

		temp=getch();
		mas[i] = temp;
		i++;

	} while (mas[i-1]!='.');
i--;
	for (int y = 0; y < i; y++) {
		std::cout << mas[y]<<"";
	}
	std::cout << "\n";
	
	int Index_start = 0;
	for (int i1 = i; i1 > -1; i1--) {
		//std::cout << mas[i1] << "";
		if (mas[i1] == ' ') {
			Index_start = i1+1;
			break;
		}//не работает при одном слове 
	}
	/*if (Index_start == -1) {
		std::cout << "Error indexstart";
	}*/
	char* word = new char[i-Index_start];
	/*std::cout << i - Index_start-2;*/
	for (int i1 = Index_start; i1 <= i; i1++)
	{
		
		word[i1 - Index_start] = mas[i1];

	}
	/*for (size_t i6 = 0; i6 < i-Index_start; i6++)
	{
		std::cout << word[i6];
	}*/
	temp = '[';
	char* wordi= new char[31];
	int cur_len = 0, i2 = 0;
	for (size_t i7 = 0; mas[i7] != '.'; i7++)
	{
		if (mas[i7] != ' ')
		{
			wordi[i2] = mas[i];
			i2++;
		}
		else
		{
			if (strcmp(wordi, word) != 0)
			{
				PrintWord(wordi, i2 + 1 - 1);
			}

			delete[] wordi;
			char* wordi = new char[31];
			i2 = 0;

		}

		/*while (temp != '.')
		{

		}*/
	}
	
	
	return 0;
}
