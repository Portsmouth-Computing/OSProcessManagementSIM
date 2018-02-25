#pragma once

#include <vector>

class TablePrinter
{
    struct Column
    {
        Column(const std::string& title)
            : title(title)
        { }

        const std::string title;
        std::vector<std::string> data;
    };
    public:
        TablePrinter(const std::vector<std::string>& columnNames);

        void addRow(const std::vector<std::string>& row);

        void clear();

        void print();

    private:
        std::vector<Column> m_columns;
};