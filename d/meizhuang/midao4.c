// /d/meizhuang/midao4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条在西湖底下的地道。墙壁上点着一盏油灯，发出淡黄色光
芒。光芒照着拐弯处朝东的一间囚室。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1450);
	set("coor/z", -150);
	setup();
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob, jianyu;

	if (query("exits/east"))
		return notify_fail("这扇囚门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("gang yaoshi", this_player())))
		return notify_fail("你不会撬锁。\n");
	if(!( jianyu = find_object(__DIR__"jianyu")) )
		jianyu = load_object(__DIR__"jianyu");
	if(objectp(jianyu))
	{
		set("exits/east", __DIR__"jianyu");
		message_vision("$N把钢芯钥匙插入了一个匙孔，转了几转，向内推动。\n只听得一阵生涩的响动，$N伸手把囚门拉开。\n", this_player());
		jianyu->set("exits/west", __FILE__);
                message("vision","只听一阵钥匙想，囚门那边好象有人开门了。\n", jianyu);
		remove_call_out("close_gate");
		call_out("close_gate", 5);
	}
        return 1;
}
void close_gate()
{
	object jianyu;

	if( !query("exits/east") ) return;
        message("vision","铁门伊咿呀呀一阵想，砰地一声又关上了。\n", this_object
());
	if( jianyu = find_object(__DIR__"jianyu") )
	{
		message("vision", "铁门伊咿呀呀一阵想，砰地一声又关上了。\n", jianyu);
		jianyu->delete("exits/west");
        }
        delete("exits/east");
}

