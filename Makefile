.PHONY : all re clean fclean

run: all
	./test_gnl file

run1: all
	./test_gnl file file1

all:
	@make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f get_next_line.o main.o && make -C libft/ clean

fclean: clean
	rm -f test_gnl && make -c libft/ fclean

re: fclean all