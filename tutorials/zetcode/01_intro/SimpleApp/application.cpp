#include <QApplication>
#include <QWidget>


int main(int argc, char *argv[])
{
    //Creating the window
    QApplication app(argc, argv);


    //adding some widgets
    QWidget window;
    window.resize(250, 150);
    window.setWindowTitle("Simple application");


    window.show();



    return app.exec();


}

