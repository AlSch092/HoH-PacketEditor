;//Made by AlSch092 @ github
.data

EXTERN g_LogSendPacketReturnAddress: dq
EXTERN g_LogSendPacketCallback: dq
EXTERN g_SendKeyPtr: dq

.code

EncryptSendPacketHook PROC 
	
    pop r10 ;our hook code pushes r10, so reverse that instruction here with a pop

    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push rsp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
    pushfq

    mov rax, 7FF7EDA84A69h ; key rotates 3~ times using junk data? after sending one valid packet?  -> return addr check, don't log data in these cases
    cmp [rsp+88h], rax
    je back

    sub rsp, 1028h
    mov g_SendKeyPtr, rcx
    mov rcx, rdx  ;buffer
    mov rdx, r8  ;len
    mov r8, 1 ; isSendPacket = true
    call g_LogSendPacketCallback 
    add rsp, 1028h

back:
    popfq
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rsp
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax

    mov [rsp+20h], r9
    jmp g_LogSendPacketReturnAddress

EncryptSendPacketHook ENDP


EncryptSendPacket PROC

        mov [rsp+20h],r9
        mov [rsp+18h],r8d
        mov [rsp+10h],rdx
        mov [rsp+08h],rcx
        sub rsp,18h
        cmp qword ptr [rsp+20h],00
        jne cmp_1
        mov eax,00000010h
        jmp ending
cmp_1:
	cmp qword ptr [rsp+28h],00
	jne cmp_2
	mov eax,00000010h
	jmp ending
cmp_2:
	cmp qword ptr [rsp+38h],00
	jne normal_1
	mov eax,00000010h
	jmp ending
normal_1:
	mov rax,[rsp+20h]
	movzx eax,byte ptr [rax]
	mov [rsp],al
	mov rax,[rsp+20h]
	movzx eax,byte ptr [rax+04h]
	mov [rsp+01h],al
	mov rax,[rsp+20h]
	add rax,08h
	mov [rsp+08h],rax
Loop1:
	mov eax,[rsp+30h]
	mov [rsp+04],eax
	mov eax,[rsp+30h]
	dec eax
	mov [rsp+30h],eax
	cmp dword ptr [rsp+04],00
	je normal_2
	movzx eax,byte ptr [rsp]
	inc eax
	and eax,000000FFh
	mov [rsp],al
	movzx eax,byte ptr [rsp+01]
	movzx ecx,byte ptr [rsp]
	mov rdx,[rsp+08h]
	movzx ecx,byte ptr [rdx+rcx]
	add eax,ecx
	and eax,000000FFh
	mov [rsp+01],al
	movzx eax,byte ptr [rsp]
	mov rcx,[rsp+08]
	movzx eax,byte ptr [rcx+rax]
	mov [rsp+02],al
	movzx eax,byte ptr [rsp+01]
	movzx ecx,byte ptr [rsp]
	mov rdx,[rsp+08]
	mov r8,[rsp+08]
	movzx eax,byte ptr [r8+rax]
	mov [rdx+rcx],al
	movzx eax,byte ptr [rsp+01]
	mov rcx,[rsp+08]
	movzx edx,byte ptr [rsp+02]
	mov [rcx+rax],dl
	movzx eax,byte ptr [rsp]
	mov rcx,[rsp+08]
	movzx eax,byte ptr [rcx+rax]
	movzx ecx,byte ptr [rsp+01]
	mov rdx,[rsp+08]
	movzx ecx,byte ptr [rdx+rcx]
	add eax,ecx
	and eax,000000FFh
	mov [rsp+02],al
	mov rax,[rsp+28h]
	movzx eax,byte ptr [rax]
	movzx ecx,byte ptr [rsp+02]
	mov rdx,[rsp+08]
	movzx ecx,byte ptr [rdx+rcx]
	xor eax,ecx
	mov rcx,[rsp+38h]
	mov [rcx],al
	mov rax,[rsp+38h]
	inc rax
	mov [rsp+38h],rax
	mov rax,[rsp+28h]
	inc rax
	mov [rsp+28h],rax
	jmp Loop1
normal_2:
	movzx eax,byte ptr [rsp]
	mov rcx,[rsp+20h]
	mov [rcx],eax
	movzx eax,byte ptr [rsp+01]
	mov rcx,[rsp+20h]
	mov [rcx+04],eax
	xor eax,eax
ending:
	add rsp,18h
	ret 

EncryptSendPacket ENDP

END
