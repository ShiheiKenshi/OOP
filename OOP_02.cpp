#include <iostream>
#include <string>

class Person
{
private:
    std::string m_name;
    char m_gender;
    int m_age;
    int m_weight;

public:
    Person (std::string name = "", char gender = 'm', int age = 0, int weight = 0):
    m_name(name), m_gender(gender), m_age(age), m_weight(weight)
    {
    }

    void setPerson (std::string name, char gender, int age, int weight)
    {
        m_name = name;
        m_gender = gender;
        m_age = age;
        m_weight = weight;
    }

    void setName (std::string name)
    {
        m_name = name;
    }

    void setAge (int age)
    {
        m_age = age;
    }

    void setWeight (int weight)
    {
        m_weight = weight;
    }

    void getPerson ()
    {
        std::cout << "Name: " << m_name << '\n' << "Gender: " << m_gender << '\n' << "Age: " << m_age << '\n' << "Weight: " << m_weight << std::endl;
    }
};

class Student : public Person
{
private:
    int m_academic_year;

public:
    Student(int academic_year = 0):
    m_academic_year(academic_year)
    {

    }

};


int main()
{

    Person Man ("William", 'm', 40, 90);
    Man.getPerson();
    Student Woman;
    Woman.getPerson();
    return 0;
}
