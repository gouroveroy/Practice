#include <iostream>
using namespace std;

class building
{
    protected:
    int room;
    int floor;
    double area;
    public:
    building(int room, int floor, double area)
    {
        this->room = room;
        this->floor = floor;
        this->area = area;
    }
};

class house : public building
{
    protected:
    int bedroom;
    int bathroom;
    public:
    house(int room, int floor, double area, int bedroom, int bathroom) : building(room, floor, area)
    {
        this->bathroom = bathroom;
        this->bedroom = bedroom;
    }

    void show()
    {
        cout << "rooms : " << room << endl;
        cout << "floors : " << floor << endl;
        cout << "area : " << area << endl;
        cout << "bedrooms : " << bedroom << endl;
        cout << "bathrooms : " << bathroom << endl;
    }
};

class office : public building
{
    protected:
    int extinguisher;
    int telephone;
    public:
    office(int room, int floor, double area, int extinguisher, int telephone) : building(room, floor, area)
    {
        this->extinguisher = extinguisher;
        this->telephone = telephone;
    }

    void show()
    {
        cout << "rooms : " << room << endl;
        cout << "floors : " << floor << endl;
        cout << "area : " << area << endl;
        cout << "extinguisher : " << extinguisher << endl;
        cout << "telephone : " << telephone << endl;
    }
};

int main()
{
    house h(50, 10, 100, 30, 40);
    office o(50, 10, 100, 20, 10);
    cout << "house" << endl;
    h.show();
    cout << "office" << endl;
    o.show();
    return 0;
}