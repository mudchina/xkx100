// Room: /d/quanzhou/gushaota.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "姑嫂塔");
	set("long", @LONG
姑嫂塔又名「关锁塔」，巍峨挺拔。登塔远望，则「手摩霄汉千山
尽，眼入沧溟百岛通」。相传古时有一张姓男子，抛妻别妹，远涉重洋，
不料海涂遇风，人舟尽沉。姑嫂俩登台远眺，日复一日，积思成疾，双
双而亡。后人建造此塔纪念二人。同时此塔也是泉州港重要的导航塔。
西边是安海港，北边则是永宁港。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west"  : __DIR__"anhaigang",
		"north" : __DIR__"yongninggang",
	]));
	set("objects", ([
		__DIR__"npc/langren" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6630);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
