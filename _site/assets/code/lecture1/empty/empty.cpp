#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    //Creating the main application
    QApplication app(argc, argv);

    //Creating a simple widget
    QWidget window;
    window.resize(400, 500);
    window.setWindowTitle("Empty application");
    window.show();
    
    // Entering the infinite loop
    return app.exec();
}
