#include "principalpanel.h"
#include "ui_principalpanel.h"
#include "mainventana.h"
#include <QString>
#include <QDebug>
//#include <windows.h>

#include <iostream>
using namespace std;


principalPanel::principalPanel(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::principalPanel), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);

}

principalPanel::~principalPanel()
{
    delete ui;
}

void principalPanel::on_pushButton_4_clicked()
{
    auto w = new mainventana(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void principalPanel::on_pushButton_3_clicked()
{
    //Estraemos el texto del box
    QString extractoTexto= ui->boxPlano->toPlainText();

    string strTexto = extractoTexto.toStdString();

    //obtenemos el valor de desplazamiento
    int desplazamiento = ui->spinBox->value();

    string codificado = mModule->cifradoCesar(strTexto, desplazamiento);

    qDebug() << "Texto codificado: "<< codificado;

    //preparamos para colocar en panel
    QString qCodificado = QString::fromStdString(codificado);

    //ponemos en panel de informacion
    ui->boxEncriptado->setPlainText(qCodificado);


}
