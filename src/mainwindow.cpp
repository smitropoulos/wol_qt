#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wol.h"
#include <iostream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->comboBox->setEditable(true);
    ui->comboBox->setDuplicatesEnabled(false);
    ui->label->setWordWrap(true);


    std::stringstream ss;
    ss << "/home/"<<getenv("USER")<<"/.wol_qt.dat";
    historyHandler = History(ss.str());

    historyHandler.load();
    if (!historyHandler.stringList().empty())
    {
    ui->comboBox->addItems(historyHandler.stringList());
    }

}

MainWindow::~MainWindow()
{
    historyHandler.write();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    handleWol();
}

int MainWindow::handleWol() {

    auto inputText = ui->comboBox->currentText();
    if (inputText.trimmed().size() != 17)
    {
        ui->label->setText("Wrong size. Paste your MAC address including colons. (expected 12 characters)");
        return -1;
    }
    ui->comboBox->addItem(inputText);
    historyHandler.addToStringlist(inputText);
    QByteArray ba = inputText.toLocal8Bit();
    char* inputTextArr = ba.data();
    int res = send(inputTextArr);
    if (!res){
        ui->label->setText("Packet Sent!");
    }
    else {
        ui->label->setText("There has been a problem!");

    }

    return res;
}
