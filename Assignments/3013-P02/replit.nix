{ pkgs }: {
	deps = [
   pkgs.unzip
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}