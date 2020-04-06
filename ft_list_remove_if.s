; Prototype : void ft_list_remove_if(t_list **list, void *data_ref, int (*cmp)(), void (*free_fct)(void*))
; registers : rdi rsi rdx rcx -- reg used by cmp -- r12 r13 r14 r15
; Description : compare elements of the list with data_ref applying cmp function and remove if return 0

global		_ft_list_remove_if

extern		_free

section		.text

_ft_list_remove_if:
	push	r12				; save callee saved registers
	push	r13				; used because don't know
	push	r14				; parameters registers
	push	r15				; used by cmp and free functions
	push	rbx
	mov		r12, [rdi]		; get *elem to cmp
	mov		r13, rsi		; get *data_ref
	mov		r14, rdx		; save cmp
	mov		r15, rcx		; save free_fct
	jmp		.compare
.compare:
	mov		rdi, [r12]		; put elem->data to arg1
	mov		rsi, r13		; put data_ref to arg2
	call	r14				; call cmp function
	test	rax, rax
	jnz		.no_del
	mov		rdi, [r12]		; put elem->data to arg1
	call	r15
	mov		rdx, [r12+8]	; get elem->next
	test	rdx, rdx		; last element ?
	jz		.del_last		; special procedure for last element
	mov		rcx, [rdx]		; get next->data
	mov		[r12], rcx		; replace elem->data
	mov		rcx, [rdx+8]	; get next->next
	mov		[r12+8], rcx	; replace elem->next
	mov		rdi, rcx		; put previous next as arg
	call	_free			; free node
.no_del:
	lea		rbx, [r12+8]	; save a pointer to next
	mov		r12, [r12+8]	; next element
	test	r12, r12		; check if end of list
	jnz		.compare		; continue if not end
.return:
	pop		rbx				; restore callee save registers
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret
.del_last:
	mov		rdi, r12
	call	_free			; free node
	mov		qword [rbx], 0x00	; set null 
	jmp		.return
