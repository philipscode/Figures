#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Draw on Top");
    ui->figureNameLineEdit->setDisabled(true);
    ui->edgeNumberLineEdit->setDisabled(true);
    ui->edgeLengthLineEdit->setDisabled(true);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_circleRadioButton_clicked()
{
    ui->figureNameLineEdit->setDisabled(true);
    ui->figureNameLineEdit->clear();
    ui->edgeNumberLineEdit->setDisabled(true);
    ui->edgeNumberLineEdit->clear();
    ui->edgeLengthLineEdit->setDisabled(true);
    ui->edgeLengthLineEdit->clear();
    ui->radiusLineEdit->setDisabled(false);
}

void AddDialog::on_regularPolygonRadioButton_clicked()
{
    ui->figureNameLineEdit->setDisabled(false);
    ui->edgeNumberLineEdit->setDisabled(false);
    ui->edgeLengthLineEdit->setDisabled(false);
    ui->radiusLineEdit->setDisabled(true);
    ui->radiusLineEdit->clear();
}

void AddDialog::on_submitButton_clicked()
{
    double transparency = ui->transparencyLineEdit
            ->text().toDouble();
    if (ui->circleRadioButton->isChecked()) {
        if (transparency > 1 || transparency < 0)
            transparency = 1;
        int radius = ui->radiusLineEdit
                ->text().toInt();
        if (radius <= 0)
            radius = 1;
        Circle *circle = new Circle(transparency, radius);
        emit circleEntered(circle);
    } else {
        string figureName = ui->figureNameLineEdit
                ->text().toStdString();
        int edgeNumber = ui->edgeNumberLineEdit
                ->text().toInt();
        if (edgeNumber <= 0) {
            edgeNumber = 1;
            figureName = "line";
        }
        int edgeLength = ui->edgeLengthLineEdit
                ->text().toInt();
        if (edgeLength <= 0)
            edgeLength = 1;
        RegularPolygon *regularPolygon =
                new RegularPolygon(figureName, transparency,
                                   edgeNumber, edgeLength);
        emit regularPolygonEntered(regularPolygon);
    }
    this->close();
}
