#include "frmcryptvigerne.h"
#include "ui_frmcryptvigerne.h"
#include "mainventana.h"
#include "cipherModule.h"
#include <QString>



frmcryptvigerne::frmcryptvigerne(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcryptvigerne), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
    ui->boxKey->setEnabled(false);
}

frmcryptvigerne::~frmcryptvigerne()
{
    delete ui;
}

void frmcryptvigerne::on_pushButton_4_clicked()
{

    auto w = new mainventana(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmcryptvigerne::on_pushButton_3_clicked()
{
    //Estraemos el texto del box
    QString extractoTexto= ui->boxPlano->toPlainText();

    string strTexto = extractoTexto.toStdString();

    string keyVigerne= mModule->genKeyVigerne(strTexto);

    string codificado = mModule->convertirVigerne(strTexto, keyVigerne);

    //preparamos para colocar en panel
    QString qCodificado = QString::fromStdString(codificado);
    QString qKey = QString::fromStdString(keyVigerne);
    //ponemos en panel de informacion
    ui->boxEncriptado->setPlainText(qCodificado);
    ui->boxKey->setPlainText(qKey);
}

