#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    operation="";
    ui->setupUi(this);
    connect(ui->btn0, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn1, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn2, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn3, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn4, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn5, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn6, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn7, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn8, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn9, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btnC, SIGNAL(clicked()),this,SLOT(clearResult()));
    connect(ui->btnPlus, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->btnMinus, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->btnMult, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->btnDiv, SIGNAL(clicked()),this,SLOT(checkOperation()));
    connect(ui->btnResult, SIGNAL(clicked()),this,SLOT(getResult()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigit(){
    QPushButton* btn = (QPushButton*)sender();
    if (ui->labelResult->text()=="0"){
        if(btn->text()!=0){
            ui->labelResult->setText("");
        }
    }
    QString field = ui->labelResult->text()+btn->text();
    ui->labelResult->setText(field);
}
void MainWindow::clearResult(){
    ui->labelResult->setText("0");
    operation="";
}
void MainWindow::checkOperation(){
    QPushButton* btn = (QPushButton*)sender();
    operation=btn->text();
    prev=ui->labelResult->text();
    ui->labelResult->setText("0");
}

void MainWindow::getResult(){
    float num1 = prev.toFloat();
    float num2 = ui->labelResult->text().toFloat();
    float result;
    switch((char)(operation[0].toLatin1())){
    case '+':
        result=num1+num2;
        break;
    case '-':
        result=num1-num2;
        break;
    case '*':
        result=num1*num2;
        break;
    case '/':
        result=num1/num2;
        break;
    }
    ui->labelResult->setNum(result);
}


