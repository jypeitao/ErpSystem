#ifndef NEWCUSTOMERDIALOG_H
#define NEWCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class NewCustomerDialog;
}

class NewCustomerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewCustomerDialog(QWidget *parent = 0);
    ~NewCustomerDialog();
    
private slots:
    void on_pb_bcxkh_clicked();

private:
    Ui::NewCustomerDialog *ui;
};

#endif // NEWCUSTOMERDIALOG_H
