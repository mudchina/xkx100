// Room: /d/nanshaolin/xiaolu3.c
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
		"southeast" : __DIR__"xiaolu4",
		"southwest" : __DIR__"xiaolu2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6140);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}

