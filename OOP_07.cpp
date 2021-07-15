#include <iostream>
using namespace std;

class Date
{
private:

    int m_Day;
    int m_Month;
    int m_Year;

public:

    Date (int day, int month, int year):
    m_Day(day), m_Month(month), m_Year(year)
    {

    }

    ~Date ()
    {

    }

    int getDay() const
    {
        return m_Day;
    }

    int getMonth() const
    {
        return m_Month;
    }

    int getYear() const
    {
        return m_Year;
    }

    friend ostream &operator<< (ostream &os, const Date &date);
};

ostream &operator<< (ostream &os, const Date &date)
    {
        os  << date.getDay() << '.' << date.getMonth() << '.' << date.getYear() << endl;
        return os;
    };

    std::unique_ptr<Item> item1(new Item);
    std::unique_ptr<Item> item2;
    item2 = std::move(item1);

int main()
{
    Date date (19, 01, 1986);
    cout << date;

    return 0;
}
