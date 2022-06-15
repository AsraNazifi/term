#include <iostream>
#include "term.h"
#include "polynomial.h"
using namespace std;
int main()
{
    polynomial mylist1, mylist2;
    cin >> mylist1;
    cout << mylist1 << endl;
    cin >> mylist2;
    cout << mylist1 * mylist2;
    return 0;
}
