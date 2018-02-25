#pragma once

#include <vector>
#include <algorithm>

class TablePrinter
{
     class Column
     {
         public:
             Column(const std::string& title)
             : m_title(title)
             { 
                 m_maxSize = title.length();
             }

             size_t getWidth()
             {
                 return m_maxSize + 3;
             }

             void clear()
             {
                 m_maxSize = m_title.length();
                 m_data.clear();
             }
        
             void addData(const std::string& newData)
             {
                 m_data.push_back(newData);
                 m_maxSize = std::max(m_maxSize, newData.length());
             }

             const std::string& getTitle()
             {
                 return m_title;
             }

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