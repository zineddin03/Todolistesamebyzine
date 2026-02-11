#ifndef ATTIVITA_H
#define ATTIVITA_H

#include <string>
#include <ctime>
using namespace std;

class Attivita {
private:
    int id;
    string titolo;
    string descrizione;
    int priorita;
    bool completata;
    string categoria;
    time_t dataCreazione;
    time_t dataScadenza;
    
public:
    Attivita();
    Attivita(int i, string t, string d, int p);
    
    int getId() { return id; }
    string getTitolo() { return titolo; }
    string getDescrizione() { return descrizione; }
    int getPriorita() { return priorita; }
    bool isCompletata() { return completata; }
    string getCategoria() { return categoria; }
    time_t getDataCreazione() { return dataCreazione; }
    time_t getDataScadenza() { return dataScadenza; }
    
    void setTitolo(string t) { titolo = t; }
    void setDescrizione(string d) { descrizione = d; }
    void setPriorita(int p) { priorita = p; }
    void setCompletata(bool c) { completata = c; }
    void setCategoria(string c) { categoria = c; }
    void setDataScadenza(time_t d) { dataScadenza = d; }
    
    void stampa();
    bool scaduta();
    int giorniMancanti();
};

#endif