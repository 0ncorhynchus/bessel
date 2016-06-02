
.PHONY: all
all: sphj_test

.cpp.o:
	$(CXX) -c -o $@ $<

sphj_test: sphj_test.cpp sphj.o
	$(CXX) -o $@ $^
