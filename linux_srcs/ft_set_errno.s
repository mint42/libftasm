;---------------------------------------;
;	int		ft_set_errno(int errno);	;
;---------------------------------------;

global	_ft_set_errno

extern	__errno_location

section	.text

_ft_set_errno:
	push	rbp
	mov		rbp, rsp

	push	rax							; save error code
	call	__errno_location wrt ..plt	; get errno location
	mov		r12, rax					; move errno location ptr
	mov		byte [r12], 0x0				; zero ptr value
	pop		rax							; pop error code 
	sub		[r12], rax					; move error code to errno location and swap sign
	mov		rax, -1						; set new return to -1

	pop		rbp
	ret
