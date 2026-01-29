section .text
	global _start

_start:
	mov rax, 60 ; 60 is the system call for exit
	mov rdi, 67 ; rdi holds return value
	syscall
