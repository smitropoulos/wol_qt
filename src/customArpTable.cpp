#include "customArpTable.h"
#include <QHeaderView>
#include <QtCore/QDebug>


void customArpTable::fillTable(bool rescan) {

    enum {
        INTERFACE_COLUMN = 0, IP_COLUMN, MAC_COLUMN,
    };

    if ( rescan )
    {
        if ( m_arpWorker->scan(true))
        {
            if ( rowCount())
            {
                this->setRowCount(0);
            }
            return;
        }
    }

    size_t numberOfRows = m_arpWorker->table().size();
    setRowCount(numberOfRows);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for ( int i = 0; i < numberOfRows; i++ )
    {

        auto elm = m_arpWorker->table().at(i);

        auto *ip = new QTableWidgetItem(QString::fromStdString(elm.m_ipAddress));
        ip->setTextAlignment(Qt::AlignCenter);
        auto *mac = new QTableWidgetItem(QString::fromStdString(elm.m_hwAddress));
        mac->setTextAlignment(Qt::AlignCenter);
        auto *interface = new QTableWidgetItem(QString::fromStdString(elm.m_interface));
        interface->setTextAlignment(Qt::AlignCenter);

        setItem(i, INTERFACE_COLUMN, interface);
        setItem(i, IP_COLUMN, ip);
        setItem(i, MAC_COLUMN, mac);
    }
}

void customArpTable::generateList() {

    m_macList.clear();
    QList<QTableWidgetItem *> list = selectedItems();

    for ( const auto item : list )
    {
        auto itemString = item->text();
        QRegularExpressionMatch match = regExp.match(itemString);
        bool hasMatch = match.hasMatch();
        if ( hasMatch )
        {
            m_macList.push_back(itemString);
        }
    }
}

customArpTable::customArpTable(QWidget *parent) : QTableWidget(parent) {

    QString rawRegexp = R"(^("?)([a-zA-Z0-9][a-zA-Z0-9]:)+([a-zA-Z0-9]*)("?)$)";
    regExp.setPattern(rawRegexp);
    m_arpWorker = new ArpWorker;
    m_arpWorker->scan(true);
}

customArpTable::~customArpTable() {

    delete m_arpWorker;
}
