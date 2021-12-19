#include <iostream>
#include "List.h"

using namespace std;

int main()
{

    showMenu();
    int choose;
    cout << "Pilih Menu : "; cin >> choose;
    while(choose != EXIT) {
        switch(choose) {
            case ADD_EVENT: {
                cout << "ADD EVENT" << endl;
                break;
            }
            case REMOVE_EVENT: {
                cout << "REMOVE EVENT" << endl;
                break;
            }
            case SHOW_EVENT: {
                cout << "SHOW EVENT" << endl;
                break;
            }
            case SHOW_PARTICIPANT: {
                cout << "SHOW PARTICIPANT" << endl;
                break;
            }
        }
        showMenu();
        cout << "Pilih Menu : "; cin >> choose;
    }

    return 0;
}
