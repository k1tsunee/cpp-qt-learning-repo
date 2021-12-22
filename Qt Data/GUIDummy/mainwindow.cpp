#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    QMessageBox::information(this, "Test", "This is a test!");
    int inputNumber = QInputDialog::getInt(this, "Input Test", "This is an input test!", 0, 0, 255);
    QString selectedFile = QFileDialog::getSaveFileName(this, "This is a file select test.");
}

MainWindow::~MainWindow(){
    delete ui;
}
