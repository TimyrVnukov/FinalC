#include "dialogaddmedicine.h"
#include "ui_dialogaddmedicine.h"
#include <QMessageBox>

DialogAddMedicine::DialogAddMedicine(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddMedicine)
{
    ui->setupUi(this);
    query = new QSqlQuery(db);
}

DialogAddMedicine::~DialogAddMedicine()
{
    delete ui;
}

void DialogAddMedicine::on_pushButton_clicked()
{
    query->prepare("INSERT INTO medicine(title, dateManufacture,term, price, country)"
    " VALUES (:title, :dateManufacture,:term, :price, :country)");



    query->bindValue(":title", ui->lineEdit->text());
    query->bindValue(":dateManufacture", ui->dateEdit->date().toString("yyyy-MM-dd"));
    query->bindValue(":term", ui->spinBox->value());
    query->bindValue(":price", ui->spinBox_2->value());
    query->bindValue(":country", ui->lineEdit_2->text());
    query->exec();



    QMessageBox::about(this, "Add", "Add Medicine");
    this->close();
}

