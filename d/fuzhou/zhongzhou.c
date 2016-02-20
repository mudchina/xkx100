// Room: /d/fuzhou/zhongzhou.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "中洲桥");
	set("long", @LONG
中洲桥横越闽江，桥面平整，桥下水花喧闹。中洲为一小岛，尽是
水上人家。西边是一个码头。
LONG );
	set("exits", ([
		"west"  : __DIR__"matou",
		"north" : __DIR__"nanmen",
		"south" : __DIR__"puxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
