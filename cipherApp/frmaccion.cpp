#include "frmaccion.h"
#include "ui_frmaccion.h"
#include "mainventana.h"
#include "frmchoosedesc.h"
#include "initialwindow.h"

frmaccion::frmaccion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmaccion)
{
    ui->setupUi(this);
}

frmaccion::~frmaccion()
{
    delete ui;
}

void frmaccion::on_pushButton_clicked()
{
    auto w= new mainventana();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmaccion::on_pushButton_2_clicked()
{
    auto w= new frmChooseDesc();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmaccion::on_pushButton_3_clicked()
{
    auto w= new initialWindow();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

