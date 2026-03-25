#include "frmcryptxor.h"
#include "ui_frmcryptxor.h"
#include "mainventana.h"

frmcryptXOR::frmcryptXOR(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcryptXOR), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
    ui->boxKey->setEnabled(false);
}

frmcryptXOR::~frmcryptXOR()
{
    delete ui;
}

void frmcryptXOR::on_pushButton_4_clicked()
{
    auto w = new mainventana(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();

}


void frmcryptXOR::on_pushButton_3_clicked()
{
    //Estraemos el texto del box
    QString extractoTexto= ui->boxPlano->toPlainText();

    string strTexto = extractoTexto.toStdString();

    string txtBinario = mModule->convertirABinario(strTexto);
    string keyXOR= mModule->generarKeyBinario(txtBinario);

    string codificado = mModule->convertirXOR(txtBinario, keyXOR);

    //preparamos para colocar en panel
    QString qCodificado = QString::fromStdString(codificado);
    QString qKey = QString::fromStdString(keyXOR);
    //ponemos en panel de informacion
    ui->boxEncriptado->setPlainText(qCodificado);
    ui->boxKey->setPlainText(qKey);
}

