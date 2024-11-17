#include "trimspaces.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrimSpaces window;
    window.setWindowTitle("Trim Spaces");
    window.resize(400, 200);
    window.show();

    return a.exec();
}
