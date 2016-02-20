// Room: /d/wuxi/wuguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "武馆");
	set("long", @LONG
你走进来，立刻就被这里生机勃勃的景象给吸引住了，大门口正竖
着一根旗杆，悬一幅黑底杏黄边的大旗，书着一个大大的“武”字。方
圆数百里之内的好武弟子都来这里学艺，里面的练武场上喊声阵阵。馆
主秦教头无门无派，祖传的十八般武艺，也算这一带的好手了。
LONG );
	set("exits", ([
		"west" : __DIR__"northroad2",
		"east" : __DIR__"wuchang",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", 380);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}