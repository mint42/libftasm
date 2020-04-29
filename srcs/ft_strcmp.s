;-----------------------------------------------------------;
;	size_t		ft_strcmp(const char *s1, const char *s2);	;
;-----------------------------------------------------------;

global	_ft_strcmp

section .text

_ft_strcmp:
			push	rbp
			mov		rbp, rsp

_loop:								; loop until not equal/end
			cmp		byte [rdi], 0
			je		_end
			cmp		byte [rsi], 0
			je		_end
			cmpsb
			je		_loop

_end:
			dec		rdi				; move back by one
			dec		rsi				; move back by one
			mov		rax, [rdi]		; move RDI to return register
			sub		rax, [rsi]		; subtract to get difference

			pop		rbp
			ret
