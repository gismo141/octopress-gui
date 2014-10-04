#include <QApplication>

#include "view/octopress-gui.h"

int main(int argc, char** argv) {
	QApplication::setOrganizationName("MyCompany");
QApplication::setApplicationName("Octopress-GUI");
	QApplication app(argc, argv);

    octopress_gui mainWindow;
    mainWindow.show();
    
    return app.exec();
}
