#include "h.h"

void fill(char* mas, int& i) {
	char temp;

	do
	{

		temp = getch();
		mas[i] = temp;
		i++;

	} while (mas[i - 1] != '.');

	i--;
}

void PrintWord(char* word, int len) {
	for (int i = 0; i < len; i++)
	{
		putch(word[i]);
	}
}

char* LastWord(int i, char* mas, int& len) {
	int Index_start = 0;
	for (int i1 = i; i1 > -1; i1--) {
		if (mas[i1] == ' ') {
			Index_start = i1 + 1;
			break;
		}
	}
	char* word = new char[i - Index_start];
	//std::cout << i - Index_start;
	for (int i1 = Index_start; i1 <= i; i1++)
	{
		word[i1 - Index_start] = mas[i1];
	}
	len = i - Index_start;
	return word;
}

bool Compare(char* word, char* word_temp, int len) {
	for (int i = 0; i < len; i++)
	{
		if (word[i] != word_temp[i]) {
			return false;
		}
	}
	return true;

}


void Print(char* word, int word_len, char* mas,int mas_len) {
	//char temp;
	char* wordCurrent=new char[1000];
	int wordCurrentLen = 0;
	/*int a = ;*/
	for (int i = 0; i < mas_len; i++)
	{
		if ((mas[i]!=' ')||(mas[i]!=','))
		{
			//std::cout <<wordCurrentLen;
			wordCurrent[wordCurrentLen] = mas[i];
			wordCurrentLen++;
		}
		else
		{
			//Compare(word, wordCurrent, std::max(word_len, wordCurrentLen)
			if (strcmp(word,wordCurrent) == false)
			{
				PrintWord(wordCurrent, wordCurrentLen-1);
				putch(' ');
				
			}
			else {
				
			}
			wordCurrentLen = 0;
			delete[] wordCurrent;
			char* wordCurrent = new char[1000];
		}

	}

}



