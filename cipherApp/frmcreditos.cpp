#include "frmcreditos.h"
#include "ui_frmcreditos.h"
#include "initialwindow.h"
frmcreditos::frmcreditos(cipherModule* miModule, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcreditos), mModule(miModule)
{
    ui->setupUi(this);
}

frmcreditos::~frmcreditos()
{
    delete ui;
}

void frmcreditos::on_salirBtt_clicked()
{
    auto w= new initialWindow(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}

