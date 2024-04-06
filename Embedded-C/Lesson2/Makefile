
CC=arm-none-eabi
CFLAGS=-g -mcpu=arm926ej-s
INCS=  -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=learn-in-depth


all: $(Project_name).bin
	@echo build is done 


%.o: %.c 
	$(CC)-gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

startup.o: startup.s
	$(CC)-as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)-objcopy.exe -O binary $< $@
	 
clean_all: 
	rm *.o *.elf *.bin
clean: 
	rm *.elf *.bin
	`