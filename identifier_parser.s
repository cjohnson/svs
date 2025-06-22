	.file	"identifier_parser.cpp"
	.text
	.section	.text._ZNSt11char_traitsIcE6assignERcRKc,"axG",@progbits,_ZNSt11char_traitsIcE6assignERcRKc,comdat
	.weak	_ZNSt11char_traitsIcE6assignERcRKc
	.type	_ZNSt11char_traitsIcE6assignERcRKc, @function
_ZNSt11char_traitsIcE6assignERcRKc:
.LFB1554:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movb	%dl, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1554:
	.size	_ZNSt11char_traitsIcE6assignERcRKc, .-_ZNSt11char_traitsIcE6assignERcRKc
	.section	.text._ZNSt11char_traitsIcE4copyEPcPKcm,"axG",@progbits,_ZNSt11char_traitsIcE4copyEPcPKcm,comdat
	.weak	_ZNSt11char_traitsIcE4copyEPcPKcm
	.type	_ZNSt11char_traitsIcE4copyEPcPKcm, @function
_ZNSt11char_traitsIcE4copyEPcPKcm:
.LFB1561:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L3
	movq	-8(%rbp), %rax
	jmp	.L4
.L3:
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rax, %rsi
	movq	-24(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	memcpy@PLT
	nop
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1561:
	.size	_ZNSt11char_traitsIcE4copyEPcPKcm, .-_ZNSt11char_traitsIcE4copyEPcPKcm
	.section	.text._ZSt3minImERKT_S2_S2_,"axG",@progbits,_ZSt3minImERKT_S2_S2_,comdat
	.weak	_ZSt3minImERKT_S2_S2_
	.type	_ZSt3minImERKT_S2_S2_, @function
_ZSt3minImERKT_S2_S2_:
.LFB2746:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jnb	.L6
	movq	-16(%rbp), %rax
	jmp	.L7
.L6:
	movq	-8(%rbp), %rax
.L7:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2746:
	.size	_ZSt3minImERKT_S2_S2_, .-_ZSt3minImERKT_S2_S2_
	.section	.text._ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev,"axG",@progbits,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED5Ev,comdat
	.align 2
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev
	.type	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev, @function
_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev:
.LFB3454:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3454:
	.size	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev, .-_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	.set	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED2Ev
	.section	.text._ZN3svs6ParserIcEC2Ev,"axG",@progbits,_ZN3svs6ParserIcEC5Ev,comdat
	.align 2
	.weak	_ZN3svs6ParserIcEC2Ev
	.type	_ZN3svs6ParserIcEC2Ev, @function
_ZN3svs6ParserIcEC2Ev:
.LFB3463:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTVN3svs6ParserIcEE(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3463:
	.size	_ZN3svs6ParserIcEC2Ev, .-_ZN3svs6ParserIcEC2Ev
	.weak	_ZN3svs6ParserIcEC1Ev
	.set	_ZN3svs6ParserIcEC1Ev,_ZN3svs6ParserIcEC2Ev
	.section	.data.rel.ro,"aw"
	.align 8
	.type	_ZL27alphabetic_character_parser, @object
	.size	_ZL27alphabetic_character_parser, 8
_ZL27alphabetic_character_parser:
	.quad	_ZTVN3svs25AlphabeticCharacterParserE+16
	.local	_ZL17underscore_parser
	.comm	_ZL17underscore_parser,64,32
	.local	_ZL40simple_identifier_first_character_parser
	.comm	_ZL40simple_identifier_first_character_parser,32,32
	.text
	.align 2
	.globl	_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.type	_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, @function
_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_:
.LFB3467:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3467
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$520, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -504(%rbp)
	movq	%rsi, -512(%rbp)
	movq	%rdx, -520(%rbp)
	movq	%rcx, -528(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-416(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev@PLT
.LEHE0:
	movq	-520(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -488(%rbp)
	movq	-528(%rbp), %rdx
	leaq	-488(%rbp), %rax
	leaq	_ZL40simple_identifier_first_character_parser(%rip), %rcx
	movq	%rax, %rsi
	movq	%rcx, %rdi
.LEHB1:
	call	_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_
	movl	%eax, %ecx
	movq	%rdx, %rax
	movl	%ecx, -480(%rbp)
	movq	%rax, -472(%rbp)
	leaq	-480(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE9succeededEv
	xorl	$1, %eax
	testb	%al, %al
	je	.L11
	movq	-504(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv
	jmp	.L12
.L11:
	leaq	-480(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev
	movq	%rax, -488(%rbp)
	leaq	-480(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE5valueEv
	movsbl	%al, %eax
	leaq	-416(%rbp), %rdx
	addq	$16, %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	-528(%rbp), %rdx
	leaq	-488(%rbp), %rcx
	movq	-512(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	movl	%eax, %ecx
	movq	%rdx, %rax
	movl	%ecx, -464(%rbp)
	movq	%rax, -456(%rbp)
	jmp	.L13
.L14:
	leaq	-464(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE5valueEv
	movsbl	%al, %eax
	leaq	-416(%rbp), %rdx
	addq	$16, %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	leaq	-464(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev
	movq	%rax, -488(%rbp)
	movq	-528(%rbp), %rdx
	leaq	-488(%rbp), %rcx
	movq	-512(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	movl	%eax, %ecx
	movq	%rdx, %rax
	movl	%ecx, -464(%rbp)
	movq	%rax, -456(%rbp)
.L13:
	leaq	-464(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE9succeededEv
	testb	%al, %al
	jne	.L14
	leaq	-448(%rbp), %rax
	leaq	-416(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv@PLT
.LEHE1:
	movq	-504(%rbp), %rax
	leaq	-488(%rbp), %rdx
	leaq	-448(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB2:
	call	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE
.LEHE2:
	nop
	leaq	-448(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.L12:
	leaq	-416(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L19
	jmp	.L22
.L21:
	movq	%rax, %rbx
	leaq	-448(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L17
.L20:
	movq	%rax, %rbx
.L17:
	leaq	-416(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L18
	call	__stack_chk_fail@PLT
.L18:
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume@PLT
.LEHE3:
.L22:
	call	__stack_chk_fail@PLT
.L19:
	movq	-504(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3467:
	.section	.gcc_except_table,"a",@progbits
.LLSDA3467:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3467-.LLSDACSB3467
.LLSDACSB3467:
	.uleb128 .LEHB0-.LFB3467
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3467
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L20-.LFB3467
	.uleb128 0
	.uleb128 .LEHB2-.LFB3467
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L21-.LFB3467
	.uleb128 0
	.uleb128 .LEHB3-.LFB3467
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE3467:
	.text
	.size	_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, .-_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.align 2
	.globl	_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.type	_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, @function
_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_:
.LFB3468:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movq	%rdi, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	%rdx, -136(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-128(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	(%rax), %rdx
	movq	-80(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	sete	%al
	testb	%al, %al
	je	.L27
	call	_ZN3svs11ParseResultIcE4failEv
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	jmp	.L28
.L27:
	movq	-128(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	isalnum@PLT
	testl	%eax, %eax
	jne	.L30
	movq	-128(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$95, %al
	je	.L30
	movq	-128(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	cmpb	$36, %al
	jne	.L33
.L30:
	movl	$1, %eax
	jmp	.L34
.L33:
	movl	$0, %eax
.L34:
	testb	%al, %al
	je	.L35
	movq	-128(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$1, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -96(%rbp)
	nop
	movq	-96(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	leaq	-96(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	jmp	.L28
.L35:
	call	_ZN3svs11ParseResultIcE4failEv
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	nop
.L28:
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L38
	call	__stack_chk_fail@PLT
.L38:
	movl	%ecx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3468:
	.size	_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, .-_ZNK3svs22SimpleIdentifierParser20parse_post_beginningERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD5Ev,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev:
.LFB3575:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3575:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5Ev,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev:
.LFB3577:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3577
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rbx
	leaq	-41(%rbp), %rax
	movq	%rax, -32(%rbp)
	nop
	nop
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	movq	%rax, %rcx
	leaq	-41(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_
	leaq	-41(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	movq	-56(%rbp), %rax
	movq	%rax, -40(%rbp)
	nop
	movq	-56(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
	nop
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L41
	call	__stack_chk_fail@PLT
.L41:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3577:
	.section	.gcc_except_table
.LLSDA3577:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3577-.LLSDACSB3577
.LLSDACSB3577:
.LLSDACSE3577:
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5Ev,comdat
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2Ev
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED5Ev,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev:
.LFB3580:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3580
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3580:
	.section	.gcc_except_table
.LLSDA3580:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3580-.LLSDACSB3580
.LLSDACSB3580:
.LLSDACSE3580:
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED5Ev,comdat
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev
	.section	.text._ZNK3svs11ParseResultIcE9succeededEv,"axG",@progbits,_ZNK3svs11ParseResultIcE9succeededEv,comdat
	.align 2
	.weak	_ZNK3svs11ParseResultIcE9succeededEv
	.type	_ZNK3svs11ParseResultIcE9succeededEv, @function
_ZNK3svs11ParseResultIcE9succeededEv:
.LFB3768:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3768:
	.size	_ZNK3svs11ParseResultIcE9succeededEv, .-_ZNK3svs11ParseResultIcE9succeededEv
	.section	.text._ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv,"axG",@progbits,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv,comdat
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv
	.type	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv, @function
_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv:
.LFB3769:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1Ev
	movq	-8(%rbp), %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3769:
	.size	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv, .-_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE4failEv
	.section	.rodata
	.align 8
.LC0:
	.string	"T svs::ParseResult<T>::value() const [with T = char]"
	.align 8
.LC1:
	.string	"src/parser/sv2017/../parse_result.h"
.LC2:
	.string	"_success"
	.section	.text._ZNK3svs11ParseResultIcE5valueEv,"axG",@progbits,_ZNK3svs11ParseResultIcE5valueEv,comdat
	.align 2
	.weak	_ZNK3svs11ParseResultIcE5valueEv
	.type	_ZNK3svs11ParseResultIcE5valueEv, @function
_ZNK3svs11ParseResultIcE5valueEv:
.LFB3773:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L48
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rax
	movq	%rdx, %rcx
	movl	$61, %edx
	movq	%rax, %rdi
	call	__assert_fail@PLT
.L48:
	movq	-8(%rbp), %rax
	movzbl	1(%rax), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3773:
	.size	_ZNK3svs11ParseResultIcE5valueEv, .-_ZNK3svs11ParseResultIcE5valueEv
	.section	.rodata
	.align 8
.LC3:
	.string	"std::__cxx11::basic_string<char>::const_iterator svs::ParseResult<T>::next() const [with T = char; std::__cxx11::basic_string<char>::const_iterator = std::__cxx11::basic_string<char>::const_iterator]"
	.section	.text._ZNK3svs11ParseResultIcE4nextB5cxx11Ev,"axG",@progbits,_ZNK3svs11ParseResultIcE4nextB5cxx11Ev,comdat
	.align 2
	.weak	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev
	.type	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev, @function
_ZNK3svs11ParseResultIcE4nextB5cxx11Ev:
.LFB3775:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L51
	leaq	.LC3(%rip), %rdx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rax
	movq	%rdx, %rcx
	movl	$71, %edx
	movq	%rax, %rdi
	call	__assert_fail@PLT
.L51:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3775:
	.size	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev, .-_ZNK3svs11ParseResultIcE4nextB5cxx11Ev
	.section	.text._ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE,"axG",@progbits,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE,comdat
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE
	.type	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE, @function
_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE:
.LFB3777:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3777
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1Ev
	movq	-24(%rbp), %rax
	movb	$1, (%rax)
	movq	-24(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
.LEHB4:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
.LEHE4:
	movq	-24(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	(%rdx), %rdx
	movq	%rdx, 40(%rax)
	jmp	.L57
.L56:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L57:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3777:
	.section	.gcc_except_table
.LLSDA3777:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3777-.LLSDACSB3777
.LLSDACSB3777:
	.uleb128 .LEHB4-.LFB3777
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L56-.LFB3777
	.uleb128 0
	.uleb128 .LEHB5-.LFB3777
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE3777:
	.section	.text._ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE,"axG",@progbits,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE,comdat
	.size	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE, .-_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE7succeedERKS6_RKN9__gnu_cxx17__normal_iteratorIPKcS6_EE
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC5ESt16initializer_listIS3_ERKS4_,comdat
	.align 2
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_:
.LFB3785:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3785
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -24(%rbp)
	movq	%rsi, %rax
	movq	%rdx, %rsi
	movq	%rax, %rax
	movl	$0, %edx
	movq	%rsi, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv
	movq	%rax, %r12
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv
	movq	%rax, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv
	movq	%rax, %rsi
	movq	-24(%rbp), %rax
	movq	%r12, %rcx
	movq	%rbx, %rdx
	movq	%rax, %rdi
.LEHB6:
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m
.LEHE6:
	jmp	.L61
.L60:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume@PLT
.LEHE7:
.L61:
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3785:
	.section	.gcc_except_table
.LLSDA3785:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3785-.LLSDACSB3785
.LLSDACSB3785:
	.uleb128 .LEHB6-.LFB3785
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L60-.LFB3785
	.uleb128 0
	.uleb128 .LEHB7-.LFB3785
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE3785:
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC5ESt16initializer_listIS3_ERKS4_,comdat
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ESt16initializer_listIS3_ERKS4_
	.set	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ESt16initializer_listIS3_ERKS4_,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ESt16initializer_listIS3_ERKS4_
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED5Ev,comdat
	.align 2
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev:
.LFB3788:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	movq	-40(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	-40(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -24(%rbp)
	movq	%rdx, -16(%rbp)
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_
	nop
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3788:
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED1Ev
	.set	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED1Ev,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED2Ev
	.section	.text._ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE,"axG",@progbits,_ZN3svs9AnyParserIcEC5ESt6vectorIPNS_6ParserIcEESaIS5_EE,comdat
	.align 2
	.weak	_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE
	.type	_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE, @function
_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE:
.LFB3791:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs6ParserIcEC2Ev
	leaq	16+_ZTVN3svs9AnyParserIcEE(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ERKS5_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3791:
	.size	_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE, .-_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE
	.weak	_ZN3svs9AnyParserIcEC1ESt6vectorIPNS_6ParserIcEESaIS5_EE
	.set	_ZN3svs9AnyParserIcEC1ESt6vectorIPNS_6ParserIcEESaIS5_EE,_ZN3svs9AnyParserIcEC2ESt6vectorIPNS_6ParserIcEESaIS5_EE
	.section	.text._ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_,"axG",@progbits,_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_,comdat
	.align 2
	.weak	_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_
	.type	_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_, @function
_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_:
.LFB3793:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-104(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv
	movq	%rax, -88(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv
	movq	%rax, -80(%rbp)
	jmp	.L65
.L73:
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %r8
	movq	-120(%rbp), %rdx
	movq	-112(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	*%r8
	movl	%eax, %ecx
	movq	%rdx, %rax
	movl	%ecx, -32(%rbp)
	movq	%rax, -24(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE9succeededEv
	testb	%al, %al
	je	.L67
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE4nextB5cxx11Ev
	movq	%rax, -72(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK3svs11ParseResultIcE5valueEv
	movb	%al, -89(%rbp)
	leaq	-72(%rbp), %rdx
	leaq	-89(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	jmp	.L68
.L67:
	movq	-88(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -88(%rbp)
	nop
.L65:
	leaq	-88(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-80(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	setne	%al
	testb	%al, %al
	jne	.L73
	call	_ZN3svs11ParseResultIcE4failEv
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	nop
.L68:
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L74
	call	__stack_chk_fail@PLT
.L74:
	movl	%ecx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3793:
	.size	_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_, .-_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_
	.section	.text._ZN3svs11ParseResultIcE4failEv,"axG",@progbits,_ZN3svs11ParseResultIcE4failEv,comdat
	.weak	_ZN3svs11ParseResultIcE4failEv
	.type	_ZN3svs11ParseResultIcE4failEv, @function
_ZN3svs11ParseResultIcE4failEv:
.LFB3796:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultIcEC1Ev
	movb	$0, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L77
	call	__stack_chk_fail@PLT
.L77:
	movl	%ecx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3796:
	.size	_ZN3svs11ParseResultIcE4failEv, .-_ZN3svs11ParseResultIcE4failEv
	.section	.text._ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,"axG",@progbits,_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,comdat
	.weak	_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.type	_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, @function
_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE:
.LFB3799:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3svs11ParseResultIcEC1Ev
	movb	$1, -32(%rbp)
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	movb	%al, -31(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L80
	call	__stack_chk_fail@PLT
.L80:
	movl	%ecx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3799:
	.size	_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, .-_ZN3svs11ParseResultIcE7succeedERKcRKN9__gnu_cxx17__normal_iteratorIPS2_NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv:
.LFB3813:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3813:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv:
.LFB3814:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
	call	_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3814:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC5EPcOS3_,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_:
.LFB3816:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, -40(%rbp)
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	nop
	nop
	movq	-56(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3816:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcOS3_,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC2EPcOS3_
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm:
.LFB3819:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm
	movb	$0, -9(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	movq	-32(%rbp), %rdx
	addq	%rax, %rdx
	leaq	-9(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSt11char_traitsIcE6assignERcRKc
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L88
	call	__stack_chk_fail@PLT
.L88:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3819:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv:
.LFB3820:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
	xorl	$1, %eax
	testb	%al, %al
	je	.L91
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
.L91:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3820:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv:
.LFB3823:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3823:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv:
.LFB3825:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	cmpq	%rax, %rbx
	sete	%al
	testb	%al, %al
	je	.L95
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	$15, %rax
	movl	$1, %eax
	jmp	.L97
.L95:
	movl	$0, %eax
.L97:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3825:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv:
.LFB3826:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3826:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc:
.LFB3827:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3827:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm:
.LFB3828:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3828:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm:
.LFB3829:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3829:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_lengthEm
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv:
.LFB3860:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	cmpq	-8(%rbp), %rax
	setb	%al
	testb	%al, %al
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3860:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	.section	.text._ZNSt15__new_allocatorIcED2Ev,"axG",@progbits,_ZNSt15__new_allocatorIcED5Ev,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIcED2Ev
	.type	_ZNSt15__new_allocatorIcED2Ev, @function
_ZNSt15__new_allocatorIcED2Ev:
.LFB3865:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3865:
	.size	_ZNSt15__new_allocatorIcED2Ev, .-_ZNSt15__new_allocatorIcED2Ev
	.weak	_ZNSt15__new_allocatorIcED1Ev
	.set	_ZNSt15__new_allocatorIcED1Ev,_ZNSt15__new_allocatorIcED2Ev
	.section	.text._ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev,"axG",@progbits,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC5Ev,comdat
	.align 2
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev
	.type	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev, @function
_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev:
.LFB3948:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movq	-24(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3948:
	.size	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev, .-_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev
	.weak	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1Ev
	.set	_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC1Ev,_ZN3svs11ParseResultINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEC2Ev
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_:
.LFB3951:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3951:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_
	.section	.text._ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev,"axG",@progbits,_ZNSt15__new_allocatorIPN3svs6ParserIcEEED5Ev,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	.type	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev, @function
_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev:
.LFB3956:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3956:
	.size	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev, .-_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	.weak	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED1Ev
	.set	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED1Ev,_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev:
.LFB3960:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3960:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD1Ev
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD1Ev,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD2Ev
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC5ERKS4_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_:
.LFB3962:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC1ERKS4_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3962:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC1ERKS4_
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC1ERKS4_,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2ERKS4_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev:
.LFB3965:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3965
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3965:
	.section	.gcc_except_table
.LLSDA3965:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3965-.LLSDACSB3965
.LLSDACSB3965:
.LLSDACSE3965:
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED5Ev,comdat
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED1Ev
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED1Ev,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	.section	.text._ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv,"axG",@progbits,_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv
	.type	_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv, @function
_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv:
.LFB3967:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3967:
	.size	_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv, .-_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv
	.section	.text._ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv,"axG",@progbits,_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv
	.type	_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv, @function
_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv:
.LFB3968:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIPN3svs6ParserIcEEE5beginEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv
	salq	$3, %rax
	addq	%rbx, %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3968:
	.size	_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv, .-_ZNKSt16initializer_listIPN3svs6ParserIcEEE3endEv
	.section	.text._ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv,"axG",@progbits,_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv
	.type	_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv, @function
_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv:
.LFB3969:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3969:
	.size	_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv, .-_ZNKSt16initializer_listIPN3svs6ParserIcEEE4sizeEv
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m,comdat
	.align 2
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m:
.LFB3970:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	-40(%rbp), %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm
	movq	-40(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	movq	%rax, %rcx
	leaq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	-56(%rbp), %rsi
	movq	%rax, %rdi
	call	_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E
	movq	-40(%rbp), %rdx
	movq	%rax, 8(%rdx)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3970:
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE21_M_range_initialize_nIPKS3_S8_EEvT_T0_m
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv:
.LFB3971:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3971:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC5ERKS5_,comdat
	.align 2
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_:
.LFB3974:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3974
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	-104(%rbp), %rbx
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	movq	%rax, -88(%rbp)
	leaq	-89(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rdx, -80(%rbp)
	movq	%rax, -72(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -48(%rbp)
	nop
	nop
	nop
	nop
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv
	movq	%rax, %rcx
	leaq	-89(%rbp), %rax
	movq	%rax, %rdx
	movq	%rcx, %rsi
	movq	%rbx, %rdi
.LEHB8:
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_
.LEHE8:
	leaq	-89(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	movq	%rax, %r13
	movq	-104(%rbp), %rax
	movq	(%rax), %rbx
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv
	movq	%rax, %r12
	movq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv
	movq	%r13, %rcx
	movq	%rbx, %rdx
	movq	%r12, %rsi
	movq	%rax, %rdi
.LEHB9:
	call	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E
.LEHE9:
	movq	-104(%rbp), %rdx
	movq	%rax, 8(%rdx)
	nop
	movq	-40(%rbp), %rax
	subq	%fs:40, %rax
	je	.L131
	jmp	.L134
.L132:
	movq	%rax, %rbx
	leaq	-89(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	movq	%rbx, %rax
	movq	-40(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L128
	call	__stack_chk_fail@PLT
.L128:
	movq	%rax, %rdi
.LEHB10:
	call	_Unwind_Resume@PLT
.L133:
	movq	%rax, %rbx
	movq	-104(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EED2Ev
	movq	%rbx, %rax
	movq	-40(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L130
	call	__stack_chk_fail@PLT
.L130:
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE10:
.L134:
	call	__stack_chk_fail@PLT
.L131:
	addq	$88, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3974:
	.section	.gcc_except_table
.LLSDA3974:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3974-.LLSDACSB3974
.LLSDACSB3974:
	.uleb128 .LEHB8-.LFB3974
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L132-.LFB3974
	.uleb128 0
	.uleb128 .LEHB9-.LFB3974
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L133-.LFB3974
	.uleb128 0
	.uleb128 .LEHB10-.LFB3974
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
.LLSDACSE3974:
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC5ERKS5_,comdat
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ERKS5_
	.set	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ERKS5_,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC2ERKS5_
	.section	.text._ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv,"axG",@progbits,_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv
	.type	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv, @function
_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv:
.LFB3976:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	nop
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L137
	call	__stack_chk_fail@PLT
.L137:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3976:
	.size	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv, .-_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE5beginEv
	.section	.text._ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv,"axG",@progbits,_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv
	.type	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv, @function
_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv:
.LFB3977:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	nop
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L140
	call	__stack_chk_fail@PLT
.L140:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3977:
	.size	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv, .-_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE3endEv
	.section	.text._ZN3svs11ParseResultIcEC2Ev,"axG",@progbits,_ZN3svs11ParseResultIcEC5Ev,comdat
	.align 2
	.weak	_ZN3svs11ParseResultIcEC2Ev
	.type	_ZN3svs11ParseResultIcEC2Ev, @function
_ZN3svs11ParseResultIcEC2Ev:
.LFB3982:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3982:
	.size	_ZN3svs11ParseResultIcEC2Ev, .-_ZN3svs11ParseResultIcEC2Ev
	.weak	_ZN3svs11ParseResultIcEC1Ev
	.set	_ZN3svs11ParseResultIcEC1Ev,_ZN3svs11ParseResultIcEC2Ev
	.section	.text._ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc,"axG",@progbits,_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc,comdat
	.weak	_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
	.type	_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc, @function
_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc:
.LFB3991:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3991:
	.size	_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc, .-_ZNSt19__ptr_traits_ptr_toIPccLb0EE10pointer_toERc
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm:
.LFB3995:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-64(%rbp), %rax
	leaq	1(%rax), %r12
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, -40(%rbp)
	movq	%rbx, -32(%rbp)
	movq	%r12, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcE10deallocateEPcm
	nop
	nop
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3995:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv:
.LFB3996:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
	testb	%al, %al
	je	.L148
	movq	$15, -8(%rbp)
	jmp	.L149
.L148:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
.L149:
	cmpq	$14, -8(%rbp)
	jbe	.L150
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	cmpq	-8(%rbp), %rax
	jnb	.L151
.L150:
	movl	$1, %eax
	jmp	.L152
.L151:
	movl	$0, %eax
.L152:
	testb	%al, %al
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3996:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
	.section	.rodata
.LC4:
	.string	"basic_string::_M_create"
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm:
.LFB3997:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	cmpq	%rbx, %rax
	setb	%al
	testb	%al, %al
	je	.L156
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L156:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -40(%rbp)
	jnb	.L157
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rax
	cmpq	%rax, %rdx
	jnb	.L157
	movq	-40(%rbp), %rax
	leaq	(%rax,%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	cmpq	%rbx, %rax
	setb	%al
	testb	%al, %al
	je	.L157
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	movq	-32(%rbp), %rdx
	movq	%rax, (%rdx)
.L157:
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3997:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm,comdat
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm:
.LFB3998:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$1, -24(%rbp)
	jne	.L160
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11char_traitsIcE6assignERcRKc
	jmp	.L162
.L160:
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt11char_traitsIcE4copyEPcPKcm
.L162:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3998:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv:
.LFB3999:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdi
	call	_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3999:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv:
.LFB4022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$9223372036854775807, %rax
	movq	%rax, -48(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movabsq	$9223372036854775807, %rax
	nop
	nop
	movq	%rax, -40(%rbp)
	leaq	-40(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3minImERKT_S2_S2_
	movq	(%rax), %rax
	subq	$1, %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L170
	call	__stack_chk_fail@PLT
.L170:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4022:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8max_sizeEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_:
.LFB4086:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4086
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$120, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -120(%rbp)
	movq	%rsi, -128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	testb	%al, %al
	je	.L173
	movl	$1, %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L175
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_is_localEv
	xorl	$1, %eax
	testb	%al, %al
	je	.L175
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, %rbx
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, -88(%rbp)
	movq	%rbx, -80(%rbp)
	movl	$0, %eax
	testb	%al, %al
	je	.L175
	movl	$1, %eax
	jmp	.L177
.L175:
	movl	$0, %eax
.L177:
	testb	%al, %al
	je	.L178
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	cmpq	$15, %rax
	setbe	%al
	testb	%al, %al
	je	.L179
	movq	-120(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
	movq	-120(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	movq	%rax, %rdx
	nop
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	movq	-120(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
	jmp	.L178
.L179:
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	movq	%rax, -104(%rbp)
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, -64(%rbp)
	leaq	-105(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -48(%rbp)
	nop
	nop
	movq	-104(%rbp), %rax
	leaq	1(%rax), %rdx
	leaq	-105(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB11:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m
.LEHE11:
	movq	%rax, -96(%rbp)
	movq	-120(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_destroyEm
	movq	-96(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	movq	-104(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm
	movq	-104(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
	leaq	-105(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
.L178:
	movq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, %rbx
	movq	-120(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	movq	%rax, -40(%rbp)
	movq	%rbx, -32(%rbp)
	nop
.L173:
	movq	-128(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_
	movq	-120(%rbp), %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L184
	jmp	.L186
.L185:
	movq	%rax, %rbx
	leaq	-105(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcED2Ev
	nop
	movq	%rbx, %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L183
	call	__stack_chk_fail@PLT
.L183:
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE12:
.L186:
	call	__stack_chk_fail@PLT
.L184:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4086:
	.section	.gcc_except_table
.LLSDA4086:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4086-.LLSDACSB4086
.LLSDACSB4086:
	.uleb128 .LEHB11-.LFB4086
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L185-.LFB4086
	.uleb128 0
	.uleb128 .LEHB12-.LFB4086
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE4086:
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_,comdat
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignERKS4_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC5ERKS4_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_:
.LFB4090:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	nop
	nop
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4090:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC1ERKS4_
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC1ERKS4_,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC2ERKS4_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m:
.LFB4092:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	cmpq	$0, -48(%rbp)
	je	.L190
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m
	nop
.L190:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4092:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE13_M_deallocateEPS3_m
	.section	.rodata
	.align 8
.LC5:
	.string	"cannot create std::vector larger than max_size()"
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_,comdat
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_:
.LFB4093:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-80(%rbp), %rax
	movq	%rax, -48(%rbp)
	leaq	-49(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -32(%rbp)
	nop
	nop
	leaq	-49(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_
	cmpq	-72(%rbp), %rax
	setb	%bl
	leaq	-49(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	testb	%bl, %bl
	je	.L192
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L193
	call	__stack_chk_fail@PLT
.L193:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L192:
	movq	-72(%rbp), %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L195
	call	__stack_chk_fail@PLT
.L195:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4093:
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE17_S_check_init_lenEmRKS4_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm:
.LFB4094:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	cmpq	$0, -32(%rbp)
	je	.L197
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-16(%rbp), %rax
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv
	nop
	jmp	.L199
.L197:
	movl	$0, %eax
.L199:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4094:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm
	.section	.text._ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E,"axG",@progbits,_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E,comdat
	.weak	_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E
	.type	_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E, @function
_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E:
.LFB4096:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4096:
	.size	_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E, .-_ZSt22__uninitialized_copy_aIPKPN3svs6ParserIcEES5_PS3_S3_ET1_T_T0_S7_RSaIT2_E
	.section	.text._ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_,"axG",@progbits,_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_,comdat
	.weak	_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_
	.type	_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_, @function
_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_:
.LFB4097:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4097:
	.size	_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_, .-_ZSt8_DestroyIPPN3svs6ParserIcEEEvT_S5_
	.section	.text._ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv,"axG",@progbits,_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv,comdat
	.align 2
	.weak	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv
	.type	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv, @function
_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv:
.LFB4099:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4099:
	.size	_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv, .-_ZNKSt6vectorIPN3svs6ParserIcEESaIS3_EE4sizeEv
	.section	.text._ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv,"axG",@progbits,_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv,comdat
	.align 2
	.weak	_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	.type	_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv, @function
_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv:
.LFB4100:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4100:
	.size	_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv, .-_ZNKSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE19_M_get_Tp_allocatorEv
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC5EmRKS4_,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_:
.LFB4103:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4103
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implC1ERKS4_
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB13:
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm
.LEHE13:
	jmp	.L212
.L211:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE12_Vector_implD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB14:
	call	_Unwind_Resume@PLT
.LEHE14:
.L212:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4103:
	.section	.gcc_except_table
.LLSDA4103:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4103-.LLSDACSB4103
.LLSDACSB4103:
	.uleb128 .LEHB13-.LFB4103
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L211-.LFB4103
	.uleb128 0
	.uleb128 .LEHB14-.LFB4103
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSE4103:
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC5EmRKS4_,comdat
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC1EmRKS4_
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC1EmRKS4_,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EEC2EmRKS4_
	.section	.text._ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E,"axG",@progbits,_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E,comdat
	.weak	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E
	.type	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E, @function
_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E:
.LFB4105:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4105:
	.size	_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E, .-_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEESB_PS5_S5_ET1_T_T0_SD_RSaIT2_E
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m,comdat
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m:
.LFB4115:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	movq	-16(%rbp), %rax
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIcE8allocateEmPKv
	nop
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4115:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_S_allocateERS3_m
	.section	.text._ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_,"axG",@progbits,_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_,comdat
	.weak	_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
	.type	_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_, @function
_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_:
.LFB4116:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4116:
	.size	_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_, .-_ZNSt19__ptr_traits_ptr_toIPKcS0_Lb0EE10pointer_toERS0_
	.section	.text._ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv,"axG",@progbits,_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv,comdat
	.align 2
	.weak	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	.type	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv, @function
_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv:
.LFB4130:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4130:
	.size	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv, .-_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE16_M_get_allocatorEv
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_,comdat
	.align 2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_:
.LFB4173:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-80(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	cmpq	%rax, -72(%rbp)
	setne	%al
	testb	%al, %al
	je	.L230
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	movq	%rax, -56(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
	movq	%rax, -48(%rbp)
	movq	-56(%rbp), %rax
	cmpq	%rax, -48(%rbp)
	jnb	.L227
	movq	-56(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-48(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	movq	-72(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm
	movq	%rax, -40(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv
	movq	-40(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc
	movq	-64(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEm
.L227:
	cmpq	$0, -56(%rbp)
	je	.L228
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	movq	%rax, %rbx
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv
	movq	%rax, %rcx
	movq	-56(%rbp), %rax
	movq	%rax, %rdx
	movq	%rbx, %rsi
	movq	%rcx, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_S_copyEPcPKcm
.L228:
	movq	-56(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEm
.L230:
	nop
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L229
	call	__stack_chk_fail@PLT
.L229:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4173:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC5Ev,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev:
.LFB4178:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4178:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC1Ev
	.set	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC1Ev,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_Vector_impl_dataC2Ev
	.section	.text._ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_,"axG",@progbits,_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_,comdat
	.weak	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_
	.type	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_, @function
_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_:
.LFB4181:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$1152921504606846975, %rax
	movq	%rax, -48(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movabsq	$1152921504606846975, %rax
	nop
	nop
	movq	%rax, -40(%rbp)
	leaq	-40(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3minImERKT_S2_S2_
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L237
	call	__stack_chk_fail@PLT
.L237:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4181:
	.size	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_, .-_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EE11_S_max_sizeERKS4_
	.section	.text._ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_,"axG",@progbits,_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_,comdat
	.weak	_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_
	.type	_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_, @function
_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_:
.LFB4183:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-48(%rbp), %rax
	subq	-40(%rbp), %rax
	sarq	$3, %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jle	.L239
	movq	-24(%rbp), %rax
	leaq	0(,%rax,8), %rsi
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	-24(%rbp), %rax
	salq	$3, %rax
	addq	%rax, -56(%rbp)
.L239:
	movq	-56(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4183:
	.size	_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_, .-_ZSt18uninitialized_copyIPKPN3svs6ParserIcEEPS3_ET0_T_S8_S7_
	.section	.text._ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm,"axG",@progbits,_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm,comdat
	.align 2
	.weak	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm
	.type	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm, @function
_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm:
.LFB4187:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE11_M_allocateEm
	movq	-8(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4187:
	.size	_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm, .-_ZNSt12_Vector_baseIPN3svs6ParserIcEESaIS3_EE17_M_create_storageEm
	.section	.text._ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_,"axG",@progbits,_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_,comdat
	.weak	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_
	.type	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_, @function
_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_:
.LFB4188:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	sarq	$3, %rax
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jle	.L248
	movq	-40(%rbp), %rax
	leaq	0(,%rax,8), %rsi
	movq	-56(%rbp), %rax
	movq	%rax, -48(%rbp)
	leaq	-48(%rbp), %rax
	movq	(%rax), %rdx
	movq	-72(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rsi, %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	-40(%rbp), %rax
	salq	$3, %rax
	addq	%rax, -72(%rbp)
.L248:
	movq	-72(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L253
	call	__stack_chk_fail@PLT
.L253:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4188:
	.size	_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_, .-_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKPN3svs6ParserIcEESt6vectorIS5_SaIS5_EEEEPS5_ET0_T_SE_SD_
	.section	.text._ZNSt15__new_allocatorIcE10deallocateEPcm,"axG",@progbits,_ZNSt15__new_allocatorIcE10deallocateEPcm,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIcE10deallocateEPcm
	.type	_ZNSt15__new_allocatorIcE10deallocateEPcm, @function
_ZNSt15__new_allocatorIcE10deallocateEPcm:
.LFB4191:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4191:
	.size	_ZNSt15__new_allocatorIcE10deallocateEPcm, .-_ZNSt15__new_allocatorIcE10deallocateEPcm
	.section	.text._ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m,"axG",@progbits,_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m
	.type	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m, @function
_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m:
.LFB4223:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4223:
	.size	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m, .-_ZNSt15__new_allocatorIPN3svs6ParserIcEEE10deallocateEPS3_m
	.section	.text._ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv,"axG",@progbits,_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv
	.type	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv, @function
_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv:
.LFB4225:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movabsq	$1152921504606846975, %rax
	cmpq	-32(%rbp), %rax
	setb	%al
	movzbl	%al, %eax
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L260
	movabsq	$2305843009213693951, %rax
	cmpq	-32(%rbp), %rax
	jnb	.L261
	call	_ZSt28__throw_bad_array_new_lengthv@PLT
.L261:
	call	_ZSt17__throw_bad_allocv@PLT
.L260:
	movq	-32(%rbp), %rax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znwm@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4225:
	.size	_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv, .-_ZNSt15__new_allocatorIPN3svs6ParserIcEEE8allocateEmPKv
	.section	.text._ZNSt15__new_allocatorIcE8allocateEmPKv,"axG",@progbits,_ZNSt15__new_allocatorIcE8allocateEmPKv,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIcE8allocateEmPKv
	.type	_ZNSt15__new_allocatorIcE8allocateEmPKv, @function
_ZNSt15__new_allocatorIcE8allocateEmPKv:
.LFB4229:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movabsq	$9223372036854775807, %rax
	cmpq	-32(%rbp), %rax
	setb	%al
	movzbl	%al, %eax
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L265
	call	_ZSt17__throw_bad_allocv@PLT
.L265:
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Znwm@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4229:
	.size	_ZNSt15__new_allocatorIcE8allocateEmPKv, .-_ZNSt15__new_allocatorIcE8allocateEmPKv
	.weak	_ZTVN3svs22SimpleIdentifierParserE
	.section	.data.rel.ro.local._ZTVN3svs22SimpleIdentifierParserE,"awG",@progbits,_ZTVN3svs22SimpleIdentifierParserE,comdat
	.align 8
	.type	_ZTVN3svs22SimpleIdentifierParserE, @object
	.size	_ZTVN3svs22SimpleIdentifierParserE, 24
_ZTVN3svs22SimpleIdentifierParserE:
	.quad	0
	.quad	_ZTIN3svs22SimpleIdentifierParserE
	.quad	_ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.weak	_ZTVN3svs9AnyParserIcEE
	.section	.data.rel.ro.local._ZTVN3svs9AnyParserIcEE,"awG",@progbits,_ZTVN3svs9AnyParserIcEE,comdat
	.align 8
	.type	_ZTVN3svs9AnyParserIcEE, @object
	.size	_ZTVN3svs9AnyParserIcEE, 24
_ZTVN3svs9AnyParserIcEE:
	.quad	0
	.quad	_ZTIN3svs9AnyParserIcEE
	.quad	_ZNK3svs9AnyParserIcE5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESE_
	.weak	_ZTVN3svs6ParserIcEE
	.section	.data.rel.ro._ZTVN3svs6ParserIcEE,"awG",@progbits,_ZTVN3svs6ParserIcEE,comdat
	.align 8
	.type	_ZTVN3svs6ParserIcEE, @object
	.size	_ZTVN3svs6ParserIcEE, 24
_ZTVN3svs6ParserIcEE:
	.quad	0
	.quad	_ZTIN3svs6ParserIcEE
	.quad	__cxa_pure_virtual
	.weak	_ZTIN3svs9AnyParserIcEE
	.section	.data.rel.ro._ZTIN3svs9AnyParserIcEE,"awG",@progbits,_ZTIN3svs9AnyParserIcEE,comdat
	.align 8
	.type	_ZTIN3svs9AnyParserIcEE, @object
	.size	_ZTIN3svs9AnyParserIcEE, 24
_ZTIN3svs9AnyParserIcEE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3svs9AnyParserIcEE
	.quad	_ZTIN3svs6ParserIcEE
	.weak	_ZTSN3svs9AnyParserIcEE
	.section	.rodata._ZTSN3svs9AnyParserIcEE,"aG",@progbits,_ZTSN3svs9AnyParserIcEE,comdat
	.align 16
	.type	_ZTSN3svs9AnyParserIcEE, @object
	.size	_ZTSN3svs9AnyParserIcEE, 20
_ZTSN3svs9AnyParserIcEE:
	.string	"N3svs9AnyParserIcEE"
	.weak	_ZTIN3svs22SimpleIdentifierParserE
	.section	.data.rel.ro._ZTIN3svs22SimpleIdentifierParserE,"awG",@progbits,_ZTIN3svs22SimpleIdentifierParserE,comdat
	.align 8
	.type	_ZTIN3svs22SimpleIdentifierParserE, @object
	.size	_ZTIN3svs22SimpleIdentifierParserE, 24
_ZTIN3svs22SimpleIdentifierParserE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN3svs22SimpleIdentifierParserE
	.quad	_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.weak	_ZTSN3svs22SimpleIdentifierParserE
	.section	.rodata._ZTSN3svs22SimpleIdentifierParserE,"aG",@progbits,_ZTSN3svs22SimpleIdentifierParserE,comdat
	.align 16
	.type	_ZTSN3svs22SimpleIdentifierParserE, @object
	.size	_ZTSN3svs22SimpleIdentifierParserE, 31
_ZTSN3svs22SimpleIdentifierParserE:
	.string	"N3svs22SimpleIdentifierParserE"
	.weak	_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.section	.data.rel.ro._ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,"awG",@progbits,_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,comdat
	.align 8
	.type	_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, @object
	.size	_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, 16
_ZTIN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.weak	_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE
	.section	.rodata._ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,"aG",@progbits,_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE,comdat
	.align 32
	.type	_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, @object
	.size	_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE, 68
_ZTSN3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE:
	.string	"N3svs6ParserINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE"
	.weak	_ZTIN3svs6ParserIcEE
	.section	.data.rel.ro._ZTIN3svs6ParserIcEE,"awG",@progbits,_ZTIN3svs6ParserIcEE,comdat
	.align 8
	.type	_ZTIN3svs6ParserIcEE, @object
	.size	_ZTIN3svs6ParserIcEE, 16
_ZTIN3svs6ParserIcEE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN3svs6ParserIcEE
	.weak	_ZTSN3svs6ParserIcEE
	.section	.rodata._ZTSN3svs6ParserIcEE,"aG",@progbits,_ZTSN3svs6ParserIcEE,comdat
	.align 16
	.type	_ZTSN3svs6ParserIcEE, @object
	.size	_ZTSN3svs6ParserIcEE, 17
_ZTSN3svs6ParserIcEE:
	.string	"N3svs6ParserIcEE"
	.section	.text._ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev,"axG",@progbits,_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED5Ev,comdat
	.align 2
	.weak	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev
	.type	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev, @function
_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev:
.LFB4253:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4253:
	.size	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev, .-_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev
	.weak	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED1Ev
	.set	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED1Ev,_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED2Ev
	.section	.text._ZN3svs15CharacterParserD2Ev,"axG",@progbits,_ZN3svs15CharacterParserD5Ev,comdat
	.align 2
	.weak	_ZN3svs15CharacterParserD2Ev
	.type	_ZN3svs15CharacterParserD2Ev, @function
_ZN3svs15CharacterParserD2Ev:
.LFB4255:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTVN3svs15CharacterParserE(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt13unordered_setIcSt4hashIcESt8equal_toIcESaIcEED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4255:
	.size	_ZN3svs15CharacterParserD2Ev, .-_ZN3svs15CharacterParserD2Ev
	.weak	_ZN3svs15CharacterParserD1Ev
	.set	_ZN3svs15CharacterParserD1Ev,_ZN3svs15CharacterParserD2Ev
	.section	.text._ZN3svs9AnyParserIcED2Ev,"axG",@progbits,_ZN3svs9AnyParserIcED5Ev,comdat
	.align 2
	.weak	_ZN3svs9AnyParserIcED2Ev
	.type	_ZN3svs9AnyParserIcED2Ev, @function
_ZN3svs9AnyParserIcED2Ev:
.LFB4258:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	16+_ZTVN3svs9AnyParserIcEE(%rip), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4258:
	.size	_ZN3svs9AnyParserIcED2Ev, .-_ZN3svs9AnyParserIcED2Ev
	.weak	_ZN3svs9AnyParserIcED1Ev
	.set	_ZN3svs9AnyParserIcED1Ev,_ZN3svs9AnyParserIcED2Ev
	.text
	.type	_Z41__static_initialization_and_destruction_0v, @function
_Z41__static_initialization_and_destruction_0v:
.LFB4250:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4250
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	leaq	_ZL17underscore_parser(%rip), %rax
	movl	$95, %esi
	movq	%rax, %rdi
.LEHB15:
	call	_ZN3svs15CharacterParserC1Ec@PLT
.LEHE15:
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZL17underscore_parser(%rip), %rcx
	leaq	_ZN3svs15CharacterParserD1Ev(%rip), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
	leaq	C.22.0(%rip), %r12
	movl	$2, %r13d
	leaq	-73(%rbp), %rax
	movq	%rax, -72(%rbp)
	nop
	nop
	leaq	-73(%rbp), %rdx
	movq	%r12, %rsi
	movq	%r13, %rdi
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	movq	%rdi, %rdx
	movq	%rax, %rdi
.LEHB16:
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EEC1ESt16initializer_listIS3_ERKS4_
.LEHE16:
	leaq	-64(%rbp), %rax
	leaq	_ZL40simple_identifier_first_character_parser(%rip), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
.LEHB17:
	call	_ZN3svs9AnyParserIcEC1ESt6vectorIPNS_6ParserIcEESaIS5_EE
.LEHE17:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED1Ev
	leaq	-73(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZL40simple_identifier_first_character_parser(%rip), %rcx
	leaq	_ZN3svs9AnyParserIcED1Ev(%rip), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
	nop
	movq	-40(%rbp), %rax
	subq	%fs:40, %rax
	je	.L274
	jmp	.L277
.L276:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt6vectorIPN3svs6ParserIcEESaIS3_EED1Ev
	jmp	.L272
.L275:
	movq	%rax, %rbx
.L272:
	leaq	-73(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPN3svs6ParserIcEEED2Ev
	nop
	movq	%rbx, %rax
	movq	-40(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L273
	call	__stack_chk_fail@PLT
.L273:
	movq	%rax, %rdi
.LEHB18:
	call	_Unwind_Resume@PLT
.LEHE18:
.L277:
	call	__stack_chk_fail@PLT
.L274:
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4250:
	.section	.gcc_except_table
.LLSDA4250:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4250-.LLSDACSB4250
.LLSDACSB4250:
	.uleb128 .LEHB15-.LFB4250
	.uleb128 .LEHE15-.LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB16-.LFB4250
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L275-.LFB4250
	.uleb128 0
	.uleb128 .LEHB17-.LFB4250
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L276-.LFB4250
	.uleb128 0
	.uleb128 .LEHB18-.LFB4250
	.uleb128 .LEHE18-.LEHB18
	.uleb128 0
	.uleb128 0
.LLSDACSE4250:
	.text
	.size	_Z41__static_initialization_and_destruction_0v, .-_Z41__static_initialization_and_destruction_0v
	.section	.text._ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev,"axG",@progbits,_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED5Ev,comdat
	.align 2
	.weak	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev
	.type	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev, @function
_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev:
.LFB4263:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4263:
	.size	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev, .-_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev
	.weak	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED1Ev
	.set	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED1Ev,_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED2Ev
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED5Ev,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev:
.LFB4265:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8__detail21_Hashtable_ebo_helperISaINS_10_Hash_nodeIcLb0EEEELb1EED1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4265:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED1Ev
	.set	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED1Ev,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev
	.section	.text._ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev,"axG",@progbits,_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED5Ev,comdat
	.align 2
	.weak	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev
	.type	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev, @function
_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev:
.LFB4267:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4267
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEED2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4267:
	.section	.gcc_except_table
.LLSDA4267:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4267-.LLSDACSB4267
.LLSDACSB4267:
.LLSDACSE4267:
	.section	.text._ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev,"axG",@progbits,_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED5Ev,comdat
	.size	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev, .-_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev
	.weak	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED1Ev
	.set	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED1Ev,_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEED2Ev
	.section	.text._ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv,"axG",@progbits,_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv,comdat
	.align 2
	.weak	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv
	.type	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv, @function
_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv:
.LFB4272:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4272:
	.size	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv, .-_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE8_M_beginEv
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_:
.LFB4273:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	jmp	.L284
.L285:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv
	movq	%rax, -32(%rbp)
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_
.L284:
	cmpq	$0, -32(%rbp)
	jne	.L285
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4273:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE19_M_deallocate_nodesEPS2_
	.section	.text._ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv,"axG",@progbits,_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv,comdat
	.align 2
	.weak	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv
	.type	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv, @function
_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv:
.LFB4274:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4274:
	.size	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv, .-_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEv
	.section	.text._ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev,"axG",@progbits,_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED5Ev,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev
	.type	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev, @function
_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev:
.LFB4276:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4276:
	.size	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev, .-_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev
	.weak	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED1Ev
	.set	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED1Ev,_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEED2Ev
	.section	.text._ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv,"axG",@progbits,_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv,comdat
	.align 2
	.weak	_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv
	.type	_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv, @function
_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv:
.LFB4278:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4278:
	.size	_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv, .-_ZNKSt8__detail10_Hash_nodeIcLb0EE7_M_nextEv
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_:
.LFB4279:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv
	movq	%rax, %rbx
	nop
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv
	movq	%rax, -56(%rbp)
	movq	%rbx, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	nop
	nop
	movq	-80(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4279:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE18_M_deallocate_nodeEPS2_
	.section	.text._ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm,"axG",@progbits,_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm,comdat
	.align 2
	.weak	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm
	.type	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm, @function
_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm:
.LFB4281:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE
	testb	%al, %al
	jne	.L295
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm
	jmp	.L292
.L295:
	nop
.L292:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4281:
	.size	_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm, .-_ZNSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_deallocate_bucketsEPPNS1_15_Hash_node_baseEm
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv:
.LFB4282:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4282:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_:
.LFB4285:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$1, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4285:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE22_M_deallocate_node_ptrEPS2_
	.section	.text._ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE,"axG",@progbits,_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE,comdat
	.align 2
	.weak	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE
	.type	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE, @function
_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE:
.LFB4286:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	addq	$48, %rax
	cmpq	%rax, -16(%rbp)
	sete	%al
	movzbl	%al, %eax
	testq	%rax, %rax
	setne	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4286:
	.size	_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE, .-_ZNKSt10_HashtableIccSaIcENSt8__detail9_IdentityESt8equal_toIcESt4hashIcENS1_18_Mod_range_hashingENS1_20_Default_ranged_hashENS1_20_Prime_rehash_policyENS1_17_Hashtable_traitsILb0ELb1ELb1EEEE21_M_uses_single_bucketEPPNS1_15_Hash_node_baseE
	.section	.text._ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm,"axG",@progbits,_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm,comdat
	.align 2
	.weak	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm
	.type	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm, @function
_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm:
.LFB4287:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%rdx, -88(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_
	movq	%rax, -48(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE17_M_node_allocatorEv
	movq	%rax, -24(%rbp)
	leaq	-49(%rbp), %rax
	movq	%rax, -16(%rbp)
	nop
	nop
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rdx
	movq	-40(%rbp), %rcx
	leaq	-49(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m
	nop
	leaq	-49(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	nop
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L302
	call	__stack_chk_fail@PLT
.L302:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4287:
	.size	_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm, .-_ZNSt8__detail16_Hashtable_allocISaINS_10_Hash_nodeIcLb0EEEEE21_M_deallocate_bucketsEPPNS_15_Hash_node_baseEm
	.section	.text._ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv
	.type	_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv, @function
_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv:
.LFB4288:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4288:
	.size	_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv, .-_ZN9__gnu_cxx16__aligned_bufferIcE6_M_ptrEv
	.section	.text._ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_,"axG",@progbits,_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_,comdat
	.weak	_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_
	.type	_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_, @function
_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_:
.LFB4290:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4290:
	.size	_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_, .-_ZNSt19__ptr_traits_ptr_toIPNSt8__detail10_Hash_nodeIcLb0EEES2_Lb0EE10pointer_toERS2_
	.section	.text._ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_,"axG",@progbits,_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_,comdat
	.weak	_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_
	.type	_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_, @function
_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_:
.LFB4292:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4292:
	.size	_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_, .-_ZNSt19__ptr_traits_ptr_toIPPNSt8__detail15_Hash_node_baseES2_Lb0EE10pointer_toERS2_
	.section	.text._ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv,"axG",@progbits,_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv,comdat
	.align 2
	.weak	_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv
	.type	_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv, @function
_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv:
.LFB4300:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4300:
	.size	_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv, .-_ZN9__gnu_cxx16__aligned_bufferIcE7_M_addrEv
	.section	.text._ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m,"axG",@progbits,_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m
	.type	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m, @function
_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m:
.LFB4302:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4302:
	.size	_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m, .-_ZNSt15__new_allocatorINSt8__detail10_Hash_nodeIcLb0EEEE10deallocateEPS2_m
	.section	.text._ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev,"axG",@progbits,_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED5Ev,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	.type	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev, @function
_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev:
.LFB4308:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4308:
	.size	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev, .-_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	.weak	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED1Ev
	.set	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED1Ev,_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEED2Ev
	.section	.text._ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m,"axG",@progbits,_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m,comdat
	.align 2
	.weak	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m
	.type	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m, @function
_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m:
.LFB4310:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZdlPvm@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4310:
	.size	_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m, .-_ZNSt15__new_allocatorIPNSt8__detail15_Hash_node_baseEE10deallocateEPS2_m
	.text
	.type	_GLOBAL__sub_I__ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, @function
_GLOBAL__sub_I__ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_:
.LFB4313:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	_Z41__static_initialization_and_destruction_0v
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4313:
	.size	_GLOBAL__sub_I__ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_, .-_GLOBAL__sub_I__ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZNK3svs22SimpleIdentifierParser5parseERKN9__gnu_cxx17__normal_iteratorIPKcNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEESD_
	.section	.data.rel.ro.local,"aw"
	.align 16
	.type	C.22.0, @object
	.size	C.22.0, 16
C.22.0:
	.quad	_ZL17underscore_parser
	.quad	_ZL27alphabetic_character_parser
	.weak	__cxa_pure_virtual
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.globl	__gxx_personality_v0
	.ident	"GCC: (GNU) 15.1.1 20250425"
	.section	.note.GNU-stack,"",@progbits
