;---------------------------------------;
;	void ft_bzero(void *s, size_t len);	;
;---------------------------------------;

global	ft_bzero

section .text

ft_bzero:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rsi		; i = len

_loop:
	mov		byte [rdi], 0x0	; (*dst)++ = 0;
	loop	_loop			; if (--i != 0) -> loop

_end:
	pop		rbp
	ret
