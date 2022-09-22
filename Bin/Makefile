
COMPILER := gcc

#Add your File.c
C_FILES := ../project/main.c
C_FILES += ../project/functions.c



#Add your File.o
O_FILES := main.o
O_FILES += functions.o


EXE_FILES := DATAMODULE.exe

all: clean linking

build: $(C_FILES)
	@$(COMPILER) -c $(C_FILES)
linking: build 	
	@$(COMPILER) $(O_FILES) -o $(EXE_FILES)
clean:
	rm -rf *.o *.exe