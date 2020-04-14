#include "history.h"
#include <fstream>
#include <iostream>


int History::load() {

    std::string line;
    std::ifstream file(this->m_filename);

    if ( file.is_open())
    {
        while ( getline(file, line))
        {
            std::cout << line << '\n';
            m_stringList << QString::fromStdString(line);
        }
        file.close();
        return 0;
    }
    {
        perror("Could not open file for history completion.");
        return -1;
    }
}

int History::write() {
    m_stringList.removeDuplicates();
    std::ofstream file(this->m_filename, std::ios::out);
    if ( !m_stringList.empty())
    {
        if ( file.is_open())
        {
            for ( const auto& line : m_stringList )
            {
                file << line.toStdString() << "\n";
            }
        }
        else
        {
            perror("Could not open file for history completion.");
            return -1;
        }
        file.close();
        return 0;
    }
    file.close();
    return -1;
}

const QStringList& History::stringList() const {

    return m_stringList;
}

int History::addToStringlist(const QString& element) {

    m_stringList << element;
    return 0;
}

History::History() {
}
