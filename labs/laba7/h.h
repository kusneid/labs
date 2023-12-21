#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

int *KeyFill(int &l);
void Encoding(char *exc, int *exk, int stat[256][256], int KeyLen, int *ke);
void Decoding(char *exc, int *exk, int *ke, int KeyLen);
void Stats(int stat[256][256]);