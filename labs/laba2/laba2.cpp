#include <iostream>
using namespace std;
int main()
{
    system("chcp 1251 > nul");
    int h, m;
    int i;
    cin >> h;
    cin >> m;
    if (h > 24 || h < 0 || m > 59 || m < 0) {
        cout << h << " " << m << " - данные введены некорректно";

        return 0;
    }


    if (h == 12 && m == 0) {
        cout << "полдень" << endl;

        return 0;
    }
    if (h == 0 && m == 0) {
        cout << "полночь" << endl;

        return 0;

    }


    if (h > 12)
    {
        i = h - 12;
        cout << i;
    }
    else
    {
        i = h;
        cout << i;
    }


    if (i == 2 || i == 3 || i == 4) {
        cout << " часа";
    }
    else if (i == 1) {
        cout << " час";
    }
    else {
        cout << " часов";
    }


    if (m != 0) {
        cout << " " << m;
        if (m % 10 == 1 && m != 11) {
            cout << " минута";
        }
        else if ((m % 10 == 2 || m % 10 == 3 || m % 10 == 4) && (m != 12 && m != 13 && m != 14)) {
            cout << " минуты";
        }
        else { cout << " минут"; }
    }


    if (5 <= h && h < 12) { cout << " утра"; }
    else if (12 <= h && h < 18) { cout << " дня"; }
    else if (18 <= h && h <= 23) { cout << " вечера"; }
    else
    {
        cout << " ночи";
    }
    if (m == 0) { cout << " ровно"; }
    return 0;
}