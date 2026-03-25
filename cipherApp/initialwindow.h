#ifndef INITIALWINDOW_H
#define INITIALWINDOW_H

#include <QDialog>
//#include "mainventana.h"
#include "cipherModule.h"

namespace Ui {
class initialWindow;
}

class initialWindow : public QDialog
{
    Q_OBJECT

public:
    explicit initialWindow(cipherModule* module, QWidget *parent = nullptr);
    ~initialWindow();

private slots:
    void on_signInbtt_clicked();

    void on_salirBtt_clicked();

private:
    Ui::initialWindow *ui;
   // mainventana *primeraVentana;
    cipherModule* mModule;

};

#endif // INITIALWINDOW_H
