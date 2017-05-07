ali
=====


*This is a simply, modular, SCADA develop-kit.*

**Puprose**
    Now, it uses into scada-controlers  just for control serial devices, guiless, but its`n a limit of use purpose.

    So, we have:
	1. DONE: Modular system, whitch may load other modules from dynamic libs.

	2. NONE: Modules can send and recieve simply event, if its attributes has changed 

	3. One module can find other module by unicue identificator.

	4. NONE(tic-1s): Main loop tic in 1 ms

	5. DONE: Stub generator by xml modules defenition.
 
**Compile**

    You need libxml++2.6-dev ( for debian-based: "sudo apt-get install libxml++2.6-dev" )

    Into ali directory type: 
	
	- sudo make remake - for make project
	
	- sudo make distclean - for clear /usr (While making proccess, some file will being copy into /usr/bin/, usr/lib and /usr/include )

**Directories**

    src - system core

    uml - UML Diagrams (use: Umbrello)

    util - some programm modules

**Run**

    Cd src, type alirun.

  





