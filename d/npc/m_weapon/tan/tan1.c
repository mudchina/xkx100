//tan1.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
	     "这里是嘉兴南湖水下 ，四周倒还比较明亮，几道天光从头顶的潭水中投射下来，\n"
	     "显得十分美丽。脚下漆黑一片也不知有些什么。你不由对自己说......\n"

	);
	set("exits", ([
		"up"   : "/d/jiaxing/nanhu1",
		"down" : __DIR__"tan2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
