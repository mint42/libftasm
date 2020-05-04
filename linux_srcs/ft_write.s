;-----------------------------------------------------------;
;	ssize_t		ft_write(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	ft_write

extern	ft_set_errno

section	.text

ft_write:
		push	rbp
		mov		rbp, rsp

		mov		rax, 0x1		; "load" syscall write()
		syscall					; call write()

		cmp		rax, 0x0		; if (ret >= 0)
		jge		_end			;	goto _end

		call	ft_set_errno	; (errno);

_end:
		pop		rbp
		ret
