CXXFLAGS =-Wall -Wextra -Werror -s -I.
SOURCES ?=src

main: $(SOURCES)/Shelter.cpp

clean:
	rm -f main
