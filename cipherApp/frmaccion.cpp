#include "frmaccion.h"
#include "ui_frmaccion.h"
#include "mainventana.h"
#include "frmchoosedesc.h"


frmaccion::frmaccion(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmaccion), mModule(module)
{
    ui->setupUi(this);
}

frmaccion::~frmaccion()
{
    delete ui;
}

void frmaccion::on_pushButton_clicked()
{
    auto w= new mainventana(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmaccion::on_pushButton_2_clicked()
{
    auto w= new frmChooseDesc(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmaccion::on_pushButton_3_clicked()
{
    auto w= new initialWindow(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

