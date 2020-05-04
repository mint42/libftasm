;-------------------------------------------------------------------;
;	char	*ft_strncpy(char *dst, const char *src, size_t len);	;
;-------------------------------------------------------------------;

global	ft_strncpy

extern	ft_bzero

section .text

ft_strncpy:
			push	rbp
			mov		rbp, rsp

			mov		rax, rdi		; set (ret) to head of (dst)
			mov		rcx, rdx		; (i) = (len)

_loop:
			cmp		byte [rsi], 0x0	; if (!*src)
			je		_break			;	break ;
			movsb					; (*dst)++ = (*src)++
			loop	_loop			; if (--(i) != 0) -> loop

_break:
			cmp		rcx, 0x0		; if (len)
			jne		_call_ft_bzero	; 	call bzero setup
			jmp		_end			; else -> _end

_call_ft_bzero:
			mov		rsi, rdx		; move len to param 2
			call	ft_bzero		; (dst, len);

_end:
			pop		rbp
			ret
