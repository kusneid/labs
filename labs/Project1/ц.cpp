
#include <iostream>
#include <conio.h> // ��� getch � putch
int main()
{
    int size = 2000;                          // ������������ ������ ������� ��������
    char* text = new char[size];    // ��������� ������ ��� ������ ��������
    int current_index = 0;                  // ������ �������� ������� � �������

    while (true)
    {
        char ch = _getch();                 // ���������� ������� � ����������
        if (ch == '.') break;                  //���������, ���� �����
        if (current_index == size - 1)
        {
            size *= 2;                          // ����������� ������ �������
            char* mass = new char[size];
            for (int i = 0; i < current_index; i++)
            {
                mass[i] = text[i]; // �������� ������� �� ������� ������� � �����
            }
            delete[] text;              // ����������� ������, ������� ������ ��������
            text = mass;           // �������� ��������� �� ������ �������� �� �����
        }

        else if (ch == '\b')                // ���� ������ ������ backspace
        {
            if (current_index > 0)
            {
                text[current_index] = ' ';
                current_index--;                    // ������� �� ���������� ������
                _putch('\b');
                _putch(' ');
                _putch('\b');
                continue;
            }
        }
        else if (current_index < size - 1 and ((ch >= 'a') and (ch <= 'z') or ch == ' ')) // ���� ������ ����������� ��������
        {
            text[current_index] = ch;   // ��������� ������ � ������
            _putch(ch);                         // ���������� ��������� ������
            current_index++;                    // ����������� ������
        }

    }
    while (current_index and text[current_index - 1] == ' ') // �������� ������� ����� ������
    {
        current_index--;
    }
    text[current_index] = '\0';            // ��������� ����������� ������

    int sizeWord = 100;                              // ������ ���������� ����� �� ���������
    int count_WorSymbols = 0;                       // ����� ���������� �����
    char* dynamic_lastword = new char[sizeWord];    // ��������� �����
    // ����� ���������� ����� 
    for (int k = current_index - 1; k >= 0; k--)
    {
        if ((text[k] == ' ' or text[k] == '\t') and text[k] != '\0')
        {
            break;
        }
        else if (text[k] != ' ')
        {
            dynamic_lastword[count_WorSymbols] = text[k]; // ��������� ��������� ����� � �����
            count_WorSymbols++;
        }
    }
    _putch('\n');
    //��������� � ��������� ������
    int word_start = 0; // ������ ���������� �����
    int w = 0;          // ������ ���������� ����� ��� ���������
    for (int i = 0; i < current_index; i++)     // ������ �� ���� �������� ������� ����
    {
        if (text[i] == ' ' or text[i] == '\t' or i == current_index - 1) // ���� ��������� ������ ��� ��������� ������
        {
            if (i == current_index - 1)         // ���� ��������� ������
                i++;                            // ����������� i, ����� �������� ��������� ������ � �����
            w = count_WorSymbols - 1;
            if (i - word_start == count_WorSymbols)
            {
                for (int t = word_start; t <= i; t++)
                {
                    if (text[t] != dynamic_lastword[w]) // ������������ ���������
                        break;
                    else word_start += 1;
                    w--;
                }
            }
            //������� ����� ����������
            if (i - word_start > 1)             // ���� ����� ������� ����� ��� �� ������ �������
            {
                if ((i - word_start) % 2 != 0) {      //��������� �� �������� ����� �����
                    for (int j = word_start; j < i; j++) // �������� ����� ��� �������� �������
                    {
                        if (j != ((i - word_start) / 2 + word_start))
                            _putch(text[j]);
                    }
                }

               
                else {
                    for (int j = word_start; j < i; j++) // �������� ����� ��������� � ���� ������
                        _putch(text[j]);
                }
                _putch(' ');               // �������� ������ ����� �����
            }
            else { _putch(text[word_start]); _putch(' '); }
            word_start = i + 1;                 // ������������� ������ ���������� �����
        }
    }
    delete[] text;                      // ����������� ������
    return 0;
}