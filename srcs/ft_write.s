;-----------------------------------------------------------;
;	ssize_t		ft_write(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	_ft_write

section .text

_ft_write:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0x01
	syscall

	pop		rbp
	ret
