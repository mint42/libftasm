;-------------------------------------------------------------------;
;	char	*ft_strncpy(char *dst, const char *src, size_t len);	;
;-------------------------------------------------------------------;

global	_ft_strncpy

section .text

_ft_strncpy:
			push	rbp
			mov		rbp, rsp

			mov		rcx, rdx	; move len into counter
			mov		rax, rdi	; move dst string to ret register
			cld					; move forward
	rep		movsb				; repeat a move op to copy over data

			pop		rbp
			ret
