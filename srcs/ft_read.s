;-----------------------------------------------------------;
;	ssize_t		ft_read(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	_ft_read

extern	_ft_error

section	.text

_ft_read:
		push	rbp
		mov		rbp, rsp

		push	rdi			; save (fd)
		push	rsi			; save (buf)
		push	rdx			; save (count)
		mov		rax, 0x00	; "load" syscall read()
		syscall				; call read()
		push	rdx			; pop saved (count)
		push	rsi			; pop saved (buf)
		push	rdi			; pop saved (fd)

		pop		rbp
		ret
