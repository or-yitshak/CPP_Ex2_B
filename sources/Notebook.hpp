#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    class Notebook
    {
    private:
        unsigned int _num_of_pages = 10;
        unsigned int _num_of_lines = 10;
        const unsigned int _len_of_line = 100;
        vector<vector<vector<char>>> _vect;


    public:
        // Notebook(){
        // vector<Page> pages(_num_of_pages);
        // _pages = pages;
        // }

        Notebook(){
        vector<vector<vector<char>>> vect(_num_of_pages, vector<vector<char>>(_num_of_lines, vector<char>(_len_of_line,'_')));
        _vect = vect;
        }

        void write(int page, int row, int column, Direction d, string const &str); // col<100 and if direction horizontal str.size<100-column

        string read(int page, int row, int column, Direction d, int num_to_read);

        void erase(int page, int row, int column, Direction d, int num_to_erase);

        void show(int page_num);
    };
};