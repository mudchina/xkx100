// Room: /d/5lt/yanwuqiao.c

inherit ROOM;

void create()
{
	set("short", "演武桥");
	set("long", @LONG
这是一座别致的小桥，桥栏上雕刻了许多花草动物，栩栩如生。桥
边新装了好几盏聚光灯，晚上灯亮起来的时候，简直是座水晶做的桥。
LONG);
	set("exits", ([
		"south"   : __DIR__"sroad2",
		"north"   : __DIR__"sroad1",
	]));
	set("outdoors", "5lt");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
