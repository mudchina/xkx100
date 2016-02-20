// Room: yaodian.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "济世堂");
	set("long", @LONG
济世堂药店卖很多中原买不到的药。托唐门的福，生意一直都很好。
一走进这家药店，就闻到一股股浓烈刺鼻的药味。你正奇怪药店伙计怎
么能忍受，就看到药店里还有一些人正拿奇怪的眼光看你。他们的腰间
鼓鼓囊囊的，显然不是好惹的。
LONG	);
	set("objects", ([
		__DIR__"npc/huoji1" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie1",
	]));
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
