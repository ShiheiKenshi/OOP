#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figure
{
public:

    Figure()
    {

    }

    ~Figure()
    {

    }

    virtual void area() = 0;

};

class Parallelogram : public Figure
{
private:
    int m_base;
    int m_height;

public:

    Parallelogram(int base, int height) :
        m_base(base), m_height(height)
    {

    }

    void area() override
    {
        cout << "The area of the parallelogram is " << m_base * m_height << endl;
    }

    friend class Rectangle;
    friend class Square;
    friend class Rhombus;
};

class Circle : public Figure
{
private:
    double m_radius;

public:

    Circle(double radius) :
        m_radius(radius)
    {

    }

    void area() override
    {
        cout << "The area of the circle is " << M_PI * (m_radius * m_radius) << endl;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int base, int height) :
        Parallelogram(base, height)
    {

    }

    void area() override
    {
        cout << "The area of the rectangle is " << m_base * m_height << endl;
    }
};

class Square : public Parallelogram
{
public:
    Square(int base, int height) :
        Parallelogram(base, height)
    {

    }

    void area() override
    {
        cout << "The area of the square is " << m_base * m_height << endl;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int base, int height) :
        Parallelogram(base, height)
    {

    }

    void area() override
    {
        cout << "The area of the rhombus is " << m_base * m_height << endl;
    }
};

class Car
{
private:
    string m_company;
    string m_model;

public:
    Car(string company = "Company", string model = "Model") :
        m_company(company), m_model(model)
    {
        cout << "This car is " << m_model << " from " << m_company << endl;
    }

    ~Car() = default;

    friend class PassengerCar;
    friend class Bus;
    friend class Minivan;
};

class PassengerCar : virtual public Car
{
public:

    PassengerCar(string company, string model) :
        Car(company, model)
    {
        cout << "This PassengerCar is " << m_model << " from " << m_company << endl;
    }
};

class Bus : virtual public Car
{
public:

    Bus(string company, string model) :
        Car(company, model)
    {
        cout << "This Bus is " << m_model << " from " << m_company << endl;
    }
};

class Minivan : public PassengerCar, public Bus
{
public:

    Minivan(string company, string model) :
        PassengerCar(company, model), Bus(company, model), Car(company, model)
    {
        cout << "This Minivan is " << Car::m_model << " from " << Car::m_company << endl;
    }
};

class Fraction
{
private:

    int num;
    int den;

public:

    Fraction(int numenator, int denominator) :
        num(numenator), den(denominator)
    {
        if (denominator == 0)
            throw runtime_error("Denominator can't be zero");
        else
            cout << "Fraction: " << get_num() << '/' << get_den() << endl;
    }

    int get_num()
    {
        return num;
    }

    int get_den()
    {
        return den;
    }

    friend Fraction operator+ (const Fraction& s1, const Fraction& s2);

    friend Fraction operator* (const Fraction& s1, const Fraction& s2);

    friend Fraction operator- (const Fraction& s1, const Fraction& s2);

    friend Fraction operator/ (const Fraction& s1, const Fraction& s2);

    friend Fraction operator- (const Fraction& s1);

    friend bool operator> (const Fraction& s1, const Fraction& s2);

    friend bool operator>= (const Fraction& s1, const Fraction& s2);

    friend bool operator< (const Fraction& s1, const Fraction& s2);

    friend bool operator<= (const Fraction& s1, const Fraction& s2);

};

Fraction operator+ (const Fraction& s1, const Fraction& s2)
{
    return Fraction(s1.num * s2.den + s2.num * s1.den, s1.den * s2.den);
};

Fraction operator* (const Fraction& s1, const Fraction& s2)
{
    return Fraction(s1.num * s2.num, s1.den * s2.den);
};

Fraction operator- (const Fraction& s1, const Fraction& s2)
{
    return Fraction(s1.num * s2.den - s2.num * s1.den, s1.den * s2.den);
};

Fraction operator/ (const Fraction& s1, const Fraction& s2)
{
    return Fraction(s1.num * s2.den, s1.den * s2.num);
};

Fraction operator- (const Fraction& s1)
{
    return Fraction((-1) * s1.num, s1.den);
};

bool operator> (const Fraction& s1, const Fraction& s2)
{
    return (s1.num * s2.den) > (s1.den * s2.num);
};

bool operator>= (const Fraction& s1, const Fraction& s2)
{
    return (s1.num * s2.den) >= (s1.den * s2.num);
};

bool operator< (const Fraction& s1, const Fraction& s2)
{
    return !(s1 >= s2);
};

bool operator<= (const Fraction& s1, const Fraction& s2)
{
    return !(s1 > s2);
};

class Card
{
public:

    enum rank
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };

    enum suit
    {
        CLUBS, DIAMONDS, HEARTS, SPADES
    };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true) :
        m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
    {

    };

    int GetValue() const
    {
        int value = 0;

        if (m_IsFaceUp)
        {
            value = m_Rank;
        }
        return value;
    };


    void Flip()
    {
        m_IsFaceUp = !(m_IsFaceUp);
    };

private:

    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;

};

int main()
{

    Parallelogram(2, 3).area();
    Circle(3).area();
    Rectangle(3, 3).area();
    Square(1, 4).area();
    Rhombus(2, 2).area();
    cout << endl;


    Car("Toyota", "Prado");
    PassengerCar("Renault", "Duster");
    Bus("Icarus", "66");
    Minivan("KIA", "Carnival");
    cout << endl;

    Fraction f1(4, 7);
    Fraction f2(2, 5);
    Fraction f3 = f1 + f2; // 34/35
    Fraction f4 = f1 * f2; // 8/35
    Fraction f5 = f1 - f2; // 6/35
    Fraction f6 = f1 / f2; // 20/14
    Fraction f7 = -f1; // -4/7
    Fraction f8(2, 5);
    Fraction f9(1, 5);
    if (f8 > f9)
        cout << "Fraction " << f8.get_num() << '/' << f8.get_den() << " are greater than " << f9.get_num() << '/' << f9.get_den() << '.' << endl;
    if (f8 >= f9)
        cout << "Fraction " << f8.get_num() << '/' << f8.get_den() << " are greater or equal than " << f9.get_num() << '/' << f9.get_den() << '.' << endl;
    if (f8 < f9)
        cout << "Fraction " << f9.get_num() << '/' << f9.get_den() << " are greater than " << f8.get_num() << '/' << f8.get_den() << '.' << endl;
    if (f8 <= f9)
        cout << "Fraction " << f9.get_num() << '/' << f9.get_den() << " are greater or equal than " << f8.get_num() << '/' << f8.get_den() << '.' << endl;

    return 0;
}
