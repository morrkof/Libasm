; size_t	ft_strlen(const char *s)
; s = rdi, int i = rax, return rax

global		ft_strlen

section		.text
ft_strlen:	xor rax, rax			; rax = 0
.lp:		cmp byte [rdi + rax], 0	; compare s and '\0', rax is offset
			jz .quit				; if '\0' jump to quit
			inc rax					; increment rax
			jmp .lp					; jump to loop begin
.quit:		ret