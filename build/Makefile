
all: preprocess linux_amd64

linux_amd64:
	$(MAKE) -C ../wx/linux_amd64 all

preprocess:
	if [ -d "../src/wxGoInterface" ]; then rm -r ../src/wxGoInterface; fi
	python2 preprocess.py ../src/wxGoInterface_original ../src/wxGoInterface