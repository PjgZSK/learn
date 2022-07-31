PROJECT=localutils
SUBDIR=$(shell ls -d */)
INCLUDE=$(SUBDIR)
CPPFLAGS=$(foreach dir, $(INCLUDE), -I$(dir)) -g -std=c++11
LDFLAGS=
BUILDDIR=build
ROOTSRCS=$(wildcard *.cpp)
ROOTOBJS=$(patsubst %.cpp, %.o, $(ROOTSRCS))
SUBSRCS=$(shell find $(SUBDIR) -name '*.cpp')
SUBOBJS=$(patsubst %.cpp, %.o, $(SUBSRCS))
CC=g++
LD=g++

.PHONY:all
all:$(BUILDDIR) $(BUILDDIR)/$(PROJECT)

$(BUILDDIR):
	mkdir $@

$(BUILDDIR)/$(PROJECT):$(ROOTOBJS)$(SUBOBJS)
	$(LD)$(LDFLAGS) $(foreach obj, $(^), $(BUILDDIR)/$(notdir $(obj))) -o $@

%.o:%.cpp
	$(CC)$(CPPFLAGS) -c $< -o $(BUILDDIR)/$(notdir $@)

.PHONY:print
print:
	@echo $(BUILDDIR)/$(PROJECT)
	@echo $(ROOTOBJS)$(SUBOBJS)
	@echo $(ROOTOBJS)
	@echo $(SUBOBJS)
	@echo $(SUBSRCS)
	@echo $(SUBDIR)
	

.PHONY:clean
clean:
	rm -rf $(BUILDDIR)
	
