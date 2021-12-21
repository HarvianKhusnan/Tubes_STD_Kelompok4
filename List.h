#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define participant(P) (P)->peserta
#define first(H) ((H).first)
#define last(H) ((H).last)

typedef struct elmEvent *adr_event;
typedef struct elmPeserta *adr_peserta;

const int EXIT = 0;
const int ADD_EVENT = 1;
const int REMOVE_EVENT = 2;
const int SHOW_EVENT = 3;
const int SHOW_PARTICIPANT = 4;
const int ADD_PESERTA = 5;
const int SHOW_PESERTA = 6;

struct event{
    string nama_event,tempat_pelaksanaan,tanggal_pelaksanaan,jenis_event;
    int quota_maks,jumlah;
};

struct peserta{
    int no_peserta,no_tempat_duduk;
    string nama_peserta,email,jenis_peserta,no_telp;
};

struct elmEvent{
    event info;
    adr_peserta peserta;
    adr_event prev,next;
};

struct elmPeserta{
    peserta info;
    adr_peserta next;
    adr_peserta prev;
};

struct events{
    adr_event first, last;
};

struct participants{
    adr_peserta first;
    adr_peserta last;
};

void showMenu();
void createEvents(events &events);
adr_event createElmEvent(event event);
void insertEvent(events &events, adr_event adrEvent);
void deleteEvent(events &events, adr_event &adrEvent);
void showEvents(events events);
void printEvent(event event);
void addPeserta(participants &peserta, adr_peserta adrPeserta);
void showPeserta(participants peserta);
adr_peserta createElmPeserta(peserta peserta);
void createParticipants(participants &peserta);

#endif // LIST_H_INCLUDED
