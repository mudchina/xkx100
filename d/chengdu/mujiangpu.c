// Room: /d/chengdu/mujiangpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
void create()
{
	set("short", "木匠铺");
	set("long", @LONG
这是一家简陋的木匠铺，一个中年木匠正蹲在地上钉东西。值此乱
世，木匠们也只好制作些刀枪棍棒什么的以养家糊口。地上和墙角凌乱
地堆放着一些木剑，木刀，木棍什么的，还有几件象锯子，刨子一类的
木匠工具。
LONG	);
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie2",
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

