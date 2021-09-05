#include <QTextStream>
#include <QList>
#include <QList>
#include <algorithm>

int main(int argc, char *argv[])
{
    //out stream
    QTextStream out(stdout);

    //Creating doubly linked list
    QList<int> nums{4, 1, 3, 12, 20, 5};

    //printing the list
    out << "before sorting : ";
    for(auto value:nums)
        out << value << " ";
    out << endl;


    //linear search
    out << "Index of 3 is " << nums.indexOf(3) << endl;


    //We could work with nums as an STL container
    std::sort(nums.begin(), nums.end());


    out << "After sorting : ";
    for(auto value:nums)
        out << value << " ";
    out << endl;


    //Binary search  for 4
    auto value = 4;
    auto it = std::lower_bound(nums.begin(), nums.end(), value);
    out << "The value " << value << " is in index : " << std::distance(nums.begin(), it) << endl;
    


}
