#include "h.h"
int main()
{
	char *mas = new char[2000];
	int textLen = 0;
	Fill(mas, textLen);
	int lastWordLen;
	char *word = LastWord(textLen, mas, lastWordLen);
	putch('\n');
	Print(word, lastWordLen, mas, textLen);
	return 0;
}
