#include <gtest/gtest.h>
#include "Attivita.h"
#include <ctime>


TEST(AttivitaTest, CostruttoreEGetters) {
    Attivita a(1, "Test Titolo", "Test Descrizione", 3);
    
    EXPECT_EQ(a.getId(), 1);
    EXPECT_EQ(a.getTitolo(), "Test Titolo");
    EXPECT_EQ(a.getDescrizione(), "Test Descrizione");
    EXPECT_EQ(a.getPriorita(), 3);
    EXPECT_FALSE(a.isCompletata());
    EXPECT_EQ(a.getCategoria(), "Generale");
}


TEST(AttivitaTest, ControlloScadenza) {
    Attivita a(1, "Task", "Desc", 1);
    

    EXPECT_FALSE(a.scaduta());
    

    time_t domani = time(0) + (24 * 60 * 60);
    a.setDataScadenza(domani);
    EXPECT_FALSE(a.scaduta());

    //  Scadenza passata
    time_t ieri = time(0) - (24 * 60 * 60);
    a.setDataScadenza(ieri);
    EXPECT_TRUE(a.scaduta());
}


TEST(AttivitaTest, CompletataNonScade) {
    Attivita a(1, "Task", "Desc", 1);
    time_t ieri = time(0) - (24 * 60 * 60);
    a.setDataScadenza(ieri);
    

    EXPECT_TRUE(a.scaduta());
    

    a.setCompletata(true);

    EXPECT_FALSE(a.scaduta());
}