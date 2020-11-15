; int	ft_strcmp(const char *s1, const char *s2)
; s1 = rdi, s2 = rsi

global ft_strcmp

section .text
ft_strcmp:	xor rax, rax				; rax = 0
.lp:		mov dl, byte [rdi + rax]	; one byte from s1 goes to dl
			mov cl, byte [rsi + rax]	; one byte from s2 goes to cl		
			cmp dl, cl					; compare dl and cl						
			jne .not_eq					; jump if not equal
			cmp byte [rdi + rax], 0		; if equal, check '\0'
			jz .quit					; jump if yes
			inc rax						; increment rax
			jmp .lp						; jump to loop begin
.quit:		mov rax, 0					; return 0 if equal
			ret
.not_eq:	movzx rdx, dl				; expand dl to rdx
			movzx rcx, cl				; expand cl to rcx
			cmp rdx, rcx				; compare 
			jl	.less					; jump if less
			mov rax, 1
			ret
.less:		mov rax, -1
			ret
