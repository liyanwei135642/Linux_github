cc=gcc
mb=proc 
yu=main.o proc.o
$(mb):$(yu) 
	$(cc) $(yu) -o $(mb) 
%.o:%.c
	$(cc) -c $<
.PHONY:clean
clean:
	rm -f $(mb) $(yu)

