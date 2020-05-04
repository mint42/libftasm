;---------------------------------------;
;	int		ft_set_errno(int errno);	;
;---------------------------------------;

global	_ft_set_errno

extern	___error

section	.text

_ft_set_errno:

	push	rax							; save error code
	call	___error					; get errno location
	mov		r12, rax					; move errno location ptr
	pop		rax							; pop error code 
	mov		[r12], rax					; move error code to errno location and swap sign
	mov		rax, -1						; set new return to -1

	ret
