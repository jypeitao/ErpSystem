#include "newcustomerdialog.h"
#include "ui_newcustomerdialog.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>

NewCustomerDialog::NewCustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCustomerDialog)
{
    ui->setupUi(this);
}

NewCustomerDialog::~NewCustomerDialog()
{
    delete ui;
}

void NewCustomerDialog::on_pb_bcxkh_clicked()
{
    QSqlQuery query;
    QString sql = "insert into customer (plate_number,engine_number,chassis_number,vehicle_type,mileage,owner,owner_phone) values ("
            "'"+ui->le_dph->text() + "',"
            "'"+ui->le_fdjh->text() + "',"
            "'"+ui->le_cph->text() + "',"
            "'"+ui->le_cllx->text() + "',"
            "'"+ui->le_yxlc->text() + "',"
            "'"+ui->le_czxm->text() + "',"
            "'"+ui->le_czdh->text()+"')";
    std::cout<<sql.toUtf8().data()<<std::endl;
    if(query.exec(sql))
    {
        std::cout<<"OK"<<std::endl;

        QMessageBox::information(this, QObject::tr("提示信息"),QObject::tr("保存成功"), QObject::tr("确定"));
        close();

    }else
    {
       std::cout<< "error :"<<query.lastError().text().data() <<std::endl;

       QMessageBox::warning(this, tr("提示信息"),tr("保存失败 数据库错误: %1").arg(query.lastError().text()),QObject::tr("确定"));
       close();

    }

   // query.prepare("insert into customer (plate_number,engine_number,chassis_number,vehicle_type,mileage,owner,owner_phone) "
   //               "values (:pn,:en,:cn,:vt,:m,:o,:op");
   // query.bindValue(":pn",ui->le_dph->text());
   // query.bindValue(":en",ui->le_fdjh->text());
   // query.bindValue(":cn",ui->le_cph->text());
   // query.bindValue(":vt",ui->le_cllx->text());
   // query.bindValue(":m",ui->le_yxlc->text());
   // query.bindValue(":o",ui->le_czxm->text());
   // query.bindValue(":op",ui->le_czdh->text());
   // query.exec();


}
