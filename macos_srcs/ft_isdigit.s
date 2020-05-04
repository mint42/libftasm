; ---------------------------------------------------------------------------- ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/20 00:41:56 by rreedy            #+#    #+#              ;
;    Updated: 2019/12/20 00:41:58 by rreedy           ###   ########.fr        ;
;                                                                              ;
; ---------------------------------------------------------------------------- ;

;
; int ft_isdigit(int c);
;

global	_ft_isdigit

section .text

_ft_isdigit:
	push	rbp
	mov		rbp, rsp

	xor		rax, rax	; set ret = 0

	cmp		rdi, 48		; if (c < 48)
	jl		_end		;	goto _end
	cmp		rdi, 57		; if (c > 57)
	jg		_end		;	goto _end

	mov		eax, 1		; true -> set ret = 1

_end:
	pop		rbp
	ret
