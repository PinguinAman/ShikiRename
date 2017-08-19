#include "ShikiRename.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ShikiRename w;

	w.showMaximized();

	return a.exec();
}
