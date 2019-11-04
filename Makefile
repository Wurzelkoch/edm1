# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++                        # compiler to use
AP = cpp
EXEC = TreeIsomorphism 		# Executable Name

LINKERFLAG = -lm

SRCS := $(wildcard *.cpp)
OBJS := ${SRCS:.$(AP)=.o}

all: ${EXEC}

${EXEC}: $(OBJS)
	@echo "Checking.."
	@echo ${OBJS}
	${CC} ${LINKERFLAG} $(OBJS) -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} -c $<

clean:
	@echo "Cleaning up..."
	rm -rvi *.o ${OBJS}
