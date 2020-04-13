#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wol.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    handleWol();
}

void MainWindow::on_pushButton_clicked()
{
    handleWol();
}

int MainWindow::handleWol() {
    auto inputText = ui->lineEdit->text();
    if (inputText.trimmed().size() != 17)
    {
        ui->label->setText("Wrong size. Paste your MAC address including colons. (expected 12 characters)");
        return -1;
    }
    QByteArray ba = inputText.toLocal8Bit();
    char* inputTextArr = ba.data();
    int res = send(inputTextArr);
    if (!res){
        ui->label->setText("Packet Sent!");
    }
    else {
        ui->label->setText("There has been a problem!");

    }
}
