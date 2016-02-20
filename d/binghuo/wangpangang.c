// Room: /binghuo/wangpangang.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "王盘山渔港");
	set("long", @LONG
这里就是王盘岛山渔港了。北边是一望无际的大海；往西北是一
片树林。岛上的空气似乎又热又闷，咸湿的海风中带着一股腥臭。海
边泊着几艘大船(chuan)。
LONG );
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"chuan" : "几艘远洋大海船。上船(enter)就可以出海。\n",
	]));
	set("exits", ([
		"northwest" : __DIR__"wangpanlin",
	]));
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	ob = this_player ();
	if (random(4) >0)
	{
		message_vision("风帆升起，船头缓缓转过，风向逆转，船反而向西方航行。\n", ob);
		ob ->move(__DIR__"westboat") ;
		tell_object(ob, BLU "你在钱塘江上顺风顺水兜风，心情蛮好.......\n" NOR ) ;
		call_out("home", 10 , ob );
	}
	else
	{
		message_vision("风帆升起，船头缓缓转过，风力渐劲，船向东方大海深处航行。\n", ob);
		ob ->move(__DIR__"eastboat1") ;
		tell_object(ob, BLU "你在海上凭栏戏鸥，心情起伏不宁......\n" NOR ) ;
		call_out("fore1", 10 , ob );
	}
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "船很快就回到杭州了。你走下船来。\n" ) ;
	ob->move (__DIR__"qiantang") ;
}
void fore1( object ob )
{
	tell_object(ob , "四周一望无际的大海。你不禁有点心下惴惴。\n" ) ;
	ob->move (__DIR__"eastboat2") ;
	tell_object(ob, BLU "这船去哪里呢？你不禁有点紧张......\n" NOR ) ;
	call_out("fore2", 10 , ob );
}
void fore2( object ob )
{
	tell_object(ob , "船很快就靠上岛了。你走下船来。\n" ) ;
	ob->move (__DIR__"lingshedao") ;
}
