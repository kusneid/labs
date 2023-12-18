
#include <iostream>
#include <conio.h> // для getch и putch
int main()
{
    int size = 2000;                          // максимальный размер массива символов
    char* text = new char[size];    // выделение памяти под массив символов
    int current_index = 0;                  // индекс текущего символа в массиве

    while (true)
    {
        char ch = _getch();                 // считывание символа с клавиатуры
        if (ch == '.') break;                  //прерываем, если точка
        if (current_index == size - 1)
        {
            size *= 2;                          // увеличиваем размер массива
            char* mass = new char[size];
            for (int i = 0; i < current_index; i++)
            {
                mass[i] = text[i]; // копируем символы из старого массива в новый
            }
            delete[] text;              // освобождаем память, занятую старым массивом
            text = mass;           // заменяем указатель на массив символов на новый
        }

        else if (ch == '\b')                // если введен символ backspace
        {
            if (current_index > 0)
            {
                text[current_index] = ' ';
                current_index--;                    // переход на предыдущий символ
                _putch('\b');
                _putch(' ');
                _putch('\b');
                continue;
            }
        }
        else if (current_index < size - 1 and ((ch >= 'a') and (ch <= 'z') or ch == ' ')) // ввод только разрешенных символов
        {
            text[current_index] = ch;   // добавляем символ в массив
            _putch(ch);                         // отображаем введенный символ
            current_index++;                    // увеличиваем индекс
        }

    }
    while (current_index and text[current_index - 1] == ' ') // избегаем пробелы перед точкой
    {
        current_index--;
    }
    text[current_index] = '\0';            // добавляем завершающий символ

    int sizeWord = 100;                              // размер последнего слова по умолчанию
    int count_WorSymbols = 0;                       // длина последнего слова
    char* dynamic_lastword = new char[sizeWord];    // последнее слово
    // Поиск последнего слова 
    for (int k = current_index - 1; k >= 0; k--)
    {
        if ((text[k] == ' ' or text[k] == '\t') and text[k] != '\0')
        {
            break;
        }
        else if (text[k] != ' ')
        {
            dynamic_lastword[count_WorSymbols] = text[k]; // считываем последнее слово с конца
            count_WorSymbols++;
        }
    }
    _putch('\n');
    //сравнение с последним словом
    int word_start = 0; // начало последнего слова
    int w = 0;          // индекс последнего слова для сравнения
    for (int i = 0; i < current_index; i++)     // проход по всем символам массива слов
    {
        if (text[i] == ' ' or text[i] == '\t' or i == current_index - 1) // если встретили пробел или последний символ
        {
            if (i == current_index - 1)         // если последний символ
                i++;                            // увеличиваем i, чтобы включить последний символ в слово
            w = count_WorSymbols - 1;
            if (i - word_start == count_WorSymbols)
            {
                for (int t = word_start; t <= i; t++)
                {
                    if (text[t] != dynamic_lastword[w]) // посимвольное сравнение
                        break;
                    else word_start += 1;
                    w--;
                }
            }
            //удаляем букву посередине
            if (i - word_start > 1)             // если слово состоит более чем из одного символа
            {
                if ((i - word_start) % 2 != 0) {      //проверяем на четность длины слова
                    for (int j = word_start; j < i; j++) // печатаем слово без среднего символа
                    {
                        if (j != ((i - word_start) / 2 + word_start))
                            _putch(text[j]);
                    }
                }

               
                else {
                    for (int j = word_start; j < i; j++) // печатаем слово полностью в ином случае
                        _putch(text[j]);
                }
                _putch(' ');               // печатаем пробел после слова
            }
            else { _putch(text[word_start]); _putch(' '); }
            word_start = i + 1;                 // устанавливаем начало следующего слова
        }
    }
    delete[] text;                      // освобождаем память
    return 0;
}