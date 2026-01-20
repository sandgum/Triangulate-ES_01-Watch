# How this UI project works



* After a lot of going back and forth, this UI uses EEZ studio as its drag and drop editor.
* Since EEZ Studio cannot support multiple displays in one project (The ES\_01 has three displays), each display gets its own EEZ Studio project.
* These will be exported (once done) and have custom logic added to the C files which links events happening on the main screen to changes on the two OLEDS.
* There will be a bunch of other stuff added to the C code, including wiring in all the variables and setting callback functions for haptics.
