// Room: /d/suzhou/sanglin.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "桑林");
	set("long", @LONG
这里是一片桑林。江南丝绸甲于天下，苏绣更是天下绝品。看着满
眼的绿绿桑树，想象着春蚕吐丝的情节和亮丽如彩虹的丝缎，你倒有点
想摘下几片眼前再平常不过的桑叶，好好看看。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("ye_count", 5);
	set("exits", ([
		"southwest" : __DIR__"road1",
	]));
	set("coor/x", 1000);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object ye, me = this_player();

	if( !arg || arg=="" )
	{
		message_vision("你想摘什么？\n", me);
		return 1;
	}
	if( arg=="ye"||arg=="sang ye" )
	{
		if(query("ye_count") > 0)
		{
			message_vision("$N从桑树上摘下一片绿油油的桑叶。\n",me);
			ye = new("/clone/medicine/vegetable/sangye");
			ye->move(me);
			add("ye_count",-1);
			return 1;
		}
		else
		{
			message_vision("桑叶还太嫩了，$N等一会再摘吧。\n",me);
			return 1;	     
		}
	}
	return 0;
}
