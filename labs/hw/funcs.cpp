#include "h.h"

void Fill(char* mas, int& textLen) {
	char temp;
	while (true)
	{
		temp = getch();
		if (temp == '.') {
			putch('.');
			break;

		}
		/*if (temp == '\b')
		{
			textLen--;
			continue;
			
		}
		else
		{
			
		}*/

		if (((temp >= 'a')&&(temp<='z')) || temp == ' '||temp==',')
		{
			mas[textLen] = temp;
			textLen++;
			putch(temp);//DELETE!!!!!!!
		}
		else if (temp == '\b') {
			if (textLen > 0) {
				mas[textLen] = ' ';
				textLen--;
				putch('\b');
				putch(' ');
				putch('\b');
				continue;

			}

		}
	}
	while (textLen && mas[textLen-1]==' ')
	{
		textLen--;
	}
	mas[textLen]='\0';

	//std::cout<<"\n";
}	


// 	do
// 	{
// 		temp = getch();
// 		// if (temp == '.') {
// 		// 	break;

// 		// }
// 		/*if (temp == '\b')
// 		{
// 			textLen--;
// 			continue;
			
// 		}
// 		else
// 		{
			
// 		}*/

// 		if (((temp >= 'a')&&(temp<='z')) || temp == ' ')
// 		{
// 			mas[textLen] = temp;
// 			textLen++;
// 			putch(temp);//DELETE!!!!!!!
// 		}
// 		else if (temp == '\b') {
// 			if (textLen > 0) {
// 				mas[textLen] = ' ';
// 				putch('\b');
// 				continue;

// 			}

// 		}
		
		
// 	} while (mas[textLen - 1] != '.');

// 	//textLen--;
// }

void PrintWord(char* word, int len) {
	for (int i = 0; i < len; i++)
	{
		putch(word[i]);
	}
}

//char* LastWord(int textLen, char* mas, int& LastWordLen) {
//	int Index_start = 0;
//	bool spacesAreSkipped = false;
//	if (mas[textLen-1]!=' ')
//	{
//		spacesAreSkipped = true;
//	}
//	
//	int Index_end =-1;
//	for (int i1 = textLen-1; i1 > -1; i1--) {
//		if ((mas[i1] == ' ')&&spacesAreSkipped) {
//			Index_start = i1 + 1;
//			break;
//		}
//		if (mas[i1]!=' ' && mas[i1]!=',')
//		{
//			spacesAreSkipped = true;
//			Index_end = i1;
//		}
//
//	}
//	
//	char* word = new char[Index_end - Index_start];
//	//std::cout << i - Index_start;
//	for (int i1 = Index_start; i1 <= Index_end; i1++)
//	{
//		word[i1 - Index_start] = mas[i1];
//	}
//	LastWordLen = Index_end - Index_start;
//	return word;
//}

char* LastWord(int textLen, char* mas, int& lastWordLen) {
	int Index_start = 0;
	for (int i1 = textLen; i1 > -1; i1--) {
		if (mas[i1] == ' ' || mas[i1] == ',') {
			Index_start = i1 + 1;
			break;
		}
	}
	char* word = new char[textLen - Index_start];
	//std::cout << textLen - Index_start;
	for (int i1 = Index_start; i1 <= textLen; i1++)
	{
		word[i1 - Index_start] = mas[i1];
	}
	lastWordLen = textLen - Index_start;
	return word;

}

bool Compare(char* word, char* word_temp, int lastWordLen,int wordCurrentLen) {
	if (lastWordLen!=wordCurrentLen)
	{
		return false;
	}
	int maxLen = std::min(lastWordLen, wordCurrentLen);
	for (int i = 0; i < maxLen; i++)
	{
		if (word[i] != word_temp[i]) {
			return false;
		}
	}
	return true;

}
bool CheckForSpaces(char* wordCurrent,int wordCurrentLen){
	for (int i = 0; i < wordCurrentLen; i++)
	{
		if (wordCurrent[i]==' '){
			return false;
		}
		
	}
	return true;
}

void Print(char* word, int lastWordLen, char* mas,int textLen) {
	char* wordCurrent=new char[500];
	int wordCurrentLen = 0;
	/*int a = ;*/
	for (int i = 0; i < textLen; i++)
	{
		if ((mas[i]!=' ')&&(mas[i]!=','))
		{
			//std::cout <<wordCurrentLen;
			wordCurrent[wordCurrentLen] = mas[i];
			wordCurrentLen++;
		}
		else
		{
			// std::cout<<"\nhere:\n";
			// for (size_t i = 0; i < wordCurrentLen; i++)
			// {
			// 	std::cout<<wordCurrent[i];
			// }
			// std::cout<<":\n";

			
			//Compare(word, wordCurrent, std::max(lastWordLen, wordCurrentLen)
			if (Compare(word,wordCurrent,lastWordLen,wordCurrentLen) == false)
			{
				PrintWord(wordCurrent, wordCurrentLen-1);
				
				
				putch(' ');
				
				
			}
			else {
				
			}
			wordCurrentLen = 0;
			// delete[] wordCurrent;
			// char* wordCurrent=new char[500];
			
		}

	}

}



