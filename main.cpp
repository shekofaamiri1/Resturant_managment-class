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
    void setName(const string &n)
    {
        if (!n.empty())
            name = n;
        else
            name = "Unknown";
    }
    void setPrice(int p)
    {
        if (p >= 0)
            price = p;
        else
            price = 0;
    }
    int getID() const { return ID; }
    string getName() const { return name; }
    int getPrice() const { return price; }
void print() const
    {
        cout << ID << "\t" << name << "\t" << price << " Toman" << endl;
    }
};
vector<Food> menu;
void readMenuFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file)
        return;
    menu.clear();
    int id, price;
    string name;
    while (file >> id >> name >> price)
    {
        menu.push_back(Food(id, name, price));
    }
    file.close();
}
void showMenu()
{
    cout << "ID\tName\tPrice" << endl;
    for (const auto &f : menu)
        f.print();
}
