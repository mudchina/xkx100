// /kaifeng/cangjing1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "藏经楼");
	set("long", @LONG
藏经楼是一栋两层小楼，阁楼中都是佛家经典，名贵稀少的都用檀
木盒盛放了。收藏在楼上，派有专人职司。你满眼看去，到处是高低的
书架，
LONG);
	set("objects", ([
		__DIR__"npc/zhifa" : 1,
	]));
	set("exits", ([
		"up"   : __DIR__"cangjing2",
		"west" : __DIR__"houyuan",
		"east" : __DIR__"xiaoyuan",
	]));

	setup();
	replace_program(ROOM);
}
