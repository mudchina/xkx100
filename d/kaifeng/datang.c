// /kaifeng/kaifeng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "开封府大堂");
	set("long", @LONG
两排的衙役站立两边，再旁边是龙头，虎头，狗头三把铡刀，白亮
的锋刃令人寒毛直竖。台桌后高挂『明镜高悬』的匾额。上了大堂，无
事也胆寒，东面出去就是街道。
LONG
	);
	set("objects", ([
		__DIR__"npc/baozheng" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"kaifeng",
	]));

	setup();
	replace_program(ROOM);
}
