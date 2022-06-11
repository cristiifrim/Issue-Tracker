#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "service.h"
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service srv{ repo };

    std::ifstream f{ "users.txt" };
 
    while (!f.eof()) {
        User s;
        f >> s;
        GUI* w = new GUI{ s, srv };
        w->show();
    }
    return a.exec();
}
