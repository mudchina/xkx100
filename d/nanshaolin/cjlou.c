// Room: /d/nanshaolin/cjlou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
这里就是南少林藏经阁。此处藏经之富，不下嵩山本院，天下罕有
其匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人通行
的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光及处，你看
到桌上放了几本佛经。
LONG );
	set("exits", ([
		"out" : __DIR__"xiaoxi1",
		"up"  : __DIR__"cjlou1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dachi" : 1,
		BOOK_DIR+"fojing1" : random(2),
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
        if( !present("shou yu", me) &&
		(objectp(present("dachi dashi", environment(me)))) )
	{
		if (dir == "up" )
		{
			return notify_fail("大痴大师说道: 你未经许可，不能上二楼。\n");
		}
	}
	return ::valid_leave(me, dir);
}

