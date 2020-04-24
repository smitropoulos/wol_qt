#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wol.h"
#include <iostream>
#include <sstream>
#include <QThread>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    std::stringstream ss;
    ss << "/home/" << getenv("USER") << "/.wol_qt.dat";
    m_historyHandler = new History(ss.str());

    m_historyHandler->load();
    if ( !m_historyHandler->stringList().empty())
    {
        ui->comboBox->addItems(m_historyHandler->stringList());
    }
}

MainWindow::~MainWindow() {

    m_historyHandler->write();
    delete m_historyHandler;
    delete ui;
}

void MainWindow::on_sendWol_clicked() {

    handleWol();
}

int MainWindow::handleWol() {

    auto inputText = ui->comboBox->currentText();
    if ( inputText.trimmed().size() != 17 )
    {
        ui->label->setText("Wrong size. Paste your MAC address including colons. (expected 12 characters)");
        return -1;
    }
    ui->comboBox->addItem(inputText);
    m_historyHandler->addToStringlist(inputText);
    QByteArray ba = inputText.toLocal8Bit();
    char *inputTextArr = ba.data();
    int res = sendWolPacket(inputTextArr);
    if ( !res )
    {
        ui->label->setText("Packet Sent!");
    }
    else
    {
        ui->label->setText("There has been a problem!");
    }

    return res;
}

void MainWindow::on_tabWidget_tabBarClicked(int index) {

    if ( index == 1 )       //If the second tab is pressed
    {
        if ( !m_tableDataLoaded )
        {
            ui->arpTable->fillTable(false);
            m_tableDataLoaded = true;
        }
    }
}

void MainWindow::on_arpTable_itemSelectionChanged() {

    ui->arpTable->generateList();
}

void MainWindow::on_sendPackets_clicked() {

    if ( ui->arpTable->macList().empty())
    {
        return;
    }

    for ( const auto& mac : ui->arpTable->macList())
    {
        QByteArray ba = mac.toLocal8Bit();
        char *inputTextArr = ba.data();
        int res = sendWolPacket(inputTextArr);
        if ( !res )
        {
            ui->label->setText("Packet Sent!");
        }
        else
        {
            ui->label->setText("There has been a problem!");
        }
    }

    ui->sendPackets->updateOnSuccess("Success!");
}

void MainWindow::on_rescan_clicked() {

    ui->sendPackets->restoreOriginalText();
    ui->arpTable->fillTable(true);
}

void MainWindow::on_tabWidget_currentChanged(int index) {

    ui->sendPackets->restoreOriginalText();
}
