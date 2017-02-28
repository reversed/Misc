#include <iostream>
using namespace std;

enum Day {Saturday, Sunday = 0, Monday, Tuesday, Wednesday, Thursday, Friday}; // Saturday = 0 by default, Sunday = 0 as well

void Prnt(Day day)
{
    if (day == 0) cout << "Weekend" << endl;
    else cout << "Weekday" << endl;
}

int main()
{
    enum Fruit {apple, pear, orange, banana} frtl; // 'frtl' can be declarated here.

    // int apple; // error: redefinition of 'apple'

    typedef enum Fruit ShuiGuo; // In C++, 'enum' can be omitted

    enum Fruit frt2 = apple; // In C++, 'enum' can be omitted.
    ShuiGuo frt3 = pear; // After type-declaration synonym, 'enum' can not exist here!

    frtl = (Fruit)0; // 'frtl' can be assigned with number by explicit cast.

    for (int i = apple; i <= banana; i++)
    {
        switch (i)
        {
        case apple: cout << "apple" << endl; break;
        case pear: cout << "pear" << endl; break;
        case orange: cout << "orange" << endl; break;
        case banana: cout << "banana" << endl; break;
        default: break;
        }
    }

    // Print whether a day is a 'Weekend' or a 'Weekday'.
    Prnt(Saturday);
    Prnt(Sunday);
    Prnt(Monday);
    Prnt(Tuesday);
    Prnt(Wednesday);
    Prnt(Thursday);
    Prnt(Friday);

    return 0;
}
