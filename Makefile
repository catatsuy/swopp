OUTPUT = main.tex
OUTPUTDVI = $(OUTPUT:%.tex=%.dvi)

all:
	make topdf
addtoc:
	platex $(OUTPUT)
	make topdf
topdf:
	platex $(OUTPUT)
	dvipdfmx $(OUTPUTDVI)
