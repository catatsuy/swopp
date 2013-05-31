PANDOC = pandoc.my
OPTS_SET = -f markdown -t latex --include-in-header header.tex -s
OPTS_VAR = -V documentclass=ipsj -V addoption=submit,techreq,noauthor,papersize

INPUT = top.tex
OUTPUT = main.tex
OUTPUTDVI = $(OUTPUT:%.tex=%.dvi)

all:
	make topdf
addtoc:
	platex $(OUTPUT)
	make topdf
tolatex:
	ruby pandoc.rb
	$(PANDOC) $(OPTS_SET) $(INPUT) $(OPTS_VAR) -o $(OUTPUT)
topdf:
	platex $(OUTPUT)
	dvipdfmx $(OUTPUTDVI)
