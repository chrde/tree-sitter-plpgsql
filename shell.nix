let
  pkgs = import <nixpkgs> { };
in pkgs.mkShell {
  buildInputs = with pkgs; [
    git
    nodejs
    gcc
    tree-sitter
  ];
}
