#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Figure
{
public:

    Figure ()
    {

    }

    ~Figure ()
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

    Parallelogram (int base, int height):
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

    Circle (double radius):
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
    Rectangle(int base, int height):
    Parallelogram (base, height)
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
    Square(int base, int height):
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
    Rhombus(int base, int height):
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
    Car (string company = "Company", string model = "Model"):
    m_company (company), m_model (model)
    {
        cout << "This car is " << m_model << " from " << m_company << endl;
    }

    ~Car () = default;

    friend class PassengerCar;
    friend class Bus;
    friend class Minivan;
};

class PassengerCar : virtual public Car
{
public:

    PassengerCar (string company, string model):
    Car (company, model)
    {
        cout << "This PassengerCar is " << m_model << " from " << m_company << endl;
    }
};

class Bus : virtual public Car
{
public:

    Bus (string company, string model):
    Car (company, model)
    {
        cout << "This Bus is " << m_model << " from " << m_company << endl;
    }
};

class Minivan : public PassengerCar, public Bus
{
public:

    Minivan (string company, string model):
    PassengerCar (company, model), Bus (company, model), Car (company, model)
    {
        cout << "This Minivan is " << Car::m_model << " from " << Car::m_company << endl;
    }
};

class Fraction
{
private:

    int num;
    int den;
    void normalize ();
    int gcf (int a, int b);
    int lcm (int a, int b);
public:

    Fraction (int numenator, int denominator):
    num(numenator), den(denominator)
    {
        if (denominator == 0)
            throw runtime_error ("Denominator can't be zero");
        else
            cout << "Fraction: " << get_num() << '/' << get_den() << endl;
    }

    void set (int n, int d)
    {
        num = n;
        den = d;
    }

    int get_num()
    {
        return num;
    }

    int get_den()
    {
        return den;
    }

    Fraction add (Fraction other);

    Fraction mult (Fraction other);

    Fraction subtract (Fraction other);

    Fraction divide (Fraction other);

};

Fraction Fraction::add (Fraction other)
{
    Fraction fract;
    fract.set(num*other.den+other.num*den, den*other.den);
    return fract;
};

Fraction Fraction::mult (Fraction other)
{
    Fraction fract;
    fract.set(num*other.num, den*other.den);
    return fract;
};

Fraction Fraction::subtract (Fraction other)
{
    Fraction fract;
    fract.set(num*other.den-other.num*den, den*other.den);
    return fract;
};

Fraction Fraction::divide (Fraction other)
{
    Fraction fract;
    fract.set(num*other.den, den*other.num);
    return fract;
};


int main ()
{

    Parallelogram (2, 3).area();
    Circle (3).area();
    Rectangle (3, 3).area();
    Square (1, 4).area();
    Rhombus (2, 2).area();
    cout << endl;


    Car ("Toyota", "Prado");
    PassengerCar ("Renault", "Duster");
    Bus ("Icarus", "66");
    Minivan ("KIA", "Carnival");
    cout << endl;

    Fraction f1 (4, 7);
    Fraction f2 (2, 5);
    Fraction f3 = f1.add(f2); // 34/35
    Fraction f4 = f1.mult(f2); // 6/35
    Fraction f5 = f1.subtract(f2); // 6/35
    Fraction f6 = f1.divide(f2); // 20/14

    return 0;
}
