#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

template <class P>
class Pair1
{
private:
    P m_data1;
    P m_data2;

public:
    Pair1(const P& data1, const P& data2) :
        m_data1(data1), m_data2(data2)
    {

    }

    ~Pair1()
    {

    }

    const P& first() const
    {
        return m_data1;
    }

    const P& second() const
    {
        return m_data2;
    }
};

template <class T, class D>
class Pair
{
private:
    T m_data1;
    D m_data2;

public:
    Pair(const T& data1, const D& data2)
        : m_data1(data1), m_data2(data2)
    {
    }

    ~Pair()
    {

    }

    const T& first() const
    {
        return m_data1;
    }

    const D& second() const
    {
        return m_data2;
    }
};

template <class S>
class StringValuePair : public Pair<string, S>
{
public:
    StringValuePair(const string& word, const S& set)
        : Pair<string, S>(word, set)
    {
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

class GenericPlayer : public Hand
{
private:
    friend ostream& operator<<(ostream& os, const GenericPlayer& GP);

public:
    GenericPlayer(const string& name = "") :
        m_Name(name)
    {

    }

    virtual ~GenericPlayer()
    {

    }

    virtual bool IsHitting() const = 0;

    bool IsBusted() const
    {
        return (GetTotal() > 21);
    }

    void Bust() const
    {
        cout << m_Name << " busts.\n";
    };

protected:
    string m_Name;
};

ostream& operator<<(ostream& out, const GenericPlayer& GP)
{
    out << GP.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!GP.m_Cards.empty())
    {
        for (pCard = GP.m_Cards.begin(); pCard != GP.m_Cards.end(); ++pCard)
        {
            out << *(*pCard) << "\t";
        }

        if (GP.GetTotal() != 0)
        {
            cout << "(" << GP.GetTotal() << ")";
        }
    }
    else
    {
        out << "<empty>";
    }

    return out;
}

int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}