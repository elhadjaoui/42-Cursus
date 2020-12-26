extern ___error
SYS_READ  equ 0x2000003
section .text
global _ft_read
_ft_read : 
mov rax,SYS_READ
syscall
jc check
ret
check :
mov rdi,rax
call ___error
mov [rax],rdi
mov rax,-1
ret
