#include <iostream>
using namespace std;

class coord
{
    int x, y;

public:
    coord(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    void show()
    {
        cout << x << ", " << y << endl;
    }
    coord operator+(coord obj);
    coord operator+(int i);
    coord operator-(coord obj);
    coord operator=(coord obj);
    int operator==(coord obj);
    int operator!=(coord obj);
    int operator&&(coord obj);
    int operator||(coord obj);
    coord operator++();
    coord operator-();
    void operator()(int a, int b);
};

coord coord::operator+(coord obj)
{
    coord temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
}
coord coord::operator+(int i)
{
    coord temp;
    temp.x = x + i;
    temp.y = y + i;
    return temp;
}
coord coord::operator-(coord obj)
{
    coord temp;
    temp.x = x - obj.x;
    temp.y = y - obj.y;
    return temp;
}
coord coord::operator=(coord obj)
{
    x = obj.x;
    y = obj.y;
    return *this;
}
int coord::operator==(coord obj)
{
    return (x == obj.x) && (y == obj.y);
}
int coord::operator!=(coord obj)
{
    return (x != obj.x) || (y != obj.y);
}
int coord::operator&&(coord obj)
{
    return (x && obj.x) && (y && obj.y);
}
int coord::operator||(coord obj)
{
    return (x || obj.x) || (y || obj.y);
}
coord coord::operator++()
{
    ++x;
    ++y;
    return *this;
} // prefix version

coord coord::operator-()
{
    coord temp;
    temp.x = -x;
    temp.y = -y;
    return temp;
}

void coord::operator()(int a, int b)
{
    this->x = a;
    this->y = b;
}

int main()
{
    coord c1(20, 20), c2(10, 10);
    coord c3 = c1 + c2; // c1.+(c2)
    c3.show();          // 30, 30

    coord c4 = c3 + 5; // c3.+(5)
    c4.show();         // 35, 35

    coord c5 = c2 - c1; // c2.-(c1)
    c5.show();          // -10, -10
    coord c6 = c1 + c2 + c3;
    // (c1.+(c2)).+(c3)
    c6.show();        // 60, 60
    (c6 - c4).show(); // 25, 25

    c5 = c6 = c6 - c1;
    // c5.=(c6.=(c6.-(c1)))
    c5.show(); // 40, 40
    c6.show(); // 40, 40

    c1(10, 10), c2(10, 10);
    c3 = ++c1;
    // c1.++()
    c1.show(); // 11, 11
    c2.show(); // 10, 10
    c3.show(); // 11, 11

    c5 = -c1;
    // c1.-()
    c1.show(); // 11, 11
    c5.show(); // -11, -11
    c6 = c3 - c2; // c3.-(c2)
    c6.show(); // 1, 1

    return 0;
}