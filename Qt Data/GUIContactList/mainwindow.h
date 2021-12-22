#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<map>
#include<QMainWindow>
#include<QCloseEvent>
#include<QModelIndex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addContactButton();
    void removeContactButton();
    void cleanSearchButton();
    void searchButton();
    void checkIfContactValid(QString);
    void showPhoneNumber(QModelIndex);

private:
    Ui::MainWindow *ui;
    std::map<QString, QString> contactList;

protected:
    void listContacts(QString);
};

#endif // MAINWINDOW_H
