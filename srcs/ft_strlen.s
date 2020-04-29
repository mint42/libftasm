;-------------------------------------------;
;	size_t		ft_strlen(const char *s);	;
;-------------------------------------------;

global	_ft_strlen

section .text

_ft_strlen:
			push	rbp
			mov		rbp, rsp

			mov		rcx, -1		; take RCX out of the equation
			mov		rax, 0		; null byte for comparing
			cld
	repne	scasb				; loop while [RDI] != [RAX]
			mov		rax, -2		; setup for correct subtration
			sub		rax, rcx	; store the result in RAX

			pop		rbp
			ret
