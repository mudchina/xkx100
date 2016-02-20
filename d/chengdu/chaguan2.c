// Room: /d/chengdu/chaguan2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "茶馆二楼");
	set("long", @LONG
到这里饮茶的人都是高雅之士，说话都不大声，相互交谈着各方面
的心得。推开窗户，眺目远望，芙蓉城美丽宜人的风光尽收眼底，徐徐
微风，吹着你的脸，再饮一口上等的“龙湖翠”悠哉，妙哉！
LONG );
	set("exits", ([
		"down" : __DIR__"chaguan",
	]));
	set("objects", ([
		__DIR__"obj/chair" : 3,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


