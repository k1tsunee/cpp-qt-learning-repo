#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->memes->setText("Bruhvster!");
    ui->disabledButton->setDisabled(true);

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->bruhButton, SIGNAL(clicked()), this, SLOT(bruhButtonClick()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *ev){
    //ev->ignore();
    ev->accept();
}

void MainWindow::bruhButtonClick(){
    QString msg = ui->bruh->text();

    std::cout << msg.toStdString() << std::endl;

    QString m("%0 abcdefg %1");

    m = m.arg(10).arg(msg);

    std::cout << m.toStdString() << std::endl;
}
