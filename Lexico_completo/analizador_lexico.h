#ifndef ANALIZADOR_LEXICO_H
#define ANALIZADOR_LEXICO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Analizador_lexico; }
QT_END_NAMESPACE

class Analizador_lexico : public QMainWindow
{
    Q_OBJECT

public:
    Analizador_lexico(QWidget *parent = nullptr);
    ~Analizador_lexico();
    QString vec[100][3];
    int auxvec;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Analizador_lexico *ui;
};
#endif // ANALIZADOR_LEXICO_H
