; Prototype :	ssize_t ft_read(int fd, void *buf, size_t n)
; Registers :	none
; Description :	call the read syscall

global		_ft_read

section		.text

_ft_read:
	mov		rax, 0x2000003
	syscall
	ret
