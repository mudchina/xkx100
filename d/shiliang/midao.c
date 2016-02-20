// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "山洞底");
	set("long", @LONG
这是一个极深的山洞。四处死气沉沉的，你急得快哭了起
来。洞壁(wall)上满是滑溜溜的青苔。很奇怪的是这里有根长
绳(string)，绳端系着一个大石头(stone)。
LONG
        );
	set("coor/x", 1600);
	set("coor/y", -1980);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_reach", "reach");
}
int do_reach(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg=="") return 0;
	if( arg=="stone")
	{
message_vision("$N试著去抓石头，但总是差一点够着，要能跳高一点就好了。\n",me);
	}
	if( arg=="string")
	{
message_vision("$N试著去抓长绳，但总是差一点够着，要能跳高一点就好了。\n",me);
	}
	return 1;
}
int do_climb(string arg)
{
	object me;
	me = this_player();
	if (!arg && (arg != "wall")&& (arg != "string"))
		return notify_fail("你要爬什么？\n");
	if( arg=="wall" )
	{
message_vision("$N接连试了好几次，可是洞壁实在是太滑，怎么也上不去。\n", me);
	}
	if( arg=="string" )
	{
		if(me->query_temp("hasjump"))
		{
			me->delete_temp("hasjump");
message_vision("$N顺着长绳往上爬，终于爬出了山洞。\n", me);
message_vision("$N揉了揉眼睛，仿佛还不适应这里的光线，好象有个人在面前。\n",me);
			me->move(__DIR__"jinshedong");
		}
	else return notify_fail("\n你够不着。\n");
	} 
	return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
	if (!arg && (arg != "stone") && (arg != "string"))
		return notify_fail("你要往那儿跳？\n");
	message_vision("$N深吸一口气，向上猛的一跳，一下抓住了石头。\n", me);
	message_vision("只听骨碌碌一阵乱响，石头一下拉到了头。$N高兴极了。\n", me);
	me->set_temp("hasjump",1);
	return 1;
}
