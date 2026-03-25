#include "frmcryptxor.h"
#include "ui_frmcryptxor.h"
#include "mainventana.h"

//Librerias encargadas de guardar las cosas en archivos de una manera mucho mas elegante y personalizada
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



frmcryptXOR::frmcryptXOR(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmcryptXOR), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);
    //ui->boxKey->setEnabled(false);
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


void frmcryptXOR::on_pushButton_5_clicked()
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

