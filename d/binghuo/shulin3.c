// Room: /binghuo/shulin3.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "大树林");
	set("long", @LONG
这里绿树成荫。奇花异卉，长青阔叶，漫山遍野。在这极北之处，
居然有此林木，看来是拜火山之赐了。偶尔惊起一些叫不出名目的大
鸟小兽，也不避人。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest" : __DIR__"shulin2",
		"south"     : __DIR__"pingyuan1",
		"northeast" : __DIR__"yuanye1",
		"northwest" : __DIR__"shanlu1",
	]));
	set("objects", ([
		"/d/guanwai/npc/buck": 1,
		"/d/guanwai/npc/doe": 1,
	]));
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir != "northwest")
	{
		return ::valid_leave(who, dir);
	}
	else
	{
		if (who->query_temp("binghuo") > 10)
		{
			return 1;
		}
		else
		{
			who->add_temp("binghuo",1);
			who->start_busy(2);
			return notify_fail("你向西北踉跄走去，可是好象方向不对，摸了半天，又回到了原地。\n");
		}
        }
}

void fall_down (object who, object where)
{
	who->move(where);
	this_player()->unconcious();
}
void fall_down1 (object who, object where)
{
	this_player()->unconcious();
}

