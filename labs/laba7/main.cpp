//#include "h.h



#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	system("chcp 1251 > nul");
	setlocale(LC_ALL, "Russian");

	ifstream key("key.txt");
	if (!key){return 0;}

	char ch;
	int stat[256][256]= {0};
	char s[300];

	int l = 1,i = 0,temp_key=0;
	for (key >> s; !key.eof(); key >> s) { l++; }
	int* ke = new int[l];
	key.clear();
	key.seekg(0);

	while (key.get(ch)){
		unsigned char t = static_cast<unsigned char>(ch);
		if ((static_cast<int>(t) == 32) || (static_cast<int>(t) == 10) || (static_cast<int>(t) == 9)){
			ke[i] = temp_key;			
			i++;
			temp_key=0;
			continue;
		}
		else{
			temp_key += static_cast<int>(t);
		}
	}
	ke[i] = temp_key;
	key.close();

	ifstream source("source.txt");
	if (!source){return 0;}
	fstream encoded("encoded.txt");
	if (!encoded){return 0;}
	char* exc = new char[1000];
	int* exk = new int[500];
	
	int y = 0,x;
	for (source.get(ch),i=0;!source.eof();source.get(ch),i++){
		x = static_cast<int>(ch);
		if ((x + ke[i % l])%256 == 26) {
			
			exc[i] = ch;
			exk[y] = i;
			y++;
			encoded << ch;
			stat[(256+x)%256][x] = x;
		}
		else {
			encoded << static_cast<char>((x + ke[i % l]) % 256);
			stat[(256+x)%256][(x + ke[i % l]) % 256] = (x + ke[i % l]) % 256;
		}
	}
	source.close();

	ofstream decoded("decoded.txt");
	if (!decoded){return 0;}
	i=0,y=0;
	encoded.clear();
	encoded.seekg(0);
	for (encoded.get(ch);!encoded.eof();encoded.get(ch),i++){
		if (i == exk[y]) {
			decoded << exc[i];
			y++;
		}
		else
		{
			decoded << static_cast<char>((static_cast<int>(ch) - ke[i % l]) % 256);
		}	
	}
	delete[] exc;
	delete[] exk;
	delete[] ke;
	decoded.close();
	encoded.close();

	bool exis;
	ofstream st("stat.txt");
	st << setw(2) << 0 << setw(4);
	for (int n=0;n<256;n++){
		st<<n<<' ';
	}
	st << "\n";
	for(int v=0;v<256;v++){
		if (v == 63 || v == 191 || v == 239) { continue; }
		exis = false;
		for (int b=0;b<256;b++){

			if (stat[v][b] != 0) {
				exis = true;
			}
		}
		if (exis == true){ 
			st << v << ' ';
			for (int bg = 0; bg < 256; bg++) {
				st << stat[v][bg] << ' ';
			 }
			st << "\n";
		}
		
	}
	return 0;
}
