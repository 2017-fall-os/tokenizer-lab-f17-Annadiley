all: tokenizer

tokenizer: mytoc.c
	$(CC) $(CFLAGS) -o tokenizer mytoc.c 
clean:
	$(RM) *.o tokenizer
run:
	./tokenizer
