#ifndef FRMACCION_H
#define FRMACCION_H

#include <QDialog>
#include "cipherModule.h"
namespace Ui {
class frmaccion;
}

class frmaccion : public QDialog
{
    Q_OBJECT

public:
    explicit frmaccion(cipherModule* module, QWidget *parent = nullptr);
    ~frmaccion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::frmaccion *ui;
    cipherModule* mModule;
};

#endif // FRMACCION_H
