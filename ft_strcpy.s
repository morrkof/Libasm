; char	*ft_strcpy(char *dst, const char *src)
; dst = rdi, src = rsi

global	ft_strcpy

section	.text

ft_strcpy:	xor rax, rax				; rax = 0
			cmp rdi, 0					; check dst != NULL
			jz .error					; error if NULL
			cmp rsi, 0					; check src != NULL
			jz .quit					; exit if NULL
.lp:		mov dl, byte [rsi + rax]	; one byte from src goes to buffer
			mov byte [rdi + rax], dl	; buffer goes to dst
			inc rax						; increment rax
			cmp dl, 0					; check if '\0'
			jz .quit					; jump if yes
			jmp .lp						; else jump to loop begin
.quit:		mov rax, rdi				; return char * dst
			ret
.error:		mov rax, 0					; return 0 if error
			ret