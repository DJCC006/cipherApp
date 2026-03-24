#ifndef FRMCRYPTVIGERNE_H
#define FRMCRYPTVIGERNE_H

#include <QDialog>

namespace Ui {
class frmcryptvigerne;
}

class frmcryptvigerne : public QDialog
{
    Q_OBJECT

public:
    explicit frmcryptvigerne(QWidget *parent = nullptr);
    ~frmcryptvigerne();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::frmcryptvigerne *ui;
};

#endif // FRMCRYPTVIGERNE_H
