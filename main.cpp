#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    cout << "=== GESTIONE ATTIVITA' ===" << endl;
    Lista toDoList;

    toDoList.aggiungi("Fare la spesa", "Pasta, pesto e casse d'acqua", 2);
    toDoList.aggiungi("Studiare per gli esami", "Finire esercizi e imparare il teorema", 5);
    toDoList.aggiungi("Pagare rata universitaria", "Scadenza rata di Aprile", 4);
    toDoList.aggiungi("Andare alle poste", "Spedire pacco e pagare bollettino", 3);
    toDoList.aggiungi("Uscita serale", "Guardare il film di Sorrentino con gli amici", 1);


    toDoList.modificaCategoria(1, "Casa");
    toDoList.modificaCategoria(2, "Studio");
    toDoList.modificaCategoria(3, "Finanze");
    toDoList.modificaCategoria(4, "Commissioni");
    toDoList.modificaCategoria(5, "Svago");

    toDoList.modificaScadenza(2, 3);
    toDoList.modificaScadenza(3, 45);



    cout << "-> Completamento task ID 1 (Spesa)" << endl;
    toDoList.modificaStato(1, true);

    cout << "-> Cambio priorita' task ID 4 (Poste)" << endl;
    toDoList.modificaPriorita(4, 5); // Diventa urgente

    //  Test dei Filtri
    cout << "\n--- TEST FILTRO: DA FARE ---" << endl;
    toDoList.mostraDaFare();

    cout << "\n--- TEST FILTRO: CATEGORIA 'Studio' ---" << endl;
    toDoList.mostraPerCategoria("Studio");

    cout << "\n--- TEST FILTRO: PRIORITA' ALTA (>= 4) ---" << endl;
    toDoList.mostraPerPriorita(4);



    toDoList.mostraStatistiche();

// salvataggio dei dati su file esterno csv per excel txt per il profrmamma
    cout << "\n--- TEST  Esportazione file ---" << endl;
    if(toDoList.esportaCSV("lista_impegni.csv")) {
        cout << "File 'lista_impegni.csv' creato correttamente." << endl;
    } else {
        cout << "Errore nella creazione del file." << endl;
    }


    cout << "\n--- TEST SALVATAGGIO E RICARICA ---" << endl;
    if(toDoList.salva("database_attivita.txt")) {
        cout << "Salvataggio riuscito!" << endl;
    }
// verfica del salvataggio
    Lista listaRicaricata;
    if(listaRicaricata.carica("database_attivita.txt")) {
        cout << "Ricarica riuscita! Elementi caricati: " << listaRicaricata.quante() << endl;
        listaRicaricata.mostraTutte();
    }
    return 0;
}