; Prototype : void ft_list_sort(t_list **begin_list, int (*cmp)(void*,void*))
; Registers : rdi rsi -- reg used by cmp -- r12 r13 r14 r15
; Desciption : sort elements of a list with cmp function for comparison

global		ft_list_sort

section		.text

ft_list_sort:
	push	r12				; save callee save registers
	push	r13				; used because don't know
	push	r14				; possible parameters
	push	r15				; used by cmp function
	sub		rsp, 0x08		; stack aligment
	mov		r12, [rdi]		; get *elem1
	mov		r13, [r12+8]	; get *elem2
	mov		r14, rsi		; save cmp
	jmp		.compare
.reset_continue:
	mov		r12, [r12+8]
	mov		r13, [r12+8]
	test	r13, r13
	jnz		.compare
	add		rsp, 0x08		; stack aligment
	pop		r15				; restore callee save registers
	pop		r14
	pop		r13
	pop		r12
	ret
.incr:
	mov		r13, [r13+8]
.compare:
	mov		rdi, [r12]		; put elem1->data to arg1
	mov		rsi, [r13]		; put elem2->data to arg2
	call	r14				; call cmp function
	cmp		rax, 0x00
	jle		.no_swap
	mov		r15, [r13]		; swap
	xchg	r15, [r12]		
	mov		[r13], r15
.no_swap:
	mov		rax, [r13+8]	; look at next pointer
	test	rax, rax		; check if end of list
	jz		.reset_continue	; inc the elem1 pointer
	jmp		.incr			; goto next elem2
