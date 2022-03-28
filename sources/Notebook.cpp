#include "Notebook.hpp"
#include <string>
// #include <string>
using namespace std;
using namespace ariel;


// Notebook::Notebook()
// {

// }

const unsigned int len_of_row = 100;

void Notebook::write(int page, int row, int column, Direction d, string const &str)
{
    if (column >= len_of_row)
    {
        throw invalid_argument("column is out of bound");
    }
    if (d == Direction::Horizontal && str.size() > (int)len_of_row - column)
    {
        throw invalid_argument("string is ending out of bound");
    }
    // if (str.size() == 0)
    // {
    //     return;
    // }
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str.at(i)< '!' || str.at(i) >= '~')
        {
            if(str.at(i)!=' ')
            {
                throw invalid_argument("string contains unprintable chars");
            }
        }
        
    }
    if(page<0 || row<0|| column<0)
    {
         throw invalid_argument("invalid argument");
    }
    


    unsigned int upage = (unsigned int)page;
    unsigned int urow = (unsigned int)row;
    unsigned int ucolumn = (unsigned int)column;

    if(upage >= _vect.size())
    {
        _vect.resize(upage+1);
    }
    if(urow >= _vect[upage].size())
    {
        _vect[upage].resize(urow+1);
    }
    // if(_vect[upage][urow] == 0)
    // {
    //     _vect[upage][urow].resize(100);
    //     fill(vect.begin(), vect.end(), '_');
    // }



    if (d ==  Direction::Horizontal)
    {   
        if(_vect[upage][urow].empty())
        {
            _vect[upage][urow].resize(len_of_row);
            for (size_t i = 0; i < len_of_row; i++)
            {
                _vect[upage][urow][i] = '_';
            }  
            
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
            if (_vect[upage][urow][ucolumn+i] != '_')
            {
                throw invalid_argument("fuckkkkkk");
            }
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
            _vect[upage][urow][ucolumn+i] = str.at(i);
        }
    }
    if (d ==  Direction::Vertical)
    {        
        if(_vect[upage].size() <= urow+str.size())
        {
            _vect[upage].resize(urow+str.size()+1);
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
             if(_vect[upage][urow+i].empty())
            {
                _vect[upage][urow+i].resize(len_of_row);
                 for (unsigned int j = 0; j < len_of_row; j++)
                {
                    _vect[upage][urow+i][j] = '_';
                } 
            }
            if (_vect[upage][urow+i][ucolumn] != '_')
            {
                throw invalid_argument("fuckkkkkk22222222222");
            }
        }
        for (unsigned int i = 0; i < str.size(); i++)
        {
             _vect[upage][urow+i][ucolumn] = str.at(i);
        }
    }
} // col<100 and if direction horizontal str.size<100-column

string Notebook::read(int page, int row, int column, Direction d, int num_to_read)
{
    if (column >= len_of_row)
    {
        throw invalid_argument("column is out of bound");
    }
    if (d == Direction::Horizontal && num_to_read > (int)len_of_row - column)
    {
        throw invalid_argument("string is ending out of bound");
    }
    if (num_to_read == 0)
    {
        return "";
    }
    if(page<0 || row<0|| column<0 ||num_to_read<0)
    {
         throw invalid_argument("invalid argument");
    }
    
    unsigned int upage = (unsigned int)page;
    unsigned int urow = (unsigned int)row;
    unsigned int ucolumn = (unsigned int)column;
    unsigned int unum_to_read = (unsigned int)num_to_read;


    if(upage >= _vect.size())
    {
        _vect.resize(upage+1);
    }
    if(urow >= _vect[upage].size())
    {
        _vect[upage].resize(urow+1);
    }
    string ans;
    if (d ==  Direction::Horizontal)
    {   
        if(_vect[upage][urow].empty())
        {
            _vect[upage][urow].resize(len_of_row);
            for (size_t i = 0; i < len_of_row; i++)
            {
                _vect[upage][urow][i] = '_';
            }              
        }
        for (size_t i = 0; i < num_to_read; i++)
        {
            ans += _vect[upage][urow][ucolumn+i];
        }
    }

    if (d ==  Direction::Vertical)
    {        
        if(_vect[upage].size() <= urow+unum_to_read)
        {
            _vect[upage].resize(urow+unum_to_read+1);
        }
        for (unsigned int i = 0; i < unum_to_read; i++)
        {
             if(_vect[upage][urow+i].empty())
            {
                _vect[upage][urow+i].resize(len_of_row);
                 for (unsigned int j = 0; j < len_of_row; j++)
                {
                    _vect[upage][urow+i][j] = '_';
                } 
            }
        }
        for (size_t i = 0; i < num_to_read; i++)
        {
            ans += _vect[upage][urow+i][ucolumn];
        }
    }
    return ans;
}

void Notebook::erase(int page, int row, int column, Direction d, int num_to_erase)
{
    if (column >= len_of_row)
    {
        throw invalid_argument("column is out of bound");
    }
    if (d == Direction::Horizontal && num_to_erase > (int)len_of_row - column)
    {
        throw invalid_argument("string is ending out of bound");
    }
    if (num_to_erase == 0)
    {
        return;
    }
    if(page<0 || row<0|| column<0 ||num_to_erase<0)
    {
         throw invalid_argument("invalid argument");
    }    
    unsigned int upage = (unsigned int)page;
    unsigned int urow = (unsigned int)row;
    unsigned int ucolumn = (unsigned int)column;
    unsigned int unum_to_erase = (unsigned int)num_to_erase;


    if(upage >= _vect.size())
    {
        _vect.resize(upage+1);
    }
    if(urow >= _vect[upage].size())
    {
        _vect[upage].resize(urow+1);
    }
    string ans;
    if (d ==  Direction::Horizontal)
    {   
        if(_vect[upage][urow].empty())
        {
            _vect[upage][urow].resize(len_of_row);
            for (size_t i = 0; i < len_of_row; i++)
            {
                _vect[upage][urow][i] = '_';
            }              
        }
        for (size_t i = 0; i < unum_to_erase; i++)
        {
            _vect[upage][urow][ucolumn+i] = '~';
        }
    }

    if (d ==  Direction::Vertical)
    {        
        if(_vect[upage].size() <= urow+unum_to_erase)
        {
            _vect[upage].resize(urow+unum_to_erase+1);
        }
        for (unsigned int i = 0; i < unum_to_erase; i++)
        {
             if(_vect[upage][urow+i].empty())
            {
                _vect[upage][urow+i].resize(len_of_row);
                 for (unsigned int j = 0; j < len_of_row; j++)
                {
                    _vect[upage][urow+i][j] = '_';
                } 
            }
        }
        for (size_t i = 0; i < unum_to_erase; i++)
        {
            _vect[upage][urow+i][ucolumn] = '~';
        }
    }
}

void Notebook::show(int page_num)
{
    if(page_num<0)
    {
        throw invalid_argument("should be positive");
    }
    unsigned int upage_num = (unsigned int) page_num;
    for (size_t i = 0; i < _vect[upage_num].size(); i++)
    {
        for (size_t j = 0; j < _vect[upage_num][i].size(); j++)
        {
            cout << _vect[upage_num][i][j] << " ";
        }
        if(_vect[upage_num][i].size()==len_of_row){
            cout << "\n";   
        }        
    }
}