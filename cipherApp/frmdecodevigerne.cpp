#include "frmdecodevigerne.h"
#include "ui_frmdecodevigerne.h"
#include "frmchoosedesc.h"

frmdecodevigerne::frmdecodevigerne(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodevigerne)
{
    ui->setupUi(this);
}

frmdecodevigerne::~frmdecodevigerne()
{
    delete ui;
}

void frmdecodevigerne::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc();
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

