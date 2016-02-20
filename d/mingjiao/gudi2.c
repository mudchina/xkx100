// Room: /d/mingjiao/gudi2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "昆仑谷底");
	set("long", @LONG
翻过那堵屏风也似的大山壁。眼前依旧茫茫云海，更无去路，山石
坚硬无比，你看到右边有一株大松树(tree)，左侧山壁黑黝黝似乎有个
小山洞(dong)。
LONG );
	set("outdoors", "mingjiao");
	set("item_desc", ([
		"dong": "一个不知深浅的山洞。\n",
		"tree": "一株挺拔健硕的松树。\n",
	]));
	set("coor/x", -50000);
	set("coor/y", 800);
	set("coor/z", 50);
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
		me->move(__DIR__"gudi3");
	}
	else
	{
		message_vision(HIR
"$N狂怒之下，劲运双肩，向前一挤，身子果然前进了尺许，可是再想前行，却已万万不\n", me);
		message_vision(
"能，坚硬的石壁压在他胸口背心，竟然气也喘不过来。$N窒息难受，只得后退，不料身\n", me);
		message_vision(
"子嵌在坚石之中，前进固是不能，后退却也已不得，这一下$N吓得魂飞魄散，竭尽生平\n", me);
		message_vision(
"之力，双臂向石上猛推，身子才退了尺许，猛觉得胸口一阵剧痛，竟已轧断了一根肋骨。\n"NOR, me);
		me->receive_damage("qi",15);
		me->receive_wound("qi",10);
	}
	return 1;
}
int do_climb(string arg)
{
	object me = this_player();
	if( !arg || arg != "tree")
	{
		write("你想干什么呀?\n");
		return 1;
	}
	message_vision("$N手攀松树，摇了两摇，试试是否结实。\n", me);
	message_vision("$N忽然一个失手，向悬崖下直跌下去。\n", me);
	me->move(__DIR__"shanjiao");
	me->receive_damage("qi",100 - me->query_dex());
	me->receive_wound("qi",100 - me->query_dex());
	me->unconcious();
	return 1;
}
