; ---------------------------------------------------------------------------- ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2019/12/18 15:43:17 by rreedy            #+#    #+#              ;
;    Updated: 2019/12/18 15:43:17 by rreedy           ###   ########.fr        ;
;                                                                              ;
; ---------------------------------------------------------------------------- ;

;
; void ft_bzero(void *s, size_t len);
;

global	_ft_bzero

section	.text

_ft_bzero:
	push		rbp
	mov			rbp, rsp

	cmp			rdi, 0
	je			_end
	mov			rcx, rsi
	rep movsb	[rdi + rcx], 0

_end:
	pop			rbp
	ret
