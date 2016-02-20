// Room: /d/tiezhang/dezj.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
	set("short", HIG"第二指节"NOR);
	set("long", @LONG
这里已到了中指峰的半山腰了，由于铁掌山排列得象手指一样，每
座山峰又分三截，就如手指的指节一般，因此这里正是位于第二指节的
位置。这里离峰顶已近，透过淡淡的云雾，似已可以看到山路的尽头了。
左前方二十于丈处，黑黝黝的似有一个洞穴(dong)，洞口砌以玉石，修
建得极是齐整。
LONG	);
	set("exits", ([ /* sizeof() == 3 */
		"south"   : __DIR__"sslin5",
		"enter"   : __DIR__"dong1",
		"northup" : __DIR__"shanlu8",
	]));
	set("objects", ([
		__DIR__"npc/mayi" : 2,
	]));
	set("item_desc", ([ 
		"dong" : "一个黑黝黝的山洞。黑暗中偶尔有几点磷光闪过，好吓人！！！\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1800);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
		return notify_fail("麻衣长老喝道：此乃铁掌帮禁地，任何人不得入内，否则有死无生！！\n");

	return ::valid_leave(me, dir);
}
