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

    for(int i=0; i<text.size();i++){
        if(estado==0)
        {
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

        }
        if(estado==1)
        {
            if(text[i].isLetter() or text[i].isDigit() or text[i]=='_')
            {
                lexema+=text[i];

            }else{
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

