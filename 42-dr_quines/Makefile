F= -Wall -Werror -Wextra
C= clang

all:
	$(C) $(F) -o Colleen Colleen.c
	$(C) $(F) -o Grace Grace.c
	$(C) $(F) -o Sully Sully.c

clean:
	rm -f Grace_kid.c

fclean: clean
	rm -f Sully
	rm -f Grace
	rm -f Colleen

re: fclean all

.PHONY: fclean re all clean
