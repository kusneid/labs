#pragma once
#include <conio.h>
#include <cstring>
bool Compare(char* word, char* word_temp, int lastWordLen, int wordCurrentLen);
void Fill(char* mas, int& i);
char* LastWord(int i, char* mas, int& len);
void PrintWord(char* word, int len);
void Print(char* word, int word_len, char* mas, int mas_len);
