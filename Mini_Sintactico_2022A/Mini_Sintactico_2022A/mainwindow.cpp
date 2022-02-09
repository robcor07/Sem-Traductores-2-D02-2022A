#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    r<<"Lexema"<<"Simbolo"<<"Tipo";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setHorizontalHeaderLabels(r);
    ui->tableWidget->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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


void MainWindow::on_pushButton_2_clicked()
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
    resource[0][0]="identificador";
    resource[0][1]="0";
    resource[1][0]="opSuma";
    resource[1][1]="1";
    resource[2][0]="$";
    resource[2][1]="2";
    resource[3][0]="E";
    resource[3][1]="3";

    stack<QString> mistack;
    QString auxz="0",aux1;
    mistack.push(auxz);
    int fila,columna;
    QString accion;
    int flag1=0;

    int contx=0;

    while(contx < auxvec) //Inicio del analisis sintactico
    {
        aux1=mistack.top(); // obtener valor de fila del top de la pila

        if(aux1[0].isDigit())
        {
            int n=aux1.toInt();
            fila=n;
        }
        if(aux1[0].isLetter())
        {
            QString aux;
            for(int i=0;i<4;i++)
            {
                aux=resource[i][0];
                if(aux==aux1)
                {
                   fila=resource[i][1].toInt();
                }

            }
        }
        for (int i=0;i<4;i++ ) // obtener columna de vector
        {
            QString aux;

            aux=resource[i][0];
            if(aux==vec[contx][1])
            {
               columna=resource[i][1].toInt();
            }

         }
        cout<<"Fila "<<fila<< "Columna"<< columna<<endl;
        accion=tabla1[fila][columna]; //obtener accion de tabla
        cout<<"Accion: "<<accion.toStdString()<<endl;

        if(accion[0].isDigit() && accion[0]!='0')// identificar desplazamiento
        {
            mistack.push(vec[contx][1]);
            mistack.push(accion);
            cout<<"Agregando "<<vec[contx][1].toStdString()<<" y "<<accion.toStdString()<<endl;
            contx++;
        }

        if(accion[0]=='-') //identificar reglas
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
                QString aux11=mistack.top();
                mistack.push("E");
                QString aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                mistack.push(accion=tabla1[aux11.toInt()][3]);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;
            }
            if(accion=="-1")// identificar final
            {
                QMessageBox msgBox;
                msgBox.setText("Correcto");
                msgBox.exec();
                break;
            }
        }
        if(accion=='0')// identificar error
        {
            QMessageBox msgBox;
            msgBox.setText("Error");
            msgBox.exec();
            break;
        }


    }//while
}


void MainWindow::on_pushButton_3_clicked()
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
    resource[0][0]="identificador";
    resource[0][1]="0";
    resource[1][0]="opSuma";
    resource[1][1]="1";
    resource[2][0]="$";
    resource[2][1]="2";
    resource[3][0]="E";
    resource[3][1]="3";

    stack<QString> mistack;
    QString auxz="0",aux1;
    mistack.push(auxz);
    int fila,columna;
    QString accion;
    int flag1=0;

    int contx=0;

    while(contx<auxvec)
    {
        cout<<"Inicio"<<endl;
        aux1=mistack.top();

        if(aux1[0].isDigit())
        {
            int n=aux1.toInt();
            fila=n;
        }
        if(aux1[0].isLetter())
        {
            QString aux;
            for(int i=0;i<4;i++)
            {
                aux=resource[i][0];
                if(aux==aux1)
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

        if(accion[0].isDigit() && accion[0]!='0')
        {
            mistack.push(vec[contx][1]);
            mistack.push(accion);
            cout<<"Agregando "<<vec[contx][1].toStdString()<<" y "<<accion.toStdString()<<endl;

            contx++;

        }
        if(accion[0]=='-')
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
                QString aux11=mistack.top();
                mistack.push("E");
                QString aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                mistack.push(accion=tabla1[aux11.toInt()][3]);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;

            }
            if(accion=="-3")
            {
                mistack.pop();
                mistack.pop();

                cout<<"2 pops"<<endl;
                QString aux11=mistack.top();
                mistack.push("E");
                QString aux12=mistack.top();
                cout<<"Agregando E"<<endl;
                mistack.push(accion=tabla1[aux11.toInt()][3]);
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

    }//while


}

