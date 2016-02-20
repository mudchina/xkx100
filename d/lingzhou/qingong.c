// Room: /d/lingzhou/qingong.c

inherit ROOM;

void create()
{
	set("short", "寝宫");
	set("long", @LONG
这里就是西夏皇帝的寝宫，一色的白玉地板，白色的纱帐，居中是
皇帝的龙榻，榻边是一张白老虎皮做的踏脚, 墙上挂着把新月弯刀，据
说是土蕃的贡品。东西两边侍卫们值夜守更的偏殿。北面墙上有幅老鹰
扑翅的巨画。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"piandian2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17990);
	set("coor/y", 32110);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
