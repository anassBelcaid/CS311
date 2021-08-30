#include <QApplication>
/* #include "cursors.h" */ 
/* #include "buttons.h" */
#include "plus_minus.h"


int main( int argc , char * argv[])
{
    QApplication app(argc, argv);

    /* Adding widget */
    PlusMinus window;
    window.setWindowTitle("First Window");
    window.resize(250, 250);
    window.setToolTip("Window for nothing");
    window.setVisible(true);
    
    return app.exec();
}
