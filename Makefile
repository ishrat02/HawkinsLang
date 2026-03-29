CC=gcc
WINFLEXBISON_DIR ?= C:/Users/HP/AppData/Local/Microsoft/WinGet/Packages/WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe
FLEX ?= $(WINFLEXBISON_DIR)/win_flex.exe
BISON ?= $(WINFLEXBISON_DIR)/win_bison.exe
CFLAGS=-g
FINAL_OUTPUT=program_output.txt
SHELL := cmd
.SHELLFLAGS := /C

all: hawkinslang.exe

hawkinslang.tab.c hawkinslang.tab.h: hawkinslang.y
	"$(BISON)" -d hawkinslang.y

lex.yy.c: hawkinslang.l hawkinslang.tab.h
	"$(FLEX)" hawkinslang.l

hawkinslang.exe: hawkinslang.tab.c lex.yy.c ast.c
	$(CC) $(CFLAGS) -o hawkinslang hawkinslang.tab.c lex.yy.c ast.c

run: hawkinslang.exe
	hawkinslang.exe input.hawkins > output.c
	$(CC) $(CFLAGS) -o program.exe output.c
	-program.exe > $(FINAL_OUTPUT)

clean:
	-del /Q /F hawkinslang.exe output.c program.exe $(FINAL_OUTPUT) hawkinslang.tab.c hawkinslang.tab.h lex.yy.c
