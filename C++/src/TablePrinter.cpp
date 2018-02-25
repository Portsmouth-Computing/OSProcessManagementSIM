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

void TablePrinter::addRow(const std::vector<std::string>&)
{
}

void TablePrinter::clear()
{
    for (auto& column : m_columns)  {
        column.data.clear();
    }
}

void TablePrinter::print()
{
    std::vector<size_t> widths;
    for (auto& column : m_columns) {
        widths.push_back(column.getMaxDataWidth());
    }

    std::ostringstream out;
    for (size_t i = 0; i < m_columns.size(); i++) {
        out << std::setw(widths.at(i)) << m_columns.at(i).title;
    }
    out << "\n";

    for (size_t i = 0; i < m_columns.size(); i++) {

    }
    auto buffer = out.str();
    std::cout << buffer << "\n\n";
}
