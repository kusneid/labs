#pragma once
#include <fstream>
#include <iostream>


struct Dictionary {
	char* eng= new char[31];
	char* rus= new char[31];
};

int Menu();
void Translate(Dictionary mas[], int cur_len, int type);
void AddWords(Dictionary mas[], int& cur_len,int max_len);
void DeleteWord(Dictionary mas[], int& cur_len);
void PrintDictionary(Dictionary mas[], int cur_len);
void DictionaryToFile(const char* a,Dictionary mas[], int cur_len);
//void Fill(const char* a, Dictionary mas[], int& cur_len);
void Fill(Dictionary* mas, int& cur_len);