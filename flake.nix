{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    rust-overlay.url = "github:oxalica/rust-overlay";
  };

  outputs = { self, nixpkgs, rust-overlay }:
    let
      system = "x86_64-linux";
      overlays = [ (import rust-overlay) ];
      pkgs = import nixpkgs { inherit system overlays; };
      stdenv = "stdenv";
    in {
      packages.${system}.default =
        pkgs.${stdenv}.mkDerivation {
          pname = "tazel";
          version = "0.1.0";
          src = ./.;

          buildInputs = with pkgs; [
	    zig
          ];
        };

      devShells.${system}.default =
        pkgs.mkShell {
          inputsFrom = [ self.packages.${system}.default ];
        };
    };
}
