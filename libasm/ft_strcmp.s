section .text
global _ft_strcmp
_ft_strcmp :
xor rax,rax
loop:
			mov bl, rsi[rax]
			mov cl, rdi[rax]
			cmp bl,byte 0
			je  check
			cmp cl,byte 0
			je  check
			cmp bl,cl
			jne check
			inc rax
			jmp loop
			
positive : 
			mov rax,1
			ret
negative :  
			mov rax,-1
			ret
check :
			cmp cl,bl
			ja positive
			cmp cl,bl
			jb negative
			jmp return
return :	
			mov rax,0
			ret
