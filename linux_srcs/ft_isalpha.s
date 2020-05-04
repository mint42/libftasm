;---------------------------;
;	int ft_isalpha(int c);	;
;---------------------------;

global	ft_isalpha

section .text

ft_isalpha:
	push	rbp
	mov		rbp, rsp

	xor		rax, rax	; set ret = 0

	cmp		rdi, 65		; if (c < 65)
	jl		_end		;	goto _end
	cmp		rdi, 122	; if (c > 122)
	jg		_end		;	goto _end
	cmp		rdi, 91		; if (c < 91)
	jl		_true		;	goto _true
	cmp		rdi, 96		; if (c > 96)
	jg		_true		;	goto _true
	jmp		_end		; else -> end

_true:
	mov		eax, 1		; true -> set ret = 1

_end:
	pop		rbp
	ret
