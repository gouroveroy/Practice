#include <iostream>
using namespace std;

class rectangle
{
    int width, height;

public:
    rectangle(int a, int b)
    {
        //width = new int;
        //height = new int;
        width = a;
        height = b;
    }
    ~rectangle()
    {
        //delete width;
        //delete height;
    }
    int area()
    {
        return width * height;
    }
};

int main()
{
    rectangle recta(3, 4), rectb(5, 6);
    recta = rectb;
    cout << recta.area() << endl;
}