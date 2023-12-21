#pragma once
#include <fstream>
#include <iostream>
#include <cstring>

struct Dictionary
{
	char *eng;
	char *rus;
};

int Menu();
void Translate(Dictionary mas[], int cur_len, int type);
void AddWords(Dictionary mas[], int &cur_len, int max_len);
void DeleteWord(Dictionary mas[], int &cur_len);
void PrintDictionary(Dictionary mas[], int cur_len);
void DictionaryToFile(Dictionary mas[], int cur_len);
void Fill(Dictionary *mas, int &cur_len);