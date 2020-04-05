global		_main

extern		_ft_create_elem
extern		_ft_list_push_front
extern		_ft_list_sort
extern		_ft_strcmp

default		rel

section		.data
.input1: db	"test1",0
.input2: db	"test2",0
.input3: db	"test3",0
.input4: db	"test4",0
.input5: db	"test5",0

section		.text

_main:
	lea		rdi, [.input5]
	sub		rsp, 0x08
	call	_ft_create_elem
	add		rsp, 0x08
	push	rax
	mov		rdi, rsp
	push	rsp
	sub		rsp, 0x08
	lea		rsi, [.input1]
	call	_ft_list_push_front
	add		rsp, 0x08
	pop		rdi
	push	rdi
	sub		rsp, 0x08
	lea		rsi, [.input3]
	call	_ft_list_push_front
	add		rsp, 0x08
	pop		rdi
	lea		rsi, [_ft_strcmp]
	call	_ft_list_sort
	xor		rax, rax
	ret
