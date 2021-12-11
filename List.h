#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct event *adr_event;
typedef struct peserta *adr_peserta;

struct event{
    string nama_event,tempat_pelaksanaan,tanggal_pelaksanaan,jenis_event;
    int quota_maks,jumlah;
};

struct peserta{
    int no_peserta,no_tempat_duduk;
    string nama_peserta,email,jenis_peserta,no_telp;
};

struct elmEvent{
    //prev,info,next,peserta
    adr_peserta peserta;
    adr_event prev,next;
    event info;

};

struct events{
    adr_event first;
    adr_event last;

};

struct elmPeserta{
    //info,next,prev
    peserta info;
    adr_peserta next;
    adr_peserta prev;


};

struct listPeserta{
    adr_peserta first;
    adr_peserta last;

};


#endif // LIST_H_INCLUDED
