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

			push	rdi
			push	rsi
			mov		rdi, rsi		; move RSI to parameter 1
			call	_ft_strlen
			pop		rsi
			pop		rdi
			inc 	rax				; add one to consider null term
			mov		rdx, rax		; move len to parameter 3
			call	_ft_strncpy

			pop		rbp
			ret
