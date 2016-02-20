// Room: /d/huanggong/xihuamen.c

inherit ROOM;

void create()
{
	set("short", "西华门");
	set("long", @LONG
西华门是皇帝和后妃们去京西苑囿及回宫时出入皇宫之门. 门外设
有下马碑石, 碑刻: 官员人等至此下马. 文武百官到达此地, 文官必须
下轿, 武官必须下马, 不得违背.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"humen",
		"east"  : __DIR__"wuying",
		"north" : __DIR__"dao8",
		"south" : __DIR__"dao9",
	]));
	set("no_clean_up", 0);

	set("coor/x", -230);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}