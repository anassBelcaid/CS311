#include <QTextStream>

int main(int argc, char *argv[])
{
    //Creating the main application
    QTextStream out(stdout);


    //complicated string
    QString message{ "token1 token2, token3 token4, token5 token6"};


    //spliting the message using the default space splitter
    for(auto token : message.split(QChar(' ')))
        out << token << "  ";
    out << endl;


    //spliting by a custom separator
    for(auto token : message.split(QChar(',')))
        out << token << "  ";
    out << endl;
}
