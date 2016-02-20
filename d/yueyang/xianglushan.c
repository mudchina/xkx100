// Room: /d/yueyang/xianglushan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "香炉山");
	set("long", @LONG
香炉山，位于洞庭湖中的君山南面，方圆约四亩，山成穹庐形，山
上灌木丛生，青翠欲滴。四周峭壁如削，滔滔湖水后浪赶着前浪撞击着
岩石，溅起一层层波光粼粼的水花，就好似它的腰间系着一条白色的绵
带，有时露出水面，有时隐没在烟雾里，如同一颗明珠嵌在波澜壮阔的
洞庭湖上，给“八百里洞庭”和君山增添了绚丽多姿的色彩，真是意味
独特，景趣迥然。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"longwangmiao",
		"south"     : __DIR__"xiangchunting",
		"northdown" : __DIR__"yangeng2",
	]));
	set("coor/x", -1800);
	set("coor/y", 2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
