global		_main

extern		_ft_atoi_base
extern		_printf

default		rel

section		.data
.input: db	"111111",0
.base: db	"1",0

section		.text

_main:
.test1:
	lea		rdi, [.input]
	lea		rsi, [.base]
	call	_ft_atoi_base
	xor		rax, rax
	ret
