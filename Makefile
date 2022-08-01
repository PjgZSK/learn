PROJECT=localutils
SUBDIR=$(shell ls -d */)
INCLUDE=$(SUBDIR)
CPPFLAGS=$(foreach dir, $(INCLUDE), -I$(dir)) -g -std=c++11
LDFLAGS=
SRCS=$(shell find . -name "*.cpp")
OBJS=$(SRCS:%.cpp=%.o)
CC=g++
LD=g++

$(PROJECT):$(OBJS)
	$(LD)$(LDFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

.PHONY:clean
clean:
	find ./ -name "*.o" | xargs rm -f
	rm -f $(PROJECT)
	
