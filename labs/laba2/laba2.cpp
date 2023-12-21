#include <iostream>
using namespace std;
int main()
{
    system("chcp 1251 > nul");
    int h, m;
    int i;
    cin >> h;
    cin >> m;
    if (h > 24 || h < 0 || m > 59 || m < 0)
    {
        cout << h << " " << m << " - ������ ������� �����������";

        return 0;
    }

    if (h == 12 && m == 0)
    {
        cout << "�������" << endl;

        return 0;
    }
    if (h == 0 && m == 0)
    {
        cout << "�������" << endl;

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

    if (i == 2 || i == 3 || i == 4)
    {
        cout << " ����";
    }
    else if (i == 1)
    {
        cout << " ���";
    }
    else
    {
        cout << " �����";
    }

    if (m != 0)
    {
        cout << " " << m;
        if (m % 10 == 1 && m != 11)
        {
            cout << " ������";
        }
        else if ((m % 10 == 2 || m % 10 == 3 || m % 10 == 4) && (m != 12 && m != 13 && m != 14))
        {
            cout << " ������";
        }
        else
        {
            cout << " �����";
        }
    }

    if (5 <= h && h < 12)
    {
        cout << " ����";
    }
    else if (12 <= h && h < 18)
    {
        cout << " ���";
    }
    else if (18 <= h && h <= 23)
    {
        cout << " ������";
    }
    else
    {
        cout << " ����";
    }
    if (m == 0)
    {
        cout << " �����";
    }
    return 0;
}