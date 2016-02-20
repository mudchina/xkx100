// /d/meizhuang/shimen.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "石门");
	set("long", @LONG
这是在一条昏暗潮湿的地道里的一扇石门。墙壁上点着一盏油灯，
发出淡黄色光芒。
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"midao1",
	]));
	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, midao2;

	if (query("exits/southdown"))
		return notify_fail("这扇石门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("你不会撬锁。\n");
	if(!( midao2 = find_object(__DIR__"midao2")) )
                midao2 = load_object(__DIR__"midao2");
	if(objectp(midao2))
	{
		set("exits/southdown", __DIR__"midao2");
		message_vision("$N把钢芯钥匙插入了一个匙孔，转了几转，向内推动。\n只听得轧轧声响，一扇石门缓缓开了。\n", this_player());
		message("vision","只听一阵钥匙想，石门那边好象有人开门了。\n",
 midao2);
        }
	return 1;
}
