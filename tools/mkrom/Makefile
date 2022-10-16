C_FILES = $(wildcard *.c)

%.o: %.c
	gcc -O3 %< -o $@

mkrom: $(C_FILES)
	gcc -Wno-unused-result -O3 $(C_FILES) -o mkrom
