# assignment11


```
polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	
  polynomial* r = createPolynomial(100);

	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
		if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else if (p1->data[i].expo > p2->data[j].expo) {
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
```

위 코드는 조건문은 문제가 없지만 and 연산자로 되어있어 하나의 다항식에서 항이 끝나버리면 루프문을 빠져 나온다는 문제가 생깁니다.
그렇기 때문에 p1의 data가 끝이나면 p2의 data를 추가하는 식과 그 반대의 식도 있어야 합니다.

```
while(i < sizeArrayList(p1)){
  addItemPolynomial(r, p1->data[i]);
  i++;
}

while(j < sizeArrayList(p2)){
  addItemPolynomial(r, p1->data[j]);
  j++;
}
```
