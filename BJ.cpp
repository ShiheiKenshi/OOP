#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

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

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();

    virtual bool IsHitting() const
    {
        cout << m_Name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    };

    void Win() const 
    {
        cout << m_Name << " wins.\n";
    };

    void Lose() const
    {
        cout << m_Name << " loses.\n";
    };

    void Push() const
    {
        cout << m_Name << " pushes.\n";
    };
};

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    virtual ~House();

    virtual bool IsHitting() const
    {
        return (GetTotal() <= 16);
    };

    void FlipFirstCard()
    {
        if (!(m_Cards.empty()))
        {
            m_Cards[0]->Flip();
        }
        else
        {
            cout << "No card to flip!\n";
        }
    };
};


int main()
{

    return 0;
}