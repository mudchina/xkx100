// /kaifeng/daoxiang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "稻香居二楼");
	set("long", @LONG
老大一个大厅内相互间用屏风隔成十多个小间。穿戴厉索的小二端
着菜来往奔走，如果你分量够的话，还可以捞到个窗边的位置。边喝酒
边看看下面的繁华街景，人生一乐。
LONG);
	set("objects", ([
		__DIR__"npc/gaoyanei" : 1,
		__DIR__"npc/luyuhou" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
