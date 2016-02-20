// Room: /binghuo/lingshetop.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山顶");
	set("long", @LONG
这里是灵蛇岛山顶。从这里俯瞰，碧螺般的灵蛇岛镶嵌在湛蓝的
大海中，一派生机勃勃。抬头远眺，真所谓烟波浩淼、海天一色了，
让人心襟大开。灵蛇岛所在偏僻，四周也不常有什么船只经过，除了
时而飞鸟掠空振翼外，只有不尽的海风呼啸了。
LONG );
	set("outdoors", "lingshe");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"      : __DIR__"lingsheroom",
		"southdown"  : __DIR__"lingsheroad3",
		"eastdown"   : __DIR__"lingsheroad4",
	]));
	setup();
	replace_program(ROOM);
}

