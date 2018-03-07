#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "crc32.h"

bool checa(char *nome, int serial) {
	int serial_correto = 0;

	while (*nome)
		serial_correto += *nome++;

	return (serial == serial_correto);
}

int main(void) {
	char nome[50];
	int serial;
	uint32_t crc = crc32((unsigned char *)checa, 63);

	printf("Nome: "); scanf("%s", nome);
	printf("Serial: "); scanf("%d", &serial);

	if (checa(nome, serial) && crc == 0x63280335)
		printf("Bravo!\n");
	else
		printf("Tente outra vez...\n");

	return 0;
}
