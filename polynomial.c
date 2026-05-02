#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "polynomial.h"

polynomial* createPolynomial(int capacity) {
	polynomial* po = (polynomial*)createArrayList(capacity);
	return po;
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;
	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo <= item.expo) {
			break;
		}
	}

	if (i == sizeArrayList(po)) {
		insertArrayList(po, i, item);
	}
	else if (po->data[i].expo == item.expo) {
		po->data[i].coef += item.coef;
	}
	else {
		insertArrayList(po, i, item);
	}

	return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) || j < sizeArrayList(p2)) {			//&&연산자는 한쪽이 끝나면 멈춰버려 ||로 교체

		if (i == sizeArrayList(p1) || (i < sizeArrayList(p1) && p1->data[i].expo < p2->data[j].expo)) {		//한쪽이 끝나면 남은 항 추가
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else if (j == sizeArrayList(p2) || (j < sizeArrayList(p2) && p1->data[i].expo > p2->data[j].expo)) { //한쪽이 끝나면 남은 항 추가
			addItemPolynomial(r, p1->data[i]);
			i++;
		}
		else {
			addItemPolynomial(r, (elementType) {
				p1->data[i].coef + p2->data[j].coef,
					p1->data[i].expo
			});

			i++;
			j++;
		}
	}

	return r;
}

polynomial* multiPolynomial(polynomial* p1, polynomial* p2) {

	//인덱스 = [i]는 지수 표현, 해당 인덱스의 값은 차수 = ExpoArray[i]

	int maxExpo = p1->data[0].expo + p2->data[0].expo;
	int* ExpoArray = (int*)malloc((maxExpo + 1) * sizeof(int)); //최대 지수를 구한 후 0 ~ 최대지수 만큼 배열 생성 
	int toExpo = 0;

	for (int i = 0; i <= maxExpo; i++) {
		ExpoArray[i] = 0;
	}

	for (int i = 0; i < sizeArrayList(p1); i++) {
		for (int j = 0; j < sizeArrayList(p2); j++) {
			toExpo = p1->data[i].expo + p2->data[j].expo;
			ExpoArray[toExpo] += p1->data[i].coef * p2->data[j].coef;
		}
	}

	polynomial* r = createPolynomial((p1->data[0].coef + p2->data[0].coef) + 1);

	for (int i = maxExpo; i >= 0; i--) {
		if (ExpoArray[i] != 0) {
			addItemPolynomial(r, (elementType) { ExpoArray[i], i });
		}
	}

	free(ExpoArray);

	return r;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial: \n");

	printArrayList(po);

	printf("\n");
}

polynomial* AddItemPolynomial(polynomial* po, char* item) {

	polynomial* charPoly = createPolynomial(100);

	int itemCoef;
	int itemExpo;

	int itemPtr = 0;

	while (itemPtr < strlen(item)) {

		int forRead = 0;
		sscanf(item + itemPtr, "%dX^%d%n", &itemCoef, &itemExpo, &forRead);
		itemPtr += forRead;

		addItemPolynomial(charPoly, (elementType) { itemCoef, itemExpo });

		if (item[itemPtr] == '+')
			itemPtr++;

	}

	po = addPolynomial(po, charPoly);
	free(charPoly);

	return po;
}