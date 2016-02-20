// Room: /d/wuxi/northroad2.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
青砖街道由于有条小河从底下穿过有点起伏。北边可以看到通向城
外的北城门。东边是当地武馆，不少喜爱拳脚或是有大志于胸的青年往
往到这里去学些防身技能。西边是参和堂，一股浓浓的煎草药味常常不
时地从药铺里传出来，南边通向市中心，人非常地多。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"northgate",
		"south" : __DIR__"jinlianqiao",
		"east"  : __DIR__"wuguan",
		"west"  : __DIR__"canhetang",
	]));
	set("objects", ([
			"/d/village/npc/kid" : 1,
	]));
	set("coor/x", 370);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}