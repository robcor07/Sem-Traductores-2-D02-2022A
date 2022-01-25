/********************************************************************************
** Form generated from reading UI file 'analizador_lexico.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALIZADOR_LEXICO_H
#define UI_ANALIZADOR_LEXICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Analizador_lexico
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Analizador_lexico)
    {
        if (Analizador_lexico->objectName().isEmpty())
            Analizador_lexico->setObjectName(QString::fromUtf8("Analizador_lexico"));
        Analizador_lexico->resize(800, 600);
        centralwidget = new QWidget(Analizador_lexico);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 20, 501, 171));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(200, 300, 321, 241));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 230, 141, 51));
        Analizador_lexico->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Analizador_lexico);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Analizador_lexico->setMenuBar(menubar);
        statusbar = new QStatusBar(Analizador_lexico);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Analizador_lexico->setStatusBar(statusbar);

        retranslateUi(Analizador_lexico);

        QMetaObject::connectSlotsByName(Analizador_lexico);
    } // setupUi

    void retranslateUi(QMainWindow *Analizador_lexico)
    {
        Analizador_lexico->setWindowTitle(QCoreApplication::translate("Analizador_lexico", "Analizador_lexico", nullptr));
        pushButton->setText(QCoreApplication::translate("Analizador_lexico", "Analizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Analizador_lexico: public Ui_Analizador_lexico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALIZADOR_LEXICO_H
