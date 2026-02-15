#ifndef LISTA_H
#define LISTA_H

#include "Attivita.h"
#include <vector>
#include <string>

class Lista {
private:
    vector<Attivita> attivita;
    int contatore;
    int trovaIndice(int id);

public:

    Lista();
    //gestione delle attivita
    void aggiungi(string titolo, string descrizione, int priorita);
    void rimuovi(int id);
    void modificaStato(int id, bool completata);
    void modificaTitolo(int id, string nuovoTitolo);
    void modificaDescrizione(int id, string nuovaDesc);
    void modificaPriorita(int id, int nuovaPriorita);
    void modificaCategoria(int id, string nuovaCategoria);
    void modificaScadenza(int id, int giorni);

    // visualizzazione
    void mostraTutte();
    void mostraDaFare();
    void mostraCompletate();
    void mostraPerCategoria(string cat);
    void mostraPerPriorita(int minPriorita);
    void mostraScadute();
    void mostraInScadenza(int giorniMax);
//funzione di ricerca
    void cercaPerTitolo(string parola);
    Attivita* trovaAttivita(int id);

    int quante();
    int quanteCompletate();
    int quanteDaFare();
    int quantePerCategoria(string cat);
    int quanteScadute();
    void mostraStatistiche();

//funzioni di pulizia
    void cancellaCompletate();
    void cancellaTutte();
    vector<string> ottieniCategorie();

//salvataggio
    bool salva(string nomeFile);
    bool carica(string nomeFile);
    bool esportaCSV(string nomeFile);
};

#endif