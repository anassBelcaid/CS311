#include <QTextStream>
#include <QVector>
int main(int argc, char *argv[])
{
    //Creating the main application
    QTextStream out(stdout);


    //Creating a vector using uniform initialisation
    QVector<int> nums{1, 2, 3, 4, 5};


    //printing the elements of the vectors
    for(auto value: nums)
        out << value << " ";
    out <<endl;


    //first and last value
    out << "first value : " << nums.first() << " Last value : " << nums.last() << endl; 

    //filling change all the values to 1
    QVector<int> nums2(6);
    nums2.fill(1);

    //appending the nums2 to num1 using operator overloading
    nums += nums2;

    //We can also switch to STL vectors at any time
    auto num3 = nums.toStdVector();

}


