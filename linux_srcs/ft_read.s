;-----------------------------------------------------------;
;	ssize_t		ft_read(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	ft_read

extern	ft_set_errno

section	.text

ft_read:
		push	rbp
		mov		rbp, rsp

		mov		rax, 0x0		; "load" syscall read()
		syscall					; call read()

		cmp		rax, 0x0		; if (ret >= 0)
		jge		_end			;	goto _end

		call	ft_set_errno	; (errno);

_end:
		pop		rbp
		ret
