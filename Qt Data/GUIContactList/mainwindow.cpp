#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<map>
#include<QMessageBox>
#include<QInputDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addContactButton()));
    connect(ui->inputName, SIGNAL(textChanged(QString)), this, SLOT(checkIfContactValid(QString)));
    connect(ui->inputPhone, SIGNAL(textChanged(QString)), this, SLOT(checkIfContactValid(QString)));
    connect(ui->contactListWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(showPhoneNumber(QModelIndex)));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeContactButton()));
    connect(ui->cleanSearchButton, SIGNAL(clicked()), this, SLOT(cleanSearchButton()));
    connect(ui->actionSearch, SIGNAL(triggered()), this, SLOT(searchButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addContactButton(){
    contactList[ui->inputName->text()] = ui->inputPhone->text();

    ui->inputName->clear();
    ui->inputPhone->clear();

    listContacts("");
}

void MainWindow::checkIfContactValid(QString){
    if(ui->inputName->text().count() > 0 && ui->inputPhone->text().count() > 0){
        ui->addButton->setEnabled(true);
    } else{
        ui->addButton->setEnabled(false);
    }
}

void MainWindow::removeContactButton(){
    if(ui->contactListWidget->currentItem()){
       contactList.erase(ui->contactListWidget->currentItem()->text());
       listContacts("");
    }
}

void MainWindow::cleanSearchButton(){
    listContacts("");
}

void MainWindow::searchButton(){
    QString filter = QInputDialog::getText(this, "Search", "Type a name:"); 

    listContacts(filter);
}

void MainWindow::showPhoneNumber(QModelIndex modelIndex){
    QString name = ui->contactListWidget->item(modelIndex.row())->text();
    QString message("Name: %0\n\nPhone Number: %1");
    message = message.arg(name).arg(contactList[name]);

    QMessageBox::information(this, "Contact Details...", message);
}

void MainWindow::listContacts(QString filter){
    ui->contactListWidget->clear();

    map<QString, QString>::reverse_iterator it = contactList.rbegin();

    for(;it != contactList.rend(); ++it){
        QString name = it->first;
        QString phoneNumber = it->second;

        if(name.contains(filter)){
            ui->contactListWidget->insertItem(-1, name);
        }

    }
}
