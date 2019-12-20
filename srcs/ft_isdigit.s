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

ft_isdigit:
	push	rbp
	mov		rbp, rsp

	cmp		rdi, 48
	jl		_false
	cmp		rdi, 57
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
