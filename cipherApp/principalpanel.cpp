#include "principalpanel.h"
#include "ui_principalpanel.h"
#include "mainventana.h"
#include <QString>
#include <QDebug>
#include <iostream>


//Librerias encargadas de guardar las cosas en archivos de una manera mucho mas elegante y personalizada
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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

void principalPanel::on_saveBtt_clicked()
{
    //valores que se consideran vacios
    QString empty1="";
    QString empty2=" ";

    //hacemos verificacion para no guardar un simple espacio vacio
    if(ui->boxEncriptado->toPlainText()==empty1 || ui->boxEncriptado->toPlainText()==empty2){
        QMessageBox::critical(this, "AVISO", "No se pueden guardar archivos vacios");

    }else{
        //se abre el cuadro de dialogo
        QString nameArchivo = QFileDialog::getSaveFileName(this,
                                                           "Guardar mensaje encriptado",
                                                           QDir::homePath(),
                                                           "Archivos de Texto (*.txt);; Todos los archivos (*)");


        //verificar en caso que se haya cancelado el proceso
        if(nameArchivo.isEmpty()){
            return;
        }



        //proceso para intentar escribir el archivo
        QFile archivo(nameArchivo);
        if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&archivo);
            out<< ui->boxEncriptado->toPlainText();
            archivo.close();


            QMessageBox::information(this, "Exito", "El archivo se ha guardado exitosamente");
        }else{
            QMessageBox::critical(this, "Error", "No se pudo cargar el archivo");
        }
    }


}

