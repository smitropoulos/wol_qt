#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <utility>
#include <list>
#include <QStringList>

class History
{
  private:
    std::string m_filename{};
    QStringList m_stringList;
  public:
    History();
    explicit History(std::string filename):m_filename(std::move(filename)){}
    int load();
    int write();

    const QStringList& stringList() const;
    int addToStringlist(const QString& element);
};

#endif // HISTORY_H
