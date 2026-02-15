#include "Attivita.h"
#include <iostream>
//costruttore
Attivita::Attivita() {
    id = 0;
    titolo = "";
    descrizione = "";
    priorita = 1;
    completata = false;
    categoria = "Generale";
    dataCreazione = time(0);
    dataScadenza = 0;
}

Attivita::Attivita(int i, string t, string d, int p) {
    id = i;
    titolo = t;
    descrizione = d;
    priorita = p;
    completata = false;
    categoria = "Generale";
    dataCreazione = time(0);
    dataScadenza = 0;
}
//stamoa a video
void Attivita::stampa() {
    cout << "ID: " << id << endl;
    cout << "Titolo: " << titolo << endl;
    
    if(descrizione != "") {
        cout << "Descrizione: " << descrizione << endl;
    }
    
    cout << "Categoria: " << categoria << endl;
    cout << "Priorita: " << priorita << "/5" << endl;
    
    if(completata) {
        cout << "Stato: COMPLETATA" << endl;
    } else {
        cout << "Stato: DA FARE" << endl;
        // counter giorni
        if(dataScadenza > 0) {
            int giorni = giorniMancanti();
            if(giorni < 0) {
                cout << "SCADUTA da " << (-giorni) << " giorni!" << endl;
            } else if(giorni == 0) {
                cout << "Scade OGGI!" << endl;
            } else {
                cout << "Mancano " << giorni << " giorni" << endl;
            }
        }
    }
    
    cout << "-------------------" << endl;
}


bool Attivita::scaduta() {
    if(dataScadenza == 0 || completata) {
        return false;
    }
    
    time_t adesso = time(0);
    return adesso > dataScadenza;
}

int Attivita::giorniMancanti() {
    if(dataScadenza == 0) {
        return 0;
    }
    
    time_t adesso = time(0);
    double secondi = difftime(dataScadenza, adesso);
    int giorni = secondi / (60 * 60 * 24);
    
    return giorni;
}