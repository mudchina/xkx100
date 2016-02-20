// Room: /binghuo/haitan.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "冰火岛海滩");
	set("long", @LONG
这是一个极大的岛屿。岛中心火柱周围一片青绿，岛屿西部都是
尖石嶙峋的山峰，奇形怪样，莫可名状。这些山峰均是火山的熔浆千
万年来堆积而成。岛东却是一片望不到尽头的平野，乃火山灰逐年倾
入海中而成。该处虽然地近北极，但因火山万年不灭，岛上气候便和
长白山、黑龙江一带相似，高山处玄冰白雪，平野上却极目青绿，苍
松翠柏，高大异常，更有诸般奇花异树，皆为中土所无。这岛上既有
万载玄冰，又有终古不灭的火窟，便被称为冰火岛。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"east"   : __DIR__"caodi1",
		"west"   : __DIR__"shulin1",
		"north"  : __DIR__"pingyuan1",
		"enter"  : __DIR__"southboat1",
	]));
	setup();
}

void init()
{
	object me;
	me=this_player();
	me->set("startroom",base_name(environment(me)));
	return;
}
