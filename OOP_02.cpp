#include <iostream>
#include <string>

template <class T>
class Counter
{
private:
    static int count;

public:
    Counter()
    {
        count++;
    }

    Counter(const Counter& c)
    {
        count++;
    }

    ~Counter()
    {
        count--;
    }

    static int getCount()
    {
        return count;
    }
};

template<class T>
int Counter<T>::count = 0;

class Person
{
private:
    std::string m_name;
    char m_gender;
    int m_age;
    int m_weight;

public:
    Person(std::string name = "", char gender = 'M', int age = 0, int weight = 0) :
        m_name(name), m_gender(gender), m_age(age), m_weight(weight)
    {
    }

    void setPerson(std::string name, char gender, int age, int weight)
    {
        m_name = name;
        m_gender = gender;
        m_age = age;
        m_weight = weight;
    }

    void setName(std::string name)
    {
        m_name = name;
    }

    void setAge(int age)
    {
        m_age = age;
    }

    void setWeight(int weight)
    {
        m_weight = weight;
    }

    void getPerson()
    {
        std::cout << "Name: " << m_name << '\n' << "Gender: " << m_gender << '\n' << "Age: " << m_age << '\n' << "Weight: " << m_weight << std::endl;
    }
};

class Student : public Person, private Counter<Student>
{
private:
    int m_academic_year;

public:
    Student(std::string name = "", char gender = 'm', int age = 0, int weight = 0, int academic_year = 0) :
        Person(name, gender, age, weight), m_academic_year(academic_year)
    {

    }

    void setAcademic(int academic_year)
    {
        m_academic_year = academic_year;
    }

    using Counter<Student>::getCount;

    void getStudent()
    {
        getPerson();
        std::cout << "Academic Year: " << m_academic_year << '\n' << std::endl;
    }

};

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name = "Fruit", std::string color = "White") :
        m_name(name), m_color(color)
    {
    }

    std::string getName()
    {
        return m_name;
    }

    std::string getColor()
    {
        return m_color;
    }

    void setName(std::string name)
    {
        m_name = name;
    }

    void setColor(std::string color)
    {
        m_color = color;
    }
};

class Apple : public Fruit
{
public:
    Apple(std::string color)
    {
        Fruit::setName("Apple");
        Fruit::setColor(color);
    }
};

class Banana : public Fruit
{
public:
    Banana()
    {
        Fruit::setName("Banana");
        Fruit::setColor("yellow");
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith(std::string color = "green") :
        Apple(color)
    {
        Apple::setName("Granny Smith apple");
    }
};


int main()
{
    Student Mike("Mike", 'M', 18, 55, 2);
    Mike.getStudent();
    Student Lyly("Lyly", 'F', 21, 45, 5);
    Student Egor("Egor", 'M', 19, 80, 3);
    Lyly.getStudent();
    Lyly.setName("Liliana");
    Lyly.setAge(22);
    Lyly.setAcademic(6);
    Lyly.getStudent();
    Egor.getStudent();

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


    return 0;
}

/*Blackjack

Класс           Родительский класс      Описание
Game            нет                     Игра
Card            нет                     Карта
Deck            нет                     Колода и действия с ней
Hand            Deck                    Набор карт из Deck
Player          нет                     Человек-игрок
House           нет                     Компьютер-игрок
Win             Deck                    Набор карт из Deck, необходимый для победы
*/