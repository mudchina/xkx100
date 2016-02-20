// Room: /d/5lt/tzoffice.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "台长办公室");
	set  ("long",  @LONG
这里就是台长办公室，屋内布置虽然极为简单，但是一进门你的视
线就被牢牢吸引住了。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"mishuchu",
	]));
        set("objects", ([
		__DIR__"npc/yoyo": 1,
	]));
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
