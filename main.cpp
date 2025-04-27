#include <stdlib.h>

#include "Matrix.h"
#include "Image.h"

int main(int argc, char** argv)
{


	Matrix* m = Matrix::createIdentityMatrix(5); //new Matrix();
	m->print();

	printf("\n\n");

	Matrix* minor = m->getMinor(0, 2, 3, 3);
	minor->print();


	Image* img = new Image("/Users/maxgraff/Desktop/Vision/image.rgb");
	img->show();



	return 0;
}
