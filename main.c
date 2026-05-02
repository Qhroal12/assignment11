#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#include "polynomial.h"

int main() {
	polynomial* p1;
	p1 = createPolynomial(100);

	addItemPolynomial(p1, (elementType) { 4, 0 });
	addItemPolynomial(p1, (elementType) { 2, 1 });
	addItemPolynomial(p1, (elementType) { 3, 2 });

	printPolynomial(p1);

	polynomial* p2;
	p2 = createPolynomial(100);

	addItemPolynomial(p2, (elementType) { 4, 3 });
	addItemPolynomial(p2, (elementType) { 5, 0 });

	printPolynomial(p2);

	polynomial* p3 = addPolynomial(p1, p2);

	printPolynomial(p3);




	///////////////////////////////////다항식 곱셈 및 문자열 입력/////////////////////////////////////
	polynomial* p4 = multiPolynomial(p1, p2);

	printPolynomial(p4);

	printf("\n\n");

	printPolynomial(AddItemPolynomial(p1, "7X^5+3X^3+4X^1"));
	printPolynomial(AddItemPolynomial(p2, "7X^5+3X^3+4X^1"));
}