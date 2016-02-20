//Room: yuzhengong.c 遇真宫
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","遇真宫");
	set("long",@LONG
这里是进入武当山的第一道宫宇遇真宫，宽敞无比，可容千人食宿，
是进香客的一大歇脚处。三丰真人曾在此结庵修炼，因此宫中供着张三
丰真人像。由于张真人闭关已久，外人不知其是否仍在人间，民间传说
他已得道仙逝，立像膜拜。
LONG);
	set("objects", ([
	     CLASS_D("wudang") +"/zhixiang": 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
	    "northdown": __DIR__"shijie1",
	    "southup"  : __DIR__"wdbl",
	]));
	set("coor/x", -2050);
	set("coor/y", -820);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( dir == "southup" &&
		me->query("wudang/offerring")<me->query("age") &&
		me->query("title") != "武当道童" &&
		me->query("family/family_name") != "武当派" &&
		objectp(present("lingxu daozhang", environment(me))) &&
		!objectp(present("incense", me)) )
	{
		return notify_fail("凌虚道长喝道：如不是上山敬香，即刻请回！\n");
	}
	return ::valid_leave(me, dir);
}
