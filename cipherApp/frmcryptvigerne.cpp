#include "frmcryptvigerne.h"
#include "ui_frmcryptvigerne.h"
#include "mainventana.h"


frmcryptvigerne::frmcryptvigerne(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcryptvigerne)
{
    ui->setupUi(this);
}

frmcryptvigerne::~frmcryptvigerne()
{
    delete ui;
}

void frmcryptvigerne::on_pushButton_4_clicked()
{
    auto w = new mainventana();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

