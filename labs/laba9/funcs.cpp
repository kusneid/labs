#include "h.h"


; int Menu() {
	std::cout << "Available features:\n";
	std::cout << "1.Add words\n2.Delete words\n3.Translate from russian to english\n4.Translate from english to russian\n5.Show dictionary\n6.Put dictionary in file\n7.Exit";
	std::cout << "\nEnter a number:";
	int n;
	std::cin >> n;
	return n;
}


int SearchIndex(Dictionary mas[], char word[31],int cur_len) {
	int i = 0;

	while ((mas[i].eng != word) || (mas[i].rus != word) && (i<cur_len-1)) {
		i++;
	}

	if (i == cur_len - 1) {
		std::cout << "\nCan't find the word!!";
		return -1;
	}

	return i;
}

int SearchIndex(Dictionary mas[], char word[31], int cur_len, char* lang) {
	int i = 0;

	if (lang == "eng") {
		while (strcmp(mas[i].eng,word) && (i < cur_len-1)) {
			//std::cout<<mas[i].eng<<word<<i<<"\n";
			i++;
		}
	}
	else if (lang == "rus") {
		while ((strcmp(mas[i].rus,word)) && (i < cur_len-1)) {
			//std::cout<<mas[i].rus<<word<<i<<"\n";
			i++;
		}
	}
	else
	{
		std::cout << "Error during SearchIndex";
	}

	return i;
}

void AddWords(Dictionary mas[],int& cur_len,const int max_len) {
	char eng1[31], rus1[31], state = 'y';

	while ((state == 'y') && (cur_len < max_len))
	{
		std::cout << "\nEnter english word:";
		std::cin >> eng1;
		std::cout << "\nEnter russian word:";
		std::cin >> rus1;
		strcpy_s(mas[cur_len].eng, eng1);
		strcpy_s(mas[cur_len].rus, rus1);
		cur_len++;
		std::cout << "\nDo you want to continue? (y/n)";
		std::cin >> state;
	}

	if (cur_len == max_len) {
		std::cout << "Dictionary is full!!\n\n";
	}
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

void Translate(Dictionary mas[],int cur_len,const int type) {

	char word[31];
	int i=0;
	std::cout << "\nEnter the word you want to translate:";
	std::cin >> word;
	if (type == 0) {
		i = SearchIndex(mas, word, cur_len, "rus");
		std::cout << "\nTranslated word:" << mas[i].eng << "\n";
	}
	else
	{
		i = SearchIndex(mas, word, cur_len, "eng");
		std::cout <<"\nTranslated word:" << mas[i].rus<<"\n";
	}

	return;
}
//
//void DictionaryToFile(Dictionary mas[], int cur_len) {
//	std::fstream file("output.txt",std::ios::binary);
//	/*if (!file.is_open()) {
//		std::cout << "Can't find file!!!";
//		return;
//	}
//*/
//	for (int i = 0; i < cur_len; i++) {
//		std::cout << mas[i].eng << " - " << mas[i].rus << "\n";
//		file << mas[i].eng << " - " << mas[i].rus << "\n";
//	}
//	file.close();
//	return;

void DictionaryToFile(const char* a, Dictionary mas[], int cur_len) {
	std::ofstream file(a);

	if (!file.is_open()) {
		std::cout << "Can't find file!!!";
		return;
	}

	for (int i = 0; i < cur_len; i++) {
		file << mas[i].eng << "-" << mas[i].rus << "\n";
	}

	return;
}
//void Fill(const char* a, Dictionary mas[], int& cur_len) {
//	char b;
//	//char word1[31];
//	char* word = new char[31];
//	//char word2[31];
//	int y = 0;
//	std::ifstream file(a);
//	int i = 0;
//	cur_len = 0;
//	for (file.get(b);!file.eof();file.get(b))
//	{
//		if ((b != '-') && (b != '\n')) {
//			//word1[i] = b;
//			word[i]= b;
//			i++;
//		}
//		if (b == '-') {
//			word[i + 1] = '\0';
//			strcpy_s(mas[i].eng, word);
//			/*for (size_t i = 0; i < 31; i++)
//			{
//				word1[i] = 0;
//			}*/
//			i = 0;
//			delete [] word;
//			char* word = new char[31];
//		}
//		if (b == '\n') {
//			word[i + 1] = '\0';
//			strcpy_s(mas[i].rus, word);
//			i = 0;
//			delete[] word;
//			char* word = new char[31];
//			cur_len++;
//			/*for (size_t i = 0; i < 31; i++)
//			{
//				word[i] = 0;
//			}*/
//		}
//		//if ((b != ' ') && (b != '-')) {
//		//	word[i] = b;
//		//	i++;
//		//}
//		//else
//		//{
//		//	word[i + 1] = '\0';
//		//	if (i % 2 == 0)
//		//	{
//		//		strcpy_s(mas[i].eng, word);
//		//	}
//		//	else
//		//	{
//		//		strcpy_s(mas[i].rus, word);
//		//	}
//		//	cur_len += 1;
//		//	i = 0;
//		//	//memset(word, 0, 31);
//		//	strcpy(word, "");
//		//	for (int i = 0; i < 31; i++) { word[i] = ' '; }
//		//}
//	}
//	cur_len /= 2;
//
//}

Dictionary* Fill(const char* a,int ma, int& cur_len) {
	std::fstream file(a);
	const int max_len = 200;
	Dictionary mas[max_len];
	if (!file.is_open()) {
		std::cout << "File error!!\n";
		return mas;
	}
	bool en = true;
	char t;
	char word[31];
	char word1[31];
	int i = 0;
	//mas[i] = { "place","mesto" };
	for (file.get(t);!file.eof();file.get(t))
	{
		if (t != '-') {
			if (en)
			{
				word[i] = t;
			}
			else
			{
				word1[i] = t;
			}
		}
		else
		{
			i = 0;
			en = false;
		}
		i++;
		if (t == '\n') {
			//mas[cur_len] = { word,word1 };
			i = 0;
			en = true;
		}
	}

}




