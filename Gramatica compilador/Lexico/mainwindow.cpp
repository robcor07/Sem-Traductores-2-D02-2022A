#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <stack>
#include <cstdlib>

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

void MainWindow::creaTabla()
{
    // Inicia lectura de archivo
    QFile archivo;
      QTextStream stream;
      QString nombreArchivo;
      nombreArchivo="compilador.lr";
      if(nombreArchivo.isEmpty())
        return;
      archivo.setFileName(nombreArchivo);
      archivo.open(QIODevice::ReadOnly|QIODevice::Text);
      if(!archivo.isOpen())
        {
          QMessageBox::critical(this,"Error",archivo.errorString());
          return;
        }
      stream.setDevice(&archivo);
      QString alt=(stream.readAll());
      archivo.close(); // Finaliza lectura de archivo
      QStringList plist;
      QString auxlist;
      int estado=0;


      int list=0;// Inicia eliminacion de espacios y carga a lista
      for (int r=0;r<alt.size() ;r++ ) {
          if(estado==0)
          {
           if(alt[r]=='-')
           {
               estado=1;
           }
           if(alt[r].isDigit())
           {
               estado=2;
           }
          }

          if(estado==1)
          {
              if(alt[r]=='\t' or alt[r]=='\n')
              {
                  estado=4;
              }else{
                  auxlist+=alt[r];
              }
          }
          if(estado==2)
          {
              if(alt[r]=='\t' or alt[r]=='\n')
              {
                  estado=4;
              }else{
                  auxlist+=alt[r];
              }
          }
          if(estado==4)
          {
              plist.append(auxlist);
              auxlist="";
              estado=0;
          }

      }

      for(int i=0; i<95; i++) // se carga la tabla usando lista
          for(int j=0; j<46; j++)
          {

            table[i][j]=plist[list];

            if(list<(plist.size())-1)
            {
                list++;
            }



          }
      /*QMessageBox msgBox;
      msgBox.setText(table[92][0]);
      msgBox.exec();*/
}

void MainWindow::creaTabla2()
{
    table2[0]="identificador";
    table2[1]="entero";
    table2[2]="real";
    table2[3]="cadena";
    table2[4]="tipo";
    table2[5]="opSuma";
    table2[6]="opMul";
    table2[7]="opRelac";
    table2[8]="opOr";
    table2[9]="opAnd";
    table2[10]="opNot";
    table2[11]="opIgualdad";
    table2[12]=";";
    table2[13]=",";
    table2[14]="(";
    table2[15]=")";
    table2[16]="{";
    table2[17]="}";
    table2[18]="=";
    table2[19]="if";
    table2[20]="while";
    table2[21]="return";
    table2[22]="else";
    table2[23]="$";
    table2[24]="programa";
    table2[25]="Definiciones";
    table2[26]="Definicion";
    table2[27]="DefVar";
    table2[28]="ListaVar";
    table2[29]="DefFunc";
    table2[30]="Parametros";
    table2[31]="ListaParam";
    table2[32]="BloqFunc";
    table2[33]="DefLocales";
    table2[34]="DefLocal";
    table2[35]="Sentencias";
    table2[36]="Sentencia";
    table2[37]="Otro";
    table2[38]="Bloque";
    table2[39]="ValorRegresa";
    table2[40]="Argumentos";
    table2[41]="ListaArgumentos";
    table2[42]="Termino";
    table2[43]="LlamadaFunc";
    table2[44]="SentenciaBloque";
    table2[45]="Expresion";



}

void MainWindow::creaRules()
{
    rules[0][0]="1";
    rules[0][1]="programa";
    rules[1][0]="0";
    rules[1][1]="Definiciones";
    rules[2][0]="2";
    rules[2][1]="Definiciones";
    rules[3][0]="1";
    rules[3][1]="Definicion";
    rules[4][0]="1";
    rules[4][1]="Definicion";
    rules[5][0]="4";
    rules[5][1]="DefVar";
    rules[6][0]="0";
    rules[6][1]="ListaVar";
    rules[7][0]="3";
    rules[7][1]="ListaVar";
    rules[8][0]="6";
    rules[8][1]="DefFunc";
    rules[9][0]="0";
    rules[9][1]="Parametros";
    rules[10][0]="3";
    rules[10][1]="Parametros";
    rules[11][0]="0";
    rules[11][1]="ListaParam";
    rules[12][0]="4";
    rules[12][1]="ListaParam";
    rules[13][0]="3";
    rules[13][1]="BloqFunc";
    rules[14][0]="0";
    rules[14][1]="DefLocales";
    rules[15][0]="2";
    rules[15][1]="DefLocales";
    rules[16][0]="1";
    rules[16][1]="DefLocal";
    rules[17][0]="1";
    rules[17][1]="DefLocal";
    rules[18][0]="0";
    rules[18][1]="Sentencias";
    rules[19][0]="2";
    rules[19][1]="Sentencias";
    rules[20][0]="4";
    rules[20][1]="Sentencia";
    rules[21][0]="6";
    rules[21][1]="Sentencia";
    rules[22][0]="5";
    rules[22][1]="Sentencia";
    rules[23][0]="3";
    rules[23][1]="Sentencia";
    rules[24][0]="2";
    rules[24][1]="Sentencia";
    rules[25][0]="0";
    rules[25][1]="Otro";
    rules[26][0]="2";
    rules[26][1]="Otro";
    rules[27][0]="3";
    rules[27][1]="Bloque";
    rules[28][0]="0";
    rules[28][1]="ValorRegresa";
    rules[29][0]="1";
    rules[29][1]="ValorRegresa";
    rules[30][0]="0";
    rules[30][1]="Argumentos";
    rules[31][0]="2";
    rules[31][1]="Argumentos";
    rules[32][0]="0";
    rules[32][1]="ListaArgumentos";
    rules[33][0]="3";
    rules[33][1]="ListaArgumentos";
    rules[34][0]="1";
    rules[34][1]="Termino";
    rules[35][0]="1";
    rules[35][1]="Termino";
    rules[36][0]="1";
    rules[36][1]="Termino";
    rules[37][0]="1";
    rules[37][1]="Termino";
    rules[38][0]="1";
    rules[38][1]="Termino";
    rules[39][0]="4";
    rules[39][1]="LlamadaFunc";
    rules[40][0]="1";
    rules[40][1]="SentenciaBloque";
    rules[41][0]="1";
    rules[41][1]="SentenciaBloque";
    rules[42][0]="3";
    rules[42][1]="Expresion";
    rules[43][0]="2";
    rules[43][1]="Expresion";
    rules[44][0]="2";
    rules[44][1]="Expresion";
    rules[45][0]="3";
    rules[45][1]="Expresion";
    rules[46][0]="3";
    rules[46][1]="Expresion";
    rules[47][0]="3";
    rules[47][1]="Expresion";
    rules[48][0]="3";
    rules[48][1]="Expresion";
    rules[49][0]="3";
    rules[49][1]="Expresion";
    rules[50][0]="3";
    rules[50][1]="Expresion";
    rules[51][0]="1";
    rules[51][1]="Expresion";
}


void MainWindow::on_pushButton_clicked()
{
    creaTabla();
    creaTabla2();
    creaRules();
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


    //Comienza analisis sintactico
    cout<<vec[0][1].toStdString()<<endl;
    cout<<vec[1][1].toStdString()<<endl;
    stack<Nodo> mistack;
    QString auxz="0";
    Nodo aux1;
    Estado estado1;
    estado1.lexema=auxz;
    mistack.push(estado1);
    int fila,columna;
    QString accion,thing, raux;
    int thing2, pop;




    int contx=0;

    while(contx<auxvec)
    {
        aux1=mistack.top();
        cout<<aux1.lexema.toInt()<<endl;

        if(aux1.lexema[0].isDigit())
        {
            int n=aux1.lexema.toInt();
            fila=n;
        }
        if(aux1.lexema[0].isLetter())
        {
            QString aux;
            for(int i=0;i<46;i++)
            {
                aux=table2[i];
                if(aux==aux1.lexema)
                {
                   fila=i;
                }

            }
        }
        for (int i=0;i<46;i++ )
        {
            QString aux;

            aux=table2[i];
            if(aux==vec[contx][1])
            {
               columna=i;
            }




         }
        cout<<"Fila "<<fila<< "Columna"<< columna<<endl;
        accion=table[fila][columna];
        cout<<"Accion: "<<accion.toStdString()<<endl;


        if(accion[0].isDigit() && accion[0]!='0')
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
        if(accion[0]=='-')
        {
            if(accion=="-1")
            {
                QMessageBox msgBox;
                msgBox.setText("Correcto");
                msgBox.exec();
                break;
            }
            else{
                if(accion.size()==2)
                {
                    thing+=accion[1];
                    thing2=thing.toInt();
                    thing2=thing2-1;
                    thing="";
                }
                if(accion.size()==3)
                {
                    thing+=accion[1];
                    thing+=accion[2];
                    thing2=thing.toInt();
                    thing2=thing2-1;
                    thing="";
                }
                pop=rules[thing2-1][0].toInt();
                raux=rules[thing2-1][1];

                if(pop==0)
                {
                    cout<<"0 pops"<<endl;
                }else{
                    for (int i=0;i<pop*2 ;i++ ) {
                        mistack.pop();
                        cout<<"Pop"<<endl;
                    }
                }

                Nodo aux11=mistack.top();
                NoTerminal tem;
                tem.lexema=raux;
                mistack.push(tem);
                cout<<"Agregando"<<raux.toStdString()<<endl;
                Estado estado3;
                int h;
                for (int i=0;i<46;i++ )
                {
                    QString aux17;

                    aux17=table2[i];
                    if(aux17==raux)
                    {
                        h=i;
                    }
                 }
                cout<<aux11.lexema.toInt()<<"and   "<<h<<endl;
                estado3.lexema=accion=table[aux11.lexema.toInt()][h];
                mistack.push(estado3);
                cout<<" Transicion Agregando "<<accion.toStdString()<<endl;

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

