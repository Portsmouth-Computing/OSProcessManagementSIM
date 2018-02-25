#include "TablePrinter.h"

TablePrinter::TablePrinter(const std::vector<std::string>& columnNames)
{ 
    for (auto& column : m_columns)
    {
        m_columns.emplace_back(column);
    }
}
