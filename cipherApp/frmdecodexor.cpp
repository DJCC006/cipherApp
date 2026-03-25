#include "frmdecodexor.h"
#include "ui_frmdecodexor.h"
#include "frmchoosedesc.h"

//librerias para manejo de archivos
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>




frmdecodexor::frmdecodexor(cipherModule* module, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::frmdecodexor), mModule(module)
{
    ui->setupUi(this);
    ui->boxEncriptado->setEnabled(false);

}

frmdecodexor::~frmdecodexor()
{
    delete ui;
}

void frmdecodexor::on_pushButton_4_clicked()
{
    auto w = new frmChooseDesc(mModule);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    close();
}


void frmdecodexor::on_pushButton_5_clicked()
{
    //valores que se consideran vacios
    QString empty1="";
    QString empty2=" ";


    //se abre el cuadro de dialogo
    QString nameArchivo = QFileDialog::getOpenFileName(this,
                                                       "Abrir archivo texto",
                                                       QDir::homePath(),
                                                       "Archivos de Texto (*.txt);; Todos los archivos (*)");


    //verificar en caso que se haya cancelado el proceso
    if(nameArchivo.isEmpty()){
        return;
    }



    //ahora se usa el READONLY para poder leer el contenido del archivo
    QFile archivo(nameArchivo);
    if(archivo.open(QIODevice::ReadOnly| QIODevice::Text)){
        //se setea para que ahora se una entrada de informacion del archivo
        QTextStream in(&archivo);

        QString contenido = in.readAll();

        //verificacion no mas para ver el archivo no traia nada
        if(contenido==empty1 || contenido==empty2){
            QMessageBox::critical(this, "AVISO", "El archivo no contiene informacion");
        }else{
            ui->boxPlano->setPlainText(contenido);
            QMessageBox::information(this, "Exito", "El archivo se ha cargado exitosamente");
        }

    }else{
        QMessageBox::critical(this, "Error", "No se pudo cargar el archivo");
    }
}

