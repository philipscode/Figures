#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include "drawing.h"
#include "regularpolygon.h"
#include "circle.h"
#include "adddialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateListWidget();

private slots:
    void on_drawButton_clicked();

    void circleRecieved(Circle*);

    void regularPolygonReceived(RegularPolygon*);

    void on_eraseTopButton_clicked();

    void on_clearButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    Drawing *drawing;
    AddDialog *addDialog;
};

#endif // MAINWINDOW_H
