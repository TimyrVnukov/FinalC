#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Users.db");

    if(db.open()){
        ui->statusbar->showMessage("Open");
    }
    else {
        ui->statusbar->showMessage("{Error} BD open error!");
    }
    //formMed = new DialogAddMedicine(db, this);

    query = new QSqlQuery();
    query->exec("SELECT * FROM [Users]");
    int i = 0;
    while(query->next()){
        QString name = query->value(0).toString();
        QString points = query->value(2).toString();
        ui->tableWidget->setRowCount(i+1);
        QTableWidgetItem* itemName = new QTableWidgetItem();
        QTableWidgetItem* itemPoints = new QTableWidgetItem();
        itemName->setText(name);
        itemPoints->setText(points);
        ui->tableWidget->setItem(i, 0, itemName);
        ui->tableWidget->setItem(i, 1, itemPoints);
        i++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionMedicine_triggered()
{
    formMed->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();

    if(!inGame){
        query = new QSqlQuery();
        query->exec("SELECT * FROM [Users] where login = \"" + login +"\"");
        query->next();
        if(password == query->value(1).toString()){
            ui->statusbar->showMessage("Login " + login + " password: " + password);
            QDesktopServices::openUrl(QUrl("file:///E:\\!repos\\Exam2.0\\x64\\Release\\[EXEMC++].exe", QUrl::TolerantMode));
            inGame = true;
            ui->pushButton->setText("Close game");
        }
    }
    else {
        query = new QSqlQuery();
        query->exec("SELECT Points FROM [Users] where login = \"" + login + "\"");
        query->next();

        int poinstTmp = query->value(0).toString().split(" ")[0].toInt();

        QFile file("E:\\!repos\\Exam2.0\\exam.txt");
        QByteArray data;
        if (!file.open(QIODevice::ReadOnly))
            return;
        data = file.readAll();
        qDebug() << QString(data);
        poinstTmp += QString(data).split(" ")[0].toInt();

        QSqlQuery query(db);
        query.prepare("UPDATE Users SET Points = '" + QString::number(poinstTmp) +"' WHERE Login = '" + login +"'");
        query.exec();
        ui->pushButton->setText("Play");
        inGame = false;
    }
}
