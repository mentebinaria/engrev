#!/usr/bin/env python3

nome = input('Nome: ')

nome = nome.upper()

soma = 0
for i in nome:
	soma = soma + ord(i)

chave = soma ^ 0x5678 ^ 0x1234

print('Chave: ' + str(chave))
