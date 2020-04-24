//
// Created by smitropoulos on 21/04/2020.
//

#ifndef _ARPWORKER_H_
#define _ARPWORKER_H_

#include <vector>


struct tableElement {
    std::string m_ipAddress{};
    std::string m_hwAddress{};
    std::string m_interface{};
    static constexpr int numberOfmembers{3};
};

class ArpWorker {
  private:
    std::vector<tableElement> m_table;
    void tokenizeAndFill(const std::string& inputToTokenize);
  public:
    const std::vector<tableElement>& table() const;
    int scan(bool startOver);
    void emptyElementTable();
};

#endif //_ARPWORKER_H_
