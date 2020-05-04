;---------------------------;
;	int ft_isalnum(int c);	;
;---------------------------;

global	_ft_isalnum

extern	_ft_isalpha
extern	_ft_isdigit

section .text

_ft_isalnum:
	push	rbp
	mov		rbp, rsp

	call	_ft_isalpha	; (c);
	cmp		rax, 0x0	; if (ret != 0)
	jne		_end		;	goto _end
	call	_ft_isdigit	; (c);

_end:
	pop		rbp
	ret
