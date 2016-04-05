#ifndef MainWindow_H
#define MainWindow_H

#include "math.h"
#include <QQueue>
#include <QStack>

#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>

class mainwindow : public QWidget
{
    //Obligatoire pour création de slots
    Q_OBJECT

public:
    mainwindow();

    void baseDep();
    void baseDest();
    void saisieDep();
    void resultat();
    bool ok;

public slots:
    void valider();
    void effacer();


private :
    QPushButton *m_valider; //déclaration bouton
    QPushButton *m_fermer;
    QPushButton *m_effacer;

    QComboBox *m_baseDep;
    QComboBox *m_baseDest;

    QLineEdit *m_saisieDep;
    QLineEdit *m_resultat;

    QString m_valeurSaisie;
    QString m_baseDepart;
    QString m_baseDestination;

    QString m_base;
    QString m_valeur;
};

#endif
