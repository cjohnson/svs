#!/bin/sh

python cpplint.py \
	--exclude src/compiler/sv2017/parser_impl.cpp \
	--exclude src/compiler/sv2017/parser_impl.h \
	--exclude src/compiler/sv2017/scanner_impl.h \
	--exclude src/compiler/sv2017/scanner_impl.cpp \
	--exclude src/compiler/sv2017/location.hh \
	--recursive src
