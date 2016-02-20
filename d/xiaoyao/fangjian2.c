// fangjian2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的
木头制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
       set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21030);
	set("coor/z", -40);
	setup();
}

void init()
{
        add_action("do_shout", "shout");
}

int do_shout(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="芝麻开门") 
	{
		tell_object(me,"你气运丹田，对着墙壁大喝一声：“芝麻开门！”\n");
		if (random(100) >50 || ((me->query("family")) && me->query("family")["master_name"]=="逍遥子"))
		{
		message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		}
	else
		{
		message("vision", "房间里到处回荡着你的声音，震得你的耳朵翁翁作响。\n", me);
		me->receive_wound("qi",20);
		me->unconcious();
		}
		return 1;
	}
}

void close(object room)
{
	message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
	room->delete("exits/down");
}