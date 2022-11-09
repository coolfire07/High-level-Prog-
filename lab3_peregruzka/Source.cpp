// перегрузка операторов и функций, "целое число"
//  = [] () (++) (+- <> однотипные операнды) члены класса
//  (+- <> разнотипные операнды) << friend
// преобразование во втроенный тип и в пользоваетльский тип

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int menu();

class Integer
{
    int number;

public:
    Integer(const int number = 0 ) : number(number) {}

    Integer& operator = (const Integer& n)
    {
        this->number = n.number;
        return *this;
    }

    Integer operator + (const Integer& n)
    {
        return Integer(this->number + n.number);
    }

    Integer operator - (const Integer& n)
    {
        return Integer(this->number - n.number);
    }

    Integer operator<<(const Integer& n)
    {
        cout << n.number << endl ;
        return Integer(this->number);
    } 

    bool operator>(const Integer& n)
    {
        return this->number > n.number;
    }

    bool operator<(const Integer& n)
    {
        return this->number < n.number;
    }

    bool operator==(const Integer& n)
    {
        return this->number == n.number;
    }

    Integer& operator++()
    {
        this->number++;
        return *this;
    }

    Integer operator++(int)
    {
        Integer temp(*this);
        this->number++;
        return temp;
    }
    Integer& operator--()
    {
        this->number--;
        return *this;
    }
    Integer operator--(int)
    {
        Integer temp(this->number);
        this->number--;
        return temp;
    }
    operator double() const
    {
        (double)this->number;
        return (double)this->number;
    }
};

int main()
{
    int r;
    cout << "Input the first number: " << endl;
    cout << "Number = ";
    cin >> r;
    Integer a(r);
    cout << a << endl;

    cout << "Input the second number: " << endl;
    cout << "Number = ";
    cin >> r;
    Integer b(r);
    cout << b << endl;
    Integer c;

    bool ch = true;
    bool res;
    while (ch)
    {
        switch (menu())
        {
        case 1:
            c = b;
            cout << c << endl;
            break;
        case 2:
            cout << a + b << endl;
            break;
        case 3:
            cout << a - b << endl;
            break;
        case 4:
            res = a < b;
            cout << res << endl;
            break;
        case 5:
            res = a > b;
            cout << res << endl;
            break;
        case 6:
            res = a == b;
            cout << res << endl;
            break;
        case 7:
            c = a++;
            cout << c << endl;
            cout << a << endl;
            break;
        case 8:
            c = ++a;
            cout << c << endl;
            cout << a << endl;
            break;
        case 9:
            c = a--;
            cout << c << endl;
            cout << a << endl;
            break;
        case 10:
            c = --a;
            cout << c << endl;
            cout << a << endl;
            break;
        case 11:
            cout << ((int)a) << endl;
            break;
        default:
            ch = false;
            break;
        }
    }
    system("pause");
    return 0;
}

int menu()
{
    int chooser;
    cout << "Choose the operator" << endl;
    cout << " 1. c = b               6. a == b" << endl;
    cout << " 2. a + b               7. a++" << endl;
    cout << " 3. a - b               8. ++a" << endl;
    cout << " 4. a < b               9. a--" << endl;
    cout << " 5. a > b               10. --a" << endl;
    cout << " 11. int to double" << endl;
    cout << "Other to exit" << endl;
    cin >> chooser;
    return chooser;
}
