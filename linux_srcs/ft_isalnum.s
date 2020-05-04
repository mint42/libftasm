;---------------------------;
;	int ft_isalnum(int c);	;
;---------------------------;

global	ft_isalnum

extern	ft_isalpha
extern	ft_isdigit

section .text

ft_isalnum:
	push	rbp
	mov		rbp, rsp

	call	ft_isalpha	; (c);
	cmp		rax, 0x0	; if (ret != 0)
	jne		_end		;	goto _end
	call	ft_isdigit	; (c);

_end:
	pop		rbp
	ret
