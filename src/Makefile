cc = gcc
CFLAGS = -g -Wall
SRCS = factorize.c narcissus.c prime.c rabit.c
OBJECTS = $(SRCS:%.c=%.o)
TARGETS = $(SRCS:%.c=%)
all:$(TARGETS)
clean:
	rm -rf $(TARGETS) $(OBJECTS)
echo:
	@echo $(TARGETS)
