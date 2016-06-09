
.PHONY: all
all: sphj_test specfun_test

.cpp.o:
	$(CXX) -c -o $@ $<

sphj_test: sphj_test.cpp sphj.o
	$(CXX) -o $@ $^

specfun_test: specfun_test.cpp sphj.o sphy.o
	$(CXX) -o $@ $^
