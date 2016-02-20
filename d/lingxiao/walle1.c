// Room: /d/lingxiao/walle1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城头");
	set("long", @LONG 
这是凌霄城的城头，从这极目远望，只见万里雪山，一片苍茫。黄
云万丈之下，无数起伏的山脉向东奔腾而去。沉寂的雪岭之间，只偶尔
传来一阵阵狼嗷。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east"     : __DIR__"walle2",
		"westdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

