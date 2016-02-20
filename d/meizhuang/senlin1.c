// /d/meizhuang/senlin1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽的
小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名字的
异种苗木，其中有一株黄松(huang song)特别的粗壮，在它的茂密的枝
叶后面，似乎藏着什么秘密。旁边立着一块牌子(pai zi)。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"keting",
		"north" : __DIR__"neiyuan",
		"east" : __DIR__"senlin2",
		"west" : __DIR__"neitang",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"huang song" : "一株高大的黄松，挡住了你的视线。\n",
		"pai zi"     : "百木圣林，非请莫入，只可直行，切勿东向。\n",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);
	set("coor/x", 3500);
	set("coor/y", -1400);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	string dir;
	object me=this_player();

	if( !arg || arg=="" ) {write("你想爬什么？\n");return 1;}

	if( arg=="huang song" )
	{
		write("你手脚并用，笨手笨脚地向上爬着......\n");
		if((int)me->query_skill("dodge",1)>=30)
		{
			write("你爬呀爬，终于爬到了松树的顶端。\n");
			me->move(__DIR__"shuding1");
			return 1;
		}
		write(RED"“啪”的一声你又跌回原处，摔了个四脚朝天。\n"NOR);
		me->add("jing",-100);
		me->add("qi",-100);
		me->improve_skill("dodge", random(30));
		me->unconcious();

		return 1;
	}
}
