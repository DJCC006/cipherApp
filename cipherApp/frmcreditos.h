#ifndef FRMCREDITOS_H
#define FRMCREDITOS_H

#include <QDialog>
#include "cipherModule.h"
namespace Ui {
class frmcreditos;
}

class frmcreditos : public QDialog
{
    Q_OBJECT

public:
    explicit frmcreditos(cipherModule* miModule, QWidget *parent = nullptr);
    ~frmcreditos();

private slots:
    void on_salirBtt_clicked();

private:
    Ui::frmcreditos *ui;
    cipherModule* mModule;
};

#endif // FRMCREDITOS_H
