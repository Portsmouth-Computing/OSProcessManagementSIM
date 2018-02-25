#pragma once

#include <vector>
#include <algorithm>

class TablePrinter
{
    struct Column
    {
        Column(const std::string& title)
            : title(title)
        { }

        size_t getMaxDataWidth()
        {
            size_t max = 0;
            for (auto& data : str) {
                max = std::max(str.size(), max);
            }
            return std::max(max, title.size());
        }

        const std::string title;
        std::vector<std::string> data;
    };
    public:
        TablePrinter(const std::vector<std::string>& columnNames);

        void addRow (const std::vector<std::string>& row);
        void clear  ();
        void print  ();


    private:
        std::vector<Column> m_columns;
        std::string m_outputBuffer;
};