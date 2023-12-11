#include <iostream>
using namespace std;
class complex
{
    int x, y;
public:
    complex()
    {
        x = 0;
        y = 0;
    }
    friend void operator>>(complex &u, complex &v)
    {
        cout << "Enter real part of 1st imaginary no (x1) : ";
        cin >> u.x;
        cout << "Enter imaginary part of 1st imaginary no (y1) : ";
        cin >> u.y;
        cout << "\nEnter real part of 1st imaginary no (x2) : ";
        cin >> v.x;
        cout << "Enter imaginary part of 1st imaginary no (y2) : ";
        cin >> v.y;
    }
    friend void operator<<(complex &u, complex &v)
    {
        cout << "\n\n1st complex no is : " << u.x << " + " << u.y << "i";
        cout << "\n2nd complex no is : " << v.x << " + " << v.y << "i";
    }
    friend void operator+(complex &u, complex &v)
    {
        complex add;
        add.x = u.x + v.x;
        add.y = u.y + v.y;
        if (add.y > 0)
        {
            cout << "Addition of two complex numbers:"
                 << "(" << add.x << "+" << add.y << "i)";
        }
        else
        {
            cout << "Addition of two complex numbers:"
                 << "(" << add.x << "+" << (-1) * add.y << "i)";
        }
    }
    friend void operator*(complex &u, complex &v)
    {
        complex multiply;
        multiply.x = (u.x * v.x) - (u.y * v.y);
        multiply.y = (u.x * v.y) + (u.y * v.x);
        if (multiply.y > 0)
        {
            cout << "Multiplication of two complex numbers:"
                 << "(" << multiply.x << "+" << multiply.y << "i)";
        }
        else
        {
            cout << "Multiplication of two complex numbers:"
                 << "(" << multiply.x << "+" << (-1) * multiply.y << "i)";
        }
    }
};
int main()
{
    complex a, b;
    operator>>(a, b);
    operator<<(a, b);
    char ch;
    char des;
    do
    {
        cout << endl
             << "\nPress '+' for addition and '*' for multiplication: ";
        cin >> ch;
        switch (ch)
        {
        case '+':
            a + b;
            break;
        case '*':
            a *b;
            break;
        default:
            cout << "Invalid choice\n";
        }
        cout << "\n\nDo you want to continue?(Y/N)";
        cin >> des;

    } while (des == 'y' || des == 'Y');
    return 0;
}