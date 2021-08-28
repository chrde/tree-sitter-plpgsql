.DEFAULT_GOAL := build
.PHONY: build test bless

build:
	tree-sitter generate

test:
	@$(MAKE) --no-print-directory build
	tree-sitter test

bless:
	@$(MAKE) --no-print-directory build
	tree-sitter test --update
