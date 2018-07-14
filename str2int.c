#include <stdio.h>

int str2int(char *s) {
	int chr, res = 0;

	while (*s) {
		chr = *s - '0';
		res = res * 10 + chr;
		s++;
	}

	return res;
}

int main(int argc, char *argv[]) {
	printf("%d\n", str2int("1345"));

	return 0;
}
