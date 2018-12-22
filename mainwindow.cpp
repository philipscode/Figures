#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Drawing");
    drawing = new Drawing();
    addDialog = new AddDialog();
    connect(addDialog, SIGNAL(circleEntered(Circle*)),
            this, SLOT(circleRecieved(Circle*)));
    connect(addDialog, SIGNAL(regularPolygonEntered(RegularPolygon*)),
            this, SLOT(regularPolygonReceived(RegularPolygon*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawButton_clicked()
{
    addDialog->exec();
}

void MainWindow::updateListWidget()
{
    ui->listWidget->clear();
    for (Drawing::iterator it = drawing->begin();
         it != drawing->end(); it++) {
        if ((*it)->id() == 1) {
            Circle *circle = dynamic_cast<Circle*>(*it);
            ui->listWidget->addItem(
                        QString::fromStdString(circle->getName()) +
                        " -- transparency: " +
                        QString::number(circle->getTransparency()) +
                        " -- radius: " +
                        QString::number(circle->getRadiusLength()));
        } else {
            RegularPolygon *regularPolygon =
                    dynamic_cast<RegularPolygon*>(*it);
            ui->listWidget->addItem(
                        QString::fromStdString(regularPolygon
                                               ->getName()) +
                        " -- transparency: " +
                        QString::number(
                            regularPolygon->getTransparency()) +
                        " -- Edge Number: " +
                        QString::number(
                            regularPolygon->getNumberOfEdges()) +
                        QString::number(
                            regularPolygon->getEdgeLength()));
        }
    }
}

void MainWindow::circleRecieved(Circle *circle)
{
    drawing->push(circle);
    this->updateListWidget();
}

void MainWindow::regularPolygonReceived(RegularPolygon
                                        *regularPolygon)
{
    drawing->push(regularPolygon);
    this->updateListWidget();
}

void MainWindow::on_eraseTopButton_clicked()
{
    drawing->pop();
    this->updateListWidget();
}

void MainWindow::on_clearButton_clicked()
{
    drawing->removeAll();
    this->updateListWidget();
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::
            getSaveFileName(this, tr("Save Drawing"),
                            QDir::homePath(),
                            tr("Text Files (*.txt)"));
    std::ofstream ofile(fileName.toStdString());
    ofile << *drawing;
    ofile.close();
}
