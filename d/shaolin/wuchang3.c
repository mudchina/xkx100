// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。练武场中间
竖立着不少木人和草靶。西边角上还有两个大沙坑，十来个僧人
正在练习武艺。东西两面各有一长溜僧房。
LONG
	);

	set("exits", ([
		"south" : __DIR__"fzlou",
		"east" : __DIR__"hsyuan1",
		"west" : __DIR__"hsyuan4",
		"north" : __DIR__"guangchang5",
		"northup" : __DIR__"dmyuan",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/dao-cheng" : 1,
                __DIR__"npc/mu-ren" : 4
	]));

	set("coor/x", 0);
	set("coor/y", 890);
	set("coor/z", 120);
	setup();
}

int valid_leave(object me, string dir)
{
	if( !me->query("luohan_winner") && !wizardp(me))
	{
		if (dir == "northup")
		{
			return notify_fail("你级别不够，不能进入达摩院。\n");
		}
	}
	return ::valid_leave(me, dir);
}