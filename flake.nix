{
  description = "Construct development shell from requirements.txt";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    pyproject-nix.url = "github:pyproject-nix/pyproject.nix";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    { self, nixpkgs, flake-utils, pyproject-nix, ... }:
    flake-utils.lib.eachDefaultSystem (system:
    let
      # Load/parse requirements.txt
      project = pyproject-nix.lib.project.loadRequirementsTxt { projectRoot = ./.; };
      pkgs = import nixpkgs { inherit system; };
      python = pkgs.python3;

      pythonEnv =
        # Assert that versions from nixpkgs matches what's described in requirements.txt
        # In projects that are overly strict about pinning it might be best to remove this assertion entirely.
        assert project.validators.validateVersionConstraints { inherit python; } == { };
        (
          # Render requirements.txt into a Python withPackages environment
          pkgs.python3.withPackages (project.renderers.withPackages { inherit python; })
        );

    in
    {
      devShells.default = with pkgs; mkShell {
        # Stuff needed to for libraries to link to
        buildInputs = with pkgs; [ ];
        packages = [
          pythonEnv
          qmk
          # Needed to build/display the docs
          doxygen
          yarn
        ];
      };
    }
    );
}
