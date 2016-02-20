// Room: /d/kunlun/songshu.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "松树");
	set("long", @LONG
这是一株长于峭壁上的松树。向上而望，不能看见悬之上之物，刚
才从上而跳下之时，回想起来你自不禁心悸，额头冷汗涔涔而下，一看
四下形势，向上而攀援是绝不可能，脚下深不见底。便算到了底下，十
之八九也是没有出路，唯有沿着山壁斜坡，慢慢的爬行出去。
LONG	);
	set("exits",([
	]));
	set("no_clean_up", 0);
	set("coor/x", -100030);
	set("coor/y", 20010);
	set("coor/z", 40);
	set("outdoors", "hongmei");
	setup();
}
void init()
{
	add_action("do_pa","pa");
}
int do_pa(string arg)
{
	object me;
	me=this_player();
	if (!(arg||arg=="east"||arg=="west")) return 0;
	if (arg=="east"){
		message("vision",me->name()+"向着太阳升起的地方爬去。\n",environment(me),me);
		write("你向东面的雪山斜坡爬去。\n");
		me->move(__DIR__"xsxiepo1");
		message("vision",me->name()+"从松树爬了过来。\n",environment(me),me);
		return 1;
	}
	if (arg=="west")
	{
		message("vision",me->name()+"向西边爬去。\n",environment(me),me);
		write("你向西面的悬崖爬去。\n");
		me->move(__DIR__"xuanya1");
		message("vision",me->name()+"从松树爬了过来。\n",environment(me),me);
		return 1;
	}
	return 1;
}
