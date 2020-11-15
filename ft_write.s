; ssize_t	ft_write(int fd, const void *buf, size_t count)
; fd = rdi, buf = rsi, count = rdx, return = rax

global ft_write

extern __errno_location

ft_write: 	mov rax, 1
			syscall					; return negative error code in rax if error
			cmp rax, 0				; compare rax and 0
			jl error				; jump if less
			ret
error:		neg rax
			mov	rdx, rax			; copy error code in rdx
			call __errno_location	; get errno location to set errno
			mov [rax], rdx			; copy error code to errno by pointer (location)
			mov rax, -1				; set return -1
			ret