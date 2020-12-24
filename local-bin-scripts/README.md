# local-bin-scripts

Installation:
	cd local-bin-scripts
	cp -r * ~/.local/bin

add this to your .zprofile (zsh) [or .profile for bash]

	PATH="$PATH:/$HOME/.local/bin"	
	PATH="$PATH:/$HOME/.local/bin/i3cmds"
	PATH="$PATH:/$HOME/.local/bin/statusbar"

then activate scripts:

	cd ~/.local/bin
	chmod +x *
	cd ~/.local/bin/i3cmds
	chmod +x *
	cd ~/.local/bin/statusbar
	chmod +x *

all commands should now be accessible from launchers, such as dmenu
