#include "MainWindow.h"

using namespace std;

//Décimal vers Binaire
void mainwindow::decBin(QString m_valeurSaisie)
{
    QStack<int> p;
    int a, b;

    a=m_valeurSaisie.toInt();

    while(a>0)
    {
        p.push(a%2);
        a/=2;
    }

    while(!p.empty()){
        b=p.top();
        p.pop();
    }
}

//Binaire vers Décimal
void mainwindow::binDec(QString m_valeurSaisie){
    QQueue<int> p;
    int a, i(0);

    a=m_valeurSaisie.toInt();

    while(a>0){
        p.push(a%10);
        a/=10;
    }

    while(!p.empty()){
        a+=p.front()*pow(2,i++);
        p.pop();
    }


}

//Décimal vers Hexadécimal
void mainwindow::decHex(QString m_valeurSaisie){
    QStack<int> p;
    int a;

    a = m_valeurSaisie.toInt();

    while(a>0){
        p.push(a%16);
        a/=16;
    }

    while(!p.empty()){
        a=p.top();

        if(a==10){
            cout<<"A";
            p.pop();
        }
        else if(a==11){
            cout<<"B";
            p.pop();
        }
        else if(a==12){
            cout<<"C";
            p.pop();
        }
        else if(a==13){
            cout<<"D";
            p.pop();
        }
        else if(a==14){
            cout<<"E";
            p.pop();
        }
        else if(a==15){
            cout<<"F";
            p.pop();
        }
        else{
            cout<<a;
            p.pop();
        }
    }
    cout<<"\n"<<endl;
}

//Hexadécimal vers Décimal
void mainwindow::hexDec(){
    QStack<int> f;
    char r, x[10];
    int a, i(0);

    for(unsigned long i=0; i<=strlen(x);i++){
        r=x[i];

        if(r=='A' || r=='a'){
            a=10;
            f.push(a);
        }
        else if(r=='B' || r=='b'){
            a=11;
            f.push(a);
        }
        else if(r=='C' || r=='c'){
            a=12;
            f.push(a);
        }
        else if(r=='D' || r=='d'){
            a=13;
            f.push(a);
        }
        else if(r=='E' || r=='e'){
            a=14;
            f.push(a);
        }
        else if(r=='F' || r=='f'){
            a=15;
            f.push(a);
        }
        else if(r=='1'){
            a=1;
            f.push(a);
        }
        else if(r=='2'){
            a=2;
            f.push(a);
        }
        else if(r=='3'){
            a=3;
            f.push(a);
        }
        else if(r=='4'){
            a=4;
            f.push(a);
        }
        else if(r=='5'){
            a=5;
            f.push(a);
        }
        else if(r=='6'){
            a=6;
            f.push(a);
        }
        else if(r=='7'){
            a=7;
            f.push(a);
        }
        else if(r=='8'){
            a=8;
            f.push(a);
        }
        else if(r=='9'){
            a=9;
            f.push(a);
        }
    }

    a=0;

    while(!f.empty()){
        a+=f.top()*pow(16,i++);
        f.pop();
    }
}

//Hexadécimal vers Binaire
void mainwindow::hexBin(){
    QQueue<string> f;
    char r, x[10];
    string a;

    for(unsigned long i=0; i<=strlen(x);i++){
        r=x[i];

        if(r=='A' || r=='a'){
            f.push("1010");
        }
        else if(r=='B' || r=='b'){
            f.push("1011");
        }
        else if(r=='C' || r=='c'){
            f.push("1100");
        }
        else if(r=='D' || r=='d'){
            f.push("1101");
        }
        else if(r=='E' || r=='e'){
            f.push("1110");
        }
        else if(r=='F' || r=='f'){
            f.push("1111");
        }
        else if(r=='1'){
            f.push("0001");
        }
        else if(r=='2'){
            f.push("0010");
        }
        else if(r=='3'){
            f.push("0011");
        }
        else if(r=='4'){
            f.push("0100");
        }
        else if(r=='5'){
            f.push("0101");
        }
        else if(r=='6'){
            f.push("0110");
        }
        else if(r=='7'){
            f.push("0111");
        }
        else if(r=='8'){
            f.push("1000");
        }
        else if(r=='9'){
            f.push("1001");
        }
    }

    while(!f.empty()){
        cout<<f.front();
        f.pop();
    }
}
