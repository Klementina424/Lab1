#include <iostream>
#include "dualList.h"

using namespace std;

int main()
{
    dualList* DualList=new dualList;
    size_t i, count;
    int information;
    cout << "How many elements you want to add? ";
    cin >> count;
    for (i = 0; i < count; i++)
    {
        cout << i << " item is: ";
        cin >> information;
        DualList->push_back(information);
    }
    cout << "ListNow: " << endl;
    DualList->print_to_console();
    cout << endl;
    cout <<"ListSize: " << DualList->get_size() << endl;
    cout << "Index item to insert and contend " << endl;
    cin >> i >> information;
    DualList->insert(information, i);
    cout << "ListNow: "<< endl;
    DualList->print_to_console();
}

