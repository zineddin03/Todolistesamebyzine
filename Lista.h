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

    void cercaPerTitolo(string parola);
    Attivita* trovaAttivita(int id);//è un metodo di ricerca che restiuitus e un puntatore ad un oggetto di tipo attività

    int quante();
    int quanteCompletate();
    int quanteDaFare();
    int quantePerCategoria(string cat);
    int quanteScadute();
    void mostraStatistiche();


    void cancellaCompletate();
    void cancellaTutte();
    vector<string> ottieniCategorie();


    bool salva(string nomeFile);
    bool carica(string nomeFile);
    bool esportaCSV(string nomeFile);
};

#endif