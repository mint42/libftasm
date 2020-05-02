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

			push	rdi				; save (dst)
			push	rsi				; save (src)
			mov		rdi, rsi		; move (src) to parameter 1
			call	_ft_strlen		; (src);
			pop		rsi				; pop saved (src)
			pop		rdi				; pop saved (dst)

			mov		rdx, rax		; move (len) to parameter 3
			inc 	rdx				; ++(len) for null term

			call	_ft_strncpy		; (dst, src, len);

			pop		rbp
			ret
