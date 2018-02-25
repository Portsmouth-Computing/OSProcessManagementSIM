#include "TablePrinter.h"

#include <sstream>
#include <iomanip>
#include <iostream>

TablePrinter::TablePrinter(const std::vector<std::string>& columnNames)
{ 
    for (auto& column : columnNames) {
        m_columns.emplace_back(column);
    }
}

void TablePrinter::addRow(const std::vector<std::string>& row)
{
    if (row.size() != m_columns.size()) {
        return;
    }

    m_rows++;
    for (int i = 0; i < m_columns.size(); i++)
    {
        m_columns.at(i).addData(row.at(i));
    }
}

void TablePrinter::clear()
{
    m_rows = 0;
    for (auto& column : m_columns)  {
        column.clear();
    }
}

void TablePrinter::print()
{
    std::ostringstream out;
    for (auto& column : m_columns) {
        out << std::setw(column.getWidth()) << column.getTitle();
    }
    out << "\n";


    auto buffer = out.str();
    std::cout << buffer << "\n\n";
}
