; # apt install nasm
; $ nasm -f elf32 hello.asm
; $ ld -m elf_i386 -o hello hello.o
; $ ./hello

bits 32
 
	section .rodata                   ; seção .rodata do ELF, onde ficam os dados somente-leitura
msg:db "Mente Binária", 10          ; nossa string que será impressa, seguida de um \n
len: equ $-msg                      ; "$" significa "aqui" -> posição atual menos posição do texto. len terá o tamanho da string.
 
	section .text                     ; seção .text do ELF, onde fica o código
	global _start                     ; faz o label "_start" visível ao linker (ld)

_start:
	mov edx,len                       ; arg3 da syscall write(), quantidade de bytes para imprimir (tamanho)
	mov ecx,msg                       ; arg2, pointeiro para o endereço da string
	mov ebx,1                         ; arg1, em qual file descriptor (fd) escrever. 1 é stdout
	mov eax,4                         ; 4 é o código da syscall write()
	int 0x80                          ; interrupção 0x80 do kernel (executa a syscall apontada em eax)
	 
	mov ebx,0                         ; arg1 da syscall exit(). 0 significa execução com sucesso
	mov eax,1                         ; 1 é o código da syscall exit()
	int 0x80                          ; executa a syscall apontada em eax, que vai sair do programa
