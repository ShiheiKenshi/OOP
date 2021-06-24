#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>

class Power
{
private:
    float mode_one;
    float mode_two;

public:
        Power ()
    {
      mode_one = 2.0;
      mode_two = 3.0;
    }

    void setPower (float md_one, float md_two)
    {
        mode_one = md_one;
        mode_two = md_two;
    }

    void calculatePower ()
    {
        std::cout << pow(mode_one, mode_two) << '\n';
    }

    void print ()
    {
        std::cout << "mode_one = " << mode_one << '\n';
        std::cout << "mode_two = " << mode_two << '\n';
    }
};

class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	RGBA(std::uint8_t red=0, std::uint8_t green=0, std::uint8_t blue=0, std::uint8_t alpha=255) :
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red) <<
			" g=" << static_cast<int>(m_green) <<
			" b=" << static_cast<int>(m_blue) <<
			" a=" << static_cast<int>(m_alpha) << '\n';
	}
};

class Stack
{
private:
	int m_array[10];
	int m_stack;

public:

	void reset()
	{
		m_stack = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
		if (m_stack == 10)
			return false;

		m_array[m_stack++] = value;
		return true;
	}

	int pop()
	{
		assert (m_stack > 0);
		return m_array[--m_stack];
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_stack; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};


main ()
{
    Power p1;
    p1.print();
    p1.calculatePower();
    p1.setPower(2.0, 2.0);
    p1.print();
    p1.calculatePower();

    RGBA color(200, 135, 255, 0);
	color.print();

	Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

	return 0;
}
