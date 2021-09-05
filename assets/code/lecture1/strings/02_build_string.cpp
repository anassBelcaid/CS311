#include <QTextStream>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);      // stream to print information


    //Creating the template
    QString message{ "User %1 tried to log %2 times" };


    //printing information with user (EUMF, 43)
    out << message.arg("EUMF").arg(43) << endl;


    // other instance
    out << message.arg("EIDIA").arg(12) << endl;
    

}
