#include <stdlib.h>

#include "Matrix.h"
#include <stdio.h>
#include "Image.h"
#include "AppWindow.h"

#include<QApplication>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	AppWindow window(1920, 1080);
	window.show();
	app.exec();

	return 0;
}
