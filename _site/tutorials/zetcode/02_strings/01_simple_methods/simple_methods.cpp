#include <QTextStream>
#include <iostream>
#include <vector>


using entry = std::pair<QString, int>


int main()
{
    //Initialiasing a strea on stdout
    QTextStream out(stdout);

    QString temp("Welcome %1 This your %2 th login");

    vector<entry> values {{"Hafsa", 2},{"Khadija", 10}, {"Rim", 20}};




    out << temp.arg("Class").arg(4).mid(4, 5) << '\n';






    
    return 0;

}
