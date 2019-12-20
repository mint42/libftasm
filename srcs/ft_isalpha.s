; ---------------------------------------------------------------------------- ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/20 00:11:45 by rreedy            #+#    #+#              ;
;    Updated: 2019/12/20 00:11:45 by rreedy           ###   ########.fr        ;
;                                                                              ;
; ---------------------------------------------------------------------------- ;

;
; int ft_isalpha(int c);
;

global	_ft_isalpha

section .text

_ft_isalpha:
	push	rbp
	mov		rbp, rsp

	cmp		rdi, 65
	jl		_false
	cmp		rdi, 122
	jg		_false
	cmp		rdi, 91
	jl		_true
	cmp		rdi, 96
	jg		_true
	jmp		_false

_true:
	mov		eax, 1
	jmp		_end

_false:
	mov		eax, 0
	jmp		_end

_end:
	pop		rbp
	ret
