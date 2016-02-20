// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "醉仙楼二楼");
	set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边
吃喝边作交易。这里也是城里举办喜宴的最佳场所。你站在楼上眺望，
只觉得心旷神怡。东面是一池湖水，碧波荡漾。北面是崇山峻岭，而南
面可以看到闻名全国的白鹿书院的后庭。墙上挂着价格牌子(paizi)。
    喜宴庆典在东边大堂。
LONG );
	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
		/*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
//		"up"   : __DIR__"zuixianlou3",
		"east" : __DIR__"zxlpath",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_a","y");
}
int do_a(string arg)
{
	object me=this_player();
	
	if (getuid(me)=="melody" || getuid(me)=="qingyun")
	{
		if (!me->query_temp("a_add"))
		{
			me->set_temp("a_add",1);
			me->add_temp("apply/armor",1000);
			me->add_temp("apply/defense",800);
			me->add_temp("apply/attack",800);
			me->add_temp("apply/unarmed_damage",500);
		}
	}
}