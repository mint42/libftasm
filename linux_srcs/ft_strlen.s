;-------------------------------------------;
;	size_t		ft_strlen(const char *s);	;
;-------------------------------------------;

global	_ft_strlen

section .text

_ft_strlen:
			push	rbp
			mov		rbp, rsp

			mov		rcx, -1		; don't let (i) == 0 so set (i) = -1
			xor		rax, rax	; NULL RAX for comparing
			cld					; move strings forward
	repne	scasb				; repeat while (((*s)++) != 0) and --(i)
			mov		rax, -2		; setup for correct subtration
			sub		rax, rcx	; (ret) = (ret) - (i);

			pop		rbp
			ret
