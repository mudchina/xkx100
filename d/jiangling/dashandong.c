//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "大山洞");
	set("long", @LONG
这是西山上一个大山洞，里面黑乎乎的，什么也没有。你睁眼仔细
观察，发现洞中有一丛丛齐肩的长草(cao)。
LONG );
	set("exits", ([
		"out"  : __DIR__"tulu4",
	]));
	set("item_desc", ([
	    "cao" : "长草密集厚实，好象遮盖住了什么，你实在看不清楚。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1630);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" )
	{
		write("你点燃了火折，发现草后面好象还有个洞，似乎可以钻(zuan)进去。\n");
		me->set_temp("marks/dashandong", 1);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if (me->query_temp("marks/dashandong") ) {
		message("vision", me->name() + "往草丛中滋溜一钻就不见了。\n", environment(me), ({me}) );
		me->move(__DIR__"shandong");
		message("vision", me->name() + "从草丛中钻了过来。\n", environment(me), ({me}) );
		me->delete_temp("marks/dashandong");
		return 1;
	}
        else {
		write("你想往哪儿钻？！\n");
		return 1;
        }
}