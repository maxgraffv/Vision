#include <stdlib.h>

#include "Matrix.h"
#include <stdio.h>
#include "Image.h"
#include "AppWindow.h"

#include<QApplication>
#include <QPushButton>

int main(int argc, char** argv)
{


	Matrix* m = Matrix::createIdentityMatrix(5);
	m->print();

	printf("\n\n");

	Matrix* minor = m->getMinor(0, 2, 3, 3);
	minor->print();


	Image* img = new Image("");
	img->show();

	QApplication app(argc, argv);
	AppWindow window;
	window.show();
	app.exec();

	return 0;
}
