#include "mainventana.h"
#include "ui_mainventana.h"
#include "initialwindow.h"
#include "principalpanel.h"
#include "frmaccion.h"
#include "frmcryptvigerne.h"
#include "frmcryptxor.h"

mainventana::mainventana(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainventana)
{
    ui->setupUi(this);
}

mainventana::~mainventana()
{
    delete ui;
}

void mainventana::on_cesarBtt_clicked()
{
    auto w = new principalPanel();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_logoffBtt_clicked()
{
    auto w= new frmaccion();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_xorbtt_clicked()
{
    auto w = new frmcryptXOR();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_vigenerebtt_clicked()
{
    auto w = new frmcryptvigerne();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

