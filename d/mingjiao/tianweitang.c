//tianweitang.c
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "天微堂");
	set("long", @LONG
这里就是明教的天微堂，堂主就是威名远播的殷野王。他是白眉鹰
王的独子和教主张无忌的舅舅。堂内陈设鲜丽奢华，显然甚是兴旺，往
来教众进进出出，看他们各执兵刃，似乎是守总舵的卫士。
LONG );
	set("exits", ([
		"east"      : __DIR__"tianshitang",
		"west"      : __DIR__"ziweitang",
		"southdown" : __DIR__"zhandao2",
		"north"     : __DIR__"square",
	]));
	set("objects",([
		__DIR__"npc/yinyewang":1,
		__DIR__"npc/yinwufu":1,
	]));
	set("coor/x", -52030);
	set("coor/y", 1040);
	set("coor/z", 100);
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();
	if ((me->query("party/party_name")!=HIG "明教" NOR) &&
		(dir=="north") &&
		(objectp(present("yin yewang", environment(me)))))
	return notify_fail("殷野王拦住你说：此处乃明教重地，请止步。\n");
	return ::valid_leave(me, dir);
}