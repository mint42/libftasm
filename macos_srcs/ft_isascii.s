;---------------------------;
;	int ft_isascii(int c);	;
;---------------------------;

global	_ft_isascii

section .text

_ft_isascii:
	push	rbp
	mov		rbp, rsp

	xor		rax, rax	; set ret = 0

	cmp		rdi, 0x0	; if (c < 0)
	jl		_end		;	goto _end
	cmp		rdi, 127	; if (c > 127)
	jg		_end		;	goto _end

	mov		rax, 1		; true -> set ret = 1

_end:
	pop		rbp
	ret
