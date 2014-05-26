#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class MaterialDialog;
}

class MaterialDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MaterialDialog(QWidget *parent = 0);
    ~MaterialDialog();

private:
    void createTableMode();
    
private:
    Ui::MaterialDialog *ui;
    QSqlTableModel * model;
private slots:
   //void showAll();
   //void query(); //图书信息查询
   //void setEnable(); //输入框可用性设定
    void dataChanged(const QModelIndex &lt, const QModelIndex &rb);
    void on_ph_cx_clicked();
    void on_bcxg_clicked();
    void on_cxxg_clicked();
};

#endif // MATERIALDIALOG_H
