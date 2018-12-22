#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "circle.h"
#include "regularpolygon.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();
signals:
    void circleEntered(Circle*);

    void regularPolygonEntered(RegularPolygon*);

private slots:
    void on_circleRadioButton_clicked();

    void on_regularPolygonRadioButton_clicked();

    void on_submitButton_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
