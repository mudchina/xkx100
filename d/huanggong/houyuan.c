// houyuan.c
inherit ROOM;

void create()
{
	set("short", "清和殿后院");
	set("long", @LONG
这里是清和殿后院。院里种着些青菜。墙角有一口水井(well)。站
在水井边往下看，只觉深不见底，井壁上满是滑溜溜的青苔。一个轱辘
吊着一根长绳，绳端系着一个木桶。北边是一条走廊，通往御膳房。
LONG
	);
	set("outdoors", "huanggong");
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"yushanfang",
	]));
	set("item_desc", ([
		"well" : "一口枯井，相传跳进去可以美容。\n"
	]));

	set("coor/x", -180);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}