all:
	swig -c++ -python -py3 levenshtein.i
	python3 setup.py install

.PHONY: clean
clean:
	rm -rf build; \
	    rm -f levenshtein_wrap.cxx; \
	    rm -f levenshtein.py; \
	    rm -f levenshtein.pyc; \
	    rm -f _levenshtein.so; \
	    rm -f _levenshtein_distance.py; \
	    rm -rf __pycache__
