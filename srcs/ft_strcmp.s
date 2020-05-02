;-------------------------------------------------------;
;	int		ft_strcmp(const char *s1, const char *s2);	;
;-------------------------------------------------------;

global	_ft_strcmp

section .text

_ft_strcmp:
			push	rbp
			mov		rbp, rsp

			cmp		byte [rdi], 0	; if (*s1 == 0)
			je		_end			; goto _end
			cmp		byte [rsi], 0	; if (*s2 == 0)
			je		_end			; goto _end
			inc		rdi				; ++s1
			inc		rsi				; ++s2

_loop:								; loop until not equal/end
			cmp		byte [rdi], 0	; if (*s1 == 0)
			je		_dec			; 	goto _dec
			cmp		byte [rsi], 0	; if (*s2 == 0)
			je		_dec			;	goto _dec
			cmpsb					; if ((*s1)++ == (*s2)++)
			je		_loop			; 	goto _loop

_dec:
			dec		rdi				; --s1
			dec		rsi				; --s2

_end:
			mov		rax, [rdi]		; ret = *s1
			sub		rax, [rsi]		; ret = ret - *s2

			pop		rbp
			ret
