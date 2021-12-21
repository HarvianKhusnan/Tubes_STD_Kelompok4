#include <iostream>
#include "List.h"

using namespace std;

void showMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << ADD_EVENT << ". Tambahkan event baru" << endl;
    cout << REMOVE_EVENT << ". Hapus event" << endl;
    cout << SHOW_EVENT << ". Tampilkan semua event" << endl;
    cout << SHOW_PARTICIPANT << ". Tampilkan peserta dari sebuah event" << endl;
    cout << ADD_PESERTA << ". Tambahkan Data Pesera" << endl;
    cout << SHOW_PESERTA << ". Tampilkan data peserta" << endl;
    cout << EXIT << ". Keluar" << endl;
}

void createEvents(events &events) {
    first(events) = NULL;
    last(events) = NULL;
}

adr_event createElmEvent(event event) {
    // make sure the default jumlah for new event is 0
    if(event.jumlah != 0) {
        event.jumlah = 0;
    }

    adr_event p = new elmEvent;
    info(p) = event;
    next(p) = NULL;
    prev(p) = NULL;
    participant(p) = NULL;

    return p;
}

void insertEvent(events &events, adr_event adrEvent) {
    if(first(events) == NULL && last(events) == NULL) {
        first(events) = adrEvent;
        last(events) = adrEvent;
        next(adrEvent) = first(events);
        prev(adrEvent) = last(events);
    } else {
        next(adrEvent) = first(events);
        prev(adrEvent) = last(events);
        next(last(events)) = adrEvent;
        last(events) = adrEvent;
    }
}

void deleteEvent(events &events, adr_event &adrEvent) {
    adr_event adrEvent2;

    adrEvent2 = first(events);
    if(first(events) != next(adrEvent2)){
        while(next(adrEvent2) != first(events)){
            adrEvent2 = next(adrEvent2);
        }
        adrEvent = first(events);
        first(events) = next(first(events));
        next(adrEvent2) = first(events);
        next(adrEvent2) = NULL;
    }else{
        adrEvent = first(events);
        next(adrEvent) = NULL;
        first(adrEvent) = NULL;
    }



}

void printEvent(event event) {
    cout << "Nama Event : " << event.nama_event << endl;
    cout << "Jenis Event : " << event.jenis_event << endl;
    cout << "Tanggal Pelaksanaan : " << event.tanggal_pelaksanaan << endl;
    cout << "Tempat Pelaksanaan : " << event.tempat_pelaksanaan << endl;
    cout << "Quota Maks : " << event.quota_maks << endl;
    cout << "Jumlah Peserta : " << event.jumlah << endl;
}

void showEvents(events events) {
    if(first(events) == NULL && last(events) == NULL) {
        cout << "Tidak ada event tersedia" << endl << endl;
    } else {
        adr_event p = first(events);
        int counter = 1;
        while(next(p) != first(events)) {
            cout << "========== Event " << counter << " ==========" << endl;
            event temp = info(p);
            printEvent(temp);
            counter += 1;
            p = next(p);
        }
        cout << "========== Event " << counter << " ==========" << endl;
        printEvent(info(p));
    }
}

void addPeserta(participants &peserta, adr_peserta adrPeserta){
    if(first(peserta) == NULL && last(peserta) == NULL){
        first(peserta) = adrPeserta;
        last(peserta) = adrPeserta;
    }else{
        prev(adrPeserta) = last(peserta);
        next(last(peserta)) = adrPeserta;
        last(peserta) = adrPeserta;
    }


}

void showPeserta(participants peserta){

    adr_peserta adrPeserta;


    if(first(peserta)== NULL && last(peserta) == NULL){
        cout << "Empty List" << endl;
    }else{
        adrPeserta = first(peserta);
        while(adrPeserta != NULL){
            cout << "Nomor peserta :" << info(adrPeserta).no_peserta<<endl;
            cout << "Nomor tempat duduk :" << info(adrPeserta).no_tempat_duduk<<endl;
            cout << "Nama peserta :"<<info(adrPeserta).nama_peserta<<endl;
            cout << "Email :" << info(adrPeserta).email<<endl;
            cout << "Jenis peserta :" << info(adrPeserta).jenis_peserta<<endl;
            cout << "Nomor telpon :" << info(adrPeserta).no_telp<<endl;
            cout << endl;
            adrPeserta = next(adrPeserta);
        }

    }
    cout << endl;

}

adr_peserta createElmPeserta(peserta peserta) {
    adr_peserta adrPeserta;

    adrPeserta = new elmPeserta;
    info(adrPeserta) = peserta;
    next(adrPeserta) = NULL;
    prev(adrPeserta) = NULL;

    return adrPeserta;


}

void createParticipants(participants &peserta){
    first(peserta) = NULL;
    last(peserta) = NULL;

}