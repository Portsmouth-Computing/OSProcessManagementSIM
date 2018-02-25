#include "TablePrinter.h"

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
        m_columns.data.clear();
    }
}

void TablePrinter::print()
{
    std::vector<size_t> widths;
    for (auto& column : m_columns) {
        widths.push_back(column.getMaxDataWidth());
    }
   
}
