	cmp	rcx, rsi
	ja	.L10
	sub	rsi, rcx
	add	rsi, 1
	mov	r11, rsi
	je	.L10
	test	rcx, rcx
	jne	.L16
	mov	rax, rdi
	ret
.L10:
	xor	eax, eax
	ret
.L16:
	push	rbx
	xor	r10d, r10d
	mov	r9d, 1
.L4:
	lea	rax, [rdi+r10]
	xor	esi, esi
	xor	r8d, r8d
.L8:
	movzx	ebx, BYTE PTR [rdx+rsi]
	cmp	BYTE PTR [rax+rsi], bl
	cmovne	r8d, r9d
	add	rsi, 1
	cmp	rsi, rcx
	jne	.L8
	test	r8d, r8d
	je	.L12
	add	r10, 1
	cmp	r10, r11
	jne	.L4
	xor	eax, eax
.L12:
	pop	rbx
	ret