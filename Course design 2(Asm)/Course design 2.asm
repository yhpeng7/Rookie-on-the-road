assume cs:code,ss:stack

stack segment
		db 128 dup (0)
stack ends

code segment		
start:
		mov bx,stack
		mov ss,bx
		mov sp,128
		
		call cpy_boot
		call save_old_int9
		
		mov bx,0
		push bx
		mov bx,7e00H
		push bx
		retf
		
		mov ax,4c00H
		int 21H

;============================================================================
cpy_boot:
		mov bx,cs
		mov ds,bx
		mov si,offset boot
		mov bx,0
		mov es,bx
		mov di,7e00H
		mov cx,offset boot_end - offset boot
		
		cld
		rep movsb
				
		ret
;============================================================================

boot:	jmp program
;============================================================================		
;============================================================================		
		a 	db "1) reset pc",0							
		b 	db "2) start system",0
		c 	db "3) clock",0
		d 	db "4) set clock",0
		x 	dw		offset a - offset boot + 7e00H
			dw		offset b - offset boot + 7e00H
			dw		offset c - offset boot + 7e00H
			dw		offset d - offset boot + 7e00H
			
		CLOCK	db 9,8,7,4,2,0
		STYLE 	db "YY/MM/DD HH:MM:SS",0
;============================================================================		
;============================================================================
program:	
		call init_reg
		call clear_screen
		call show_option
		call choose_option
		
cir:	mov ax,1000H
		jmp cir
		mov ax,4c00H
		int 21H
;============================================================================
		
init_reg:
		mov bx,0b800H
		mov es,bx
		mov bx,cs
		mov ds,bx	

		ret
;============================================================================		
clear_screen:
		mov di,0
		mov cx,2000
clear:	mov word ptr es:[di],0700H				;0700H。。。
		add di,2
		loop clear

		ret
;============================================================================		
show_option:
		mov bx,offset x - offset boot + 7e00H	
		mov cx,4
		mov di,160*10+30*2
		
showoption:	
		mov si,ds:[bx]								;wrong1!
		call show_string
		add bx,2						;add bx,21
		add di,160
		loop showoption
		
		ret
;============================================================================
show_string:
		push di
		push si
		push dx

showstring:		
		mov dl,ds:[si]
		cmp dl,0
		je show_stringREt
		mov es:[di],dl
		inc si
		add di,2
		jmp showstring
			
show_stringREt:
		pop dx
		pop si
		pop di
		ret
;============================================================================
clear_buff:
		mov ah,1
		int 16H
		jz clear_buffRet
		mov ah,0
		int 16H
		jmp clear_buff
		
clear_buffRet:		
		ret
;============================================================================		
choose_option:
		call clear_buff
		
		mov ah,0
		int 16H
		
		cmp al,'1'
		je isChooseOne
		
		cmp al,'2'
		je isChooseTwo	
		
		cmp al,'3'
		je isChooseThree
		
		cmp al,'4'
		je isChooseFour	
		
		jmp choose_option
		
		ret
;============================================================================	
isChooseOne:

		jmp choose_option
;=========================================
isChooseTwo:

		jmp choose_option
;==================================================================================
isChooseThree:
		call show_theclock	
		jmp program
;============================================================================
show_theclock:	
		call show_clock
		call set_new_int9
		mov bx,offset CLOCK - offset boot + 7e00H
		
showtime:	
		mov si,bx
		mov di,160*20
		mov cx,6
		
show_time:
		mov al,ds:[si]
		out 70H,al
		in al,71H
		
		mov ah,al
		shr ah,1						;此处使用mov cl,4   
		shr ah,1						;			 shr ah,cl,时一定要push pop
		shr ah,1
		shr ah,1
		and al,00001111B
		
		add ah,30H
		add al,30H
		
		mov es:[di],ah
		mov es:[di+2],al
		inc si
		add di,6

		loop show_time
		jmp showtime

showtimeRet:
		call set_old_int9
		ret
;============================================================================
set_old_int9:
		push bx
		push es

		mov bx,0
		mov es,bx
		
		cli
		push es:[200H]
		pop es:[9*4]
		push es:[202H]
		pop es:[9*4+2]
		sti

		pop es
		pop bx
		ret
;============================================================================
isChooseFour:

		jmp choose_option
;============================================================================
show_clock:
		push si
		push di
		
		mov si,offset STYLE - offset boot +7e00H
		mov di,160*20
		call show_string
		
		pop di
		pop si
		
		ret
;============================================================================
new_int9:
		push ax
		call clear_buff
		
		in al,60H							;模拟int9中断例程
		pushf
		call dword ptr cs:[200H]			;cs自动设置为0
		
		cmp al,01H
		je isEsc
		
		cmp al,3bH
		jne new_int9Ret
		call change_color		 
		
new_int9Ret:
		pop ax	
		iret
;============================================================================
isEsc:
		pop ax 								;模拟new_int9Ret
		add sp,4
		popf
		
		jmp showtimeRet
;============================================================================
change_color:
		push es
		push di
		push cx

		mov di,0b800H
		mov es,di
		mov di,160*20+1
		mov cx,17
change:	
		inc byte ptr es:[di]
		add di,2
		loop change
		
		pop cx
		pop di
		pop es
		
		ret
;============================================================================
set_new_int9:
		push es
		push bx
		
		mov bx,0
		mov es,bx
		
		cli
		mov word ptr es:[9*4],offset new_int9 - offset boot + 7e00H
		mov word ptr es:[9*4+2],0
		sti

		pop bx
		pop es		
		ret
;============================================================================
save_old_int9:
		push es
		push bx
		
		mov bx,0
		mov es,bx
		push es:[9*4]					;以字为单位进行传输
		pop es:[200H]
		push es:[9*4+2]
		pop es:[202H]
		
		pop bx
		pop es
		
		ret
;============================================================================
boot_end:
		nop

code ends
end start