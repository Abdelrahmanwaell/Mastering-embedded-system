
CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g -mthumb 
INCS=  -I .
LIBS=
SRC=$(wildcard *.c)
STARTUP_FILE = $(wildcard startup.c startup.s)
STARTUP_OBJ = $(patsubst %.c,%.o,$(patsubst %.s,%.o,$(STARTUP_FILE)))
OBJ=$(SRC:.c=.o) #$(STARTUP_OBJ)
Project_name=learn-in-depth_cortexM4
#STARTUP_FILE=$(wildcard startup*)

all: $(Project_name).bin
	@echo build is done 

%.o: %.s 
	$(CC)-as.exe  $(CFLAGS) $< -o $@

%.o: %.c 
	$(CC)-gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@



$(Project_name).elf: $(OBJ) 
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
$(Project_name).bin: $(Project_name).elf
	$(CC)-objcopy.exe -O binary $< $@
	 
clean_all: 
	rm *.o *.elf *.bin *.hex
clean: 
	rm *.elf *.bin *.hex
	`