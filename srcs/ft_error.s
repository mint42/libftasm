;
;	int		ft_error()
;

global	_ft_error

extern	___error

section	.text

_ft_error:
	push	rbp
	mov		rbp, rsp

	push	rax
	call	___error
	mov		rbx, rax
	pop		rax
	mov		[rbx], rax
	mov		rax, -1

	pop		rbp
	ret
