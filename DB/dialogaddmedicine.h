#ifndef DIALOGADDMEDICINE_H
#define DIALOGADDMEDICINE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class DialogAddMedicine;
}

class DialogAddMedicine : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddMedicine(QSqlDatabase db, QWidget *parent = nullptr);
    ~DialogAddMedicine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogAddMedicine *ui;
    QSqlQuery* query;
};

#endif // DIALOGADDMEDICINE_H
