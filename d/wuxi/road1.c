// Room: /d/wuxi/road1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "东驿道");
	set("long", @LONG
这是一条连接苏州和无锡的大驿道，富饶的鱼米之乡也使得官府
的所藏十分地殷实，筑桥修路自然就舍得花钱了。这里的路要比别的
地方宽阔得多，路边的杨柳树也显得特别得精神，向西可以看见无锡
的熙春门。北面是一片茂盛的杏树林，好象有一条小道穿进去。向东
就可以去苏州了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road2",
		"west"  : __DIR__"eastgate",
	]));
	set("coor/x", 500);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}