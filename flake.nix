{
  description = "QMK userspace";

  # make sure to have this on configuration.nix
  # services.udev.packages = with pkgs; [
  #   qmk-udev-rules
  # ];

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        devShells.default = pkgs.mkShell {
          nativeBuildInputs = with pkgs; [
            qmk
          ];
        };
      }
    );
}
