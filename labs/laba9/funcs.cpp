#include "h.h"
int Menu() {
	std::cout << "Available features:\n";
	std::cout << "1.Add words\n2.Delete words\n3.Translate from russian to english\n4.Translate from english to russian\n5.Show dictionary\n6.Put dictionary in file\n7.Exit";
	std::cout << "\nEnter a number:";
	int n;
	std::cin >> n;
	return n;
}
int SearchIndex(Dictionary mas[], char word[31],int cur_len) {
	int i = 0;
	/*do
	{
		i++;
	} while ((mas[i].eng!=word)|| (mas[i].rus != word));*/
	while ((mas[i].eng != word) || (mas[i].rus != word) && (i<cur_len-1)) {
		i++;
	}
	if (i == cur_len - 1) {
		std::cout << "\nCan't find the word!!";
		return -1;
	}
	return i;
}
int SearchIndex(Dictionary mas[], char word[31], int cur_len, lang lang) {
	int i = 0;
	switch (lang)
	{
	case eng:
		while ((mas[i].eng != word) && (i < cur_len - 1)) {
			i++;
		}
		break;
	case rus:
		while ((mas[i].rus != word) && (i < cur_len - 1)) {
			i++;
		}
		break;
	default:
		break;
	}
	if (i == cur_len - 1) {
		std::cout << "\nCan't find the word!!";
		return -1;
	}
	return i;
}
void AddWords(Dictionary mas[],int& cur_len,const int max_len, bool& isFull) {
	char eng1[31], rus1[31], state = 'y';
	while ((state == 'y') && (cur_len < max_len))
	{
		std::cout << "\nEnter english word:";
		std::cin >> eng1;
		std::cout << "\nEnter russian word:";
		std::cin >> rus1;
		//mas[cur_len] = { eng1[31],rus1[31] };
		//mas[cur_len].eng = {'f'};
		strcpy_s(mas[cur_len].eng, eng1);
		strcpy_s(mas[cur_len].rus, rus1);
		cur_len++;
		std::cout << "\nDo you want to continue? (y/n)";
		std::cin >> state;
	}
	if (cur_len == max_len) {
		std::cout << "Dictionary is full!!\n\n";
		isFull = true;
	}
	std::cout << cur_len;
	return;
}
void DeleteWord(Dictionary mas[], int& cur_len) {
	char word[31];
	std::cout << "\nWhich word do you want to delete?:";
	std::cin >> word;
	
	for (int i = SearchIndex(mas, word, cur_len); i < cur_len-1; i++) {
		if (i == -1) { 
			std::cout << "cant find";
			return; }
		strcpy_s(mas[i].eng, mas[i + 1].eng);
		strcpy_s(mas[i].rus, mas[i + 1].rus);
	}
	cur_len--;
	return;
}
void PrintDictionary(Dictionary mas[], int cur_len) {
	std::cout << "\nDictionary:\n";
	for (int i = 0; i < cur_len; i++) {
		std::cout << "\n" << mas[i].eng << " - " << mas[i].rus << "\n";
	}
	std::cout << "\n\n";
	return;
}
void Translate(Dictionary mas[],int cur_len, int type) {
	char word[31];
	int i;
	std::cout << "\nEnter the word you want to translate:";
	std::cin >> word;
	switch (type)
	{
	case(0):
		i = SearchIndex(mas,word,cur_len,eng);
		std::cout << i <<"\nTranslated word:" << mas[i].rus<<"\n";
	case(1):
		i = SearchIndex(mas, word, cur_len, rus);
		std::cout << "\nTranslated word:" << mas[i].eng << "\n";

	default:
		break;
	}
}
void DictionaryToFile(const char* a, Dictionary mas[], int cur_len) {
	std::ofstream file(a);
	if (!file.is_open()) {
		std::cout << "masha makarova proebalas'";
		return;
	}
	for (int i = 0; i < cur_len; i++) {
		file << mas[i].eng << " - " << mas[i].rus << "\n";
	}
}



