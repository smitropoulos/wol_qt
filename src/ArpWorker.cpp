//
// Created by smitropoulos on 21/04/2020.
//

#include <array>
#include <memory>
#include <iostream>
#include "ArpWorker.h"
#include <sstream>


int ArpWorker::scan(bool startOver) {

    if ( startOver )
    {
        emptyElementTable();
    }

    const char *cmd = R"(arp |awk '{if(NR>1)print}' | awk -F " " '{print $1 "~" $3"~"$NF}' | tr '\n' ';')";
    std::array<char, 64> buffer{};
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if ( !pipe )
    {
        throw std::runtime_error("popen() failed!");
    }
    while ( fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr )
    {
        result += buffer.data();
    }
    if ( result.empty())
    {
        return -1;
    }
    tokenizeAndFill(result);
    return 0;
}

void ArpWorker::tokenizeAndFill(const std::string& inputToTokenize) {

    // Vector of string to save tokens
    std::vector<std::string> tokens;

    std::stringstream check1(inputToTokenize);

    std::string intermediate;

    // Tokenizing w.r.t. colon ';'
    while ( getline(check1, intermediate, ';'))
    {
        tokens.push_back(intermediate);
    }

    // Printing the token vector
    for ( auto const& token :tokens )
    {
        std::vector<std::string> innerTokens;
        std::stringstream ss(token);

        while ( getline(ss, intermediate, '~'))
        {
            innerTokens.push_back(intermediate);
        }
        if ( intermediate.size() == 1 )  //Handle the new line in the end.
        {
            return;
        }
        m_table.push_back(tableElement{innerTokens[0], innerTokens[1], innerTokens[2]});
        innerTokens.clear();
    }
}

const std::vector<tableElement>& ArpWorker::table() const {

    return m_table;
}

void ArpWorker::emptyElementTable() {

    m_table.clear();
}
