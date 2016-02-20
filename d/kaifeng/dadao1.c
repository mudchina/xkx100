// /kaifeng/dadao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "三叉路口");
	set ("long", @LONG
道路至此分为三路，一条路向北就是开封城，东南面是座树林。林
中隐有条小道穿过。西南面的路通向野猪林。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"dadao0",
		"southwest" : __DIR__"dadao2",
		"southeast" : __DIR__"shulin",
	]));

	setup();
	replace_program(ROOM);
}
