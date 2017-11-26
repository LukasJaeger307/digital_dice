P = digital_dice

SRCDIR = src
HDIR = include
BINDIR = bin
OBJDIR = obj
DOCDIR = doc

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(HDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


CC = gcc
CROSS = msp430
CROSS_COMPILE = ${CROSS}-${CC}
MACHINEFLAGS=-mmcu=msp430g2553
CFLAGS = -Os -g -Iinclude -Wextra -std=c99 $(MACHINEFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CROSS_COMPILE) -c -o $@ $< $(CFLAGS)
	
$(BINDIR)/$(P) : folders $(OBJECTS)
	$(CROSS_COMPILE) $(OBJECTS) $(MACHINEFLAGS) -o $(BINDIR)/$(P)
		
$(BINDIR):
	mkdir $(BINDIR)
			
$(OBJDIR):
	mkdir $(OBJDIR)
				
$(DOCDIR):
	mkdir $(DOCDIR)
					
folders : $(BINDIR) $(OBJDIR)
							
install : $(BINDIR)/$(P)
	mspdebug rf2500 "prog $(BINDIR)/$(P)"
								
clean : $(BINDIR)/$(P) $(FOLDERS)
	rm -f $(OBJDIR)/*.o $(BINDIR)/*.hex $(BINDIR)/*.elf
	rm -rf $(OBJDIR)
	rm -rf $(DOCDIR)
													
documentation : $(DOCDIR) $(SOURCES) $(INCLUDES)
	doxygen Doxyfile

git : 
	git add COPYING include/*.h src/*.c Makefile .gitignore Doxyfile
	git status
