#!/usr/bin/env python3

nome = input('Nome: ').upper()
chave = sum(map(ord, nome)) ^ 0x444c

print('Chave: {}'.format(chave))
