#ifndef CUSTOMARPTABLE_H
#define CUSTOMARPTABLE_H

#include <QTableWidget>
#include "ArpWorker.h"


class customArpTable : public QTableWidget {
  Q_OBJECT
  private:
    QStringList m_macList;
    QRegularExpression regExp;
  public:
    explicit customArpTable(QWidget *parent);
    void generateList();
    ArpWorker *m_arpWorker{};
    void fillTable(bool rescan);
    ~customArpTable() override;

    inline const QStringList& macList() const { return m_macList; }
};

#endif // CUSTOMARPTABLE_H

