#include <gtest/gtest.h>
#include "Lista.h"
#include <vector>
#include <cstdio> // Per remove()


class ListaTest : public ::testing::Test {
protected:
    Lista lista;

    void SetUp() override {

        lista.aggiungi("Task 1", "Desc 1", 1);
        lista.aggiungi("Task 2", "Desc 2", 2);
        lista.aggiungi("Task 3", "Desc 3", 3);
    }
};


TEST_F(ListaTest, AggiungiEConta) {
    EXPECT_EQ(lista.quante(), 3);
    lista.aggiungi("Task 4", "Desc 4", 1);
    EXPECT_EQ(lista.quante(), 4);
}


TEST_F(ListaTest, RimuoviElemento) {
    lista.rimuovi(2);
    EXPECT_EQ(lista.quante(), 2);
    EXPECT_EQ(lista.trovaAttivita(2), (Attivita*)NULL);
}


TEST_F(ListaTest, ModificaStato) {
    lista.modificaStato(1, true);
    EXPECT_TRUE(lista.trovaAttivita(1)->isCompletata());
    EXPECT_EQ(lista.quanteCompletate(), 1);
}


TEST_F(ListaTest, ConteggioCategorie) {
    lista.modificaCategoria(1, "Lavoro");
    lista.modificaCategoria(2, "Lavoro");
    lista.modificaCategoria(3, "Svago");

    EXPECT_EQ(lista.quantePerCategoria("Lavoro"), 2);
    EXPECT_EQ(lista.quantePerCategoria("Svago"), 1);
}


TEST_F(ListaTest, CancellaSoloCompletate) {
    lista.modificaStato(1, true);
    lista.modificaStato(3, true);

    lista.cancellaCompletate();

    EXPECT_EQ(lista.quante(), 1);
    EXPECT_NE(lista.trovaAttivita(2), (Attivita*)NULL);
}


TEST_F(ListaTest, SalvaECaricaSuFile) {
    string filename = "test_db.txt";

    lista.modificaTitolo(1, "SalvataggioCheck");
    ASSERT_TRUE(lista.salva(filename));

    Lista lista2;
    ASSERT_TRUE(lista2.carica(filename));

    EXPECT_EQ(lista2.quante(), 3);
    EXPECT_EQ(lista2.trovaAttivita(1)->getTitolo(), "SalvataggioCheck");

    remove(filename.c_str());
}