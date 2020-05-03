;-------------------------------------------------------;
;	int		ft_strcmp(const char *s1, const char *s2);	;
;-------------------------------------------------------;

global	_ft_strcmp

section .text

_ft_strcmp:
			push	rbp
			mov		rbp, rsp

_loop:								; loop until not equal/end
			cmp		byte [rdi], 0x0	; if (*s1 == 0)
			je		_end			; 	goto _end
			cmp		byte [rsi], 0x0	; if (*s2 == 0)
			je		_end			;	goto _end
			cmpsb					; if ((*s1)++ != (*s2)++)
			jne		_dec			; 	goto _dec
			jmp		_loop			; else -> loop

_dec:
			dec		rdi				; --s1
			dec		rsi				; --s2

_end:
			mov		rax, [rdi]		; ret = *s1
			sub		rax, [rsi]		; ret = ret - *s2

			pop		rbp
			ret
