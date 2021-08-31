.DEFAULT_GOAL := g
.PHONY: g t b

g:
	tree-sitter generate

t:
	# @$(MAKE) --no-print-directory build
	tree-sitter test

b:
	tree-sitter test --update
