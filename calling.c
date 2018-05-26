// https://gcc.gnu.org/onlinedocs/gcc/x86-Function-Attributes.html

int soma(int a, int b, int c) {
  return a+b+c;
}

int main(void) {
	return soma(1, 2, 3) + 4;
}
