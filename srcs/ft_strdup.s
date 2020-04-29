;---------------------------------------;
;	char	*ft_strdup(const char *s);	;
;---------------------------------------;

global	_ft_strdup

extern	_malloc
extern	_ft_strlen
extern	_ft_strncpy

section .text

_ft_strdup:
			push	rbp
			mov		rbp, rsp

			call	_ft_strlen		; call strlen with parameter 1 loaded
			push	rdi
			mov		rdi, rax		; move length into parameter 1
			call	_malloc
			mov		rbx, rdi		; move length into parameter 3
			inc		rbx				; increase length by one for null term
			pop		rsi				; pop string into parameter 2
			mov		rdi, rax		; move new memory into parameter 1
			call	_ft_strncpy

			pop		rbp
			ret
