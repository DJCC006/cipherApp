#include "mainventana.h"
#include "ui_mainventana.h"
#include "initialwindow.h"
#include "principalpanel.h"
#include "frmaccion.h"
#include "frmcryptvigerne.h"
#include "frmcryptxor.h"

mainventana::mainventana(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainventana), mModule(module)
{
    ui->setupUi(this);
}

mainventana::~mainventana()
{
    delete ui;
}

void mainventana::on_cesarBtt_clicked()
{
    auto w = new principalPanel(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_logoffBtt_clicked()
{
    auto w= new frmaccion(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_xorbtt_clicked()
{
    auto w = new frmcryptXOR(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void mainventana::on_vigenerebtt_clicked()
{
    auto w = new frmcryptvigerne(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

