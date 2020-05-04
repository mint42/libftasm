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
			movzx	rax, byte [rdi]	; ret = *s1
			sub		al, byte [rsi]	; ret = ret - *s2
			movsx	rax, al			; move back into large register

			pop		rbp
			ret
