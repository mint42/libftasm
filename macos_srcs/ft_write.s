;-----------------------------------------------------------;
;	ssize_t		ft_write(int fd, void *buf, size_t count);	;
;-----------------------------------------------------------;

global	_ft_write

extern	_ft_set_errno

section	.text

_ft_write:
		push	rbp
		mov		rbp, rsp

		mov		rax, 0x2000004	; "load" syscall write()
		syscall					; call write()

		jc		_call_errno		; if carry flag set, call errno setter
		jmp		_end			; else goto _end

_call_errno:
		call	_ft_set_errno	; (errno);

_end:
		pop		rbp
		ret
