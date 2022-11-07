#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression exp("^\\+\\d{11}$");
    connect(ui->lineEdit, &QLineEdit::textEdited, [this, &exp](QString currentText){
        if (exp.match(currentText).hasMatch()) {
            setOkLabel();
        } else {
            setNonOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Fail");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

