; ---------------------------------------------------------------------------- ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/20 00:38:23 by rreedy            #+#    #+#              ;
;    Updated: 2019/12/20 00:38:23 by rreedy           ###   ########.fr        ;
;                                                                              ;
; ---------------------------------------------------------------------------- ;

;
; int ft_isascii(int c);
;

global	_ft_isascii

section .text

_ft_isascii:
	push	rbp
	mov		rbp, rsp

	xor		rax, rax	; set ret = 0

	cmp		rdi, 0		; if (c < 0)
	jl		_end		;	goto _end
	cmp		rdi, 127	; if (c > 127)
	jg		_end		;	goto _end

	mov		rax, 1		; true -> set ret = 1

_end:
	pop		rbp
	ret
