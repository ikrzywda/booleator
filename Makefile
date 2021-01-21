cln:
	gcc -o bootor src/*.c
sanitize:
	gcc -o bootor -fsanitize=address src/*.c
