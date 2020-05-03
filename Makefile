CXXFLAGS =-Wall -Wextra -Werror -s -I./include
FILES = main
main: $(FILES).cpp

clean:
	rm -f $(FILES)
