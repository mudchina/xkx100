// Room: /d/taiwan/penghu.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "澎湖岛");
	set("long", @LONG
澎湖为台湾属岛，海峡中砥，台岛屏障。马公港内多为本地渔民，
早晚劳作，与世无争。
    港内有舟(zhou)船(chuan) 往返大陆台岛，冲波激浪中，自有渔家
滋味。
LONG );
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
                "zhou"  : "一条水军战舟，前往台湾，还得靠它。\n",
	]));
	set("objects", ([
		__DIR__"npc/lanli": 1,
		__DIR__"npc/bing": 4,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2300);
	set("coor/y", -6800);
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
	if( !arg || (arg !="chuan" && arg !="zhou"))
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	if (arg == "chuan")
	{
		message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
		message_vision("船夫升起帆，船就向西方顺风航行。\n", ob);
		call_out("tdalu", 10 , ob );
	}
	else
	{
		message_vision("水兵一见有人上船，忙叫了一声：开船喽！\n", ob);
		message_vision("水兵升起帆，船就向东方逆风航行。\n", ob);
		call_out("ttaiwan", 10 , ob );
	}
	ob->move(__DIR__"dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	return 1 ;
}
void tdalu( object ob )
{
	tell_object(ob , "大船终于抵达了福建的一个繁华海港。你走下船来。\n" ) ;
	ob->move("/d/quanzhou/houzhu") ;
}
void ttaiwan( object ob )
{
	tell_object(ob , "战舟终于抵达了台湾的一个港口城市。你走下船来。\n" ) ;
	ob->move(__DIR__"lugang") ;
}
