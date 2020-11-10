#include <iostream>
#include "dualList.h"

using namespace std;

int main()
{
    dualList* testDualList=new dualList;
    size_t i, count;
    int con;
    cout << "How many elements you want to add? ";
    cin >> count;
    for (i = 0; i < count; i++)
    {
        cout << i << " item is: ";
        cin >> con;
        testDualList->push_back(con);
    }
    cout << "ListNow: " << endl;
    testDualList->print_to_console();
    cout << endl;
    cout <<"ListSize: " << testDualList->get_size() << endl;
    cout << "Index item to insert and contend " << endl;
    cin >> i >> con;
    testDualList->insert(con, i);
    cout << "ListNow: "<< endl;
    testDualList->print_to_console();
}

