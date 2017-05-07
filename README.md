ali
=====


*This is a simply, modular, SCADA develop-kit.*

**Compile**
    You need libxml++2.6-dev ( for debian-based: "sudo apt-get install libxml++2.6-dev" )
    Into ali directory type: make remake

**Puprose**
    Now, it uses into scada-controlers  just for control serial devices, guiless, but its`n a limit of use purpose.

    So, we have:
	1. DONE: Modular system, whitch may load other modules from dynamic libs.

	2. NONE: Modules can send and recieve simply event, if its attributes has changed 

	3. One module can find other module by unicue identificator.

	4. NONE(tic-1s): Main loop tic in 1 ms

	5. DONE: Stub generator by xml modules defenition.
 
  





