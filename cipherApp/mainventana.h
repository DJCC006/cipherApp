#ifndef MAINVENTANA_H
#define MAINVENTANA_H

#include <QDialog>
#include "initialwindow.h"
#include "cipherModule.h"

namespace Ui {
class mainventana;
}

class mainventana : public QDialog
{
    Q_OBJECT

public:
    explicit mainventana(cipherModule* module, QWidget *parent = nullptr);
    ~mainventana();

private slots:
    void on_cesarBtt_clicked();

    void on_logoffBtt_clicked();

    void on_xorbtt_clicked();

    void on_vigenerebtt_clicked();

private:
    Ui::mainventana *ui;
    cipherModule* mModule;

};

#endif // MAINVENTANA_H
