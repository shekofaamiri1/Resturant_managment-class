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
int findFoodByID(int id)
{
    for (size_t i = 0; i < menu.size(); ++i)
    {
        if (menu[i].getID() == id)
            return i;
    }
    return -1;
}
void saveMenuToFile(const string &filename)
{
    ofstream file(filename);
    if (!file)
        return;
    for (const auto &f : menu)
    {
        file << f.getID() << " " << f.getName() << " " << f.getPrice() << endl;
    }
    file.close();
}
// Class for single order item
class OrderItem
{
private:
    int foodID;
    string foodName;
    int quantity;
    int Price;

public:
    OrderItem()
    {
        setFoodID(0);
        setFoodName("");
        setQuantity(0);
        setPrice(0);
    }
    OrderItem(int id, int qty, int pri, const string &name)
    {
        setFoodID(id);
        setFoodName(name);
        setQuantity(qty);
        setPrice(pri);
    }
    ~OrderItem() {}
    void setFoodID(int id)
    {
        if (id > 0)
            foodID = id;
        else
            foodID = 0;
    }
    void setFoodName(const string &name)
    {
        if (!name.empty())
            foodName = name;
        else
            foodName = "Unknown";
    }
    void setQuantity(int qty)
    {
        if (qty > 0)
            quantity = qty;
        else
            quantity = 0;
    }
    void setPrice(int pri)
    {
        if (pri >= 0)
            Price = pri;
        else
            Price = 0;
    }
    int getFoodID() const { return foodID; }
    string getFoodName() const { return foodName; }
    int getQuantity() const { return quantity; }
    int getPrice() const { return Price; }

    void addQuantity(int qty)
    {
        if (qty > 0)
            quantity += qty;
    }
    int getTotalPrice() const { return quantity * Price; }
    void print() const
    {
        cout << foodName << "\t" << Price << "\t" << quantity << "\t" << getTotalPrice() << "\n";
    }
};
// Class for customer order
class CustomerOrder
{
private:
    vector<OrderItem> items;

public:
    CustomerOrder() {}
    ~CustomerOrder() {}

 void addItem(int id, const string &name, int qty, int price)
    {
        for (auto &item : items)
        {
            if (item.getFoodID() == id)
            {
                item.addQuantity(qty);
                return;
            }
        }
        items.push_back(OrderItem(id, qty, price, name));
    }
 int calculateTotal() const
    {
        int total = 0;
        for (const auto &item : items)
            total += item.getTotalPrice();
        return total;
    }
    void printOrder() const
    {
        cout << "Name\tPrice\tQty\tTotal\n";
        for (const auto &item : items)
            item.print();
        cout << "-------------------------------\n";
        cout << "Total: " << calculateTotal() << "\n";
    }
void saveToFile(const string &filename) const
    {
        ofstream fout(filename);
        if (!fout)
            return;
        for (const auto &item : items)
        {
            fout << item.getFoodID() << " " << item.getFoodName() << " " << item.getPrice() << " " << item.getQuantity() << endl;
        }
        fout.close();
    }
    void loadFromFile(const string &filename)
    {
        ifstream fin(filename);
        if (!fin)
            return;
        items.clear();
    