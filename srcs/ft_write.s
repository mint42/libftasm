;-----------------------------------------------------------;
;	ssize_t		ft_write(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	_ft_write

section .text

_ft_write:
		push	rbp
		mov		rbp, rsp
	
		push	rdi			; save (fd)
		push	rsi			; save (buf)
		push	rdx			; save (count)
		mov		rax, 0x01	; "load" syscall write()
		syscall				; call write()
		push	rdx			; pop saved (count)
		push	rsi			; pop saved (buf)
		push	rdi			; pop saved (fd)
	
		pop		rbp
		ret
