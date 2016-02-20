// Room: /heizhao/shanlu4.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "密林矮树");
	set("long", @LONG
黑森森的四下里都是树木，无法直行，林中小路东盘西曲，密
林中难辨方向，你树林之中来回奔行。这时你已知林中道路，乃是
由人工布置，这般时而向左，时而转右，有时更倒退斜走数步，似
乎越行越是迂回迢遥。
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"east"       : __DIR__"shanlu3",
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
		who->add_temp("heizhao3",-1);
		return ::valid_leave(who, dir);
	}
	else
	{
		if (who->query_temp("heizhao3") < 26)
		{
			who->add_temp("heizhao3",1);
			return ::valid_leave(who, dir);
		}
		else
		{
			who->move(__DIR__"shanlu5");
			return notify_fail(HIR"好辛苦哦！总算走过一程了！\n"NOR);
		}
        }
}