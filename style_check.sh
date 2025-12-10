#!/bin/sh

python cpplint.py \
	--exclude src/compiler/sv2017/parser.generated.cpp \
	--exclude src/compiler/sv2017/parser.generated.h \
	--exclude src/compiler/sv2017/scanner.generated.h \
	--exclude src/compiler/sv2017/scanner.generated.cpp \
	--exclude src/compiler/sv2017/location.hh \
	--recursive src
