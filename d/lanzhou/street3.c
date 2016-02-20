//  Room:  /d/lanzhou/street3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "滨河大街西");
	set("long",  @LONG
这是一条宽阔的青石板街道，向东西两头延伸。两旁路树成荫，行
人稀少，静悄悄地很是冷清。南面通往贡院，北面是一片树林，树林后
隐约可见一座寺院。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"jintian",
		"south" : __DIR__"cuiying",
		"east"  : __DIR__"street2",
		"west"  : __DIR__"westgate",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}