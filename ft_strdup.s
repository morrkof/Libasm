; char	*ft_strdup(const char *s)
; s = rdi

global ft_strdup

extern	malloc
extern	ft_strlen
extern	ft_strcpy

ft_strdup:	call ft_strlen	; s in rdi, return in rax
			push rdi		; save string
			mov	rdi, rax	; prepare to malloc, argument must be in rdi
			inc rdi			; +1 for '\0'
			call malloc		; return in rax
			cmp rax, 0		; protect malloc
			jz .quit		
			mov rdi, rax	; prepare to strcpy, dest must be in rdi
			pop rsi			; prepare to strcpy, saved string (src) must be in rsi
			call ft_strcpy	; return in rax
.quit:		ret