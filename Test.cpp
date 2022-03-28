/**
 * AUTHORS: or yitshak
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

TEST_CASE("Good input")
{
    Notebook notebook;
    CHECK(notebook.read(0, 3, 3, Direction::Horizontal, 5) == "_____");

    notebook.write(0, 3, 4, Direction::Horizontal, "xyz");
    CHECK(notebook.read(0, 3, 3, Direction::Horizontal, 5) == "_xyz_");
    CHECK(notebook.read(0, 2, 4, Direction::Vertical, 3) == "_x_");
    CHECK(notebook.read(0, 2, 5, Direction::Vertical, 3) == "_y_");
    CHECK(notebook.read(0, 2, 6, Direction::Vertical, 3) == "_z_");
    //       123456789
    //    2: _________
    //    3: ___xyz___
    //    4: _________
    //    5: _________
    //    6: _________

    notebook.write(0, 4, 4, Direction::Horizontal, "abc");
    CHECK(notebook.read(0, 4, 3, Direction::Horizontal, 5) == "_abc_");
    CHECK(notebook.read(0, 2, 4, Direction::Vertical, 3) == "_xa");
    CHECK(notebook.read(0, 2, 5, Direction::Vertical, 3) == "_yb");
    CHECK(notebook.read(0, 2, 6, Direction::Vertical, 3) == "_zc");
    //       123456789
    //    2: _________
    //    3: ___xyz___
    //    4: ___abc___
    //    5: _________
    //    6: _________

    notebook.erase(0, 3, 4, Direction::Horizontal, 2);
    CHECK(notebook.read(0, 3, 3, Direction::Horizontal, 5) == "_~~z_");
    CHECK(notebook.read(0, 2, 4, Direction::Vertical, 3) == "_~a");
    CHECK(notebook.read(0, 2, 5, Direction::Vertical, 3) == "_~b");
    CHECK(notebook.read(0, 2, 6, Direction::Vertical, 3) == "_zc");

    //       123456789
    //    2: _________
    //    3: ___~~z___
    //    4: ___abc___
    //    5: _________
    //    6: _________


    notebook.erase(0, 3, 6, Direction::Vertical, 2);
    CHECK(notebook.read(0, 3, 3, Direction::Horizontal, 5) == "_~~~_");
    CHECK(notebook.read(0, 4, 3, Direction::Horizontal, 5) == "_ab~_");
    CHECK(notebook.read(0, 2, 4, Direction::Vertical, 3) == "_~a");
    CHECK(notebook.read(0, 2, 5, Direction::Vertical, 3) == "_~b");
    CHECK(notebook.read(0, 2, 6, Direction::Vertical, 3) == "_~~");

    //       123456789
    //    2: _________
    //    3: ___~~~___
    //    4: ___ab~___
    //    5: _________
    //    6: _________

    notebook.erase(0, 3, 4, Direction::Horizontal, 4);
    CHECK(notebook.read(0, 3, 3, Direction::Horizontal, 5) == "_~~~~");//delete somthing that was already deleted.

   



// input need to be positive? >0?

}

TEST_CASE("Bad input")
{
    Notebook notebook;
    CHECK_THROWS(notebook.write(0, 0, 100, Direction::Vertical, "xyz")); // should throw because the last col is 99.
    CHECK_THROWS(notebook.write(0, 0, 100, Direction::Horizontal, "xyz")); // should throw because the last col is 99.
    CHECK_THROWS(notebook.write(1, 1, 98, Direction::Horizontal, "xyz")); // should throw because "z" will be in the 100 entrance. 
    notebook.write(2, 2, 5, Direction::Horizontal, "xyz");
    CHECK_THROWS(notebook.write(2, 2, 5, Direction::Horizontal, "abc")); // should throw because "xyz" is already written in this place.
    notebook.erase(2, 2, 5, Direction::Horizontal, 3);
    CHECK_THROWS(notebook.write(2, 2, 5, Direction::Horizontal, "abc")); // should throw because "~~~" is already written in this place.

    CHECK_THROWS(notebook.erase(0, 0, 100, Direction::Vertical, 3)); // should throw because the last col is 99.
    CHECK_THROWS(notebook.erase(0, 0, 100, Direction::Horizontal, 3)); // should throw because the last col is 99.
    CHECK_THROWS(notebook.erase(1, 1, 98, Direction::Horizontal, 3)); // should throw because it will try to erase the 100 entrance. 

    CHECK_THROWS(notebook.read(0, 0, 100, Direction::Vertical, 3)); // should throw because the last col is 99.
    CHECK_THROWS(notebook.read(0, 0, 100, Direction::Horizontal, 3)); // should throw because the last col is 99.
    CHECK_THROWS(notebook.read(1, 1, 98, Direction::Horizontal, 3)); // should throw because it will try to read the 100 entrance. 

    // CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "")); // should throw because string.size should be > 0.
    // CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Vertical, 0)); // should throw because number of chras to erase should be > 0.
    // CHECK_THROWS(notebook.read(0, 0, 0, Direction::Vertical, 0)); // should throw because number of chras to read should be > 0.

    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "\t")); // should throw because char is not printable.
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "\n")); // should throw because char is not printable.
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "\r")); // should throw because char is not printable.

    CHECK_THROWS(notebook.write(-1, 0, 0, Direction::Vertical, "xd")); // should throw because number < 0.
    CHECK_THROWS(notebook.read(0, -1, 0, Direction::Vertical, -5)); // should throw because number < 0.
    CHECK_THROWS(notebook.erase(0, 0, -1, Direction::Vertical, -16)); // should throw because number< 0.






}

// TEST_CASE("Random input")
// {
//     int cols = rand() % 100;
//     int rows = rand() % 100;

//     if (cols % 2 == 0 || rows % 2 == 0)
//     {
//     	CHECK_THROWS(mat(cols, rows, '$', '%'));
//     }

//     else
//     {
//     	string str = mat(cols, rows, '$', '%');
//     	CHECK(nospaces(str).size() == cols * rows);

//     	char ch = '\n';
//     	CHECK(count(str.begin(), str.end(), ch) == rows - 1);

//     	char ch1 = '$';
//     	char ch2 = '%';
//     	CHECK(count(str.begin(), str.end(), ch1) >= count(str.begin(), str.end(), ch2));

//     	CHECK(isPalindrom(nospaces(str)) == true);
//     }
// }
