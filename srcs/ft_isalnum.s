; ---------------------------------------------------------------------------- ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/20 00:11:45 by rreedy            #+#    #+#              ;
;    Updated: 2019/12/20 00:11:45 by rreedy           ###   ########.fr        ;
;                                                                              ;
; ---------------------------------------------------------------------------- ;

;
; int ft_isalnum(int c);
;

global	_ft_isalnum

extern	_ft_isalpha
extern	_ft_isdigit

section .text

_ft_isalnum:
	push	rbp
	mov		rbp, rsp

	call	_ft_isalpha	; (c);
	cmp		rax, 0		; if (ret == 0)
	je		_end		;	goto _end
	call	_ft_isdigit ; (c);

_end:
	pop		rbp
	ret
