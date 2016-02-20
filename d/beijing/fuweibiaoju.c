// Room: /beijing/fuweibiaoju.c

inherit ROOM;

void create()
{
	set("short", "福威镖局北京分局");
	set("long", @LONG
朱漆大门上茶杯大小的铜钉闪闪发光，门顶的匾额写着“福威镖局
”四个金漆大字，下面横书“北京分号”四个小字。门内是两排长凳，
分坐八名劲装汉子，个个腰板笔挺，显出一股英悍之气。
LONG );

	set("exits", ([
		"north" : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/fuzhou/npc/yi" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
