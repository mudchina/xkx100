// Room: /yangzhou/pailou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","牌楼");
	set("long",@LONG
大明寺山门前建牌楼，四柱三楹，木皆香材，正上题篆体“栖灵遗
址”，背题“丰乐名区”，极显雄伟。牌楼斗拱托顶，仰如伞盖，下置
白玉石础。牌楼前有一对青石正头巨型石狮。
    大明寺因始建于南朝刘宋大明年间故名。隋代，因寺在隋宫西侧，
故又名西寺。又因在寺内建九层栖灵塔，亦名栖灵寺。
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/boy" : 3,
	]));
	set("exits", ([
		"northup"   : __DIR__"shanmen",
		"southdown" : __DIR__"pingshanwu",
	]));
	set("coor/x", -30);
	set("coor/y", 130);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}