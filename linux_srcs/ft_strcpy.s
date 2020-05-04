;---------------------------------------------------;
;	char	*ft_strcpy(char *dst, const char *src);	;
;---------------------------------------------------;

global	ft_strcpy

section .text

ft_strcpy:
			push	rbp
			mov		rbp, rsp

			mov		rax, rdi		; set (ret) to head of (dst)

_loop:
			cmp		byte [rsi], 0x0	; if (!*src)
			je		_end			;	break ;
			movsb					; (*dst)++ = (*src)++
			jmp		_loop			; loop

_end:
			mov		byte [rdi], 0x0
			pop		rbp
			ret
