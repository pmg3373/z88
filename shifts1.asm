	.org	0x50
one:	.word	0xa5a5a5a5
	.org	0x100
	.entry	main
main:
	addi	r1,r0,#0x0010
	addi	r2,r0,#0x0004
	addi	r3,r0,#0xffff
	nop
	nop
	nop
;
	lw	r4,0x50(r0)
	nop
	nop
	nop
;
	sllv	r10,r4,r1
	srlv	r11,r4,r1
	srav	r12,r4,r1
;
	sllv	r13,r4,r2
	srlv	r14,r4,r2
	srav	r15,r4,r2
;
	sllv	r16,r4,r3
	srlv	r17,r4,r3
	srav	r18,r4,r3
;
	halt
