#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QDialog>
//#include "mainventana.h"


namespace Ui {
class initialWindow;
}

class initialWindow : public QDialog
{
    Q_OBJECT

public:
    explicit initialWindow(QWidget *parent = nullptr);
    ~initialWindow();

private slots:
    void on_signInbtt_clicked();

    void on_salirBtt_clicked();

private:
    Ui::initialWindow *ui;
   // mainventana *primeraVentana;

};

#endif // INITIALWINDOW_H
