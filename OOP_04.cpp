#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength()
    {
        return m_length;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value)
    {
        insertBefore(value, m_length);
    }

    void print_Array()
    {
        cout << "ArrayInt: ";
        for (int i = 0; i < m_length; ++i)
        {
            cout << m_data[i] << ' ';
        }
        cout << '\n' << "Array length = " << getLength() << '\n' << endl;
    }

    void pop_back()
    {
        if (m_length - 1 <= 0)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];

        for (int index = 0; index < m_length - 1; ++index)
            data[index] = m_data[index];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_front()
    {
        if (m_length - 1 <= 0)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];

        for (int index = 1; index < m_length; ++index)
            data[index - 1] = m_data[index];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void sort_array()
    {
        if (m_length <= 0)
        {
            return;
        }

        sort(m_data, m_data + m_length);
    }

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

class Hand
{
public:
    Hand();
    virtual ~Hand();

    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    };

    void Clear()
    {
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete* iter;
            *iter = 0;
        }
        m_Cards.clear();
    };

    int GetTotal() const
    {
        if (m_Cards.empty())
        {
            return 0;
        }

        if (m_Cards[0]->GetValue() == 0)
        {
            return 0;
        }

        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            total += (*iter)->GetValue();
        }

        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            if ((*iter)->GetValue() == Card::ACE)
            {
                containsAce = true;
            }
        }


        if (containsAce && total <= 11)
        {
            total += 10;
        }

        return total;
    };

protected:
    vector<Card*> m_Cards;
};


int main()
{

    ArrayInt arr;
    arr.print_Array();
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(4);
    arr.print_Array();
    arr.sort_array();
    arr.print_Array();
    arr.pop_back();
    arr.print_Array();
    arr.pop_front();
    arr.print_Array();

    vector<int> v = { 1, 0, 3, 1, 2 };
    set<int> s(v.begin(), v.end());
    cout << "Total different numbers=" << s.size() << endl << "They are: ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
