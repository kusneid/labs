#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    //раскомментировать нужное,2 вариант
    cout << "1:\n";
    int n, m;
    char u = 'y';
    do {
        int k = 1, count = 0;
        cin >> n;
        cin >> m;
        for (int k = 5; k <= n; k = k + 5) {
            if (k % m != 0) { count = count + k; }
        }
        cout << count << endl;
        cout << " Продолжить работу?(y/n)";
        cin >> u;
    } while (u == 'y');
    /*cout << "2:\n";
    float a, s = 1;
    cin >> a;
    if (a >= 0) {
        for (int i = 2; i <= 8; i += 2) {
            s = s * (i * i);

        }
        s = s - a;
    }
    else {
        for (int i = 3; i <= 9; i += 3) {
            s *= (i - 2);
        }
    }
    cout << setprecision(7) << s;*/
    
    /*cout << "3:\n";
    const double e = 2.718281828459045;
    double eps = 0.000001, y, koe, x1, s;
    int n = 0;
    for (double x = 0; x <= 1.0; x += 0.2) {
        s = 1.0;
        n = 1;
        x1 = 1.0;
        y = (pow(e, x) + pow(e, x * (-1))) * 0.5;
    
        do
        {
            koe = (x * x) / (2 * n * (2 * n - 1));
            s = s + (x1 * koe);
    
            x1 = x1 * koe;
            n++;
        } while (koe >= eps);
    
        cout << setw(3) << x << " " << setw(10) << y << " " << setw(10) << s << " " << setw(10) << --n << endl;
    }*/
    
    
    /*cout << "4:\n";
    char un = 'y';
    int x, a, n, temp = 1;
    double y = 1;
    cout << "введите x,a:";
    cin >> x;
    cin >> a;
    
    
    
    while (un == 'y') {
        cout << "введите n:";
        cin >> n;
        if (n < 1)
            break;
    
    
        y = 1;
        for (int i = 1; i <= n; i++) {
    
            y += ((pow(x * log(a), i)) / temp);
            temp = temp * (i + 1);
            switch (i) {
            case 3:
                cout << y << temp << " при 3, ";
                break;
            case 5:
                cout << y << temp << " при 5, ";
                break;
            case 10:
                cout << y << temp << " при 10, ";
                break;
    
            }
    
    
    
        }
        cout << y;
        cout << " Продолжить?(y/n)";
        cin >> un;
    }*/




}
