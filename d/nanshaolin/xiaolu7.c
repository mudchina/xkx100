// Room: /d/nanshaolin/xiaolu7.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是一片密密的竹林。这里人迹罕至，惟闻足底叩击路面，有僧敲
木鱼声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳
的禅修所在。
LONG );
	set("exits", ([
		"west" : __DIR__"fzjs",
		"east" : __DIR__"xiaolu6",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

