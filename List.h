#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define participant(P) (P)->participant
#define lastParticipant(P) (P)->lastParticipant
#define first(H) ((H).first)
#define last(H) ((H).last)

const int EXIT = 0;
const int JOIN_EVENT = 1;
const int CANCEL_JOIN_EVENT = 2;
const int ADD_EVENT = 3;
const int REMOVE_EVENT = 4;
const int SHOW_AVAILABLE_EVENTS = 5;
const int SHOW_EVENTS_WITH_PARTICIPANT = 6;
const int SHOW_PARTICIPANTS_IN_AN_EVENT = 7;
const int SEARCH_PARTICIPANT_IN_AN_EVENT = 8;
const int REGISTER_PARTICIPANT = 9;
const int REMOVE_PARTICIPANT = 10;
const int SHOW_PARTICIPANTS = 11; // This feature only use for development process
const int SHOW_EVENTS = 12; // This feature only use for development process

const int SHOW_ALL = 1;
const int SHOW_ONLY_AVAILABLE = 2;
const int SHOW_ONLY_NOT_AVAILABLE = 3;

typedef struct elmEvent *adr_event;
typedef struct elmParticipant *adr_participant;
typedef struct elmEventParticipant *adr_event_participant;

struct event {
    string nama_event, jenis_event, tanggal_pelaksanaan, tempat_pelaksanaan;
    int quota_maks, jumlah;
};

struct elmEvent {
    event info;
    adr_event_participant participant;
    adr_event_participant lastParticipant;
    adr_event prev, next;
};

struct events{
    adr_event first, last;
};


struct participant {
    int no_peserta, no_tempat_duduk;
    string nama_peserta, email, jenis_peserta, no_telp;
};

struct elmParticipant {
    participant info;
    adr_participant next, prev;
};

struct participants{
    adr_participant first, last;
};

struct elmEventParticipant {
    adr_event_participant next, prev;
    adr_participant info;
};

void showMenu();

void createEvents(events &events);
adr_event createElmEvent(event event);
void insertEvent(events &events, adr_event adrEvent);
void deleteFirstEvent(events &events, adr_event &adrEvent);
void deleteLastEvent(events &events, adr_event &adrEvent);
void deleteAfterEvent(adr_event adrEventPrec, adr_event &adrEvent);
void deleteEvent(events &events, string eventName, adr_event &deletedEvent);
void showEvents(events events, int showFlag = SHOW_ALL, bool eventData = true, bool eventParticipant = false);
void printEvent(event event);
void showEventWithFlag(adr_event currentEvent, int showFlag, bool eventData, bool eventParticipant, int counter);
adr_event searchEvent(events events, string eventName);
void joinEvent(adr_event adrEvent, adr_event_participant adrEventParticipant);

adr_event_participant createElmEventParticipant(adr_participant adrParticipant);

void createParticipants(participants &participants);
adr_participant createElmParticipant(participant participant);
void insertParticipant(participants &participants, adr_participant adrParticipant);
void showParticipants(participants participants);
void showParticipantsInEvent(adr_event adrEvent);
void printParticipant(participant participant);
adr_participant searchParticipant(participants participants, string participantEmail);
adr_event_participant searchParticipantInEvent(adr_event adrEvent, string participantEmail);

#endif // LIST_H_INCLUDED
