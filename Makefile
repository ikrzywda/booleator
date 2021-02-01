build:
	gcc -o bootor src/*.c
debug:
	gcc -o bootor -fsanitize=address -Wpadded src/*.c
