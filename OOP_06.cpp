#include <iostream>
using namespace std;

ostream& endll (ostream& os)
{
    os << "\n\n";
    os.flush();

    return os;
}


int main()
{
    int i;
    cout<<"Enter int : ";
    while (!(cin>>i) || cin.get() != '\n')
    {
        cout<<"Error !! Enter again !\n";
        cin.clear();
        cin.ignore(32767,'\n');
        cout<<"Enter int : ";
    }
    cout << "I = " << i << endll << "The end." << endl;
    return 0;
}
