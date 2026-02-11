#include "Lista.h"
#include <fstream>
#include <iostream>


Lista::Lista() {
    contatore = 1;
}

int Lista::trovaIndice(int id) {
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void Lista::aggiungi(string titolo, string descrizione, int priorita) {
    Attivita temp(contatore, titolo, descrizione, priorita);
    attivita.push_back(temp);
    contatore++;
}

void Lista::rimuovi(int id) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita.erase(attivita.begin() + indice);
    }
}

void Lista::modificaStato(int id, bool completata) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita[indice].setCompletata(completata);
    }
}

void Lista::modificaTitolo(int id, string nuovoTitolo) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita[indice].setTitolo(nuovoTitolo);
    }
}

void Lista::modificaDescrizione(int id, string nuovaDesc) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita[indice].setDescrizione(nuovaDesc);
    }
}

void Lista::modificaPriorita(int id, int nuovaPriorita) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita[indice].setPriorita(nuovaPriorita);
    }
}

void Lista::modificaCategoria(int id, string nuovaCategoria) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        attivita[indice].setCategoria(nuovaCategoria);
    }
}

void Lista::modificaScadenza(int id, int giorni) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        time_t adesso = time(0);
        time_t scadenza = adesso + (giorni * 24 * 60 * 60);
        attivita[indice].setDataScadenza(scadenza);
    }
}

void Lista::mostraTutte() {
    if(attivita.size() == 0) {
        cout << "Nessuna attivita presente!" << endl;
        return;
    }
    
    for(int i = 0; i < attivita.size(); i++) {
        attivita[i].stampa();
    }
}


void Lista::mostraDaFare() {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(!attivita[i].isCompletata()) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Tutte le attivita sono completate!" << endl;
    }
}

void Lista::mostraCompletate() {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].isCompletata()) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Nessuna attivita completata!" << endl;
    }
}

void Lista::mostraPerCategoria(string cat) {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].getCategoria() == cat) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Nessuna attivita nella categoria: " << cat << endl;
    }
}

void Lista::mostraPerPriorita(int minPriorita) {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].getPriorita() >= minPriorita) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Nessuna attivita con priorita >= " << minPriorita << endl;
    }
}

void Lista::mostraScadute() {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].scaduta()) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Nessuna attivita scaduta!" << endl;
    }
}

void Lista::mostraInScadenza(int giorniMax) {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(!attivita[i].isCompletata()) {
            int giorni = attivita[i].giorniMancanti();
            if(giorni > 0 && giorni <= giorniMax) {
                attivita[i].stampa();
                trovata = true;
            }
        }
    }
    
    if(!trovata) {
        cout << "Nessuna attivita in scadenza!" << endl;
    }
}

void Lista::cercaPerTitolo(string parola) {
    bool trovata = false;
    
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].getTitolo().find(parola) != string::npos) {
            attivita[i].stampa();
            trovata = true;
        }
    }
    
    if(!trovata) {
        cout << "Nessun risultato per: " << parola << endl;
    }
}

Attivita* Lista::trovaAttivita(int id) {
    int indice = trovaIndice(id);
    if(indice != -1) {
        return &attivita[indice];
    }
    return NULL;
}

int Lista::quante() {
    return attivita.size();
}

int Lista::quanteCompletate() {
    int conta = 0;
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].isCompletata()) {
            conta++;
        }
    }
    return conta;
}

int Lista::quanteDaFare() {
    return quante() - quanteCompletate();
}

int Lista::quantePerCategoria(string cat) {
    int conta = 0;
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].getCategoria() == cat) {
            conta++;
        }
    }
    return conta;
}

int Lista::quanteScadute() {
    int conta = 0;
    for(int i = 0; i < attivita.size(); i++) {
        if(attivita[i].scaduta()) {
            conta++;
        }
    }
    return conta;
}

void Lista::mostraStatistiche() {
    cout << "\n=== STATISTICHE ===" << endl;
    cout << "Totale attivita: " << quante() << endl;
    cout << "Completate: " << quanteCompletate() << endl;
    cout << "Da fare: " << quanteDaFare() << endl;
    cout << "Scadute: " << quanteScadute() << endl;
    
    // percentuale completamento
    if(quante() > 0) {
        float perc = (float)quanteCompletate() / quante() * 100;
        cout << "Completamento: " << perc << "%" << endl;
    }
    
    // categorie
    vector<string> categorie = ottieniCategorie();
    if(categorie.size() > 0) {
        cout << "\nPer categoria:" << endl;
        for(int i = 0; i < categorie.size(); i++) {
            int num = quantePerCategoria(categorie[i]);
            cout << "  " << categorie[i] << ": " << num << endl;
        }
    }
}

void Lista::cancellaCompletate() {
    int cancellate = 0;
    
    for(int i = attivita.size() - 1; i >= 0; i--) {
        if(attivita[i].isCompletata()) {
            attivita.erase(attivita.begin() + i);
            cancellate++;
        }
    }
    
    cout << "Cancellate " << cancellate << " attivita" << endl;
}

void Lista::cancellaTutte() {
    attivita.clear();
    contatore = 1;
}

vector<string> Lista::ottieniCategorie() {
    vector<string> categorie;
    
    for(int i = 0; i < attivita.size(); i++) {
        string cat = attivita[i].getCategoria();
        
        // controllo se già presente
        bool presente = false;
        for(int j = 0; j < categorie.size(); j++) {
            if(categorie[j] == cat) {
                presente = true;
                break;
            }
        }
        
        if(!presente) {
            categorie.push_back(cat);
        }
    }
    
    return categorie;
}

bool Lista::salva(string nomeFile) {
    ofstream file(nomeFile.c_str());
    
    if(!file.is_open()) {
        return false;
    }
    
    file << contatore << endl;
    file << attivita.size() << endl;
    
    for(int i = 0; i < attivita.size(); i++) {
        file << attivita[i].getId() << endl;
        file << attivita[i].getTitolo() << endl;
        file << attivita[i].getDescrizione() << endl;
        file << attivita[i].getPriorita() << endl;
        file << attivita[i].isCompletata() << endl;
        file << attivita[i].getCategoria() << endl;
        file << attivita[i].getDataCreazione() << endl;
        file << attivita[i].getDataScadenza() << endl;
    }
    
    file.close();
    return true;
}

bool Lista::carica(string nomeFile) {
    ifstream file(nomeFile.c_str());
    
    if(!file.is_open()) {
        return false;
    }
    
    attivita.clear();
    
    file >> contatore;
    
    int num;
    file >> num;
    file.ignore();
    
    for(int i = 0; i < num; i++) {
        int id, prio, stato;
        string tit, desc, cat;
        time_t dataCrea, dataScad;
        
        file >> id;
        file.ignore();
        getline(file, tit);
        getline(file, desc);
        file >> prio;
        file >> stato;
        file.ignore();
        getline(file, cat);
        file >> dataCrea;
        file >> dataScad;
        file.ignore();
        
        Attivita a(id, tit, desc, prio);
        if(stato == 1) {
            a.setCompletata(true);
        }
        a.setCategoria(cat);
        a.setDataScadenza(dataScad);
        
        attivita.push_back(a);
    }
    
    file.close();
    return true;
}

bool Lista::esportaCSV(string nomeFile) {
    ofstream file(nomeFile.c_str());
    
    if(!file.is_open()) {
        return false;
    }
    
    // intestazione
    file << "ID,Titolo,Descrizione,Priorita,Stato,Categoria" << endl;
    
    for(int i = 0; i < attivita.size(); i++) {
        file << attivita[i].getId() << ",";
        file << attivita[i].getTitolo() << ",";
        file << attivita[i].getDescrizione() << ",";
        file << attivita[i].getPriorita() << ",";
        
        if(attivita[i].isCompletata()) {
            file << "COMPLETATA,";
        } else {
            file << "DA FARE,";
        }
        
        file << attivita[i].getCategoria() << endl;
    }
    
    file.close();
    return true;
}