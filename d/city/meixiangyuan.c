// Room: /city/meixiangyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "媚香院");
	set("long", @LONG
院中点缀几块山石，西边依墙种着一株芭蕉，一株铁梗海棠。北边
有一轩，上面一额题曰「媚香楼」，轩外有数十株梅花植着。山石后，
有一池。池中畜许多挂珠蛋种，细白花鳞，中盖一亭，曰弦风。
LONG );
	set("no_fight", 1);
	set("item_desc", ([
		"north" : "依稀可以看到有女子在里面。\n",
	]));
	set("objects", ([
		__DIR__"npc/changxiang" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"beiliuxiang",
		"north" : __DIR__"waifang",
	]));
	set("coor/x", 41);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	string time = NATURE_D->game_time();
	string money, msg;
	if ( objectp( ob = present( "chang xiang", environment(me) ) ) 
		&& living( ob ) )
	{
		if ( dir == "north" )
		{
			if( (strsrch(time, "巳时") >= 0) || (strsrch(time, "午时") >= 0) || (strsrch(time, "丑时") >= 0) || (strsrch(time, "申时") >= 0)) 
			{
				message_vision("常翔栏住了$N说道：“现在小姐在休息呢，请以后再来吧吧。”\n", me);
				return notify_fail( "你被常翔拦住了去路。\n" );
			}
			if ( random(2) || me->query_temp( "chang_block" ) )
			{
				message_vision("常翔拦住了$N说道：“现在小姐不见客，请回吧。”\n", me);
				me->set_temp("chang_block", 1);
				remove_call_out("chang_dest");
				call_out("chang_dest", 1, me);
				return notify_fail("你被常翔拦住了去路。\n");
			}
		}
		if ( dir == "west" && me->query("lu_sing") )
		{
			money = chinese_number ( 8 + 2 * me->query("lu_sing") );
			msg = sprintf("%s%s%s%s%s", "常翔告诉你：你听了小姐", 
				chinese_number( me->query("lu_sing") ), 
				"首曲子，一共是", money, "两金子。\n");
			write( msg );
			return notify_fail("你被常翔拦住了去路。\n");
		}
	}
	return ::valid_leave(me, dir);
}
void chang_dest(object me)
{
	if ( me->query_temp("chang_block") )
		me->delete_temp("chang_block");
}
