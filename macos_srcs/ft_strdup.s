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

			push	rdi				; save (s)
			call	_ft_strlen		; (s);
									; dont need to pop (s) because it will
									; need pushed again for malloc() call

			mov		rdi, rax		; move (len) to parameter 1
			inc		rdi				; ++(len) for null term

			push	rdi				; save (len)
			call	_malloc			; (len);
			pop		rdx				; pop saved (len) into parameter 3

			pop		rsi				; pop saved (s) into parameter 2
			mov		rdi, rax		; move (new memory) into parameter 1

			call	_ft_strncpy		; (new_mem, s, len);

			pop		rbp
			ret
