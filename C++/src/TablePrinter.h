#pragma once

#include <vector>
#include <algorithm>

class TablePrinter
{
     class Column
     {
         public:
             Column(const std::string& title);
             size_t getWidth();
             void clear();
             void addData(const std::string& newData);
             const std::string& getTitle();
             const std::string& getDataAt(size_t i);

        private:
             const std::string m_title;
             std::vector<std::string> m_data;
             size_t m_maxSize;
     };

     public:
         TablePrinter(const std::vector<std::string>& columnNames);

         void addRow (const std::vector<std::string>& row);
         void clear  ();
         void print  ();


     private:
         std::vector<Column> m_columns;
         unsigned m_rows;
};