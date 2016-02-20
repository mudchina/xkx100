// Room: /heizhao/shanlu2.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "密林矮树");
	set("long", @LONG
往前苦苦走了二里有余，但见黑森森的四下里都是树木，一入
林中，再也无法直行，林中小路东盘西曲，密林中难辨方向，忙跃
上树去眺望，无论你往那边望，都找不到出路。
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"east"       : __DIR__"shanlu1",
		"west"       : __FILE__,
		"north"      : __FILE__,
		"south"      : __FILE__,
		"northwest"  : __FILE__,
		"southwest"  : __FILE__,
		"northeast"  : __FILE__,
		"southeast"  : __FILE__,
	]));
	set("coor/x", -4000);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir != "northeast")
	{
		who->add_temp("heizhao1", -1);
		return ::valid_leave(who, dir);
	}
	else
	{
		if (who->query_temp("heizhao1") < 34)
		{
			who->add_temp("heizhao1",1);
			return ::valid_leave(who, dir);
		}
		else
		{
			who->move(__DIR__"shanlu3");
			return notify_fail(HIR"好辛苦哦！总算走过一程了！\n"NOR);
		}
        }
}