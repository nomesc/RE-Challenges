	mov	edx, edi
	shr	edx
	or	edx, edi
	mov	eax, edx
	shr	eax, 2
	or	eax, edx
	mov	edx, eax
	shr	edx, 4
	or	edx, eax
	mov	eax, edx
	shr	eax, 8
	or	eax, edx
	mov	edx, eax
	shr	edx, 16
	or	edx, eax
	imul	eax, edx, 79355661 ; 0x4badf0d
	shr	eax, 26
	mov	eax, DWORD PTR v[0+rax*4]
	ret