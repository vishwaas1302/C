.PHONY: run run-line-replace clean

run: line.c
	gcc -w -o line line.c
	./line

run-line-replace: line_replace.c
	gcc -w -o line_replace line_replace.c
	./line_replace

run-line-replace-char: line_replace_char.c
	gcc -w -o line_replace_char line_replace_char.c
	./line_replace_char

run-word-count: word_count.c
	gcc -w -o word_count word_count.c
	./word_count

run-word-histogram: word_histogram.c
	gcc -w -o word_histogram word_histogram.c
	./word_histogram

run-longest-line: longest_line.c
	gcc -w -o longest_line longest_line.c
	./longest_line

clean:
	rm -f line line_replace line_replace_char word_count word_histogram longest_line