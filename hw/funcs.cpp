#include "h.h"

void Fill(char *mas, int &textLen)
{
	char temp;
	while (temp != '.')
	{
		temp = getch();

		if (((temp >= 'a') && (temp <= 'z')) || temp == ' ')
		{
			mas[textLen] = temp;
			textLen++;
			putch(temp);
		}
		else if (temp == '\b')
		{
			if (textLen > 0)
			{
				mas[textLen] = ' ';
				textLen--;
				putch('\b');
				putch(' ');
				putch('\b');
				continue;
			}
		}
	}
	while (textLen && mas[textLen - 1] == ' ')
	{
		textLen--;
	}
	mas[textLen] = '\0';
	putch('.');
}

void PrintWord(char *word, int len)
{
	for (int i = 0; i < len; i++)
	{
		putch(word[i]);
	}
}

char *LastWord(int textLen, char *mas, int &lastWordLen)
{
	int Index_start = 0;
	for (int i1 = textLen; i1 > -1; i1--)
	{
		if (mas[i1] == ' ')
		{
			Index_start = i1 + 1;
			break;
		}
	}
	char *word = new char[textLen - Index_start];
	for (int i1 = Index_start; i1 <= textLen; i1++)
	{
		word[i1 - Index_start] = mas[i1];
	}
	lastWordLen = textLen - Index_start;
	return word;
}


bool Compare(char *lastWord, char *word_temp, int lastWordLen, int wordCurrentLen)
{
	if (lastWordLen != wordCurrentLen)
	{
		return false;
	}

	for (int i = 0; i < lastWordLen; i++)
	{
		if (lastWord[i] != word_temp[i])
		{
			return false;
		}
	}
	return true;
}


void Print(char *lastWord, int lastWordLen, char *mas, int textLen)
{
	char *wordCurrent = new char[500];
	int wordCurrentLen = 0;
	for (int i = 0; i < textLen; i++)
	{
		if (mas[i] != ' ')
		{
			wordCurrent[wordCurrentLen] = mas[i];
			wordCurrentLen++;
		}
		else
		{
			if (Compare(lastWord, wordCurrent, lastWordLen, wordCurrentLen) == false)
			{
				PrintWord(wordCurrent, wordCurrentLen - 1);
				putch(' ');
			}
			
			wordCurrentLen = 0;
		}
	}
}
