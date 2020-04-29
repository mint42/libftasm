;-----------------------------------------------------------;
;	ssize_t		ft_read(int rd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	_ft_read

section	.text

_ft_read:
	push	rbp
	mov		rbp, rsp

	mov		rax, 0x00
	syscall

	pop		rbp
	ret
