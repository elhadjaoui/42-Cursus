extern ___error
SYS_WRITE equ 0x2000004
section .text
global _ft_write
_ft_write:
			mov rax,SYS_WRITE
			syscall
			jc error
			ret
error:
			push	rax
			call 	___error
			pop		rdi
			mov		[rax],rdi
			mov 	rax,-1
			ret
