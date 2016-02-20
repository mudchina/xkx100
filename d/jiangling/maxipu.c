//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "麻溪铺");
	set("long", @LONG
这是在湘西沅陵南郊的麻溪乡下，在小溪旁、柳树边的三间小屋之
前，是一个晒谷场。屋前矮凳上坐着一个老头儿，嘴里咬着一根短短的
旱烟管，手中正在打草鞋。淡淡阳光穿过他口中喷出来的一缕缕青烟，
照在他满头白发、满脸皱纹之上，但他向你瞥上一眼时，眼中神光炯然，
凛凛有威，看来他的年纪其实也并不很老，似乎五十岁也还不到。
LONG );
	set("exits", ([
		"east"   : __DIR__"caidi",
		"north"  : __DIR__"tiandi",
		"westup" : __DIR__"tulu4",
	]));
	set("objects", ([
		__DIR__"npc/qichangfa" : 1,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1610);
	set("coor/y", -2210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}