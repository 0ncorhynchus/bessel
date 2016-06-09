
.PHONY: all
all: specfun_test

.cpp.o:
	$(CXX) -c -o $@ $<

specfun_test: specfun_test.cpp sphj.o sphy.o
	$(CXX) -o $@ $^
