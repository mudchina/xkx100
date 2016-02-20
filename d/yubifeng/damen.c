// /yubifeng/damen.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "山庄大门");
	set("long", @long
转过了几株雪松，只见前面一座五开间极大的石屋，屋前屋后都是
白雪。大门外写着“玉笔峰山庄”几个大字，此处气候酷寒，上下艰难，
当初不知道庄主花了多少的心思才能在此建成如此石室，不禁令人啧啧
称奇。
long );
	set("exits", ([
		"west"  : __DIR__"fengding",
		"enter" : __DIR__"changlang",
	]));
	set("objects", ([
		__DIR__"npc/caoyunqi" : 1,
		__DIR__"npc/zhouyunyang" : 1,
		__DIR__"npc/ruanshizhong" : 1,
		__DIR__"npc/yinji" : 1,
	]));
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
