;---------------------------------------------------;
;	char	*ft_strcpy(char *dst, const char *src);	;
;---------------------------------------------------;

global	_ft_strcpy

extern	_ft_strlen
extern	_ft_strncpy

section .text

_ft_strcpy:
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
