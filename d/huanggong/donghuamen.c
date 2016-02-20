// Room: /d/huanggong/donghuamen.c

inherit ROOM;

void create()
{
	set("short", "东华门");
	set("long", @LONG
东华门是朝臣和内官员们平时进出皇宫之门. 门外设有下马碑石,
碑刻: 官员人等至此下马. 文武百官到达此地, 文官必须下轿, 武官必
须下马, 不得违背.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"wenhua",
		"south" : __DIR__"dao2",
		"north" : __DIR__"dao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}