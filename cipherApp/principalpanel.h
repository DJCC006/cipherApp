#ifndef PRINCIPALPANEL_H
#define PRINCIPALPANEL_H

#include <QDialog>
#include "cipherModule.h"

namespace Ui {
class principalPanel;
}

class principalPanel : public QDialog
{
    Q_OBJECT

public:
    explicit principalPanel(cipherModule* module, QWidget *parent = nullptr);
    ~principalPanel();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::principalPanel *ui;
    cipherModule* mModule;
};

#endif // PRINCIPALPANEL_H
