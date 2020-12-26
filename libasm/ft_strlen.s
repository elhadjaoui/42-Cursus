section .text
global _ft_strlen
_ft_strlen :
xor rax,rax
loop:
	cmp rdi[rax],byte 0
	je return
	inc rax
	jmp loop
return :
	ret
