#ifndef FRMDECODECESAR_H
#define FRMDECODECESAR_H

#include <QDialog>
#include "cipherModule.h"
namespace Ui {
class frmdecodecesar;
}

class frmdecodecesar : public QDialog
{
    Q_OBJECT

public:
    explicit frmdecodecesar(cipherModule* module, QWidget *parent = nullptr);
    ~frmdecodecesar();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmdecodecesar *ui;
    cipherModule* mModule;
};

#endif // FRMDECODECESAR_H
