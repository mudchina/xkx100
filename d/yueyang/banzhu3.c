// Room: /d/yueyang/banzhu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "斑竹林");
	set("long", @LONG
这里是一片斑竹林。湖风吹来，一阵叶响。斑竹又叫湘妃竹，在君
山，它多长在斑竹山上。清初施闺章在《江行杂咏》中写有《见斑竹》
的观感： “碧玉森森绿水湾，风鸣环佩满湘山。游人自洒离愁泪，不
是当年旧泪斑”。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"erfeimu",
		"west"  : __DIR__"banzhu3",
		"south" : __DIR__"banzhu1",
		"north" : __DIR__"banzhu2",
	]));
	set("coor/x", -1680);
	set("coor/y", 2300);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
