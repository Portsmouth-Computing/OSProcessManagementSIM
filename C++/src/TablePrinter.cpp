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


TablePrinter::Column::Column(const std::string& title)
    : m_title(title)
{
    m_maxSize = title.length();
}

size_t TablePrinter::Column::getWidth()
{
    return m_maxSize + 3;
}

void TablePrinter::Column::clear()
{
    m_maxSize = m_title.length();
    m_data.clear();
}

void TablePrinter::Column::addData(const std::string& newData)
{
    m_data.push_back(newData);
    m_maxSize = std::max(m_maxSize, newData.length());
}

const std::string& TablePrinter::Column::getTitle()
{
    return m_title;
}