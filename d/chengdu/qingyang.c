// Room: qingyang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "青羊宫");
	set("long", @LONG
青羊宫是天下第一大道观。观中林木婆娑，冠盖亭亭。观中道士匆
匆来去，没人得空理你，更没人接待你。你觉得到一种宽松的失落。
LONG );
	set("exits", ([
		"southeast" : __DIR__"nanjie2",
	]));
	set("objects", ([
		__DIR__"npc/dao-ren" : 1,
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
