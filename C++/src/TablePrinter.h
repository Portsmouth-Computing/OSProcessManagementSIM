#pragma once

#include <vector>

class TablePrinter
{
    struct Column
    {
        Column(std::string name)
            :   name (name) {}

        std::string name;
        std::vector<std::string> data;
    };
    public:
        TablePrinter(const std::vector<std::string>& columnNames);

    private:
        std::vector<Column> m_columns;
};