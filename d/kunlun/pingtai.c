// Room: /d/kunlun/dashibi.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"大平台"NOR);
	set("long", @LONG
前面是一堵屏风也似的大山壁。眼前茫茫云海，更无去路，你竟是
置身在一个三面皆空的极高平台上。那平台倒有十余丈方圆，可是半天
临空，上既不得，下又不能，当真是死路一条。这大平台上白皑皑的都
是冰雪，既无树林，更无野兽。唯有平台下有一株松树(tree)。
    你向前滑出一步，但见左侧山壁黑黝黝的似乎有个洞穴，山壁侧黑
黝黝似乎有个小山洞(dong)。
LONG );
	set("exits",([
		"west" : __DIR__"xsxiepo2",
	]));
        set("item_desc", ([
		"tree": "一株挺拔健硕的松树。\n",
                "dong": "一个不知深浅的山洞。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -100000);
	set("coor/y", 20010);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_enter","enter");
	add_action("do_climb","climb");
}
int do_enter(string arg)
{
	object me = this_player();
	int n = me->query("str");
	if( !arg || arg != "dong")
	{
		write("你想干什么呀?\n");
		return 1;
	}
	message_vision("$N深吸了一口气，慢慢沿着洞壁往里爬。\n", me);
	if(n < 20 || wizardp(me))
	{
		message_vision("$N爬进数丈，忽见前面透进光亮，心中大喜，手足兼施，加速前行。\n", me);
		me->move(__DIR__"cuigu");
	}
	else
	{
		message_vision( HIR"$N狂怒之下，劲运双肩，向前一挤，身子果然前进了尺许，可是再想前行，却已万万不\n能，坚硬的石壁压在他胸口背心，竟然气也喘不过来。$N窒息难受，只得后退，不料身\n子嵌在坚石之中，前进固是不能，后退却也已不得，这一下$N吓得魂飞魄散，竭尽生平\n之力，双臂向石上猛推，身子才退了尺许，猛觉得胸口一阵剧痛，竟已轧断了一根肋骨。\n"NOR, me);
		me->receive_damage("qi", 45);
		me->receive_wound("qi", 40);
	}
	return 1;
}
int do_climb(string arg)
{
	object me = this_player();
	if( !arg || arg != "tree")
	{
		write("你想干什么呀？\n");
		return 1;
	}
	message_vision("$N手攀松树，摇了两摇，试试是否结实。\n", me);
	message_vision("$N忽然一个失手，向悬崖下直跌下去。\n", me);
	me->move(__DIR__"xuedi");
	me->receive_damage("qi",100 - me->query_dex());
	me->receive_wound("qi",100 - me->query_dex());
	me->unconcious();
	return 1;
}
