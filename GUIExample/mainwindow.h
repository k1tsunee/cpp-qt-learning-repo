#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void randomNumbersClick();
    void newWindowClick();

private:
    Ui::MainWindow *ui;

protected:
    void closeEvent(QCloseEvent *ev);
};

#endif // MAINWINDOW_H
