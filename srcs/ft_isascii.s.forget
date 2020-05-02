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

	cmp		rdi, 0
	jl		_false
	cmp		rdi, 127
	jg		_false
	jmp		_true

_true:
	mov		eax, 1
	jmp		_end

_false:
	mov		eax, 0
	jmp		_end

_end:
	pop		rbp
	ret
