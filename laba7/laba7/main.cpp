#include "h.h"

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "Russian");
	
	//cout<<static_cast<int>('\n');
	ifstream key("key.txt");
	if (!key){return 0;}
	char ch;
	int stat[256][256]= {0};
	
	//keylen
	char s[300];
	int l = 1,i = 0,temp_key=0;
	for (key >> s; !key.eof(); key >> s) { l++; }
	//keymas
	//cout <<l<< endl;
	int* ke = new int[l];
	key.clear();
	key.seekg(0);
	
	//bool newl = true;
	while (key.get(ch)){
		unsigned char t = static_cast<unsigned char>(ch);
		if ((static_cast<int>(t) == 32) || (static_cast<int>(t) == 10) || (static_cast<int>(t) == 9)){
			ke[i] = temp_key;
			
			i++;
			temp_key=0;
			
			//newl= true;
			continue;
		}
		else{
			temp_key += static_cast<int>(t);
			//newl = false;
		}
	}
	ke[i] = temp_key;
	/*for (int f = 0; f < l; f++) {
		cout << ke[f]<<" " << f << '\n';
	}*/
	key.close();
	ifstream source("source.txt");
	if (!source){return 0;}
	fstream encoded("encoded.txt");
	if (!encoded){return 0;}
	
	//i=0;
	/*while(source>>ch){
		temp = static_cast<char>((static_cast<int>(ch) + ke[i%l])%256);
		cout << i << " " << static_cast<int>(ch)%256 <<"  "<< ke[i%l]%256 << "  "<< temp << endl;
		encoded<<temp;
		i++;
	}*/
	char* exc = new char[1000];
	int* exk = new int[500];
	
	int y = 0,x;
	for (source.get(ch),i=0;!source.eof();source.get(ch),i++){
		//cout<<static_cast<int>(ch)<<' '<<ke[i%l]%256<<'\n';
		//temp = static_cast<char>(((static_cast<int>(ch)) + ((ke[i%l])))%256);
		x = static_cast<int>(ch);
		if ((static_cast<int>(ch) + ke[i % l])%256 == 26) {
			
			exc[i] = ch;
			exk[y] = i;
			y++;
			encoded << ch;
			stat[(256+x)%256][static_cast<int>(ch)] = static_cast<int>(ch);
		}
		else {
			encoded << static_cast<char>((static_cast<int>(ch) + ke[i % l]) % 256);
			stat[(256+x)%256][(static_cast<int>(ch) + ke[i % l]) % 256] = (static_cast<int>(ch) + ke[i % l]) % 256;
		}
	}
	source.close();
	ofstream decoded("decoded.txt");
	if (!decoded){return 0;}
	i=0,y=0;
	encoded.clear();
	encoded.seekg(0);
	
	for (encoded.get(ch);!encoded.eof();encoded.get(ch),i++){
		//temp = static_cast<char>(((static_cast<int>(ch)) - ((ke[i%l])))%256);
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
	ch = 'y';
	char temp;
	int g,count;
	
	/*while (ch == 'y') {
		count=0;
		cout << "Введите символ для анализа: ";
		cin >> temp;
		cout << "\n";
		g = static_cast<int>(temp);
		for (int u = 0; u < 256; u++) {
			if (stat[g][u] != 0) {
				count++;
				cout <<count<<"." << static_cast<char>(stat[g][u]) << "  ";
				cout<< stat[g][u]<<"\n";

			}
		}
		cout << "\nСимвол был закодирован " << count << " раз\nПродолжить?(y/n)";
		cin >> ch;
		
	}*/
	
	bool exis;
	ofstream st("stat.txt");

	st << setw(2) << 0 << setw(4);
	for (int n=0;n<256;n++){
		st<<n<<' ';
	}
	st << "\n";
	for(int v=0;v<256;v++){
		if ((char)v == '»' || (char)v == 'ї' || (char)v == 'п') { continue; }
		exis = false;
		for (int b=0;b<256;b++){
			/*if ((stat[v][b]!=0)&&(stat[v][b]!=10)&&(stat[v][b]!=32)&&(stat[v][b]!=9)){
				st<<(char)stat[v][b]<<' ';
			}
			else
			{
				st<<stat[v][b]<<' ';
			}*/
			
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
	
	


	/*int check[256] = { 0 };
	int len2 = 0;
	for (int i2 = 0; i2 < 256; i2++) {
		len2 = 0;
		for (int j2 = 0; j2 < 256; j2++) {
			if (stat[i2][j2] != 0) { len2++; }

		}
		if (len2 != 0) { check[i2] = 1; }

	}
	for (int i3 = 0; i3 < 256; i3++) {
		if (check[i3] == 1) {
			st << char(i3) << ' ';
			for (int j3 = 0; j3 < 256; j3++) {
				st << stat[i3][j3] << ' ';
			}

		}
		st << "\n";
		
	}*/

	
	return 0;
}
