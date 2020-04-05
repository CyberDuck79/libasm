; Prototype : void ft_list_sort(t_list **begin_list, int (*cmp)(void*,void*))
; Registers : rdi rsi rcx rdx r8 r9
; Desciption : sort elements of a list with cmp function for comparison

global		_ft_list_sort

section		.text

; sorting :
; get the first element
; compare with the first
; if lesser than first, swap
; go to next element
_ft_list_sort:
	mov		rdx, [rdi]		; get *elem1
	mov		rcx, [rdx+8]	; get *elem2
	mov		r8, rsi			; save cmp
	jmp		.compare
.reset_continue:
	mov		rdx, [rdx+8]
	mov		rcx, [rdx+8]
	test	rcx, rcx
	jnz		.compare
	ret
.incr:
	mov		rcx, [rcx+8]
.compare:
	mov		rdi, [rdx]		; put elem1->data to arg1
	mov		rsi, [rcx]		; put elem2->data to arg2
	call	r8				; call cmp
	cmp		rax, 0x00		; look at cmp result
	jle		.no_swap		; if lesser or equal noswap
	mov		r9, [rcx]		; swap
	xchg	r9, [rdx]		
	mov		[rcx], r9
.no_swap:
	mov		rax, [rcx+8]	; look at next pointer
	test	rax, rax		; check if end of list
	jz		.reset_continue	; inc the elem1 pointer
	jmp		.incr			; goto next
