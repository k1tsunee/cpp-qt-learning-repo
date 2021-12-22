#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<qglobal.h>
#include<QTIme>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->randomizeButton, SIGNAL(clicked()), this, SLOT(randomNumbersClick()));
    connect(ui->newWindowButton, SIGNAL(clicked()), this, SLOT(newWindowClick()));

    QTime time = QTime::currentTime();
    qsrand(time.msec());
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::randomNumbersClick(){
    int luckyNumbersVector[6];

    for(int i = 0; i < 6; i++){
        luckyNumbersVector[i] = (qrand() % 60) + 1;
    }

    QString luckyNumbersString("%0 %1 %2 %3 %4 %5");
    for(int i = 0; i < 6; i++){
        luckyNumbersString = luckyNumbersString.arg(luckyNumbersVector[i], 2, 10, QLatin1Char('0'));
    }

    ui->numbersGeneratedLabel->setText(luckyNumbersString);
}

void MainWindow::newWindowClick(){
    MainWindow *newWindow = new MainWindow;
    newWindow->show();
}

void MainWindow::closeEvent(QCloseEvent *ev){
    qApp->exit();
}