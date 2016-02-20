//TOHSQ4.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
山路到这里似乎变得宽阔了些。清新的山风扑面而来，令人精神顿
为一爽。远处传来淙淙水声，渐行渐远。山壁上挂满了厚密的藤萝，随
风轻轻摇弋。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq5",
		"south" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 890);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}