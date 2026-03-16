// S. Trowbridge 2023
#include <iostream>
using namespace std;                  // std namespace has global scope

namespace et575 {                     // create a namespace called et575
    int x = 5;                        // create an integer variable in this namespace
}

namespace et580 {                     // create a namespace called et580
    char x = 'X';                     // create a char variable in this namespace
}

int main() {
    cout << endl;

    {
        using namespace et575;        // et575 namespace has scope in this code block
        cout << x << endl;            // print x from the et575 namespace
        cout << et580::x << endl;     // print x from previously defined ET580 namespace
    }
    {
        using namespace et580;        // et580 namespace has scope in this code block
        cout << x << endl;            // print x from the et580 namespace
        cout << et575::x << endl;     // print x from previously defined ET575 namespace
    }

    cout << et575::x << endl;          // print x from previously defined ET575 namespace
    cout << et580::x << endl;          // print x from previously defined ET580 namespace

    cout << endl;
    return 0;
}
