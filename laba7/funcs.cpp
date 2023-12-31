#include "h.h"

using namespace std;

int *KeyFill(int &KeyLen)
{
	char s[60];
	char ch;
	int i = 0;
	ifstream key("key.txt");
	if (!key)
	{
		return 0;
	}
	for (key >> s; !key.eof(); key >> s)
	{
		KeyLen++;
	}
	int *ke = new int[KeyLen];
	key.clear();
	key.seekg(0);

	int temp_key = 0;
	while (key.get(ch))
	{
		unsigned char t = static_cast<unsigned char>(ch);
		if ((static_cast<int>(t) == 32) || (static_cast<int>(t) == 10) || (static_cast<int>(t) == 9))
		{
			ke[i] = temp_key;
			i++;
			temp_key = 0;
			continue;
		}
		else
		{
			temp_key += static_cast<int>(t);
		}
	}
	ke[i] = temp_key;
	key.close();

	return ke;
}

void Encoding(char *Exceptions, int *ExceptionsIndex, int stat[256][256], int KeyLen, int *ke)
{
	char ch;
	int y = 0;
	int x;
	ifstream source("source.txt");

	ofstream encoded("encoded.txt");
	if (!source || !encoded)
	{
		return;
	}

	int i;
	for (source.get(ch), i = 0; !source.eof(); source.get(ch), i++)
	{
		x = static_cast<int>(ch);
		if ((x + ke[i % KeyLen]) % 256 == 26)
		{

			Exceptions[i] = ch;
			ExceptionsIndex[y] = i;
			y++;
			encoded << ch;
			stat[(256 + x) % 256][x]++;
		}
		else
		{
			encoded << static_cast<char>((x + ke[i % KeyLen]) % 256);
			stat[(256 + x) % 256][(x + ke[i % KeyLen]) % 256]++;
		}
	}
	source.close();
	encoded.close();
}

void Decoding(char *Exceptions, int *ExceptionsIndex, int *ke, int KeyLen)
{
	char ch;
	ifstream encoded("encoded.txt");
	ofstream decoded("decoded.txt");
	if (!decoded || !encoded)
	{
		return;
	}
	int i = 0, y = 0;
	encoded.clear();
	encoded.seekg(0);
	for (encoded.get(ch); !encoded.eof(); encoded.get(ch), i++)
	{
		if (i == ExceptionsIndex[y])
		{
			decoded << Exceptions[i];
			y++;
		}
		else
		{
			decoded << static_cast<char>((static_cast<int>(ch) - ke[i % KeyLen]) % 256);
		}
	}
	decoded.close();
	encoded.close();
}

void Stats(int stat[256][256])
{
	bool exis;
	ofstream st("stat.txt");
	if (!st)
	{
		return;
	}
	st << setw(2) << 0 << setw(6);
	for (int n = 0; n < 256; n++)
	{
		st << n << setw(6);
	}
	st << "\n";
	for (int v = 0; v < 256; v++)
	{
		if (v == 63 || v == 191 || v == 239)
		{
			continue;
		}
		exis = false;
		for (int b = 0; b < 256; b++)
		{

			if (stat[v][b] != 0)
			{
				exis = true;
			}
		}
		if (exis == true)
		{
			st <<setw(2)<< v << setw(6);
			for (int bg = 0; bg < 256; bg++)
			{
				st << stat[v][bg] << setw(6);
			}
			st << "\n";
		}
	}
}