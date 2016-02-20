// majuan.c.c 马圈

inherit ROOM;

void create()
{
	set("short", "马圈");
	set("long", @LONG
皇家马圈, 自然是好马云集. 一排排齐整的马厩, 一匹匹英挺高头
俊马, 让你不由想起大草原上万马奔腾的壮伟景象.
LONG
	);
	set("exits", ([
		"east" : __DIR__"yuhuayuan2",
	]) );
	set("objects", ([
		"/d/beijing/npc/yucongma" : 1,
	]) );
	set("coor/x", -210);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
