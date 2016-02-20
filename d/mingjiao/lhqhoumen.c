//lhqhoumen.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "烈火旗后门");
	set("long", @LONG
这里就是烈火旗的后门，后面就是明教总舵所在，门宇轩大，教众
出入纷纷。由于地处紧要，这里的关防也很严密。
LONG );
	set("exits", ([
		"northup"   : __DIR__"zhandao1",
		"southdown" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/tuoba" : 1,
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1010);
	set("coor/z", 70);
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if ((me->query("party/party_name")!=HIG "明教" NOR) &&
		(dir=="northup") &&
		(objectp(present("tuoba", environment(me)))))
		return notify_fail("拓跋拦住你说：此处乃明教重地，请止步。\n");
	return ::valid_leave(me, dir);
}