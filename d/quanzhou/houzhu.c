// Room: /d/quanzhou/houzhu.c
// Last Modified by winder on May. 29 2001
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后渚港");
	set("long", @LONG
后渚港是泉州三大港口之首。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。由于海外贸易
的广泛发展，泉州因而成为「海上丝绸之路」的起点。在众多的船只中
间，还有一只大战船(chuan)。
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
	]));
	set("exits", ([
		"north"   : __DIR__"portroad2",
	]));
	set("objects", ([
		__DIR__"npc/boy": 2,
		__DIR__"npc/girl": 1,
		__DIR__"npc/shuishi" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob = this_player () ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("船夫升起帆，船就向东方航行。\n", ob);
	ob ->move("/d/taiwan/dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("tpenghu", 10 , ob );
	return 1 ;
}
void tpenghu(object ob )
{
	tell_object(ob , "大船终于抵达了大海中一个大岛屿。你走下船来。\n" ) ;
	ob->move ("/d/taiwan/penghu") ;
}
