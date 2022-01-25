#include "analizador_lexico.h"
#include "ui_analizador_lexico.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <stack>
#include <cstdlib>

using namespace std;

Analizador_lexico::Analizador_lexico(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Analizador_lexico)
{
    ui->setupUi(this);
    QStringList r;
    r<<"Lexema"<<"Simbolo"<<"Tipo";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setHorizontalHeaderLabels(r);
    ui->tableWidget->verticalHeader()->setVisible(false);
}

Analizador_lexico::~Analizador_lexico()
{
    delete ui;
}


void Analizador_lexico::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    int estado=0;
    text+='$';
    QString lexema,simbolo,tipo;
    auxvec=0;

    for(int i=0;i<text.size();i++)
    {

        if(estado==0)
        {
            if(text[i]==' ')
            {
                i++;
            }

            if(text[i].isLetter()) //Identificar character para pasar a estado 1
            {

                estado=1;
                simbolo="identificador";
                tipo='0';


            }
            if(text[i].isDigit()) //Identificar digito para pasar a estado 2
            {
                estado=2;
                simbolo="entero";
                tipo='1';
            }
            if(text[i]=='+' or text[i]=='-')//Identificar opSuma
            {
                lexema+=text[i];
                simbolo="opSuma";
                tipo='5';
                estado=27;
            }
            if(text[i]=='*' or text[i]=='/')//Identificar opMul
            {
                lexema+=text[i];
                simbolo="opMul";
                tipo='6';
                estado=27;
            }
            if(text[i]=='<') //Identificar opRelac parte 1 estado 3
            {

                simbolo="opRelac";
                tipo='7';
                estado=3;
            }
            if(text[i]=='>') //Identificar opRelac parte 2 estado 4
            {

                simbolo="opRelac";
                tipo='7';
                estado=4;
            }
            if(text[i]=='|') //Identificar opOr estado 5
            {

                simbolo="opOr";
                tipo='8';
                estado=5;
            }
            if(text[i]=='&') //Identificar opAnd estado 6
            {

                simbolo="opAnd";
                tipo='9';
                estado=6;
            }
            if(text[i]=='=') // identificar tipo 10 o opIgualdad parte 1
            {
                lexema+=text[i];
                simbolo='=';
                tipo="18";
                i++;
                if(text[i]=='=')
                {
                    lexema+=text[i];
                    simbolo="opIgualdad";
                    tipo="11";
                    estado=27;
                }else{
                    i--;
                    estado=27;
                }

            }
            if(text[i]=='!')//Identificar opNot o opIgualdad parte 2
            {
                lexema+=text[i];
                simbolo="opNot";
                tipo="10";
                i++;
                if(text[i]=='=')
                {
                    lexema+=text[i];
                    simbolo="opIgualdad";
                    tipo="11";
                    estado=27;
                }else{
                    i--;
                    estado=27;
                }

            }
            if(text[i]==';')
            {
                lexema+=text[i];
                simbolo=';';
                tipo="12";
                estado=27;
            }
            if(text[i]==',')
            {
                lexema+=text[i];
                simbolo=',';
                tipo="13";
                estado=27;
            }
            if(text[i]=='(')
            {
                lexema+=text[i];
                simbolo='(';
                tipo="14";
                estado=27;
            }
            if(text[i]==')')
            {
                lexema+=text[i];
                simbolo=')';
                tipo="15";
                estado=27;
            }
            if(text[i]=='{')
            {
                lexema+=text[i];
                simbolo='{';
                tipo="16";
                estado=27;
            }
            if(text[i]=='}')
            {
                lexema+=text[i];
                simbolo='}';
                tipo="17";
                estado=27;
            }



            if(text[i]=='$') //Identificar Final de datos
            {

                lexema+=text[i];
                simbolo='$';
                tipo="23";
                estado=27;
            }

        }

        if(estado==1) // estado de cadenas
        {
            if(text[i].isLetter() or text[i].isDigit() or text[i]=='_')
            {
                lexema+=text[i];

            }else{
                if(lexema=="int" or lexema=="float" or lexema=="void")
                {
                    simbolo="tipo";
                    tipo='4';
                }
                if(lexema=="if")
                {
                    simbolo="if";
                    tipo="19";
                }
                if(lexema=="while")
                {
                    simbolo="while";
                    tipo="20";
                }
                if(lexema=="return")
                {
                    simbolo="return";
                    tipo="21";
                }
                if(lexema=="else")
                {
                    simbolo="else";
                    tipo="22";

                }
                i--;
                estado=27;



            }

        }
        if(estado==2) // estado de entero y real
        {
            if(text[i].isDigit())
            {
                lexema+=text[i];
            }else{
                if(text[i]=='.')
                {
                    lexema+=text[i];
                    simbolo="real";
                    tipo='2';

                }else{
                    i--;
                    estado=27;
                }


            }

        }
        if(estado==3) //estado de oprealc parte 1
        {
            if(text[i]=='<')
            {
                lexema+=text[i];


            }else{
                if(text[i]=='=')
                {
                    lexema+=text[i];
                    estado=27;

                }else{
                    i--;
                    estado=27;
                }
            }
        }
        if(estado==4)  //estado de oprealc parte 2
        {
            if(text[i]=='>')
            {
                lexema+=text[i];


            }else{
                if(text[i]=='=')
                {
                    lexema+=text[i];
                    estado=27;

                }else{
                    i--;
                    estado=27;
                }
            }
        }
        if(estado==5) //estado de opOr
        {
            if(text[i]=='|')
            {
                lexema+=text[i];
            }else{
                i--;
                estado=27;
            }
        }
        if(estado==6) //estado de opAnd
        {
            if(text[i]=='&')
            {
                lexema+=text[i];
            }else{
                i--;
                estado=27;
            }
        }

        if(estado==27)
        {
            vec[auxvec][0]=lexema;
            vec[auxvec][1]=simbolo;
            vec[auxvec][2]=tipo;

            ui->tableWidget->setItem(auxvec,0,new QTableWidgetItem(lexema));
            ui->tableWidget->setItem(auxvec,1,new QTableWidgetItem(simbolo));
            ui->tableWidget->setItem(auxvec,2,new QTableWidgetItem(tipo));
            auxvec+=1;
            lexema="";
            simbolo="error";
            tipo="";

            estado=0;


        }



    }
}

