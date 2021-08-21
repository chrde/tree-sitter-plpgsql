let
  pkgs = import <nixpkgs> { };
  # openssl = pkgs.openssl.override { static = true; };
in pkgs.mkShell {
  buildInputs = with pkgs; [
    nodejs
    gcc
    tree-sitter
  ];
  # buildInputs = with pkgs; [ openssl pkg-config lld ];
  # LD_LIBRARY_PATH="${pkgs.openssl.out}/lib";
  # LD_LIBRARY_PATH = "${openssl}/lib";
}
