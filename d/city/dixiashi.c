// Room: /yangzhou/dixiashi.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set( "short", "地下室" );
	set( "long" , "这里黑乎乎的，什么也看不见。\n" );
	set( "exits", ([
		"up" : __DIR__"shufengguan",
	]));
	set("coor/x", -11);
	set("coor/y", -47);
	set("coor/z", -10);
	set("no_quest",1);
	setup();
}

void init()
{
	add_action( "do_use", "use" );
}

int do_use( string arg )
{
	object ob, me = this_player();

	if ( !me->can_act() ) return 0;
	if ( arg != "fire" ) return 0;
	if ( objectp ( ob = present( arg, me) ) )
	{
		write( "你取出怀里的火折子一晃，" );
		message_vision( "顿时你的眼前一亮。", me );
		set( "long", @LONG
这里颇为狭窄，却很干燥，中间放着一张桌子，上面放着一个小匣子。整个屋子里就这
么一点东西。
LONG
		);
/*
		本应该火折子到一定时间就灭的，
		不过好象比较麻烦，考虑的情况太多，以后再说。
		remove_call_out( "no_fire" );
		call_out( "no_fire", 10, ob )
*/
		ob = new( __DIR__"obj/xiaoxiazi" );
		ob->move();
		return 1;
	}
	return 0;
}