#include <iostream>
#include "List.h"

using namespace std;

void showMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << ADD_EVENT << ". Tambahkan event baru" << endl;
    cout << REMOVE_EVENT << ". Hapus event" << endl;
    cout << SHOW_EVENT << ". Tampilkan semua svent" << endl;
    cout << SHOW_PARTICIPANT << ". Tampilkan peserta dari sebuah event" << endl;
    cout << EXIT << ". Keluar" << endl;
}
