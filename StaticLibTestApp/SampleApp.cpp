/*
	This is part of CFugue, a C++ Runtime for MIDI Score Programming
	Copyright (C) 2009 Gopalakrishna Palem

	For links to further information, or to contact the author,
	see <http://cfugue.sourceforge.net/>.
*/

// SampleApp.cpp
//
// Demonstrates the usage of CFugue as a Statically Linked Library
//
// CFugue is under active development.
// Please refer to documentation and latest releases at: http://cfugue.sourceforge.net/
#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

#include "CFugueLib.h"


int main()
{
    // Create the Player Object
    CFugue::Player player;
    // Play the Music Notes on the default MIDI output port
    player.Play("C D E F G A B");

    return 0;
}

