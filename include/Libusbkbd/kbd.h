/*
	This library is based off of Luke Bridges' Homebrew library libusbkbd.
	Since we do not have access to STD libs in SMG2, it needed to be slightly altered to work.
	The current solution works on Dolphin, however a Real Console seems to fail.

	Here's an example on how to use the library:
    kbdfd = kbdinit();
    char *receivedmessage = kbdscan(kbdfd);
    char *pressed = kbdhandle(kbdfd, receivedmessage, false);
    kbddeinit(kbdfd);
*/

char* kbdhandle(int fd, char message[15], bool output);
int kbdinit();
void kbddeinit(int kbdfd);
char* kbdscan(int kbdfd);
int kbdver();
