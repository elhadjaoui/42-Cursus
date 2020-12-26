section .text
global _ft_strcpy

_ft_strcpy :
xor rax,rax
loop :
		cmp [rsi], byte 0
		je return
		mov bh,[rsi]
		mov rdi[rax],bh
		inc rsi
		inc rax
		jmp loop
return :
		mov rdi[rax],byte 0
		mov rax,rdi
		ret
