#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <string>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList r;
    r<<"Lexema"<<"Simbolo"<<"Tipo"<<" "<<" "<<" ";

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setHorizontalHeaderLabels(r);
    ui->tableWidget->verticalHeader()->setVisible(false);


}


MainWindow::~MainWindow()
{
    delete ui;
}

class Nodo{
public:
    QString lexema;
};

class Terminal:public Nodo{
public:

};

class NoTerminal:public Nodo{
public:

};

class Estado:public Nodo{
public:

};

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit1->toPlainText();
    int flag=0,estado=0;
    QString lexema,simbolo,tipo;

    auxvec=0;

    for(int i=0;i<=text.length();i++)
    {
        if(flag==1)
        {
         i--;
         flag=0;
        }

        if(estado==0)
        {
            if(text[i]=="\n")//espacios
            {

                i++;
            }
            if(text[i]=="\n")//espacios
            {

                i++;
            }

            if(text[i].isSpace() or text[i]=="\n" or text[i]=="\f" or text[i]=="\r" or text[i]=="\t" or text[i]=="\v")//mas espacios
            {
                i++;

            }

            if(text[i]=="!" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opIgualdad";
                tipo="11";

            }
            if(text[i]=="!")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="opNot";
                tipo="10";

            }
            if(text[i]==">" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opRelac";
                tipo="7";

            }
            if(text[i]=="<" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opRelac";
                tipo="7";

            }
            if(text[i]=="=")
            {
                estado=24;
                lexema+=text[i];
                simbolo="=";
                tipo="18";
                if(text[i+1]=="=")
                {
                    i++;
                    lexema+=text[i];
                    simbolo="opIgualdad";
                    tipo="11";

                }
            }
            if(text[i]=="<" or text[i]==">")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="opRelac";
                tipo="7";
            }
            if(text[i]=="*" or text[i]=="/")
            {
                estado=24;
                lexema+=text[i];
                simbolo="opMul";
                tipo="6";
            }
            if(text[i]=="+" or text[i]=="-")
            {
                estado=24;
                lexema+=text[i];
                simbolo="opSuma";
                tipo="5";
            }
            if(text[i]=="|" and text[i+1]=="|")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opOr";
                tipo="8";
            }
            if(text[i]=="&" and text[i+1]=="&")
            {
                estado=20;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opAnd";
                tipo="9";
            }
            if(text[i]==";")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=";";
                tipo="12";
            }
            if(text[i]==",")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=",";
                tipo="13";
            }
            if(text[i]=="(")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="(";
                tipo="14";
            }
            if(text[i]==")")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=")";
                tipo="15";
            }
            if(text[i]=="{")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="{";
                tipo="16";
            }
            if(text[i]=="}")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="}";
                tipo="17";
            }
            if(text[i]=="$")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="$";
                tipo="23";

            }
            if(text[i].isLetter())
            {
                estado=1;
                lexema+=text[i];
                simbolo="Identificador";
                tipo="0";
                i++;
            }
            if(text[i].isDigit() and text[i+1]==".")
            {
                estado=3;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                i++;
                simbolo="real";
                tipo="2";

            }
            if(text[i].isDigit())
            {
                estado=2;


            }


        }
        if(estado==1)
        {
            while(text[i].isDigit() or text[i].isLetter() or text[i]=="_")
            {



                estado=1;
                lexema+=text[i];
                if(lexema=="if")
                {
                    tipo="19";
                    simbolo="if";

                    break;
                }
                if(lexema=="while")
                {
                    tipo="20";
                    simbolo="while";
                    i++;
                    break;
                }
                if(lexema=="return")
                {
                    tipo="21";
                    simbolo="return";
                    i++;

                    break;
                }
                if(lexema=="else")
                {
                    tipo="22";
                    simbolo="else";
                    i++;

                    break;
                }

                if(lexema=="int" or lexema=="char" or lexema=="float" or lexema=="void" )
                {
                    tipo="4";
                    simbolo="tipo";
                    i++;

                    break;
                }

                simbolo="Identificador";
                tipo="0";
                i++;






            }



                flag=1;
                estado=24;

        }
        if(estado==2)
        {
            while(text[i].isDigit())
            {
                lexema+=text[i];
                simbolo="entero";
                tipo="1";

                i++;
            }
            flag=1;
            estado=24;

        }
        if(estado==3)
        {
            while(text[i].isDigit())
            {
                lexema+=text[i];
                simbolo="real";
                tipo="3";

                i++;
            }
            flag=1;
            estado=24;

        }
        if(estado==24)
        {
            estado=0;

        }
        vec[auxvec][0]=lexema;
        vec[auxvec][1]=simbolo;
        vec[auxvec][2]=tipo;

        ui->tableWidget->setItem(auxvec,0,new QTableWidgetItem(lexema));
        ui->tableWidget->setItem(auxvec,1,new QTableWidgetItem(simbolo));
        ui->tableWidget->setItem(auxvec,2,new QTableWidgetItem(tipo));
        auxvec+=1;
        estado=0;

        lexema="";
        simbolo="error";
        tipo="";



    }

}

void MainWindow::on_Ejercicio1_clicked()
{
    QString tabla1[5][4];
    tabla1[0][0]="2";
    tabla1[0][1]="0";
    tabla1[0][2]="0";
    tabla1[0][3]="1";
    tabla1[1][0]="0";
    tabla1[1][1]="0";
    tabla1[1][2]="-1";
    tabla1[1][3]="0";
    tabla1[2][0]="0";
    tabla1[2][1]="3";
    tabla1[2][2]="0";
    tabla1[2][3]="0";
    tabla1[3][0]="4";
    tabla1[3][1]="0";
    tabla1[3][2]="0";
    tabla1[3][3]="0";
    tabla1[4][0]="0";
    tabla1[4][1]="0";
    tabla1[4][2]="-2";
    tabla1[4][3]="0";

    QString resource[4][2];
    resource[0][0]="Identificador";
    resource[0][1]="0";
    resource[1][0]="opSuma";
    resource[1][1]="1";
    resource[2][0]="$";
    resource[2][1]="2";
    resource[3][0]="E";
    resource[3][1]="3";


    stack<Nodo> mistack;
    QString auxz="0";
    Nodo aux1;
    Estado estado1;
    estado1.lexema=auxz;
    mistack.push(estado1);
    int fila,columna;
    QString accion;
    int flag1=0;

    int contx=0;

    while(contx<auxvec)
    {
        aux1=mistack.top();

        if(aux1.lexema[0].isDigit())
        {
            int n=aux1.lexema.toInt();
            fila=n;
        }
        if(aux1.lexema[0].isLetter())
        {
            QString aux;
            for(int i=0;i<4;i++)
            {
                aux=resource[i][0];
                if(aux==aux1.lexema)
                {
                   fila=resource[i][1].toInt();
                }

            }
        }
        for (int i=0;i<4;i++ )
        {
            QString aux;

            aux=resource[i][0];
            if(aux==vec[contx][1])
            {
               columna=resource[i][1].toInt();
            }




         }
        cout<<"Fila "<<fila<< "Columna"<< columna<<endl;
        accion=tabla1[fila][columna];
        cout<<"Accion: "<<accion.toStdString()<<endl;


        if(accion[0].isDigit() && accion[0]!="0")
        {
            Estado estado2;
            Terminal terminal1;
            terminal1.lexema=vec[contx][1];
            estado2.lexema=accion;
            mistack.push(terminal1);
            mistack.push(estado2);
            cout<<"Agregando "<<vec[contx][1].toStdString()<<" y "<<accion.toStdString()<<endl;
            contx++;


        }
        if(accion[0]=="-")
        {
            if(accion=="-2")
            {
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                cout<<"6 pops"<<endl;
                Nodo aux11=mistack.top();
                NoTerminal tem;
                tem.lexema="E";
                mistack.push(tem);
                Nodo aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                Estado estado3;
                estado3.lexema=accion=tabla1[aux11.lexema.toInt()][3];
                mistack.push(estado3);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;

            }
            if(accion=="-1")
            {
                QMessageBox msgBox;
                msgBox.setText("Correcto");
                msgBox.exec();
                break;
            }

        }
        if(accion=="0")
        {
            QMessageBox msgBox;
            msgBox.setText("Error");
            msgBox.exec();
            break;

        }

    }

}

void MainWindow::on_Ejercicio2_clicked()
{
    QString tabla1[5][4];
    tabla1[0][0]="2";
    tabla1[0][1]="0";
    tabla1[0][2]="0";
    tabla1[0][3]="1";
    tabla1[1][0]="0";
    tabla1[1][1]="0";
    tabla1[1][2]="-1";
    tabla1[1][3]="0";
    tabla1[2][0]="0";
    tabla1[2][1]="3";
    tabla1[2][2]="-3";
    tabla1[2][3]="0";
    tabla1[3][0]="2";
    tabla1[3][1]="0";
    tabla1[3][2]="0";
    tabla1[3][3]="4";
    tabla1[4][0]="0";
    tabla1[4][1]="0";
    tabla1[4][2]="-2";
    tabla1[4][3]="0";

    QString resource[4][2];
    resource[0][0]="Identificador";
    resource[0][1]="0";
    resource[1][0]="opSuma";
    resource[1][1]="1";
    resource[2][0]="$";
    resource[2][1]="2";
    resource[3][0]="E";
    resource[3][1]="3";


    stack<Nodo> mistack;
    QString auxz="0";
    Nodo aux1;
    Estado estado1;
    estado1.lexema=auxz;
    mistack.push(estado1);
    int fila,columna;
    QString accion;
    int flag1=0;

    int contx=0;

    while(contx<auxvec)
    {
        cout<<"Inicio"<<endl;
        aux1=mistack.top();

        if(aux1.lexema[0].isDigit())
        {
            int n=aux1.lexema.toInt();
            fila=n;
        }
        if(aux1.lexema[0].isLetter())
        {
            QString aux;
            for(int i=0;i<4;i++)
            {
                aux=resource[i][0];
                if(aux==aux1.lexema)
                {
                   fila=resource[i][1].toInt();
                }

            }
        }
        for (int i=0;i<4;i++ )
        {
            QString aux;

            aux=resource[i][0];
            if(aux==vec[contx][1])
            {
                cout<<"Found"<<aux.toStdString()<<endl;
               columna=resource[i][1].toInt();
            }




         }
        cout<<"Fila "<<fila<< "Columna"<< columna<<endl;
        accion=tabla1[fila][columna];
        cout<<"Accion: "<<accion.toStdString()<<endl;


        if(accion[0].isDigit() && accion[0]!="0")
        {
            Terminal terminal1;
            Estado estado2;
            terminal1.lexema=vec[contx][1];
            estado2.lexema=accion;
            mistack.push(terminal1);
            mistack.push(estado2);
            cout<<"Agregando "<<vec[contx][1].toStdString()<<" y "<<accion.toStdString()<<endl;

            contx++;

        }
        if(accion[0]=="-")
        {
            if(accion=="-2")
            {
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                mistack.pop();
                cout<<"6 pops"<<endl;
                Nodo aux11=mistack.top();
                NoTerminal tem;
                tem.lexema="E";
                mistack.push(tem);
                Nodo aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                Estado estado3;
                estado3.lexema=accion=tabla1[aux11.lexema.toInt()][3];
                mistack.push(estado3);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;

            }
            if(accion=="-3")
            {
                mistack.pop();
                mistack.pop();

                cout<<"2 pops"<<endl;
                Nodo aux11=mistack.top();
                NoTerminal temp;
                temp.lexema="E";
                mistack.push(temp);
                Nodo aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                Estado estado3;
                estado3.lexema=accion=tabla1[aux11.lexema.toInt()][3];
                mistack.push(estado3);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;

            }
            if(accion=="-1")
            {
                QMessageBox msgBox;
                msgBox.setText("Correcto");
                msgBox.exec();
                break;
            }

        }
        if(accion=="0")
        {
            QMessageBox msgBox;
            msgBox.setText("Error");
            msgBox.exec();
            break;

        }


    }

}
