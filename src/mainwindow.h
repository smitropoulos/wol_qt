#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "history.h"
#include "ArpWorker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
  private slots:
    void on_tabWidget_tabBarClicked(int index);
    void on_arpTable_itemSelectionChanged();
    void on_sendPackets_clicked();
    void on_sendWol_clicked();
    void on_rescan_clicked();
    void on_tabWidget_currentChanged(int index);
  private:
    bool m_tableDataLoaded{false};
    History *m_historyHandler;
    int handleWol();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
