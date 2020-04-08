#include "image.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	image w;
	w.show();
	return a.exec();
}
