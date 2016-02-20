//tan2.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
		"这里是嘉兴南湖水下 ，四周倒还渐渐有些昏暗了，几道天光从头顶的潭水中投射下\n"
		"来，此时也不那么瑰丽了，昏沉沉的犹如天边的晚霞。脚下漆黑一片也不知有\n"
		"些什么。四周的水流也没有那么平静了，似乎在向一个方向流动着。你不由心中\n"
		"一动：不会有暗流吧！！\n"

	);
	set("exits", ([
		"up"   : __DIR__"tan1",
		"down" : __DIR__"tan3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
