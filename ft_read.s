; ssize_t	ft_read(int fd, void *buf, size_t count)
; fd = rdi, buf = rsi, count = rdx, return = rax

global ft_read

extern __errno_location

ft_read: 	mov rax, 0
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