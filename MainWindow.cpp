#include "MainWindow.h"

mainwindow::mainwindow()
{
    setFixedSize(700,400);

    m_valider=new QPushButton("Valider",this);
    m_valider->move(600,350);
    QObject::connect(m_valider,SIGNAL(clicked()),this,SLOT(valider()));

    m_fermer=new QPushButton("Fermer",this);
    m_fermer->move(515,350);
    QObject::connect(m_fermer,SIGNAL(clicked()),this,SLOT(close()));

    m_effacer=new QPushButton("Effacer",this);
    m_effacer->move(50,350);
    QObject::connect(m_effacer,SIGNAL(clicked()),this,SLOT(effacer()));

    m_baseDep=new QComboBox(this);
    m_baseDep->move(50,80);
    m_baseDep->addItem("Décimal");
    m_baseDep->addItem("Binaire");
    m_baseDep->addItem("Hexadécimal");
    m_baseDep->addItem("Octal");
    m_baseDep->addItem("Autre");

    m_baseDest=new QComboBox(this);
    m_baseDest->move(500,80);
    m_baseDest->addItem("Décimal");
    m_baseDest->addItem("Binaire");
    m_baseDest->addItem("Hexadécimal");
    m_baseDest->addItem("Octal");

    m_saisieDep=new QLineEdit(this);
    m_saisieDep->setGeometry(50,170,150,20);

    m_resultat=new QLineEdit(this);
    m_resultat->setGeometry(500,170,150,20);
}

void mainwindow::effacer()
{
    m_resultat->setText("");
    m_saisieDep->setText("");
}

/*
void mainwindow::valider()
{
    int baseA, baseD;
    bool dac;

if(m_baseDep->currentText()=="Binaire"){
  baseD = 2;
}
else if(m_baseDep->currentText()=="Décimal"){
  baseD = 10;
}
else if(m_baseDep->currentText()=="Hexadécimal"){
  baseD = 16;
}
else if(m_baseDep->currentText()=="Octal"){
  baseD = 8;
}
else if(m_baseDep->currentText()=="Autre"){
  int coupe;

  if(m_valeurSaisie.mid(1,2).toInt(&ok,10)){
    m_base = m_valeurSaisie.mid(1,2);
    baseD = m_base.toInt();
    coupe = 4;
  }
  else{
    m_base = m_valeurSaisie.mid(1,1);
    baseD = m_base.toInt();
    coupe = 3;
  }
  m_valeurSaisie = m_valeurSaisie.mid(coupe);
}

if(m_baseDest->currentText()=="Binaire"){
  baseA = 2;
}
else if(m_baseDest->currentText()=="Décimal"){
  baseA = 10;
}
else if(m_baseDest->currentText()=="Hexadécimal"){
  baseA = 16;
}
else if(m_baseDest->currentText()=="Octal"){
  baseA = 8;
}

m_resultat->setText(QString::number(m_valeurSaisie()));

}*/


void mainwindow::valider()
{
    m_baseDepart=m_baseDep->currentText();
    m_baseDestination=m_baseDest->currentText();
    m_valeurSaisie=m_saisieDep->text();

    if(m_baseDep->currentText()=="Autre")
    {
        int coupe;

        if( m_valeurSaisie.mid(1,2).toInt(&ok,10))
        {
            m_base = m_valeurSaisie.mid(1,2);
            coupe=4;
        }
        else
        {
            m_base = m_valeurSaisie.mid(1,1);
            coupe=3;
        }

        m_valeurSaisie = m_valeurSaisie.mid(coupe);
    }
    if (m_baseDep->currentText()=="Autre" && m_baseDest->currentText()=="Binaire")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,m_base.toInt()),2));
    }
    else if (m_baseDep->currentText()=="Autre" && m_baseDest->currentText()=="Hexadécimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,m_base.toInt()),16));
    }
    else if (m_baseDep->currentText()=="Autre" && m_baseDest->currentText()=="Décimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,m_base.toInt()),10));
    }
    else if (m_baseDep->currentText()=="Autre" && m_baseDest->currentText()=="Octal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,m_base.toInt()),8));
    }
    else if(m_baseDep->currentText()=="Décimal" && m_baseDest->currentText()=="Binaire")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(),2));
    }
    else if(m_baseDep->currentText()=="Décimal" && m_baseDest->currentText()=="Hexadécimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(),16).toUpper());
    }
    else if(m_baseDep->currentText()=="Décimal" && m_baseDest->currentText()=="Octal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(),8));
    }
    else if(m_baseDep->currentText()=="Binaire" && m_baseDest->currentText()=="Décimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,2),10));
    }
    else if(m_baseDep->currentText()=="Binaire" && m_baseDest->currentText()=="Hexadécimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,2),16).toUpper());
    }
    else if(m_baseDep->currentText()=="Binaire" && m_baseDest->currentText()=="Octal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,2),8));
    }
    else if(m_baseDep->currentText()=="Hexadécimal" && m_baseDest->currentText()=="Décimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,16),10));
    }
    else if(m_baseDep->currentText()=="Hexadécimal" && m_baseDest->currentText()=="Binaire")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,16),2));
    }
    else if(m_baseDep->currentText()=="Hexadécimal" && m_baseDest->currentText()=="Octal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,16),8));
    }
    else if(m_baseDep->currentText()=="Octal" && m_baseDest->currentText()=="Décimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,8),10));
    }
    else if(m_baseDep->currentText()=="Octal" && m_baseDest->currentText()=="Binaire")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,8),2));
    }
    else if(m_baseDep->currentText()=="Octal" && m_baseDest->currentText()=="Hexadécimal")
    {
        m_resultat->setText(QString::number(m_valeurSaisie.toInt(&ok,8),16).toUpper());
    }
    else if(m_baseDep->currentText()==m_baseDest->currentText())
    {
        m_resultat->setText(m_valeurSaisie);
    }

    if(m_resultat->text()=="0")
    {
        m_resultat->setText("Erreur !");
    }
}
