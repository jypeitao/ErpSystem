#include <QtGui/QApplication>
#include "mainwindow.h"
#include "logindialog.h"
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <iostream>
bool createConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("erp_system");
    db.setUserName("root");
    db.setPassword("peter");
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
        return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnect())
    {
        return 1;
    }
    MainWindow w;
    LoginDialog loginDlg;
    QDesktopWidget *desk=QApplication::desktop();

    QSqlQuery query;
    query.exec("select * from material");
    while(query.next())
    {
        QString title = query.value(2).toString();
        std::cout<<title.toUtf8().constData()<<std::endl;
        //std::cerr<<qPrintabel(title)<<std::endl;
    }
    if(loginDlg.exec() == QDialog::Accepted)
    {
        w.move((desk->width() - w.width())/2,
                   (desk->height() - w.height())/2);
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
