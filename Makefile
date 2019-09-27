Gcc=g++
gccFlag=-c
app=circularBuffer

all: $(app)

$(app): main.o CircularBuffer.o
	$(Gcc) -o $@ $^

main.o: main.cpp
	$(Gcc) $(gccFlag) $<

CircularBuffer.o: CircularBuffer.cpp
	$(Gcc) $(gccFlag) $<

clean:
	rm *o *~ $(app)

