//  Room:  /d/lanzhou/street1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "滨河大街东");
	set("long",  @LONG
这是一条宽阔的青石板街道，向东西两头延伸。两旁路树成荫，行
人稀少，静悄悄地很是冷清。北面是一所道观，南面则是个热闹的集市。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"baiyun",
		"south" : __DIR__"market",
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"street2",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9280);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}