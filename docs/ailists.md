# AI Lists

AI lists are responsible for all character programming and much of the logic used in each stage. Without AI lists guards would not talk, move, or even respond to you.

Each character has an AI list assigned to it. An AI list is a list of commands for characters to follow. Commands could be things like go to a certain room, shoot the player or say something. AI lists also contain if-statements, so it may for example check if the player is in sight then jump to a different part of the AI list if so.

In some cases AI lists are assigned to objects as well (hoverbots, the Extraction chopper and Area 51 interceptors). Some AI lists, such as those which implement general level logic, are run automatically for the duration of the level without being assigned to a character or object.

Under the hood, AI lists are custom bytecode that is interpreted by the game's C engine. Each command has a two byte identifier, following by a variable-length number of parameters that is specific to the command. However the low level details of this is abstracted away via meaningful C macros.

There are about 50 "global" AI lists. These global AI lists handle common tasks such as generic combat, patrolling and sitting idle in a chair. They are available to use in any stage. The rest of the AI lists are specific to each stage and can only be used by that stage.

Examples of AI lists can be found in each stage's setup file (`src/files/setup/*.c`) as well as the global ones in `src/game/data/ailists.c`.

A list of all commands can be found in `src/include/commands.h`.

## IDs and Naming

Every AI list has a unique ID. These IDs are required so AI lists can reference other AI lists, such as assigning a different one. The IDs also determine what type of AI list it is and if/when it's started automatically depending on what range the ID falls into.

### Global AI Lists (00xx)

Global AI lists can be assigned as the initial AI list for characters or assigned manually by other AI lists. They are not started automatically.

In this project global AI lists can be referenced using constants such as `GAILIST_ALERTED`. The list of these constants are in `src/include/constants.h` and their implementations are in `src/game/data/ailists.c`.

### Character AI lists (04xx excluding 0400)

These are similar to global AI lists, but they are specific to individual stages. They are defined in each stage's setup file and use constants such as `AILIST_SCIENTIST` (no G prefix). They do not run automatically; they must be assigned as the initial function for a character or invoked by another function.

### Cutscene AI Lists (0cxx)

Cutscene AI lists are started automatically when the player is using the cinema menu. There will typically be only two of these AI lists, for the opening and closing cutscenes, but levels which have a mid-gameplay cutscene will have a third. The number of the AI list corresponds to the cutscene number, so for a stage with three cutscenes 0c00 is the intro, 0c01 is the middle cutscene and 0c02 is the outro.

These AI lists are not started automatically during actual gameplay, so it's common to store the cutscene logic in a 04xx AI list then make the cutscene AI list call it.

### Background AI lists (10xx)

AI lists in this range will be started automatically when the stage is started using gameplay (but not run when using the cinema menu). They are commonly used for overarching stage logic that isn't specific to a character, such as monitoring objectives, or waiting for the player to enter a room then triggering a radio message.

### Environmental AI lists (14xx)

AI lists in this range are started automatically during both gameplay and when using the cutscene menu. They are typically used to configure lighting and portals.

## Yielding

When rendering a frame, the engine needs to iterate all characters and allow each of them to process a bit of their AI list. They can't process the list for too long or the engine will not be able to produce a frame in time and will cause frame lag. But it's also not desirable to give each AI list a fixed amount of CPU time before pausing it for the next frame, because then the state of the game may change between any two commands which would introduce bugs.

Instead, each AI list is able to choose when to pause and yield control back to the game engine. This is done using the `yield` command. When yielding, the AI list is declaring that it's done for this frame. The game engine will continue the AI list from the next command in a later frame.

Any time there's a loop, there must be a yield inside it otherwise the game would soft lock. Yields should also be done around relatively CPU heavy operations such as when spawning characters in bulk.

## Labels, If Statements and Loops

AI lists lack native language constructs such as if/else/endif and while loops, however they do have primitive if/goto statements which can be used to achieve the same effect, albeit with less readable code.

The primitive building blocks are:

* Labels: A label is a marker in the AI list. It is given a number so it can be identified. This number should be unique if it marks the start of a while loop. If it's the destination of an if statement then it can be a reused number.
* Goto next: Jumps to the next label with the given ID.
* Goto first: Jumps to the first label in the AI list with the given ID. These are used for loops.
* If statements: Many commands will check for a condition then jump to the next label with the given ID if the condition passes. If the condition fails execution continues from the next command as normal.
* Try statements: These commands make the character attempt to do something and then go to the label if successful, otherwise execution continues from the next command. An example is pathfinding; if the character can't find a path to the destination then it will fail.

This project provides some macros to help give some structure to the AI lists:

* `beginloop`: Is just the same as declaring a `label` followed by `yield`.
* `endloop`: Is literally just a `goto_first`, but endloop was a more meaningful name given the intention.
* `reloop`: Used when a loop has multiple points that jump back to the top of the loop. Like `endloop`, it's also the same as a `goto_first` but with a more meaningful name.
