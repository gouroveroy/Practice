#include <iostream>
#include <cstdlib>
using namespace std;

class dyna
{
    int *p;

public:
    dyna(int i)
    {
        p = new int;
        if (!p)
        {
            cout << "allocation failure" << endl;
            exit(1);
        }
        *p = i;
    }
    ~dyna()
    {
        delete p;
        cout << "destructing" << endl;
    }
    int get()
    {
        return *p;
    }
};

int neg(dyna obj)
{
    return -obj.get();
}

int main()
{
    dyna o(-10);
    cout << o.get() << endl;
    cout << neg(o) << endl;

    dyna o2(20);
    cout << o2.get() << endl;
    cout << neg(o2) << endl;

    cout << o.get() << endl;
    cout << neg(o) << endl;

    return 0;
}