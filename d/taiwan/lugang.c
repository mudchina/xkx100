// Room: /d/taiwan/lugang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "鹿港");
	set("long", @LONG
鹿港地濒海滨，风帆争飞、万商毕集，是海峡两岸贸易的中部要港、
台湾中部的门户。俗谚云：一府二鹿三笨港，乃指鹿港为全台仅次于台
湾府的第二大城。
    海港内有舟(zhou)船来往澎湖。
LONG );
	set("exits", ([
		"east"       : __DIR__"banxianshe",
	]));
	set("objects", ([
		__DIR__"npc/shangren": 3,
	]));
	set("item_desc", ([
		"zhou" : "一条兵舟，往返澎湖的交通兵船。\n",
	]));

	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7000);
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
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	message_vision("水兵一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("水兵升起帆，船就向西方航行。\n", ob);
	ob ->move(__DIR__"dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("tpenghu", 10 , ob );
	return 1 ;
}
void tpenghu(object ob )
{
	tell_object(ob , "兵舟终于抵达了海峡中一个大岛。你走下船来。\n" ) ;
	ob->move (__DIR__"penghu") ;
}
