#include <iostream>
#include "List.h"

using namespace std;

int main()
{

    // Define the events
    events eventList;

    // create the event list
    createEvents(eventList);

    showMenu();
    int choose;
    cout << "Pilih Menu : "; cin >> choose;
    while(choose != EXIT) {
        switch(choose) {
            case ADD_EVENT: {
                string tanggal, bulan, tahun;
                event newEvent;
                adr_event newEventElm;

                cout << "Nama event : "; cin >> newEvent.nama_event;
                cout << "Jenis event : "; cin >> newEvent.jenis_event;
                cout << "Tanggal pelaksanaan : "; cin >> tanggal;
                cout << "Bulan pelaksanaan : "; cin >> bulan;
                cout << "Tahun pelaksanaan : "; cin >> tahun;
                newEvent.tanggal_pelaksanaan = tanggal + " " + bulan + " " + tahun;
                cout << "Tempat pelaksanaan : "; cin >> newEvent.tempat_pelaksanaan;
                cout << "Quota Maks : "; cin >> newEvent.quota_maks;
                newEvent.jumlah = 0;

                newEventElm = createElmEvent(newEvent);
                insertEvent(eventList, newEventElm);
                break;
            }
            case REMOVE_EVENT: {
                cout << "REMOVE EVENT" << endl;
                break;
            }
            case SHOW_EVENT: {
                showEvents(eventList);
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
