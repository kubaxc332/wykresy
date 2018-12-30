#include "logowanie.h"
#include "mainwindow.h"
#include "ui_logowanie.h"
#include <QMessageBox>
#include <QPixmap>
logowanie::logowanie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logowanie)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/login.jpg");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

logowanie::~logowanie()
{
    delete ui;
}

void logowanie::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username ==  "user" && password == "chart") {
        QMessageBox::information(this, "Login", "Wprowadzono prawidłowy login i haslo!");
        MainWindow mainwindow;
        mainwindow.setModal(true);
        mainwindow.exec();
        mainwindow = new mainwindow(this);
    }
    else {
        QMessageBox::warning(this,"Login", "Wprowadzono  nieprawidłowy login lub hasło");
    }
}
