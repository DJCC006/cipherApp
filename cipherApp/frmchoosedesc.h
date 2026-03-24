#ifndef FRMCHOOSEDESC_H
#define FRMCHOOSEDESC_H

#include <QDialog>

namespace Ui {
class frmChooseDesc;
}

class frmChooseDesc : public QDialog
{
    Q_OBJECT

public:
    explicit frmChooseDesc(QWidget *parent = nullptr);
    ~frmChooseDesc();

private slots:
    void on_logoffBtt_clicked();

    void on_xorbtt_clicked();

    void on_vigenerebtt_clicked();

    void on_cesarBtt_clicked();

private:
    Ui::frmChooseDesc *ui;
};

#endif // FRMCHOOSEDESC_H
