.DEFAULT_GOAL := test
.PHONY: build test bless

build:
	tree-sitter generate

test:
	@$(MAKE) --no-print-directory build
	tree-sitter test
	# watchexec --clear dune test

bless:
	@$(MAKE) --no-print-directory build
	tree-sitter test --update
