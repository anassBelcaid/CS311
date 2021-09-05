#include <QTextStream>

int main(int argc, char *argv[])
{

    //QTestStream to print string (plays the role of cout)
    QTextStream out(stdout);

    //initiating a Qt String using uniform initializer
    QString simple { "random" };

    //printing the string
    out << simple << endl;


    //adding at the end
    simple.append(" Walk!");

    //adding at the beginning
    simple.prepend("The use of ");
    out << simple << endl;


    //converting to lower and uppper
    out << simple.toLower() << endl;
    out << simple.toUpper() << endl;

}
