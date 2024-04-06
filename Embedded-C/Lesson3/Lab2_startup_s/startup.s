.section .vectors
.word 0x20001000         /*stack top address*/
.word _reset             /*reset*/
.word Vector_handler     /*NMI*/
.word Vector_handler     /*hard fault*/
.word Vector_handler     /*memory management fault*/
.word Vector_handler     /*bus fault*/
.word Vector_handler     /*usage fault*/
.word Vector_handler     /*reserved*/ 
.word Vector_handler	 /*reserved*/
.word Vector_handler	 /*reserved*/
.word Vector_handler	 /*reserved*/
.word Vector_handler	 /*SV call*/
.word Vector_handler	 /*Debug monitor*/
.word Vector_handler	 /*reserved*/	
.word Vector_handler	 /*PendSV
.word Vector_handler	 /*Systick*/
.word Vector_handler     /*IRQ0*/
.word Vector_handler	 /*IRQ1*/
.word Vector_handler	 /*IRQ2*/
.word Vector_handler	 /*...*/
		/*on to IRQ67*/



.section .text


_reset:

	bl main
	b . 


.thumb_func



Vector_handler:
	b _reset





	 


