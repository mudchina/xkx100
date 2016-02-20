// Room: /d/taohua/jingshe.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;
int do_pai(string arg);

void create()
{
	set("short","精舍");
	set("long",@LONG
这是桃花岛主黄药师的书房，全是以不刨皮的松树搭成，屋外攀满
了青藤。即便正当炎夏，一见到这间屋子，都是突感一阵清凉。屋里满
是诗经典籍玉器古玩。屋边摆着一张桌子(zhuozi)。正面的墙壁上挂着
一幅淡墨山水。
LONG
	);
	set("exits",([
		"south" : __DIR__"dating",
	]) );
	set("no_clean_up",0);
	set("item_desc",([
		"table" : "这是一张石桌。\n",
		"zhuozi" : "这是一张石桌。\n",
	]) );
	set("coor/x", 9010);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_pai", "pai");
	add_action("do_pai", "press");
}

void close_door(object room)
{
	message("vision", "卷轴自动拉下来，遮住了入口。\n", room);
	room->delete("exits/enter");
}

int do_pai(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if( arg == "table" || arg == "zhuozi")
        {
		write("正面壁上挂着的淡墨山水忽地徐徐升起，露出一个暗间来。\n");
		set("exits/enter", __DIR__"liandanfang");
		remove_call_out("close_door");
		call_out("close_door", 5, this_object());

                return 1;
        }
}