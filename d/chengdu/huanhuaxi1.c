// Room: huanhuaxi1.c
// Date: Feb.14 1998 by Java

inherit ROOM;

void create()
{
	set("short", "浣花溪边");
	set("long",@LONG
你走在浣花溪边，流水清澈，河边不少女子在此洗衣，淘菜。这条
蜿蜒的小溪，顺着那府南河流出，水面上尚有几株横里伸展的枝桠，轻
拂流水，有一股淡淡的诗意。秋风萧瑟，枝摇影斜，在静寂中，带着一
丝凄清与孤独。 
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"north"     : __DIR__"huanhuaxi",
		"southwest" : __DIR__"path2",
		"northeast" : __DIR__"huanhuaxi2",
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


