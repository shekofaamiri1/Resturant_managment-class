#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
// Class for food menu items
class Food
{
private:
    int ID;
    string name;
    int price;
public:
Food()
    {
        setID(0);
        setName("");
        setPrice(0);
    }
    Food(int i, const string &n, int p)
    {
        setID(i);
        setName(n);
        setPrice(p);
    }
    ~Food() {}
    void setID(int i)
    {
        if (i > 0)
            ID = i;
        else
            ID = 0;
    }