#include "frmcryptxor.h"
#include "ui_frmcryptxor.h"
#include "mainventana.h"

frmcryptXOR::frmcryptXOR(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcryptXOR)
{
    ui->setupUi(this);
}

frmcryptXOR::~frmcryptXOR()
{
    delete ui;
}

void frmcryptXOR::on_pushButton_4_clicked()
{
    auto w = new mainventana();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();

}

